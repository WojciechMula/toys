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

/*
    The input data is 20 bytes (a..t):

    bytes: abcdefghijklmnop qrst
    index: 0123456789abcdef 0124

    We validate the first 16 bytes (a..p), and need
    extra four bytes after the byte `p`: the bytes q..t.
*/
bool avx512_utf8_structure_validate_16_bytes(const char* ptr, uint16_t& leading_bytes, uint16_t& valid_chars) {
    // 1. Load leading 16 bytes (a..p)
    const __m128i bytes_ap_128 = _mm_loadu_si128((const __m128i*)ptr);

    // 2. Load the tail 4 bytes (q..t)
    const __m128i bytes_qt_128 = _mm_loadu_si128((const __m128i*)(ptr + 16));

    return avx512_utf8_structure_validate_16_bytes(bytes_ap_128, bytes_qt_128, leading_bytes, valid_chars);
}

bool avx512_utf8_structure_validate_16_bytes(__m128i bytes_ap_128, __m128i bytes_qt_128) {
    uint16_t unused1;
    uint16_t unused2;

    return avx512_utf8_structure_validate_16_bytes(bytes_ap_128, bytes_qt_128, unused1, unused2);
}

bool avx512_utf8_structure_validate_16_bytes(__m128i bytes_ap_128, __m128i bytes_qt_128, uint16_t& leading_bytes, uint16_t& valid_chars) {

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


/*
    Valid ranges:
                        min         max
    ASCII               0x00'0000   0x00'007f
    2-byte chars        0x00'0080   0x00'07ff
    3-byte chars        0x00'0800   0x00'ffff
    4-byte chars        0x01'0000   0x10'ffff

    Excluded range for surrogate pairs:

                        0x00'd800   0x00'dfff
*/
__mmask16 avx512_utf8_validate_ranges(__m512i char_class, __m512i utf32) {
    // 1. Build minimum value
    //    We start with the min for 4-byte char (single bit set)
    //    and shift it right by the amount depeding on character class.
    __m512i min = _mm512_set1_epi32(0x0100000);

    /** pshufb

        continuation = 0x80
        ascii    = 32       # 0x0100000 >> 32 = 0x0000 - set to zero (vpsrlv guarantees this)
        _2_bytes = 13       # 0x0100000 >> 13 = 0x0800
        _3_bytes = 9        # 0x0100000 >> 9  = 0x8000
        _4_bytes = 0        # 0x0100000                - keep intact

        min_shifts = 4 * [
            ascii, # 0000
            ascii, # 0001
            ascii, # 0010
            ascii, # 0011
            ascii, # 0100
            ascii, # 0101
            ascii, # 0110
            ascii, # 0111
            continuation, # 1000
            continuation, # 1001
            continuation, # 1010
            continuation, # 1011
            _2_bytes, # 1100
            _2_bytes, # 1101
            _3_bytes, # 1110
            _4_bytes, # 1111
        ]
    */
    const __m512i min_shifts = _mm512_setr_epi64(
        0x2020202020202020,
        0x00090d0d80808080,
        0x2020202020202020,
        0x00090d0d80808080,
        0x2020202020202020,
        0x00090d0d80808080,
        0x2020202020202020,
        0x00090d0d80808080
    );

    {
        __m512i shift;
        shift = _mm512_shuffle_epi8(min_shifts, char_class);
        // Note: modify char_class to keep 32-bit values 0x8080800Y, thanks
        //       to that we get rid of the masking.
        shift = _mm512_and_si512(shift, _mm512_set1_epi32(0xff));
        min = _mm512_srlv_epi32(min, shift);
    }

    // 2. Build maximum value
    //    We start with the max for 4-byte char and shift it **left** by the amount
    //    depeding on character class. Then the negated-and-shifted mask is used
    //    to reset higher order bits: max andnot (max << k)
    __m512i max = _mm512_set1_epi32(0x010ffff);

    /** pshufb

        continuation = 0x80
        ascii    = 7        # 0x010ffff andnot 0x087fff80 = 0x0000007f
        _2_bytes = 11       # 0x010ffff andnot 0x87fff800 = 0x000007ff
        _3_bytes = 16       # 0x010ffff andnot 0xffff0000 = 0x0000ffff
        _4_bytes = 32       # 0x010ffff andnot 0x00000000 = 0x0010ffff -- keep intact

        max_shifts = 4 * [
            ascii, # 0000
            ascii, # 0001
            ascii, # 0010
            ascii, # 0011
            ascii, # 0100
            ascii, # 0101
            ascii, # 0110
            ascii, # 0111
            continuation, # 1000
            continuation, # 1001
            continuation, # 1010
            continuation, # 1011
            _2_bytes, # 1100
            _2_bytes, # 1101
            _3_bytes, # 1110
            _4_bytes, # 1111
        ]
    */
    const __m512i max_shifts = _mm512_setr_epi64(
        0x0707070707070707,
        0x20100b0b80808080,
        0x0707070707070707,
        0x20100b0b80808080,
        0x0707070707070707,
        0x20100b0b80808080,
        0x0707070707070707,
        0x20100b0b80808080
    );

    {
        __m512i shift;
        shift = _mm512_shuffle_epi8(max_shifts, char_class);
        shift = _mm512_and_si512(shift, _mm512_set1_epi32(0xff));
        const __m512i shifted = _mm512_sllv_epi32(max, shift);
        max = _mm512_andnot_si512(shifted, max);
    }

    // 4. check range min-max
    __mmask16 r1;
    r1 = _mm512_cmpge_epu32_mask(utf32, min);
    r1 = _mm512_mask_cmple_epu32_mask(r1, utf32, max);

    // 5. check surrogate pairs range
    __mmask16 r2;
    r2 = _mm512_cmpge_epu32_mask(utf32, _mm512_set1_epi32(0xd800));
    r2 = _mm512_mask_cmple_epu32_mask(r2, utf32, _mm512_set1_epi32(0xdfff));

    return _kandn_mask16(r2, r1);
}
