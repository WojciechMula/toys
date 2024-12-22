#include <cstdio>
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
    BEST_TIME(/**/, scalar_long_div_u8(a, b, c, SIZE), "scalar (long div)", repeat, SIZE);
    BEST_TIME(/**/, scalar_long_div_u8_autovect(a, b, c, SIZE), "scalar (long div, autovect)", repeat, SIZE);

    #ifdef HAVE_SSE
        BEST_TIME(/**/, sse_div_u8(a, b, c, SIZE), "SSE", repeat, SIZE);
        BEST_TIME(/**/, sse_div_u8_no_rounding(a, b, c, SIZE), "SSE (no rounding)", repeat, SIZE);
        BEST_TIME(/**/, sse_div_u8_cvtt(a, b, c, SIZE), "SSE (cvtt)", repeat, SIZE);
        BEST_TIME(/**/, sse_div_u8_rcp(a, b, c, SIZE), "SSE (rcp)", repeat, SIZE);
        BEST_TIME(/**/, sse_long_div_u8(a, b, c, SIZE), "SSE long div", repeat, SIZE);
    #endif

    #ifdef HAVE_AVX2
        BEST_TIME(/**/, avx2_div_u8(a, b, c, SIZE), "AVX2", repeat, SIZE);
        BEST_TIME(/**/, avx2_div_u8_cvtt(a, b, c, SIZE), "AVX2 (cvtt)", repeat, SIZE);
        BEST_TIME(/**/, avx2_div_u8_rcp(a, b, c, SIZE), "AVX2 (rcp)", repeat, SIZE);
        BEST_TIME(/**/, avx2_long_div_u8(a, b, c, SIZE), "AVX2 long div", repeat, SIZE);
    #endif

    #ifdef HAVE_AVX512
        BEST_TIME(/**/, avx512_div_u8_cvtt(a, b, c, SIZE), "AVX512 (cvtt)", repeat, SIZE);
        BEST_TIME(/**/, avx512_div_u8_rcp(a, b, c, SIZE), "AVX512 (rcp)", repeat, SIZE);
        BEST_TIME(/**/, avx512_long_div_u8(a, b, c, SIZE), "AVX512 long div", repeat, SIZE);
    #endif
}
