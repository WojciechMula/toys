#include "sse.h"

#include <immintrin.h>

uint32_t sse_sumwords(uint16_t* array, size_t size) {

    __m128i accumulator = _mm_setzero_si128();

    for (size_t i=0; i < size; i += 8) {
        const __m128i v = _mm_loadu_si128((__m128i*)(array + i));
        
        const __m128i t0 = _mm_cvtepu16_epi32(v);
        const __m128i t1 = _mm_cvtepu16_epi32(_mm_bsrli_si128(v, 2*4));

        accumulator = _mm_add_epi32(accumulator, t0);
        accumulator = _mm_add_epi32(accumulator, t1);
    }

    return uint32_t(_mm_extract_epi32(accumulator, 0)) +
           uint32_t(_mm_extract_epi32(accumulator, 1)) +
           uint32_t(_mm_extract_epi32(accumulator, 2)) +
           uint32_t(_mm_extract_epi32(accumulator, 3));
}


uint32_t sse_sumwords_variant2(uint16_t* array, size_t size) {

    const __m128i loword_mask = _mm_set1_epi32(0x0000ffff);

    __m128i accumulator = _mm_setzero_si128();

    for (size_t i=0; i < size; i += 8) {
        const __m128i v = _mm_loadu_si128((__m128i*)(array + i));

        const __m128i lo = _mm_and_si128(v, loword_mask);
        const __m128i hi = _mm_srli_epi32(v, 16);
        
        accumulator = _mm_add_epi32(accumulator, lo);
        accumulator = _mm_add_epi32(accumulator, hi);
    }

    return uint32_t(_mm_extract_epi32(accumulator, 0)) +
           uint32_t(_mm_extract_epi32(accumulator, 1)) +
           uint32_t(_mm_extract_epi32(accumulator, 2)) +
           uint32_t(_mm_extract_epi32(accumulator, 3));
}
