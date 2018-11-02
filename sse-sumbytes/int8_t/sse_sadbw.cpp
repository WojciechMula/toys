#include "sse_sadbw.h"

#include <immintrin.h>

int32_t sse_sadbw_sumsignedbytes(int8_t* array, size_t size) {

    const __m128i zero = _mm_setzero_si128();
    __m128i positive = zero;
    __m128i negative = zero;

    for (size_t i=0; i < size; i += 16) {
        const __m128i v  = _mm_loadu_si128((__m128i*)(array + i));
        const __m128i m  = _mm_cmplt_epi8(v, zero);
        const __m128i va = _mm_abs_epi8(v);

        // sum just positive numbers
        const __m128i t0 = _mm_sad_epu8(_mm_andnot_si128(m, v), zero);

        // sum just negative numbers
        const __m128i t1 = _mm_sad_epu8(_mm_and_si128(m, va), zero);
        
        positive = _mm_add_epi32(positive, t0);
        negative = _mm_sub_epi32(negative, t1);
    }

    const __m128i accumulator = _mm_add_epi32(positive, negative);

    return int32_t(_mm_extract_epi32(accumulator, 0)) +
           int32_t(_mm_extract_epi32(accumulator, 2));
}

int32_t sse_sadbw_unrolled4_sumsignedbytes(int8_t* array, size_t size) {

    const __m128i zero = _mm_setzero_si128();
    __m128i positive = zero;
    __m128i negative = zero;

    for (size_t i=0; i < size; i += 16*4) {
        const __m128i v0 = _mm_loadu_si128((__m128i*)(array + i + 0*16));
        const __m128i v1 = _mm_loadu_si128((__m128i*)(array + i + 1*16));
        const __m128i v2 = _mm_loadu_si128((__m128i*)(array + i + 2*16));
        const __m128i v3 = _mm_loadu_si128((__m128i*)(array + i + 3*16));

        {
            const __m128i v   = v0;
            const __m128i m   = _mm_cmplt_epi8(v, zero);
            const __m128i t0  = _mm_sad_epu8(_mm_andnot_si128(m, v), zero);
            const __m128i va = _mm_abs_epi8(v);
            const __m128i t1 = _mm_sad_epu8(_mm_and_si128(m, va), zero);
            positive = _mm_add_epi32(positive, t0);
            negative = _mm_sub_epi32(negative, t1);
        }

        {
            const __m128i v   = v1;
            const __m128i m   = _mm_cmplt_epi8(v, zero);
            const __m128i t0  = _mm_sad_epu8(_mm_andnot_si128(m, v), zero);
            const __m128i va = _mm_abs_epi8(v);
            const __m128i t1 = _mm_sad_epu8(_mm_and_si128(m, va), zero);
            positive = _mm_add_epi32(positive, t0);
            negative = _mm_sub_epi32(negative, t1);
        }

        {
            const __m128i v   = v2;
            const __m128i m   = _mm_cmplt_epi8(v, zero);
            const __m128i t0  = _mm_sad_epu8(_mm_andnot_si128(m, v), zero);
            const __m128i va = _mm_abs_epi8(v);
            const __m128i t1 = _mm_sad_epu8(_mm_and_si128(m, va), zero);
            positive = _mm_add_epi32(positive, t0);
            negative = _mm_sub_epi32(negative, t1);
        }

        {
            const __m128i v   = v3;
            const __m128i m   = _mm_cmplt_epi8(v, zero);
            const __m128i t0  = _mm_sad_epu8(_mm_andnot_si128(m, v), zero);
            const __m128i va = _mm_abs_epi8(v);
            const __m128i t1 = _mm_sad_epu8(_mm_and_si128(m, va), zero);
            positive = _mm_add_epi32(positive, t0);
            negative = _mm_sub_epi32(negative, t1);
        }
    }

    const __m128i accumulator = _mm_add_epi32(positive, negative);

    return int32_t(_mm_extract_epi32(accumulator, 0)) +
           int32_t(_mm_extract_epi32(accumulator, 2));
}
