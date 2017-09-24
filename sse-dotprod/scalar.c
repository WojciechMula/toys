float scalar(const float* a, const float* b, size_t n) {
    float result = 0;

    for (size_t i=0; i < n; i++) {
        result += a[i] * b[i];
    }

    return result;
}
