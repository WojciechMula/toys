#include "avx2.h"

#include <cstdint>
#include <immintrin.h>


float avx2(float x, float* x_boudary, float* a, float* b) {
    // 1. find index
    const __m256 X = _mm256_set1_ps(x);
    const __m256 B = _mm256_loadu_ps(x_boudary);
    const __m256 cmp = _mm256_cmp_ps(X, B, _CMP_LT_OS);
    const uint32_t mask = _mm256_movemask_ps(cmp);

    int index;
    if (mask != 0)
        index = __builtin_ctz(mask);
    else
        index = 7;

    // 2. evaluate linear function
    return a[index] * x + b[index];
}
