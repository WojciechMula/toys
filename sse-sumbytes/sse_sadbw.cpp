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
