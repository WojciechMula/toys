#include "sse.h"

#include <immintrin.h>

uint32_t sse_8bit_sumbytes(uint8_t* array, size_t size) {

    __m128i accumulator = _mm_setzero_si128();

    for (size_t i=0; i < size; i += 256) {

        __m128i accu_8bit_lo = _mm_setzero_si128();
        __m128i accu_8bit_hi = _mm_set1_epi8(16);

        for (size_t j=0; j < 256; j += 16) {
            const __m128i v = _mm_loadu_si128((__m128i*)(array + i + j));

            const __m128i t0 = _mm_add_epi8(v, accu_8bit_lo);
            const __m128i t1 = _mm_adds_epu8(v, accu_8bit_lo);

            const __m128i not_carry = _mm_cmpeq_epi8(t0, t1);

            accu_8bit_lo = t0;
            accu_8bit_hi = _mm_add_epi8(accu_8bit_hi, not_carry);
        }
 
        const __m128i t0 = _mm_unpacklo_epi8(accu_8bit_lo, accu_8bit_hi);
        const __m128i t1 = _mm_unpackhi_epi8(accu_8bit_lo, accu_8bit_hi);

        accumulator = _mm_add_epi32(accumulator, _mm_cvtepu16_epi32(t0));
        accumulator = _mm_add_epi32(accumulator, _mm_cvtepu16_epi32(t1));
        accumulator = _mm_add_epi32(accumulator, _mm_cvtepu16_epi32(_mm_bsrli_si128(t0, 8)));
        accumulator = _mm_add_epi32(accumulator, _mm_cvtepu16_epi32(_mm_bsrli_si128(t1, 8)));
    }

    return uint32_t(_mm_extract_epi32(accumulator, 0)) +
           uint32_t(_mm_extract_epi32(accumulator, 1)) +
           uint32_t(_mm_extract_epi32(accumulator, 2)) +
           uint32_t(_mm_extract_epi32(accumulator, 3));
}


