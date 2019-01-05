#include <immintrin.h>
#include <cstdint>
#include <cassert>

char* remove_spaces__avx512vbmi(const char* src, char* dst, size_t n) {

    assert(n % 64 == 0);

    // values 0..63
    const __m512i no_gaps_indices = _mm512_setr_epi32(
        0x03020100, 0x07060504, 0x0b0a0908, 0x0f0e0d0c,
        0x13121110, 0x17161514, 0x1b1a1918, 0x1f1e1d1c,
        0x23222120, 0x27262524, 0x2b2a2928, 0x2f2e2d2c,
        0x33323130, 0x37363534, 0x3b3a3938, 0x3f3e3d3c
    );

    const __m512i ones   = _mm512_set1_epi8(1);
    const __m512i spaces = _mm512_set1_epi8(' ');

    size_t len;
    for (size_t i=0; i < n; i += 64) {
        
        const __m512i input  = _mm512_loadu_si512((const __m512i*)(src + i));
        __m512i output;

        uint64_t mask = _mm512_cmpeq_epi8_mask(input, spaces);
        if (mask) {
            len = 64 - __builtin_popcountll(mask);
            __m512i indices = no_gaps_indices;
            __m512i increment = ones;

            uint64_t first;
            uint64_t prev;

            first = (mask & -mask); // isolate the first bit set
            prev  = first;
            mask ^= first;          // reset it in the mask
            mask >>= 1;             // and shift by 1

            while (mask) {
                const uint64_t curr = (mask & -mask);
                mask ^= curr;
                mask >>= 1;
                
                if (prev == curr) {
                    // run continues
                    increment = _mm512_add_epi8(increment, ones);
                    prev = curr;
                } else {
                    // new run
                    indices = _mm512_mask_add_epi8(indices, ~(first - 1), indices, increment);

                    first = curr;
                    prev  = curr;
                    increment = ones;
                }
            }

            indices = _mm512_mask_add_epi8(indices, ~(first - 1), indices, increment);

            output = _mm512_permutexvar_epi8(indices, input);
        } else {
            output = input;
            len = 64;
        }

        _mm512_storeu_si512((__m512i*)(dst), output);
        dst += len;
    }

    return dst;
}

