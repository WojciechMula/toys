#include "avx2.h"

#include <immintrin.h>

int32_t avx2_sumsignedbytes(int8_t* array, size_t size) {

    __m256i accumulator = _mm256_setzero_si256();

    for (size_t i=0; i < size; i += 32) {
        const __m256i v = _mm256_loadu_si256((__m256i*)(array + i));

        const __m128i lo = _mm256_extracti128_si256(v, 0);
        const __m128i hi = _mm256_extracti128_si256(v, 1);

        const __m256i t0 = _mm256_cvtepi8_epi32(lo);
        const __m256i t1 = _mm256_cvtepi8_epi32(hi);
        const __m256i t2 = _mm256_cvtepi8_epi32(_mm_bsrli_si128(lo, 8));
        const __m256i t3 = _mm256_cvtepi8_epi32(_mm_bsrli_si128(hi, 8));

        accumulator = _mm256_add_epi32(accumulator, t0);
        accumulator = _mm256_add_epi32(accumulator, t1);
        accumulator = _mm256_add_epi32(accumulator, t2);
        accumulator = _mm256_add_epi32(accumulator, t3);
    }

    return int32_t(_mm256_extract_epi32(accumulator, 0)) +
           int32_t(_mm256_extract_epi32(accumulator, 1)) +
           int32_t(_mm256_extract_epi32(accumulator, 2)) +
           int32_t(_mm256_extract_epi32(accumulator, 3)) +
           int32_t(_mm256_extract_epi32(accumulator, 4)) +
           int32_t(_mm256_extract_epi32(accumulator, 5)) +
           int32_t(_mm256_extract_epi32(accumulator, 6)) +
           int32_t(_mm256_extract_epi32(accumulator, 7));
}


int32_t avx2_sumsignedbytes_variant2(int8_t* array, size_t size) {

    __m256i accumulator = _mm256_setzero_si256();

    for (size_t i=0; i < size; i += 32) {
        const __m256i v = _mm256_loadu_si256((__m256i*)(array + i));
        const __m256i v0 = _mm256_srai_epi32(v, 3*8);
        const __m256i v1 = _mm256_srai_epi32(_mm256_slli_epi32(v, 1*8), 3*8);
        const __m256i v2 = _mm256_srai_epi32(_mm256_slli_epi32(v, 2*8), 3*8);
        const __m256i v3 = _mm256_srai_epi32(_mm256_slli_epi32(v, 3*8), 3*8);
        
        accumulator = _mm256_add_epi32(accumulator, v0);
        accumulator = _mm256_add_epi32(accumulator, v1);
        accumulator = _mm256_add_epi32(accumulator, v2);
        accumulator = _mm256_add_epi32(accumulator, v3);
    }

    return int32_t(_mm256_extract_epi32(accumulator, 0)) +
           int32_t(_mm256_extract_epi32(accumulator, 1)) +
           int32_t(_mm256_extract_epi32(accumulator, 2)) +
           int32_t(_mm256_extract_epi32(accumulator, 3)) +
           int32_t(_mm256_extract_epi32(accumulator, 4)) +
           int32_t(_mm256_extract_epi32(accumulator, 5)) +
           int32_t(_mm256_extract_epi32(accumulator, 6)) +
           int32_t(_mm256_extract_epi32(accumulator, 7));
}
