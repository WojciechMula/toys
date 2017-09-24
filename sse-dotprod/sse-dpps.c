float sse_dpps(const float* a, const float* b, size_t n) {
    
    const size_t chunks = n/4;

    float result = 0;
    for (size_t i=0; i < n; i += 4) {
        __m128 A = _mm_loadu_ps(&a[i]);
        __m128 B = _mm_loadu_ps(&b[i]);
        __m128 AB = _mm_dp_ps(A, B, 0xf1);

        result += _mm_cvtss_f32(AB);

    }

    for (size_t i=chunks*4; i < n; i++) {
        result += a[i] * b[i];
    }

    return result;
}
