#include "avx512-utf8-to-utf32.h"

#include <cstdio>
#include <type_traits>

#include "avx512-expand.h"
#include "avx512-transcode-utf8.h"
#include "utf8.h"


namespace {
    const __m512i v_3f3f_3f7f = _mm512_set1_epi32(0x3f3f3f7f);
    const __m512i v_0140_0140 = _mm512_set1_epi32(0x01400140);
    const __m512i v_0001_1000 = _mm512_set1_epi32(0x00011000);
    const __m512i v_0001_0000 = _mm512_set1_epi32(0x00010000);
    const __m512i v_0010_ffff = _mm512_set1_epi32(0x0010ffff);
    const __m512i v_ffff_f800 = _mm512_set1_epi32(0xfffff800);
    const __m512i v_0000_d800 = _mm512_set1_epi32(0xd800);
    const __m512i v_0000_000f = _mm512_set1_epi32(0x0f);
    const __m512i v_8080_8000 = _mm512_set1_epi32(0x80808000);
    const __m512i v_0000_00c0 = _mm512_set1_epi32(0xc0);
    const __m512i v_0000_0080 = _mm512_set1_epi32(0x80);
}


__m512i avx512_utf8_to_utf32__aux__version1(__m512i utf8);
__m512i avx512_utf8_to_utf32__aux__version2(__m512i utf8);

template <typename EXPANDFN>
size_t avx512_utf8_to_utf32(EXPANDFN expandfn, const char* str, size_t len, uint32_t* dwords) {
    const char* ptr = str;
    const char* end = ptr + len;

    uint32_t* output = dwords;

    while (ptr + 16 + 3 < end) {
        /* 1. Load all possible 4-byte substring into an AVX512 register
              For example if we have bytes abcdefgh... we create following 32-bit lanes

              [abcd|bcde|cdef|defg|efgh|...]
               ^                          ^
               byte 0 of reg              byte 63 of reg

              It means, we are touching 16+3 = 19 bytes
        */
        const __m512i input = expandfn(ptr);

        /*
            2. Classify which words contain valid UTF-8 characters.
               We test if the 0th byte is not a continuation byte (0b10xxxxxx) */
        __mmask16 valid;
        {
            const __m512i t0 = _mm512_and_si512(input, _mm512_set1_epi32(0xc0));
            valid = _mm512_cmpneq_epu32_mask(t0, _mm512_set1_epi32(0x80));
        }
        const int valid_count = __builtin_popcount(valid);

        // 3. Convert words into UCS-32
        //    (XXX: would passing `valid` mask speed things up?
        //     answer: no)
        const __m512i utf32 = avx512_utf8_to_utf32__aux__version1(input);

        // 4. Pack only valid words
        const __m512i out = _mm512_mask_compress_epi32(_mm512_setzero_si512(), valid, utf32);

        // 5. Store them
        _mm512_storeu_si512((__m512i*)output, out);

        output += valid_count;
        ptr += 16;
    }

    // TODO: process the tail

    return output - dwords;
}

size_t avx512_utf8_to_utf32__version1(const char* str, size_t len, uint32_t* dwords) {
    return avx512_utf8_to_utf32(avx512_expand__version1, str, len, dwords);
}

size_t avx512_utf8_to_utf32__version2(const char* str, size_t len, uint32_t* dwords) {
    return avx512_utf8_to_utf32(avx512_expand__version2, str, len, dwords);
}

