#include "avx2_madd.h"

#include <immintrin.h>

uint32_t avx2_madd_sumwords(uint16_t* array, size_t size) {

    const __m256i one    = _mm256_set1_epi16(1);
    const __m256i addend = _mm256_set1_epi16(-32768);

    __m256i accumulator = _mm256_setzero_si256();

    for (size_t i=0; i < size; i += 16) {
        const __m256i v  = _mm256_loadu_si256((__m256i*)(array + i));
        const __m256i t0 = _mm256_xor_si256(v, addend);
        const __m256i t1 = _mm256_madd_epi16(t0, one);
        accumulator = _mm256_add_epi32(accumulator, t1);
    }
    const __m128i accumulator128 = _mm_add_epi32(_mm256_extracti128_si256(accumulator, 0), _mm256_extracti128_si256(accumulator, 1));

    return uint32_t(_mm_extract_epi32(accumulator128, 0)) +
           uint32_t(_mm_extract_epi32(accumulator128, 1)) +
           uint32_t(_mm_extract_epi32(accumulator128, 2)) +
           uint32_t(_mm_extract_epi32(accumulator128, 3)) +
           32768 * uint32_t(size);
}
