void scalar_div_u16(const uint16_t* a, const uint16_t* b, uint16_t* out, size_t n) {
    for (size_t i=0; i < n; i++) {
        out[i] = a[i] / b[i];
    }
}
