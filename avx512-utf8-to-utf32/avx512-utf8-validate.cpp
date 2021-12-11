#include "avx512-utf8-validate.h"

#include <immintrin.h>

/*
    Structural UTF-8 validation

    We assume that the portion of bytes validated by the AVX512 code
    never reaches the end-of-stream. In other words: every character is
    followed by at least four bytes. Then we have just two rules to
    check:

    1. The leading byte is followed by the correct number of
       continuation bytes (0, 1, 2 or 3).
    2. The next byte after all character bytes has to be a leading byte.

    Let's set symbols:
    * L - leading byte/ASCII,
    * C - continuation byte,
    * x - don't care byte

    For 4-byte characters we have:

        [L|C|C|C|L]
         ^^^^^^^ ^
         char    the next byte

    For 3-byte characters we have:

        [L|C|C|L|?]
         ^^^^^ ^^^
         char  the tail bytes

    For 2-byte characters we have:

        [L|C|L|?|?]
         ^^^ ^^^^^
         char  the tail bytes

    For ASCII chars we have:

        |L|L|?|?|?|
         ^ ^^^^^^^
         |  the tail bytes
         += char

    To fully validate any UTF-8 character we need five bytes.

    The first byte is used to classify a character (ASCII/2-/3-/4-bytes).
    The remaining four bytes are just classified whether they
    are continuation bytes or not (1=continuation); this yields
    a 4-bit mask.

    Using the character class we pick how many bytes are required
    to validate and what is the mask of continuation bytes.

                    tail bytes  mask    expected
    4-byte chars    4           0b1111  0b0111
    3-byte chars    3           0b0111  0b0011
    2-byte chars    2           0b0011  0b0001
    ASCII           1           0b0001  0b0000
    continuation    n/a         0b0000  0b0000

    Note that expected = mask >> 1, thus only `mask` is stored.
*/

bool avx512_utf8_structure_validate_16_bytes(const char* ptr, uint16_t& leading_bytes, uint16_t& valid_chars) {
    /*
        The input data is 20 bytes (a..t):

        bytes: abcdefghijklmnop qrst
        index: 0123456789abcdef 0124

        We validate the first 16 bytes (a..p), and need
        extra four bytes after the byte `p`: the bytes q..t.
    */

    // 1. Load leading 16 bytes (a..p)
    const __m128i bytes_ap_128 = _mm_loadu_si128((const __m128i*)ptr);

    // 2. Load the tail 4 bytes (q..t)
    const __m128i bytes_qt_128 = _mm_loadu_si128((const __m128i*)(ptr + 16));

    // 3. Produce bitmask of continuation bytes for input in range b..q
    //    Continuation bytes have the following bit pattern: 10xxx.xxxx
    uint32_t continuation;
    {
        const __m128i t0 = _mm_and_si128(_mm_set1_epi8(char(0xc0)), bytes_ap_128);
        const __m128i t1 = _mm_cmpeq_epi8(_mm_set1_epi8(char(0x80)), t0);
        continuation = _mm_movemask_epi8(t1);
    }
    {
        const __m128i t0 = _mm_and_si128(_mm_set1_epi8(char(0xc0)), bytes_qt_128);
        const __m128i t1 = _mm_cmpeq_epi8(_mm_set1_epi8(char(0x80)), t0);
        continuation |= uint32_t(_mm_movemask_epi8(t1)) << 16;
    }

    // 4. Populate the continuation bitmask
    __m512i v_continuation = _mm512_set1_epi32(continuation);

    // 5. Move 4-bit sub-words to proper positions
    v_continuation = _mm512_srlv_epi32(v_continuation, _mm512_setr_epi32(
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16
    ));

    // 6. Get expected mask based on character class
    __m128i mask;
    constexpr uint8_t mask_continuation = 0x00;
    constexpr uint8_t mask_ascii   = 0x01;
    constexpr uint8_t mask_2_bytes = 0x03;
    constexpr uint8_t mask_3_bytes = 0x07;
    constexpr uint8_t mask_4_bytes = 0x0f;

    const __m128i mask_lookup = _mm_setr_epi8(
        /* 0000 */ mask_ascii,
        /* 0001 */ mask_ascii,
        /* 0010 */ mask_ascii,
        /* 0011 */ mask_ascii,
        /* 0100 */ mask_ascii,
        /* 0101 */ mask_ascii,
        /* 0110 */ mask_ascii,
        /* 0111 */ mask_ascii,
        /* 1000 */ mask_continuation,
        /* 1001 */ mask_continuation,
        /* 1010 */ mask_continuation,
        /* 1011 */ mask_continuation,
        /* 1100 */ mask_2_bytes,
        /* 1101 */ mask_2_bytes,
        /* 1110 */ mask_3_bytes,
        /* 1111 */ mask_4_bytes
    );
    {
        const __m128i t0 = _mm_srli_epi16(bytes_ap_128, 4);
        const __m128i t1 = _mm_and_si128(t0, _mm_set1_epi8(0x0f));
        mask = _mm_shuffle_epi8(mask_lookup, t1);
    }

    __m128i expected = mask;
    expected = _mm_srli_epi16(expected, 1);
    expected = _mm_and_si128(expected, _mm_set1_epi8(0x0f));

    // 7. Compare the expected continuation mask with the actual mask
    const __m128i t0 = _mm512_cvtepi32_epi8(v_continuation);
    const __m128i t1 = _mm_and_si128(mask, t0);
    const __m128i valid = _mm_cmpeq_epi8(t1, expected);

    // 8. Prepare bitmask for leading bytes and valid chars
    leading_bytes = ~uint16_t(_mm_movemask_epi8(_mm_cmpeq_epi8(mask, _mm_setzero_si128())));
    valid_chars = _mm_movemask_epi8(valid);

    return (leading_bytes & 0x1) // detect strings starting with continuation bytes
       and (leading_bytes == valid_chars);
}
