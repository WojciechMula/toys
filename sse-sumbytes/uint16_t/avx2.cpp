#include "sse.h"

#include <immintrin.h>

uint32_t avx2_sumwords(uint16_t* array, size_t size) {

    __m256i accumulator = _mm256_setzero_si256();

    for (size_t i=0; i < size; i += 16) {
        const __m256i v = _mm256_loadu_si256((__m256i*)(array + i));
        
        const __m128i lo = _mm256_extracti128_si256(v, 0);
        const __m128i hi = _mm256_extracti128_si256(v, 1);

        const __m256i t0 = _mm256_cvtepu16_epi32(lo);
        const __m256i t1 = _mm256_cvtepu16_epi32(hi);

        accumulator = _mm256_add_epi32(accumulator, t0);
        accumulator = _mm256_add_epi32(accumulator, t1);
    }

    return uint32_t(_mm256_extract_epi32(accumulator, 0)) +
           uint32_t(_mm256_extract_epi32(accumulator, 1)) +
           uint32_t(_mm256_extract_epi32(accumulator, 2)) +
           uint32_t(_mm256_extract_epi32(accumulator, 3)) +
           uint32_t(_mm256_extract_epi32(accumulator, 4)) +
           uint32_t(_mm256_extract_epi32(accumulator, 5)) +
           uint32_t(_mm256_extract_epi32(accumulator, 6)) +
           uint32_t(_mm256_extract_epi32(accumulator, 7));
}


uint32_t avx2_sumwords_variant2(uint16_t* array, size_t size) {

    const __m256i loword_mask = _mm256_set1_epi32(0x0000ffff);

    __m256i accumulator = _mm256_setzero_si256();

    for (size_t i=0; i < size; i += 16) {
        const __m256i v = _mm256_loadu_si256((__m256i*)(array + i));

        const __m256i lo = _mm256_and_si256(v, loword_mask);
        const __m256i hi = _mm256_srli_epi32(v, 16);
        
        accumulator = _mm256_add_epi32(accumulator, lo);
        accumulator = _mm256_add_epi32(accumulator, hi);
    }

    return uint32_t(_mm256_extract_epi32(accumulator, 0)) +
           uint32_t(_mm256_extract_epi32(accumulator, 1)) +
           uint32_t(_mm256_extract_epi32(accumulator, 2)) +
           uint32_t(_mm256_extract_epi32(accumulator, 3)) +
           uint32_t(_mm256_extract_epi32(accumulator, 4)) +
           uint32_t(_mm256_extract_epi32(accumulator, 5)) +
           uint32_t(_mm256_extract_epi32(accumulator, 6)) +
           uint32_t(_mm256_extract_epi32(accumulator, 7));
}
