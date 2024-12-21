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

uint8_t long_div_u8(uint8_t dividend, uint8_t divisor) {
    uint8_t reminder = 0;
    uint8_t quotient = 0;

    for (int i=7; i >= 0; i--) {
        // make room for i-th bit of dividend at 0-th position
        reminder <<= 1;

        // inject that bit
        reminder |= (dividend >> i) & 1;

        if (reminder >= divisor) {
            // set i-th bit in quotient
            quotient |= 1 << i;

            // adjust reminder
            reminder -= divisor;
        }
    }

    return quotient;
}

__attribute__((optimize("no-tree-vectorize")))
void scalar_long_div_u8(const uint8_t* a, const uint8_t* b, uint8_t* out, size_t n) {
    for (size_t i=0; i < n; i++) {
        out[i] = long_div_u8(a[i], b[i]);
    }
}

void scalar_long_div_u8_autovect(const uint8_t* a, const uint8_t* b, uint8_t* out, size_t n) {
    for (size_t i=0; i < n; i++) {
        out[i] = long_div_u8(a[i], b[i]);
    }
}
