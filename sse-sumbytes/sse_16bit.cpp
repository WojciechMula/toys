#include "sse.h"

#include <immintrin.h>

uint32_t sse_16bit_sumbytes(uint8_t* array, size_t size) {

    __m128i accumulator = _mm_setzero_si128();

#define SIZE (8 * 256)

    for (size_t i=0; i < size; i += SIZE) {

        __m128i accu_16bit = _mm_setzero_si128();

        for (size_t j=0; j < SIZE; j += 16) {
            const __m128i v = _mm_loadu_si128((__m128i*)(array + i + j));

            const __m128i v0_7   = v;
            const __m128i v8_15  = _mm_bsrli_si128(v, 8);

            const __m128i t0 = _mm_cvtepu8_epi16(v0_7);
            const __m128i t1 = _mm_cvtepu8_epi16(v8_15);

            accu_16bit = _mm_add_epi16(accu_16bit, t0);
            accu_16bit = _mm_add_epi16(accu_16bit, t1);
        }

        const __m128i t0 = _mm_cvtepu16_epi32(accu_16bit);
        const __m128i t1 = _mm_cvtepu16_epi32(_mm_bsrli_si128(accu_16bit, 8));

        accumulator = _mm_add_epi32(accumulator, t0);
        accumulator = _mm_add_epi32(accumulator, t1);
    }
#undef SIZE

    return uint32_t(_mm_extract_epi32(accumulator, 0)) +
           uint32_t(_mm_extract_epi32(accumulator, 1)) +
           uint32_t(_mm_extract_epi32(accumulator, 2)) +
           uint32_t(_mm_extract_epi32(accumulator, 3));
}

uint32_t sse_16bit_sumbytes_variant2(uint8_t* array, size_t size) {

    const __m128i mask_lobytes = _mm_set1_epi16(0x00ff);

    __m128i accumulator = _mm_setzero_si128();

#define SIZE (8 * 256)
    for (size_t i=0; i < size; i += SIZE) {

        __m128i accu_16bit = _mm_setzero_si128();

        for (size_t j=0; j < SIZE; j += 16) {
            const __m128i v = _mm_loadu_si128((__m128i*)(array + i + j));

            const __m128i t0 = _mm_and_si128(v, mask_lobytes);
            const __m128i t1 = _mm_srli_epi16(v, 8);

            accu_16bit = _mm_add_epi16(accu_16bit, t0);
            accu_16bit = _mm_add_epi16(accu_16bit, t1);
        }
        
        const __m128i t0 = _mm_and_si128(accu_16bit, _mm_set1_epi32(0x0000ffff));
        const __m128i t1 = _mm_srli_epi32(accu_16bit, 16);

        accumulator = _mm_add_epi32(accumulator, t0);
        accumulator = _mm_add_epi32(accumulator, t1);
    }
#undef SIZE

    return uint32_t(_mm_extract_epi32(accumulator, 0)) +
           uint32_t(_mm_extract_epi32(accumulator, 1)) +
           uint32_t(_mm_extract_epi32(accumulator, 2)) +
           uint32_t(_mm_extract_epi32(accumulator, 3));
}


uint32_t sse_16bit_sumbytes_variant2_unrolled4(uint8_t* array, size_t size) {

    const __m128i mask_lobytes = _mm_set1_epi16(0x00ff);

    __m128i accumulator = _mm_setzero_si128();

    for (size_t i=0; i < size; i += 4 * 16) {

        __m128i accu_16bit = _mm_setzero_si128();

        {
            const __m128i v0 = _mm_loadu_si128((__m128i*)(array + i + 0*16));
            const __m128i v1 = _mm_loadu_si128((__m128i*)(array + i + 1*16));
            const __m128i v2 = _mm_loadu_si128((__m128i*)(array + i + 2*16));
            const __m128i v3 = _mm_loadu_si128((__m128i*)(array + i + 3*16));

            const __m128i l0 = _mm_and_si128(v0, mask_lobytes);
            const __m128i h0 = _mm_srli_epi16(v0, 8);
            const __m128i l1 = _mm_and_si128(v1, mask_lobytes);
            const __m128i h1 = _mm_srli_epi16(v1, 8);
            const __m128i l2 = _mm_and_si128(v2, mask_lobytes);
            const __m128i h2 = _mm_srli_epi16(v2, 8);
            const __m128i l3 = _mm_and_si128(v3, mask_lobytes);
            const __m128i h3 = _mm_srli_epi16(v3, 8);

            accu_16bit = _mm_add_epi16(accu_16bit, l0);
            accu_16bit = _mm_add_epi16(accu_16bit, h0);
            accu_16bit = _mm_add_epi16(accu_16bit, l1);
            accu_16bit = _mm_add_epi16(accu_16bit, h1);
            accu_16bit = _mm_add_epi16(accu_16bit, l2);
            accu_16bit = _mm_add_epi16(accu_16bit, h2);
            accu_16bit = _mm_add_epi16(accu_16bit, l3);
            accu_16bit = _mm_add_epi16(accu_16bit, h3);
        }
        
        const __m128i t0 = _mm_and_si128(accu_16bit, _mm_set1_epi32(0x0000ffff));
        const __m128i t1 = _mm_srli_epi32(accu_16bit, 16);

        accumulator = _mm_add_epi32(accumulator, t0);
        accumulator = _mm_add_epi32(accumulator, t1);
    }

    return uint32_t(_mm_extract_epi32(accumulator, 0)) +
           uint32_t(_mm_extract_epi32(accumulator, 1)) +
           uint32_t(_mm_extract_epi32(accumulator, 2)) +
           uint32_t(_mm_extract_epi32(accumulator, 3));
}