size_t avx512_utf8_to_utf32__version3(const char* str, size_t len, uint32_t* dwords) {
    const char* ptr = str;
    const char* end = ptr + len;

    uint32_t* output = dwords;

    if (len > 64) {

        // load 16 bytes: [abcdefghijklmnop]
        __m512i prev = _mm512_broadcast_i64x2(_mm_loadu_si128((const __m128i*)ptr));
        ptr += 16;

        while (ptr + 16 < end) {
            // load next 16 bytes: [qrstu....]
            const __m512i curr = _mm512_broadcast_i64x2(_mm_loadu_si128((const __m128i*)ptr));

            /* 1. Load all possible 4-byte substring into an AVX512 register
                  from bytes a..p (16) and q..t (4). For these bytes
                  we create following 32-bit lanes

                  [abcd|bcde|cdef|defg|efgh|...]
                   ^                          ^
                   byte 0 of reg              byte 63 of reg */

            const __m512i merged = _mm512_mask_mov_epi32(prev, 0x1000, curr);
            const __m512i expand_ver2 = _mm512_setr_epi64(
                0x0403020103020100,
                0x0605040305040302,
                0x0807060507060504,
                0x0a09080709080706,
                0x0c0b0a090b0a0908,
                0x0e0d0c0b0d0c0b0a,
                0x000f0e0d0f0e0d0c,
                0x0201000f01000f0e
            );

            const __m512i input = _mm512_shuffle_epi8(merged, expand_ver2);
            prev = curr;

            /*
                2. Classify which words contain valid UTF-8 characters.
                   We test if the 0th byte is not a continuation byte (0b10xxxxxx) */
            __mmask16 valid;
            {
                const __m512i t0 = _mm512_and_si512(input, _mm512_set1_epi32(0xc0));
                valid = _mm512_cmpneq_epu32_mask(t0, _mm512_set1_epi32(0x80));
            }
            const int valid_count = __builtin_popcount(valid);

            // 3. Convert words into UCS-32
            const __m512i utf32 = avx512_utf8_to_utf32__aux__version1(input);

            // 4. Pack only valid words
            const __m512i out = _mm512_mask_compress_epi32(_mm512_setzero_si512(), valid, utf32);

            // 5. Store them
            _mm512_storeu_si512((__m512i*)output, out);

            output += valid_count;
            ptr += 16;
        }
    }

    // TODO: process the tail

    return output - dwords;
}


#include "avx512-utf8-validate.h"


size_t avx512_validating_utf8_to_utf32_naive(const char* str, size_t len, uint32_t* dwords) {
    const char* ptr = str;
    const char* end = ptr + len;

    uint32_t* output = dwords;

    if (len > 64) {

        // load 16 bytes: [abcdefghijklmnop]
        __m128i prev128 = _mm_loadu_si128((const __m128i*)ptr);
        __m512i prev = _mm512_broadcast_i64x2(prev128);
        ptr += 16;

        while (ptr + 16 < end) {
            // load next 16 bytes: [qrstu....]
            const __m128i curr128 = _mm_loadu_si128((const __m128i*)ptr);

            // validate if bytes a..u form valid UTF-8 string
            if (!avx512_utf8_structure_validate_16_bytes(prev128, curr128)) {
                return 0;
            }

            const __m512i curr = _mm512_broadcast_i64x2(curr128);


            /* 1. Load all possible 4-byte substring into an AVX512 register
                  from bytes a..p (16) and q..t (4). For these bytes
                  we create following 32-bit lanes

                  [abcd|bcde|cdef|defg|efgh|...]
                   ^                          ^
                   byte 0 of reg              byte 63 of reg */

            const __m512i merged = _mm512_mask_mov_epi32(prev, 0x1000, curr);
            const __m512i expand_ver2 = _mm512_setr_epi64(
                0x0403020103020100,
                0x0605040305040302,
                0x0807060507060504,
                0x0a09080709080706,
                0x0c0b0a090b0a0908,
                0x0e0d0c0b0d0c0b0a,
                0x000f0e0d0f0e0d0c,
                0x0201000f01000f0e
            );

            const __m512i input = _mm512_shuffle_epi8(merged, expand_ver2);
            prev = curr;
            prev128 = curr128;

            /*
                2. Classify which words contain valid UTF-8 characters.
                   We test if the 0th byte is not a continuation byte (0b10xxxxxx)

                   Note: can reause bitmask build inside avx512_utf8_structure_validate_16_bytes.
            */
            __mmask16 valid;
            {
                const __m512i t0 = _mm512_and_si512(input, _mm512_set1_epi32(0xc0));
                valid = _mm512_cmpneq_epu32_mask(t0, _mm512_set1_epi32(0x80));
            }
            const int valid_count = __builtin_popcount(valid);

            // 3. Convert words into UTF-32
            const __m512i utf32 = avx512_utf8_to_utf32__aux__version3(input);

            // 4. Validate if UTF-32 chars are in valid ranges
            {
                const __m512i char_class = _mm512_and_si512(_mm512_srli_epi32(input, 4),
                                                            _mm512_set1_epi32(0x0000000f));
                const __mmask16 in_range = avx512_utf8_validate_ranges(char_class, utf32);
                if ((valid & in_range) != valid)
                    return 0;
            }

            // 4. Pack only valid words
            const __m512i out = _mm512_mask_compress_epi32(_mm512_setzero_si512(), valid, utf32);

            // 5. Store them
            _mm512_storeu_si512((__m512i*)output, out);

            output += valid_count;
            ptr += 16;
        }
    }

    // TODO: process the tail

    return output - dwords;
}


