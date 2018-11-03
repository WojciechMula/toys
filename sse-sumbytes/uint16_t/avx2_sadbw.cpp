#include "avx2_sadbw.h"

#include <immintrin.h>

uint32_t avx2_sadbw_sumwords(uint16_t* array, size_t size) {

    const __m256i zero = _mm256_setzero_si256();
    const __m256i lo_byte = _mm256_set1_epi16(0x00ff);
    const __m256i hi_byte = _mm256_set1_epi16(-256); // 0xff00

    __m256i accumulator_lo = zero;
    __m256i accumulator_hi = zero;

    for (size_t i=0; i < size; i += 16) {
        const __m256i v  = _mm256_loadu_si256((__m256i*)(array + i));
        const __m256i lo = _mm256_and_si256(v, lo_byte);
        const __m256i hi = _mm256_and_si256(v, hi_byte);
        const __m256i sum_lo = _mm256_sad_epu8(lo, zero);
        const __m256i sum_hi = _mm256_sad_epu8(hi, zero);
        
        accumulator_lo = _mm256_add_epi32(accumulator_lo, sum_lo);
        accumulator_hi = _mm256_add_epi32(accumulator_hi, sum_hi);
    }

    accumulator_hi = _mm256_slli_epi32(accumulator_hi, 8);

    const __m256i accumulator = _mm256_add_epi32(accumulator_lo, accumulator_hi);
    
    return uint32_t(_mm256_extract_epi32(accumulator, 0)) +
           uint32_t(_mm256_extract_epi32(accumulator, 2)) +
           uint32_t(_mm256_extract_epi32(accumulator, 4)) +
           uint32_t(_mm256_extract_epi32(accumulator, 6));
}

uint32_t avx2_sadbw_sumwords_variant2(uint16_t* array, size_t size) {

    const __m256i zero = _mm256_setzero_si256();
    const __m256i lo_byte = _mm256_set1_epi16(0x00ff);
    const __m256i hi_byte = _mm256_set1_epi16(-256); // 0xff00

    __m256i accumulator_lo = zero;
    __m256i accumulator_hi = zero;

    for (size_t i=0; i < size; i += 32) {
        const __m256i v0 = _mm256_loadu_si256((__m256i*)(array + i + 0*16));
        const __m256i v1 = _mm256_loadu_si256((__m256i*)(array + i + 1*16));

        const __m256i v0_lo = _mm256_and_si256(v0, lo_byte);
        const __m256i v1_lo = _mm256_slli_epi16(v1, 8);
        const __m256i lo    = _mm256_or_si256(v0_lo, v1_lo);

        const __m256i v0_hi = _mm256_and_si256(v0, hi_byte);
        const __m256i v1_hi = _mm256_srli_epi16(v1, 8);
        const __m256i hi    = _mm256_or_si256(v0_hi, v1_hi);

        const __m256i sum_lo = _mm256_sad_epu8(lo, zero);
        const __m256i sum_hi = _mm256_sad_epu8(hi, zero);
        
        accumulator_lo = _mm256_add_epi32(accumulator_lo, sum_lo);
        accumulator_hi = _mm256_add_epi32(accumulator_hi, sum_hi);
    }

    accumulator_hi = _mm256_slli_epi32(accumulator_hi, 8);

    const __m256i accumulator = _mm256_add_epi32(accumulator_lo, accumulator_hi);
    
    return uint32_t(_mm256_extract_epi32(accumulator, 0)) +
           uint32_t(_mm256_extract_epi32(accumulator, 2)) +
           uint32_t(_mm256_extract_epi32(accumulator, 4)) +
           uint32_t(_mm256_extract_epi32(accumulator, 6));
}

uint32_t avx2_sadbw_unrolled4_sumwords(uint16_t* array, size_t size) {

    const __m256i zero = _mm256_setzero_si256();

    const __m256i lo_byte = _mm256_set1_epi16(0x00ff);
    const __m256i hi_byte = _mm256_set1_epi16(-256); // 0xff00

    __m256i accumulator_lo = zero;
    __m256i accumulator_hi = zero;

    for (size_t i=0; i < size; i += 16*4) {
        const __m256i v0 = _mm256_loadu_si256((__m256i*)(array + i + 0*16));
        const __m256i v1 = _mm256_loadu_si256((__m256i*)(array + i + 1*16));
        const __m256i v2 = _mm256_loadu_si256((__m256i*)(array + i + 2*16));
        const __m256i v3 = _mm256_loadu_si256((__m256i*)(array + i + 3*16));

        const __m256i sum_lo0 = _mm256_sad_epu8(_mm256_and_si256(v0, lo_byte), zero);
        const __m256i sum_lo1 = _mm256_sad_epu8(_mm256_and_si256(v1, lo_byte), zero);
        const __m256i sum_lo2 = _mm256_sad_epu8(_mm256_and_si256(v2, lo_byte), zero);
        const __m256i sum_lo3 = _mm256_sad_epu8(_mm256_and_si256(v3, lo_byte), zero);

        const __m256i sum_hi0 = _mm256_sad_epu8(_mm256_and_si256(v0, hi_byte), zero);
        const __m256i sum_hi1 = _mm256_sad_epu8(_mm256_and_si256(v1, hi_byte), zero);
        const __m256i sum_hi2 = _mm256_sad_epu8(_mm256_and_si256(v2, hi_byte), zero);
        const __m256i sum_hi3 = _mm256_sad_epu8(_mm256_and_si256(v3, hi_byte), zero);
        
        accumulator_lo = _mm256_add_epi32(accumulator_lo, sum_lo0);
        accumulator_lo = _mm256_add_epi32(accumulator_lo, sum_lo1);
        accumulator_lo = _mm256_add_epi32(accumulator_lo, sum_lo2);
        accumulator_lo = _mm256_add_epi32(accumulator_lo, sum_lo3);
        
        accumulator_hi = _mm256_add_epi32(accumulator_hi, sum_hi0);
        accumulator_hi = _mm256_add_epi32(accumulator_hi, sum_hi1);
        accumulator_hi = _mm256_add_epi32(accumulator_hi, sum_hi2);
        accumulator_hi = _mm256_add_epi32(accumulator_hi, sum_hi3);
    }

    accumulator_hi = _mm256_slli_epi32(accumulator_hi, 8);

    const __m256i accumulator = _mm256_add_epi32(accumulator_lo, accumulator_hi);

    return uint32_t(_mm256_extract_epi32(accumulator, 0)) +
           uint32_t(_mm256_extract_epi32(accumulator, 2)) +
           uint32_t(_mm256_extract_epi32(accumulator, 4)) +
           uint32_t(_mm256_extract_epi32(accumulator, 6));
}
