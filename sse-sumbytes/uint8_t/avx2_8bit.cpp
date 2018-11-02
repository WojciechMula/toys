#include "avx2_8bit.h"

#include <immintrin.h>

uint32_t avx2_8bit_sumbytes(uint8_t* array, size_t size) {

    __m256i accumulator = _mm256_setzero_si256();

    for (size_t i=0; i < size; i += 256) {

        __m256i accu_8bit_lo = _mm256_setzero_si256();
        __m256i accu_8bit_hi = _mm256_set1_epi8(8);

        for (size_t j=0; j < 256; j += 32) {
            const __m256i v = _mm256_loadu_si256((__m256i*)(array + i + j));

            const __m256i t0 = _mm256_add_epi8(v, accu_8bit_lo);
            const __m256i t1 = _mm256_adds_epu8(v, accu_8bit_lo);

            const __m256i not_carry = _mm256_cmpeq_epi8(t0, t1);

            accu_8bit_lo = t0;
            accu_8bit_hi = _mm256_add_epi8(accu_8bit_hi, not_carry);
        }
 
        const __m256i sum_lo = _mm256_sad_epu8(accu_8bit_lo, _mm256_setzero_si256());
        const __m256i sum_hi = _mm256_slli_epi32(_mm256_sad_epu8(accu_8bit_hi, _mm256_setzero_si256()), 8);

        accumulator = _mm256_add_epi32(accumulator, sum_lo);
        accumulator = _mm256_add_epi32(accumulator, sum_hi);
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


