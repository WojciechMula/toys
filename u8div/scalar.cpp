#include <cstdint>
#include <cstdlib>

void scalar_div_u8(const uint8_t* a, const uint8_t* b, uint8_t* out, size_t n) {
    for (size_t i=0; i < n; i++) {
        out[i] = a[i] / b[i];
    }
}

void scalar_div_u8_unrolled4(const uint8_t* a, const uint8_t* b, uint8_t* out, size_t n) {
    for (size_t i=0; i < n; i += 4) {
        out[i + 0] = a[i + 0] / b[i + 0];
        out[i + 1] = a[i + 1] / b[i + 1];
        out[i + 2] = a[i + 2] / b[i + 2];
        out[i + 3] = a[i + 3] / b[i + 3];
    }
}
