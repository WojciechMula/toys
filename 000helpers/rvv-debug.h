#pragma once

#include <cstdio>

void dump(const vuint8m1_t v) {
    uint8_t out[16];

    const size_t vlmax = __riscv_vsetvlmax_e8m1();
    __riscv_vse8_v_u8m1(out, v, vlmax);

    putchar('[');
    for (size_t i=0; i < vlmax; i++) {
        if (i == 0) {
            printf("%02x", out[i]);
        } else {
            printf("|%02x", out[i]);
        }
    }
    printf("]\n");
}

void dump(const vuint8m8_t v) {
    uint8_t out[16*8];

    const size_t vlmax = __riscv_vsetvlmax_e8m8();
    __riscv_vse8_v_u8m8(out, v, vlmax);

    putchar('[');
    for (size_t i=0; i < vlmax; i++) {
        if (i == 0) {
            printf("%02x", out[i]);
        } else {
            printf("|%02x", out[i]);
        }
    }
    printf("]\n");
}

void dump(const vuint16m1_t v) {
    uint16_t out[16];

    const size_t vlmax = __riscv_vsetvlmax_e16m1();
    __riscv_vse16_v_u16m1(out, v, vlmax);

    putchar('[');
    for (size_t i=0; i < vlmax; i++) {
        if (i == 0) {
            printf("%04x", out[i]);
        } else {
            printf("|%04x", out[i]);
        }
    }
    printf("]\n");
}

void dump(const vuint16m8_t v) {
    uint16_t out[16*8];

    const size_t vlmax = __riscv_vsetvlmax_e16m1();
    __riscv_vse16_v_u16m8(out, v, vlmax);

    putchar('[');
    for (size_t i=0; i < vlmax; i++) {
        if (i == 0) {
            printf("%04x", out[i]);
        } else {
            printf("|%04x", out[i]);
        }
    }
    printf("]\n");
}

void dump(const vuint32m8_t v) {
    uint32_t out[16/4 * 8];

    const size_t vlmax = __riscv_vsetvlmax_e32m8();
    __riscv_vse32_v_u32m8(out, v, vlmax);

    putchar('[');
    for (size_t i=0; i < vlmax; i++) {
        if (i == 0) {
            printf("%08x", out[i]);
        } else {
            printf("|%08x", out[i]);
        }
    }
    printf("]\n");
}

void dump(const vuint16m2_t v) {
    uint16_t out[256];

    const size_t vlmax = __riscv_vsetvlmax_e16m2();
    __riscv_vse16_v_u16m2(out, v, vlmax);

    putchar('[');
    for (size_t i=0; i < vlmax; i++) {
        if (i == 0) {
            printf("%04x", out[i]);
        } else {
            printf("|%04x", out[i]);
        }
    }
    printf("]\n");
}

void dump(const vuint32m4_t v) {
    uint32_t out[256];

    const size_t vlmax = __riscv_vsetvlmax_e32m4();
    __riscv_vse32_v_u32m4(out, v, vlmax);

    putchar('[');
    for (size_t i=0; i < vlmax; i++) {
        if (i == 0) {
            printf("%08x", out[i]);
        } else {
            printf("|%08x", out[i]);
        }
    }
    printf("]\n");
}

void dump(const vbool8_t mask, size_t vl) {
    // __riscv_vsm_v_b8(uint8_t *rs1, vbool8_t vs3, size_t vl)
    constexpr size_t N = 8;
    uint8_t val[N];
    for (size_t i=0; i < N; i++) {
        val[i] = 0;
    }

    __riscv_vsm_v_b8(&val[0], mask, vl);
    for (ssize_t i=N-1; i >= 0; i--) {
        uint8_t active = 0x80;
        for (int j=0; j < 8; j++, active >>= 1) {
            putchar(((val[i] & active) != 0) ? '1' : '0');
        }
    }

    putchar('\n');
}
void dump(const vuint8m1_t v) {
    uint8_t out[16];

    const size_t vlmax = __riscv_vsetvlmax_e8m1();
    __riscv_vse8_v_u8m1(out, v, vlmax);

    putchar('[');
    for (size_t i=0; i < vlmax; i++) {
        if (i == 0) {
            printf("%02x", out[i]);
        } else {
            printf("|%02x", out[i]);
        }
    }
    printf("]\n");
}

void dump(const vuint8m8_t v) {
    uint8_t out[16*8];

    const size_t vlmax = __riscv_vsetvlmax_e8m8();
    __riscv_vse8_v_u8m8(out, v, vlmax);

    putchar('[');
    for (size_t i=0; i < vlmax; i++) {
        if (i == 0) {
            printf("%02x", out[i]);
        } else {
            printf("|%02x", out[i]);
        }
    }
    printf("]\n");
}

void dump(const vuint16m1_t v) {
    uint16_t out[16];

    const size_t vlmax = __riscv_vsetvlmax_e16m1();
    __riscv_vse16_v_u16m1(out, v, vlmax);

    putchar('[');
    for (size_t i=0; i < vlmax; i++) {
        if (i == 0) {
            printf("%04x", out[i]);
        } else {
            printf("|%04x", out[i]);
        }
    }
    printf("]\n");
}

void dump(const vuint16m8_t v) {
    uint16_t out[16*8];

    const size_t vlmax = __riscv_vsetvlmax_e16m1();
    __riscv_vse16_v_u16m8(out, v, vlmax);

    putchar('[');
    for (size_t i=0; i < vlmax; i++) {
        if (i == 0) {
            printf("%04x", out[i]);
        } else {
            printf("|%04x", out[i]);
        }
    }
    printf("]\n");
}

void dump(const vuint32m8_t v) {
    uint32_t out[16/4 * 8];

    const size_t vlmax = __riscv_vsetvlmax_e32m8();
    __riscv_vse32_v_u32m8(out, v, vlmax);

    putchar('[');
    for (size_t i=0; i < vlmax; i++) {
        if (i == 0) {
            printf("%08x", out[i]);
        } else {
            printf("|%08x", out[i]);
        }
    }
    printf("]\n");
}
