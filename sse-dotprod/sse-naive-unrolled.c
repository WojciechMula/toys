float sse_naive_unrolled(const float* a, const float* b, size_t n) {
    
    const size_t chunks = n/(4*4);

    __m128 dots = _mm_setzero_ps();
    for (size_t i=0; i < n; i += 4*4) {
        __m128 A0 = _mm_loadu_ps(&a[i + 0*4]);
        __m128 A1 = _mm_loadu_ps(&a[i + 1*4]);
        __m128 A2 = _mm_loadu_ps(&a[i + 2*4]);
        __m128 A3 = _mm_loadu_ps(&a[i + 3*4]);

        __m128 B0 = _mm_loadu_ps(&b[i + 0*4]);
        __m128 B1 = _mm_loadu_ps(&b[i + 1*4]);
        __m128 B2 = _mm_loadu_ps(&b[i + 2*4]);
        __m128 B3 = _mm_loadu_ps(&b[i + 3*4]);

        __m128 AB0 = _mm_mul_ps(A0, B0);
        __m128 AB1 = _mm_mul_ps(A1, B1);
        __m128 AB2 = _mm_mul_ps(A2, B2);
        __m128 AB3 = _mm_mul_ps(A3, B3);

        dots = _mm_add_ps(dots, AB0);
        dots = _mm_add_ps(dots, AB1);
        dots = _mm_add_ps(dots, AB2);
        dots = _mm_add_ps(dots, AB3);
    }

    float tmp[4];
    _mm_storeu_ps(tmp, dots);
    float result = dots[0] + dots[1] + dots[2] + dots[3];

    for (size_t i=chunks*4*4; i < n; i++) {
        result += a[i] * b[i];
    }

    return result;
}
