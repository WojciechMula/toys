#include "avx2_sadbw.h"

#include <immintrin.h>

uint32_t avx2_sadbw_sumbytes(uint8_t* array, size_t size) {

    const __m256i zero = _mm256_setzero_si256();
    __m256i accumulator = zero;

    for (size_t i=0; i < size; i += 32) {
        const __m256i v  = _mm256_loadu_si256((__m256i*)(array + i));
        const __m256i t0 = _mm256_sad_epu8(v, zero);
        
        accumulator = _mm256_add_epi32(accumulator, t0);
    }

    return uint32_t(_mm256_extract_epi32(accumulator, 0)) +
           uint32_t(_mm256_extract_epi32(accumulator, 2)) +
           uint32_t(_mm256_extract_epi32(accumulator, 4)) +
           uint32_t(_mm256_extract_epi32(accumulator, 6));
}

uint32_t avx2_sadbw_unrolled4_sumbytes(uint8_t* array, size_t size) {

    const __m256i zero = _mm256_setzero_si256();
    __m256i accumulator = zero;

    for (size_t i=0; i < size; i += 32*4) {
        const __m256i v0 = _mm256_loadu_si256((__m256i*)(array + i + 0*32));
        const __m256i v1 = _mm256_loadu_si256((__m256i*)(array + i + 1*32));
        const __m256i v2 = _mm256_loadu_si256((__m256i*)(array + i + 2*32));
        const __m256i v3 = _mm256_loadu_si256((__m256i*)(array + i + 3*32));

        const __m256i t0 = _mm256_sad_epu8(v0, zero);
        const __m256i t1 = _mm256_sad_epu8(v1, zero);
        const __m256i t2 = _mm256_sad_epu8(v2, zero);
        const __m256i t3 = _mm256_sad_epu8(v3, zero);
        
        accumulator = _mm256_add_epi32(accumulator, t0);
        accumulator = _mm256_add_epi32(accumulator, t1);
        accumulator = _mm256_add_epi32(accumulator, t2);
        accumulator = _mm256_add_epi32(accumulator, t3);
    }

    return uint32_t(_mm256_extract_epi32(accumulator, 0)) +
           uint32_t(_mm256_extract_epi32(accumulator, 2)) +
           uint32_t(_mm256_extract_epi32(accumulator, 4)) +
           uint32_t(_mm256_extract_epi32(accumulator, 6));
}
