#include <cstdio>
#include "benchmark.h"

#include "impl.cpp"

#define SIZE 1024*1024
uint8_t a[SIZE];
uint8_t b[SIZE];
uint8_t c[SIZE + 64];

#define BENCH(func) \
    BEST_TIME(/**/, func(a, b, c, SIZE), names[func].c_str(), repeat, SIZE);

int main() {
    for (size_t i=0; i < SIZE; i++) {
        a[i] = i;
        b[i] = (i % 255) + 1;
    }

    auto names = function_names();

    const size_t repeat = 100;

    BENCH(scalar_div_u8);
    BENCH(scalar_div_u8_unrolled4);
    BENCH(scalar_long_div_u8);
    BENCH(scalar_long_div_u8_autovect);

    #ifdef HAVE_SSE
        BENCH(sse_div_u8);
        BENCH(sse_div_u8_no_rounding);
        BENCH(sse_div_u8_cvtt);
        BENCH(sse_div_u8_rcp);
        BENCH(sse_long_div_u8);
    #endif

    #ifdef HAVE_AVX2
        BENCH(avx2_div_u8);
        BENCH(avx2_div_u8_cvtt);
        BENCH(avx2_div_u8_rcp);
        BENCH(avx2_div_u8_rcp_4x);
        BENCH(avx2_long_div_u8);
    #endif

    #ifdef HAVE_AVX512
        BENCH(avx512_div_u8_cvtt);
        BENCH(avx512_div_u8_rcp);
        BENCH(avx2_div_u8_rcp_4x);
        BENCH(avx512_long_div_u8);
    #endif
}
