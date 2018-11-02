#include "sse_sadbw.h"

#include <immintrin.h>

uint32_t sse_sadbw_sumwords(uint16_t* array, size_t size) {

    const __m128i zero = _mm_setzero_si128();
    const __m128i lo_byte = _mm_set1_epi16(0x00ff);
    const __m128i hi_byte = _mm_set1_epi16(-256); // 0xff00

    __m128i accumulator_lo = zero;
    __m128i accumulator_hi = zero;

    for (size_t i=0; i < size; i += 8) {
        const __m128i v  = _mm_loadu_si128((__m128i*)(array + i));
        const __m128i lo = _mm_and_si128(v, lo_byte);
        const __m128i hi = _mm_and_si128(v, hi_byte);
        const __m128i sum_lo = _mm_sad_epu8(lo, zero);
        const __m128i sum_hi = _mm_sad_epu8(hi, zero);
        
        accumulator_lo = _mm_add_epi32(accumulator_lo, sum_lo);
        accumulator_hi = _mm_add_epi32(accumulator_hi, sum_hi);
    }

    accumulator_hi = _mm_slli_epi32(accumulator_hi, 8);

    const __m128i accumulator = _mm_add_epi32(accumulator_lo, accumulator_hi);
    

    return uint32_t(_mm_extract_epi32(accumulator, 0)) +
           uint32_t(_mm_extract_epi32(accumulator, 2));
}

uint32_t sse_sadbw_unrolled4_sumwords(uint16_t* array, size_t size) {

    const __m128i zero = _mm_setzero_si128();

    const __m128i lo_byte = _mm_set1_epi16(0x00ff);
    const __m128i hi_byte = _mm_set1_epi16(-256); // 0xff00

    __m128i accumulator_lo = zero;
    __m128i accumulator_hi = zero;

    for (size_t i=0; i < size; i += 8*4) {
        const __m128i v0 = _mm_loadu_si128((__m128i*)(array + i + 0*8));
        const __m128i v1 = _mm_loadu_si128((__m128i*)(array + i + 1*8));
        const __m128i v2 = _mm_loadu_si128((__m128i*)(array + i + 2*8));
        const __m128i v3 = _mm_loadu_si128((__m128i*)(array + i + 3*8));

        const __m128i sum_lo0 = _mm_sad_epu8(_mm_and_si128(v0, lo_byte), zero);
        const __m128i sum_lo1 = _mm_sad_epu8(_mm_and_si128(v1, lo_byte), zero);
        const __m128i sum_lo2 = _mm_sad_epu8(_mm_and_si128(v2, lo_byte), zero);
        const __m128i sum_lo3 = _mm_sad_epu8(_mm_and_si128(v3, lo_byte), zero);

        const __m128i sum_hi0 = _mm_sad_epu8(_mm_and_si128(v0, hi_byte), zero);
        const __m128i sum_hi1 = _mm_sad_epu8(_mm_and_si128(v1, hi_byte), zero);
        const __m128i sum_hi2 = _mm_sad_epu8(_mm_and_si128(v2, hi_byte), zero);
        const __m128i sum_hi3 = _mm_sad_epu8(_mm_and_si128(v3, hi_byte), zero);
        
        accumulator_lo = _mm_add_epi32(accumulator_lo, sum_lo0);
        accumulator_lo = _mm_add_epi32(accumulator_lo, sum_lo1);
        accumulator_lo = _mm_add_epi32(accumulator_lo, sum_lo2);
        accumulator_lo = _mm_add_epi32(accumulator_lo, sum_lo3);
        
        accumulator_hi = _mm_add_epi32(accumulator_hi, sum_hi0);
        accumulator_hi = _mm_add_epi32(accumulator_hi, sum_hi1);
        accumulator_hi = _mm_add_epi32(accumulator_hi, sum_hi2);
        accumulator_hi = _mm_add_epi32(accumulator_hi, sum_hi3);
    }

    accumulator_hi = _mm_slli_epi32(accumulator_hi, 8);

    const __m128i accumulator = _mm_add_epi32(accumulator_lo, accumulator_hi);

    return uint32_t(_mm_extract_epi32(accumulator, 0)) +
           uint32_t(_mm_extract_epi32(accumulator, 2));
}