uint32_t continuation_bytes(__m128i utf8bytes) {
    const __m128i t0 = _mm_and_si128(_mm_set1_epi8(char(0xc0)), utf8bytes);
    const __m128i t1 = _mm_cmpeq_epi8(_mm_set1_epi8(char(0x80)), t0);
    return _mm_movemask_epi8(t1);
}


__mmask16 avx512_utf8_validate_ranges_masked(__m512i char_class, __m512i utf32) {
    __m512i min = v_0001_0000;

    const __m512i min_shifts = _mm512_setr_epi64(
        0x2020202020202020,
        0x0005090980808080,
        0x2020202020202020,
        0x0005090980808080,
        0x2020202020202020,
        0x0005090980808080,
        0x2020202020202020,
        0x0005090980808080
    );

    {
        const __m512i shift = _mm512_shuffle_epi8(min_shifts, char_class);
        min = _mm512_srlv_epi32(min, shift);
    }

    __m512i max = v_0010_ffff;

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
        const __m512i shift = _mm512_shuffle_epi8(max_shifts, char_class);
        const __m512i shifted = _mm512_sllv_epi32(max, shift);
        max = _mm512_andnot_si512(shifted, max);
    }

    __mmask16 not_surrogate;
    {
        const __m512i t0 = _mm512_and_si512(utf32, v_ffff_f800);
        not_surrogate = _mm512_cmpneq_epu32_mask(t0, v_0000_d800);
    }

    __mmask16 in_range;
    in_range = _mm512_mask_cmpge_epu32_mask(not_surrogate, utf32, min);
    in_range = _mm512_mask_cmple_epu32_mask(in_range, utf32, max);

    return in_range;
}


