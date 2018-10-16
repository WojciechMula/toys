#include "sse_sadbw.h"

#include <immintrin.h>

uint32_t sse_sadbw_sumbytes(uint8_t* array, size_t size) {

    const __m128i zero = _mm_setzero_si128();
    __m128i accumulator = zero;

    for (size_t i=0; i < size; i += 16) {
        const __m128i v  = _mm_loadu_si128((__m128i*)(array + i));
        const __m128i t0 = _mm_sad_epu8(v, zero);
        
        accumulator = _mm_add_epi32(accumulator, t0);
    }

    return uint32_t(_mm_extract_epi32(accumulator, 0)) +
           uint32_t(_mm_extract_epi32(accumulator, 2));
}

uint32_t sse_sadbw_unrolled4_sumbytes(uint8_t* array, size_t size) {

    const __m128i zero = _mm_setzero_si128();
    __m128i accumulator = zero;

    for (size_t i=0; i < size; i += 16*4) {
        const __m128i v0 = _mm_loadu_si128((__m128i*)(array + i + 0*16));
        const __m128i v1 = _mm_loadu_si128((__m128i*)(array + i + 1*16));
        const __m128i v2 = _mm_loadu_si128((__m128i*)(array + i + 2*16));
        const __m128i v3 = _mm_loadu_si128((__m128i*)(array + i + 3*16));

        const __m128i t0 = _mm_sad_epu8(v0, zero);
        const __m128i t1 = _mm_sad_epu8(v1, zero);
        const __m128i t2 = _mm_sad_epu8(v2, zero);
        const __m128i t3 = _mm_sad_epu8(v3, zero);
        
        accumulator = _mm_add_epi32(accumulator, t0);
        accumulator = _mm_add_epi32(accumulator, t1);
        accumulator = _mm_add_epi32(accumulator, t2);
        accumulator = _mm_add_epi32(accumulator, t3);
    }

    return uint32_t(_mm_extract_epi32(accumulator, 0)) +
           uint32_t(_mm_extract_epi32(accumulator, 2));
}
