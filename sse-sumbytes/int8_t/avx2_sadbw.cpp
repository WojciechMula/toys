#include "avx2_sadbw.h"

#include <immintrin.h>

#define _mm256_cmplt_epi8(a, b) _mm256_cmpgt_epi8(b, a)

int32_t avx2_sadbw_sumsignedbytes(int8_t* array, size_t size) {

    const __m256i zero = _mm256_setzero_si256();
    __m256i positive = zero;
    __m256i negative = zero;

    for (size_t i=0; i < size; i += 32) {
        const __m256i v  = _mm256_loadu_si256((__m256i*)(array + i));
        const __m256i m  = _mm256_cmplt_epi8(v, zero);
        const __m256i va = _mm256_abs_epi8(v);

        // sum just positive numbers
        const __m256i t0 = _mm256_sad_epu8(_mm256_andnot_si256(m, v), zero);

        // sum just negative numbers
        const __m256i t1 = _mm256_sad_epu8(_mm256_and_si256(m, va), zero);
        
        positive = _mm256_add_epi32(positive, t0);
        negative = _mm256_sub_epi32(negative, t1);
    }

    const __m256i accumulator = _mm256_add_epi32(positive, negative);

    return int32_t(_mm256_extract_epi32(accumulator, 0)) +
           int32_t(_mm256_extract_epi32(accumulator, 2)) +
           int32_t(_mm256_extract_epi32(accumulator, 4)) +
           int32_t(_mm256_extract_epi32(accumulator, 6));
}

int32_t avx2_sadbw_unrolled4_sumsignedbytes(int8_t* array, size_t size) {

    const __m256i zero = _mm256_setzero_si256();
    __m256i positive = zero;
    __m256i negative = zero;

    for (size_t i=0; i < size; i += 32*4) {
        const __m256i v0 = _mm256_loadu_si256((__m256i*)(array + i + 0*32));
        const __m256i v1 = _mm256_loadu_si256((__m256i*)(array + i + 1*32));
        const __m256i v2 = _mm256_loadu_si256((__m256i*)(array + i + 2*32));
        const __m256i v3 = _mm256_loadu_si256((__m256i*)(array + i + 3*32));

        {
            const __m256i v   = v0;
            const __m256i m   = _mm256_cmplt_epi8(v, zero);
            const __m256i t0  = _mm256_sad_epu8(_mm256_andnot_si256(m, v), zero);
            const __m256i va = _mm256_abs_epi8(v);
            const __m256i t1 = _mm256_sad_epu8(_mm256_and_si256(m, va), zero);
            positive = _mm256_add_epi32(positive, t0);
            negative = _mm256_sub_epi32(negative, t1);
        }

        {
            const __m256i v   = v1;
            const __m256i m   = _mm256_cmplt_epi8(v, zero);
            const __m256i t0  = _mm256_sad_epu8(_mm256_andnot_si256(m, v), zero);
            const __m256i va = _mm256_abs_epi8(v);
            const __m256i t1 = _mm256_sad_epu8(_mm256_and_si256(m, va), zero);
            positive = _mm256_add_epi32(positive, t0);
            negative = _mm256_sub_epi32(negative, t1);
        }

        {
            const __m256i v   = v2;
            const __m256i m   = _mm256_cmplt_epi8(v, zero);
            const __m256i t0  = _mm256_sad_epu8(_mm256_andnot_si256(m, v), zero);
            const __m256i va = _mm256_abs_epi8(v);
            const __m256i t1 = _mm256_sad_epu8(_mm256_and_si256(m, va), zero);
            positive = _mm256_add_epi32(positive, t0);
            negative = _mm256_sub_epi32(negative, t1);
        }

        {
            const __m256i v   = v3;
            const __m256i m   = _mm256_cmplt_epi8(v, zero);
            const __m256i t0  = _mm256_sad_epu8(_mm256_andnot_si256(m, v), zero);
            const __m256i va = _mm256_abs_epi8(v);
            const __m256i t1 = _mm256_sad_epu8(_mm256_and_si256(m, va), zero);
            positive = _mm256_add_epi32(positive, t0);
            negative = _mm256_sub_epi32(negative, t1);
        }
    }

    const __m256i accumulator = _mm256_add_epi32(positive, negative);

    return int32_t(_mm256_extract_epi32(accumulator, 0)) +
           int32_t(_mm256_extract_epi32(accumulator, 2)) +
           int32_t(_mm256_extract_epi32(accumulator, 4)) +
           int32_t(_mm256_extract_epi32(accumulator, 6));
}