template <typename OUTPUT>
size_t avx512_validating_utf8_to_fixed_length(const char* str, size_t len, OUTPUT* dwords) {
    constexpr bool UTF32 = std::is_same<OUTPUT, uint32_t>::value;
    constexpr bool UTF16 = std::is_same<OUTPUT, char16_t>::value;
    static_assert(UTF32 or UTF16, "output type has to be uint32_t (for UTF-32) or char16_t (for UTF-16)");

    const char* ptr = str;
    const char* end = ptr + len;

    OUTPUT* output = dwords;

    if (len > 64) {

        // load 16 bytes: [abcdefghijklmnop]
        __m128i   prev128   = _mm_loadu_si128((const __m128i*)ptr);
        uint32_t  prev_cont = continuation_bytes(prev128);
        __m512i   prev      = _mm512_broadcast_i64x2(prev128);
        __mmask16 ascii     = _mm_movemask_epi8(prev128);
        ptr += 16;

        while (ptr + 16 < end) {
            // load next 16 bytes: [qrstu....]
            const __m128i curr128 = _mm_loadu_si128((const __m128i*)ptr);
            uint32_t curr_cont = continuation_bytes(curr128);
            const __m512i curr = _mm512_broadcast_i64x2(curr128);
            if (ascii == 0) {
                if (UTF32)
                    _mm512_storeu_si512((__m512i*)output, _mm512_cvtepu8_epi32(prev128));
                else
                    _mm256_storeu_si256((__m256i*)output, _mm256_cvtepu8_epi16(prev128));

                output += 16;
                ptr += 16;
                prev = curr;
                prev128 = curr128;
                prev_cont = curr_cont;
                ascii = _mm_movemask_epi8(curr128);
                continue;
            }

            ascii = _mm_movemask_epi8(curr128);

            /* 1. Load all possible 4-byte substring into an AVX512 register
                  from bytes a..p (16) and q..t (4). For these bytes
                  we create following 32-bit lanes

                  [abcd|bcde|cdef|defg|efgh|...]
                   ^                          ^
                   byte 0 of reg              byte 63 of reg */

            const __m512i merged = _mm512_mask_mov_epi32(prev, 0x1000, curr);
            const __m512i expand_ver2 = _mm512_setr_epi64(
                0x0403020103020100,
                0x0605040305040302,
                0x0807060507060504,
                0x0a09080709080706,
                0x0c0b0a090b0a0908,
                0x0e0d0c0b0d0c0b0a,
                0x000f0e0d0f0e0d0c,
                0x0201000f01000f0e
            );

            const uint32_t continuation = prev_cont | (curr_cont << 16);

            const __m512i input = _mm512_shuffle_epi8(merged, expand_ver2);
            prev = curr;
            prev128 = curr128;
            prev_cont = curr_cont;

            /* 1. Classify leading bytes */
            __m512i char_class;
            char_class = _mm512_srli_epi32(input, 4);
            char_class = _mm512_and_si512(char_class, v_0000_000f);
            char_class = _mm512_or_si512(char_class, v_8080_8000);

            /* 2. Get positions of leading bytes */
            __mmask16 leading_bytes;
            {
                const __m512i t0 = _mm512_and_si512(input, v_0000_00c0);
                leading_bytes = _mm512_cmpneq_epu32_mask(t0, v_0000_0080);
            }

            /* 3. Validate UTF-8 structure */
            {
                /** pshufb
                continuation = 0
                ascii    = 0x01
                _2_bytes = 0x03
                _3_bytes = 0x07
                _4_bytes = 0x0f

                mask_lookup = 4 * [
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
                ] */
                const __m512i mask_lookup = _mm512_setr_epi64(
                    0x0101010101010101,
                    0x0f07030300000000,
                    0x0101010101010101,
                    0x0f07030300000000,
                    0x0101010101010101,
                    0x0f07030300000000,
                    0x0101010101010101,
                    0x0f07030300000000
                );
                const __m512i mask = _mm512_shuffle_epi8(mask_lookup, char_class);
                const __m512i expected = _mm512_srli_epi32(mask, 1);

                __m512i v_continuation;
                v_continuation = _mm512_set1_epi32(continuation);
                v_continuation = _mm512_srlv_epi32(v_continuation, _mm512_setr_epi32(
                    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16
                ));

                const __m512i masked = _mm512_and_si512(v_continuation, mask);

                const __mmask16 matched = _mm512_mask_cmpeq_epu32_mask(leading_bytes, masked, expected);
                if (matched != leading_bytes)
                    return 0;
            }

            const int valid_count = __builtin_popcount(leading_bytes);

            // 3. Convert words into UTF-32
            const __m512i utf32 = avx512_utf8_to_utf32__aux__version3(char_class, input);

            // 4. Validate if UTF-32 chars are in valid ranges
            {
                const __mmask16 in_range = avx512_utf8_validate_ranges_masked(char_class, utf32);
                if ((leading_bytes & in_range) != leading_bytes) {
                    return 0;
                }
            }

            // 4. Pack only valid words
            const __m512i out = _mm512_mask_compress_epi32(_mm512_setzero_si512(), leading_bytes, utf32);

            // 5. Store them
            if (UTF32)
                _mm512_storeu_si512((__m512i*)output, out);
            else
                _mm256_storeu_si256((__m256i*)output, _mm512_cvtepi32_epi16(out));

            output += valid_count;
            ptr += 16;
        }
    }

    // slow path
    if (len > 64) {
        ptr -= 16;
    }

    while (ptr < end) {
        uint32_t val;
        ptr += utf8_decode(ptr, val);
        *output++ = val;
    }

    return output - dwords;
}

