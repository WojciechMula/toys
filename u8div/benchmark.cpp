#include <cstdio>
#include <vector>
#include "benchmark.h"

#include "impl.cpp"

#define SIZE 1024*1024
uint8_t a[SIZE];
uint8_t b[SIZE];
uint8_t c[SIZE + 64];

int main() {
    for (size_t i=0; i < SIZE; i++) {
        a[i] = i;
        b[i] = (i % 255) + 1;
    }

    const size_t repeat = 100;

    BEST_TIME(/**/, scalar_div_u8(a, b, c, SIZE), "scalar", repeat, SIZE);
    BEST_TIME(/**/, scalar_div_u8_unrolled4(a, b, c, SIZE), "scalar (unrolled x 4)", repeat, SIZE);
    BEST_TIME(/**/, sse_div_u8(a, b, c, SIZE), "SSE", repeat, SIZE);
    BEST_TIME(/**/, sse_div_u8_no_rounding(a, b, c, SIZE), "SSE (no rounding)", repeat, SIZE);
    BEST_TIME(/**/, avx2_div_u8(a, b, c, SIZE), "AVX2", repeat, SIZE);
    BEST_TIME(/**/, manual_div_u8(a, b, c, SIZE), "manual (SSE: ver1)", repeat, SIZE);
    BEST_TIME(/**/, manual_div_u8_ver2(a, b, c, SIZE), "manual (SSE: ver2)", repeat, SIZE);
    BEST_TIME(/**/, manual_div_u8_ver2_avx(a, b, c, SIZE), "manual (AVX: ver2)", repeat, SIZE);
}
