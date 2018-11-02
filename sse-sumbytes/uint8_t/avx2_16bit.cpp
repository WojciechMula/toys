#include "avx2_16bit.h"

#include <immintrin.h>

uint32_t avx2_16bit_sumbytes_variant2(uint8_t* array, size_t size) {

    const __m256i mask_lobytes = _mm256_set1_epi16(0x00ff);

    __m256i accumulator = _mm256_setzero_si256();

#define SIZE (8 * 256)
    for (size_t i=0; i < size; i += SIZE) {

        __m256i accu_16bit = _mm256_setzero_si256();

        for (size_t j=0; j < SIZE; j += 32) {
            const __m256i v = _mm256_loadu_si256((__m256i*)(array + i + j));

            const __m256i t0 = _mm256_and_si256(v, mask_lobytes);
            const __m256i t1 = _mm256_srli_epi16(v, 8);

            accu_16bit = _mm256_add_epi16(accu_16bit, t0);
            accu_16bit = _mm256_add_epi16(accu_16bit, t1);
        }
        
        const __m256i t0 = _mm256_and_si256(accu_16bit, _mm256_set1_epi32(0x0000ffff));
        const __m256i t1 = _mm256_srli_epi32(accu_16bit, 16);

        accumulator = _mm256_add_epi32(accumulator, t0);
        accumulator = _mm256_add_epi32(accumulator, t1);
    }
#undef SIZE

    return uint32_t(_mm256_extract_epi32(accumulator, 0)) +
           uint32_t(_mm256_extract_epi32(accumulator, 1)) +
           uint32_t(_mm256_extract_epi32(accumulator, 2)) +
           uint32_t(_mm256_extract_epi32(accumulator, 3)) +
           uint32_t(_mm256_extract_epi32(accumulator, 4)) +
           uint32_t(_mm256_extract_epi32(accumulator, 5)) +
           uint32_t(_mm256_extract_epi32(accumulator, 6)) +
           uint32_t(_mm256_extract_epi32(accumulator, 7));
}


uint32_t avx2_16bit_sumbytes_variant2_unrolled4(uint8_t* array, size_t size) {

    const __m256i mask_lobytes = _mm256_set1_epi16(0x00ff);

    __m256i accumulator = _mm256_setzero_si256();

    for (size_t i=0; i < size; i += 4 * 32) {

        __m256i accu_16bit = _mm256_setzero_si256();

        {
            const __m256i v0 = _mm256_loadu_si256((__m256i*)(array + i + 0*32));
            const __m256i v1 = _mm256_loadu_si256((__m256i*)(array + i + 1*32));
            const __m256i v2 = _mm256_loadu_si256((__m256i*)(array + i + 2*32));
            const __m256i v3 = _mm256_loadu_si256((__m256i*)(array + i + 3*32));

            const __m256i l0 = _mm256_and_si256(v0, mask_lobytes);
            const __m256i h0 = _mm256_srli_epi16(v0, 8);
            const __m256i l1 = _mm256_and_si256(v1, mask_lobytes);
            const __m256i h1 = _mm256_srli_epi16(v1, 8);
            const __m256i l2 = _mm256_and_si256(v2, mask_lobytes);
            const __m256i h2 = _mm256_srli_epi16(v2, 8);
            const __m256i l3 = _mm256_and_si256(v3, mask_lobytes);
            const __m256i h3 = _mm256_srli_epi16(v3, 8);

            accu_16bit = _mm256_add_epi16(accu_16bit, l0);
            accu_16bit = _mm256_add_epi16(accu_16bit, h0);
            accu_16bit = _mm256_add_epi16(accu_16bit, l1);
            accu_16bit = _mm256_add_epi16(accu_16bit, h1);
            accu_16bit = _mm256_add_epi16(accu_16bit, l2);
            accu_16bit = _mm256_add_epi16(accu_16bit, h2);
            accu_16bit = _mm256_add_epi16(accu_16bit, l3);
            accu_16bit = _mm256_add_epi16(accu_16bit, h3);
        }
        
        const __m256i t0 = _mm256_and_si256(accu_16bit, _mm256_set1_epi32(0x0000ffff));
        const __m256i t1 = _mm256_srli_epi32(accu_16bit, 16);

        accumulator = _mm256_add_epi32(accumulator, t0);
        accumulator = _mm256_add_epi32(accumulator, t1);
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