size_t avx512_validating_utf8_to_utf32(const char* str, size_t len, uint32_t* dwords) {
    return avx512_validating_utf8_to_fixed_length<uint32_t>(str, len, dwords);
}

size_t avx512_validating_utf8_to_utf16(const char* str, size_t len, char16_t* chars) {
    return avx512_validating_utf8_to_fixed_length<char16_t>(str, len, chars);
}


#include "validate/avx512-validate-utf8.constants.cpp"
#include "validate/avx512-validate-structure.cpp"
#include "validate/avx512-validate-leading-bytes.cpp"

namespace {
    __m512i _mm512_rotate_by1_epi8(const __m512i input) {

        // lanes order: 1, 2, 3, 0 => 0b00_11_10_01
        const __m512i permuted = _mm512_shuffle_i32x4(input, input, 0x39);

        return _mm512_alignr_epi8(permuted, input, 1);
    }
}


template <unsigned idx0, unsigned idx1, unsigned idx2, unsigned idx3>
constexpr __m512i shuffle_epi128(__m512i v) {
    static_assert((idx0 >= 0 and idx0 <= 3), "idx0 must be in range 0..3");
    static_assert((idx1 >= 0 and idx1 <= 3), "idx1 must be in range 0..3");
    static_assert((idx2 >= 0 and idx2 <= 3), "idx2 must be in range 0..3");
    static_assert((idx3 >= 0 and idx3 <= 3), "idx3 must be in range 0..3");

    constexpr unsigned shuffle = idx0 | (idx1 << 2) | (idx2 << 4) | (idx3 << 6);
    return _mm512_shuffle_i32x4(v, v, shuffle);
}

template <unsigned idx>
constexpr __m512i broadcast_epi128(__m512i v) {
    return shuffle_epi128<idx, idx, idx, idx>(v);
}


