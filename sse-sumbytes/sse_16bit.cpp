#include "sse.h"

#include <immintrin.h>

uint32_t sse_16bit_sumbytes(uint8_t* array, size_t size) {

    __m128i accumulator = _mm_setzero_si128();

    for (size_t i=0; i < size; i += 256) {

        __m128i accu_16bit = _mm_setzero_si128();

        for (size_t j=0; j < 256; j += 16) {
            const __m128i v = _mm_loadu_si128((__m128i*)(array + i + j));

            const __m128i v0_7   = v;
            const __m128i v8_15  = _mm_bsrli_si128(v, 8);

            const __m128i t0 = _mm_cvtepu8_epi16(v0_7);
            const __m128i t1 = _mm_cvtepu8_epi16(v8_15);

            accu_16bit = _mm_add_epi16(accu_16bit, t0);
            accu_16bit = _mm_add_epi16(accu_16bit, t1);
        }
        
        const __m128i t0 = _mm_cvtepu16_epi32(accu_16bit);
        const __m128i t1 = _mm_cvtepu16_epi32(_mm_bsrli_si128(accu_16bit, 8));

        accumulator = _mm_add_epi32(accumulator, t0);
        accumulator = _mm_add_epi32(accumulator, t1);
    }

    return uint32_t(_mm_extract_epi32(accumulator, 0)) +
           uint32_t(_mm_extract_epi32(accumulator, 1)) +
           uint32_t(_mm_extract_epi32(accumulator, 2)) +
           uint32_t(_mm_extract_epi32(accumulator, 3));
}

