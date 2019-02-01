#include "avx2_maddubs.h"

#include <immintrin.h>

int32_t avx2_maddubs_sumsignedbytes(int8_t* array, size_t size) {

    const __m256i zero   = _mm256_setzero_si256();
    const __m256i one_8  = _mm256_set1_epi8(1);
    const __m256i one_16 = _mm256_set1_epi16(1);
    __m256i accumulator = zero;

    for (size_t j = size / (32 * 128); j != 0; --j) {
        __m256i local_accumulator = zero;
        for (size_t i = 0; i < 128 * 32; i += 32) {
            const __m256i v   = _mm256_loadu_si256((__m256i*)(array + i));
            const __m256i t0 = _mm256_maddubs_epi16(one_8, v);
            local_accumulator = _mm256_add_epi16(local_accumulator, t0);
        }
        const __m256i t1 = _mm256_madd_epi16(one_16, local_accumulator);
        accumulator = _mm256_add_epi32(accumulator, t1);
        array += 128 * 32;
    }
    size_t remainder = size - ((size / (32 * 128)) * (32 * 128));
    if (remainder) {
        __m256i local_accumulator = zero;
        for (size_t i = 0; i < remainder; i += 32) {
            const __m256i v   = _mm256_loadu_si256((__m256i*)(array + i));
            const __m256i t0 = _mm256_maddubs_epi16(one_8, v);
            local_accumulator = _mm256_add_epi16(local_accumulator, t0);
        }
        const __m256i t1 = _mm256_madd_epi16(one_16, local_accumulator);
        accumulator = _mm256_add_epi32(accumulator, t1);
    }

    const __m128i accumulator128 = _mm_add_epi32(_mm256_extracti128_si256(accumulator, 0), _mm256_extracti128_si256(accumulator, 1));

    return int32_t(_mm_extract_epi32(accumulator128, 0)) +
           int32_t(_mm_extract_epi32(accumulator128, 1)) +
           int32_t(_mm_extract_epi32(accumulator128, 2)) +
           int32_t(_mm_extract_epi32(accumulator128, 3));
}
