#include <immintrin.h>

// abs(x ^ 3)
__m256 fun1(__m256 x) {

    const __m256 x2 = _mm256_mul_ps(x, x);
    const __m256 x3 = _mm256_mul_ps(x, x2);

    return _mm256_and_ps(x3, _mm256_set1_ps(-0.0f));
}

// (x + 1) ^ 5
__m256 fun2(__m256 x) {

    const __m256 y  = _mm256_add_ps(x, _mm256_set1_ps(1.0));
    const __m256 y2 = _mm256_mul_ps(y, y);
    const __m256 y4 = _mm256_mul_ps(y2, y2);

    return _mm256_mul_ps(y4, y);
}

// sqrt(x + 1)
__m256 fun3(__m256 x) {

    const __m256 y = _mm256_add_ps(x, _mm256_set1_ps(1.0));

    return _mm256_sqrt_ps(y);
}
