#include "avx512-utf8-to-utf32.h"

#include <cstdio>

namespace {
    __attribute__((__aligned__(64))) uint32_t rotate_left_idx[16][16] = {
        { 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15},
        {15,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14},
        {14, 15,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13},
        {13, 14, 15,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12},
        {12, 13, 14, 15,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11},
        {11, 12, 13, 14, 15,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10},
        {10, 11, 12, 13, 14, 15,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9},
        { 9, 10, 11, 12, 13, 14, 15,  0,  1,  2,  3,  4,  5,  6,  7,  8},
        { 8,  9, 10, 11, 12, 13, 14, 15,  0,  1,  2,  3,  4,  5,  6,  7},
        { 7,  8,  9, 10, 11, 12, 13, 14, 15,  0,  1,  2,  3,  4,  5,  6},
        { 6,  7,  8,  9, 10, 11, 12, 13, 14, 15,  0,  1,  2,  3,  4,  5},
        { 5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,  0,  1,  2,  3,  4},
        { 4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,  0,  1,  2,  3},
        { 3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,  0,  1,  2},
        { 2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,  0,  1},
        { 1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,  0}
    };

    __m512i uint32_rotate_left(__m512i v, unsigned amount) {
        const __m512i idx = _mm512_load_si512((const __m512i*)(&rotate_left_idx[amount & 0xf]));
        return _mm512_permutexvar_epi32(idx, v);
    }

    // RegisterAccumulator accumulates the unpacked UTF-8 words until
    // an AVX512 is full and only then calls the conversion routine.
    class RegisterAccumulator {
        struct {
            __m512i vector;
            int     count; // active items 0..active     
        } current;

    public:
        RegisterAccumulator() {
            current.vector = _mm512_setzero_si512();
            current.count  = 0;
        }

        // input:
        // - value    - 16 x 32-bit values
        // - mask     - which items are active
        // - callback - fun(__m512 utf32, int count) called when at least 16 values got accumulated
        template <typename CALLBACK>
        void add(__m512i utf8, uint16_t valid, CALLBACK callback) {
            const auto     count    = __builtin_popcount(valid);
            const uint32_t new_mask = (uint32_t(1 << count) - 1) << current.count;

            __m512i tmp;

            tmp = _mm512_mask_compress_epi32(_mm512_setzero_si512(), valid, utf8);
            tmp = uint32_rotate_left(tmp, current.count);
            current.vector = _mm512_mask_mov_epi32(current.vector, (new_mask & 0xffff), tmp);

            if (count + current.count < 16) {
                // there are less than 16 items in register, nothing to do
                current.count += count;
                return;
            }

            // the whole vector is full
            callback(current.vector, 16);

            // keep the remining items from `utf8`
            const auto tail = 16 - current.count;
            current.vector = tmp;
            current.count  = count - tail;
        }

        template <typename CALLBACK>
        void flush(CALLBACK callback) {
            if (current.count)
                callback(current.vector, current.count);

            current.count = 0;
        }
    };
}

size_t avx512_utf8_to_utf32__version4(const char* str, size_t len, uint32_t* dwords) {
    const char* ptr = str;
    const char* end = ptr + len;

    uint32_t* output = dwords;

    if (len > 64) {

        // load 16 bytes: [abcdefghijklmnop]
        __m512i prev = _mm512_broadcast_i64x2(_mm_loadu_si128((const __m128i*)ptr));
        ptr += 16;

        RegisterAccumulator acc;

        auto convert_to_utf32 = [&output](__m512i utf8, int count) {
            // 3. Convert words into UCS-32
            const __m512i utf32 = avx512_utf8_to_utf32__aux__version1(utf8);

            // 4. Store them
            _mm512_storeu_si512((__m512i*)output, utf32);

            output += count;
        };

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

            acc.add(input, valid, convert_to_utf32);
            ptr += 16;
        }

        acc.flush(convert_to_utf32);
    }

    // TODO: process the tail

    return output - dwords;
}