template <typename OUTPUT>
size_t avx512bw_validating_utf8_to_fixed_length(const char* str, size_t len, OUTPUT* dwords) {
    constexpr bool UTF32 = std::is_same<OUTPUT, uint32_t>::value;
    constexpr bool UTF16 = std::is_same<OUTPUT, char16_t>::value;
    static_assert(UTF32 or UTF16, "output type has to be uint32_t (for UTF-32) or char16_t (for UTF-16)");

    const char* ptr = str;
    const char* end = ptr + len;

    OUTPUT* output = dwords;

    while (ptr + 64 < end) {
        const __m512i input = _mm512_loadu_si512((const __m512i*)ptr);
        const __mmask64 ascii = _mm512_test_epi8_mask(input, v_80);
        if (ascii == 0) {
            const __m256i h0 = _mm512_castsi512_si256(input);
            const __m256i h1 = _mm512_extracti32x8_epi32(input, 1);

            const __m128i t0 = _mm256_castsi256_si128(h0);
            const __m128i t1 = _mm256_extracti32x4_epi32(h0, 1);
            const __m128i t2 = _mm256_castsi256_si128(h1);
            const __m128i t3 = _mm256_extracti32x4_epi32(h1, 1);

            if (UTF32) {
                _mm512_storeu_si512((__m512i*)(output + 0*16), _mm512_cvtepu8_epi32(t0));
                _mm512_storeu_si512((__m512i*)(output + 1*16), _mm512_cvtepu8_epi32(t1));
                _mm512_storeu_si512((__m512i*)(output + 2*16), _mm512_cvtepu8_epi32(t2));
                _mm512_storeu_si512((__m512i*)(output + 3*16), _mm512_cvtepu8_epi32(t3));
            }
            else {
                _mm256_storeu_si256((__m256i*)(output + 0*16), _mm256_cvtepu8_epi16(t0));
                _mm256_storeu_si256((__m256i*)(output + 1*16), _mm256_cvtepu8_epi16(t1));
                _mm256_storeu_si256((__m256i*)(output + 2*16), _mm256_cvtepu8_epi16(t2));
                _mm256_storeu_si256((__m256i*)(output + 3*16), _mm256_cvtepu8_epi16(t3));
            }

            output += 64;
            ptr += 64;
            continue;
        }

        // 1. Validate the structure of UTF-8 sequence.
        //    Note: procedure validates chars that starts in range [0..60]
        //    of input.
        if (not avx512_validate_utf8_structure(input)) {
            return false;
        }

        // 2. Precise validate: once we know that the bytes structure is correct,
        //    we have to check for some forbidden input values.
        //    Note: this procedure validates chars in range [0..63], due to
        //    method of obtaining continuation1 vector. (compare with
        //    validation/avx512-validate-utf8.cpp)
        const __m512i continuation1 = _mm512_rotate_by1_epi8(input);
        if (not avx512_validate_leading_bytes(input, continuation1, 0x0ffffffffffffffflu)) {
            return false;
        }

        const __m512i expand_ver2 = _mm512_setr_epi64(
            0x0403020103020100,
            0x0605040305040302,
            0x0807060507060504,
            0x0a09080709080706,
            0x0c0b0a090b0a0908,
            0x0e0d0c0b0d0c0b0a,
            0x000f0e0d0f0e0d0c,
            0x0201000f01000f0e
        );

        // 3. Convert 3*16 input bytes
        // We waste the last 16 bytes, which are not fully validated...
        // this is another topic to check in the future.
#define TRANSCODE16(LANE0, LANE1)                                                                            \
        {                                                                                                    \
            const __m512i merged = _mm512_mask_mov_epi32(LANE0, 0x1000, LANE1);                              \
            const __m512i input = _mm512_shuffle_epi8(merged, expand_ver2);                                  \
                                                                                                             \
            __mmask16 leading_bytes;                                                                         \
            const __m512i t0 = _mm512_and_si512(input, v_0000_00c0);                                         \
            leading_bytes = _mm512_cmpneq_epu32_mask(t0, v_0000_0080);                                       \
                                                                                                             \
            __m512i char_class;                                                                              \
            char_class = _mm512_srli_epi32(input, 4);                                                        \
            char_class = _mm512_and_si512(char_class, v_0000_000f);                                          \
            char_class = _mm512_or_si512(char_class, v_8080_8000);                                           \
                                                                                                             \
            const int valid_count = __builtin_popcount(leading_bytes);                                       \
            const __m512i utf32 = avx512_utf8_to_utf32__aux__version3(char_class, input);                    \
                                                                                                             \
            const __m512i out = _mm512_mask_compress_epi32(_mm512_setzero_si512(), leading_bytes, utf32);    \
                                                                                                             \
            if (UTF32)                                                                                       \
                _mm512_storeu_si512((__m512i*)output, out);                                                  \
            else                                                                                             \
                _mm256_storeu_si256((__m256i*)output, _mm512_cvtepi32_epi16(out));                           \
                                                                                                             \
            output += valid_count;                                                                           \
        }

        const __m512i lane0 = broadcast_epi128<0>(input);
        const __m512i lane1 = broadcast_epi128<1>(input);
        TRANSCODE16(lane0, lane1)

        const __m512i lane2 = broadcast_epi128<2>(input);
        TRANSCODE16(lane1, lane2)

        const __m512i lane3 = broadcast_epi128<3>(input);
        TRANSCODE16(lane2, lane3)

        ptr += 3*16;
    }

    while (ptr < end) {
        uint32_t val;
        ptr += utf8_decode(ptr, val);
        *output++ = val;
    }

    return output - dwords;
}


size_t avx512bw_validating_utf8_to_utf32(const char* str, size_t len, uint32_t* dwords) {
    return avx512bw_validating_utf8_to_fixed_length<uint32_t>(str, len, dwords);
}

size_t avx512bw_validating_utf8_to_utf16(const char* str, size_t len, char16_t* chars) {
    return avx512bw_validating_utf8_to_fixed_length<char16_t>(str, len, chars);
}
