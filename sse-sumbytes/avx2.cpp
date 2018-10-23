#include "sse.h"

#include <immintrin.h>

uint32_t avx2_sumbytes_variant2(uint8_t* array, size_t size) {

    const __m256i lobyte_mask = _mm256_set1_epi32(0x000000ff);

    __m256i accumulator = _mm256_setzero_si256();

    for (size_t i=0; i < size; i += 32) {
        const __m256i v = _mm256_loadu_si256((__m256i*)(array + i));
        const __m256i v0 = v;
        const __m256i v1 = _mm256_srli_epi32(v, 1*8);
        const __m256i v2 = _mm256_srli_epi32(v, 2*8);
        const __m256i v3 = _mm256_srli_epi32(v, 3*8);
        
        const __m256i t0 = _mm256_and_si256(lobyte_mask, v0);
        const __m256i t1 = _mm256_and_si256(lobyte_mask, v1);
        const __m256i t2 = _mm256_and_si256(lobyte_mask, v2);
        const __m256i t3 = v3;

        accumulator = _mm256_add_epi32(accumulator, t0);
        accumulator = _mm256_add_epi32(accumulator, t1);
        accumulator = _mm256_add_epi32(accumulator, t2);
        accumulator = _mm256_add_epi32(accumulator, t3);
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
