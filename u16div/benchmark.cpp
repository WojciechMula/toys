#include <cstdio>
#include "benchmark.h"

#include "impl.cpp"

#define SIZE 1024*1024*2
uint16_t a[SIZE];
uint16_t b[SIZE];
uint16_t c[SIZE + 64];

#define BENCH(func) \
    BEST_TIME(/**/, func(a, b, c, SIZE), names[func].c_str(), repeat, SIZE);

int main() {
    for (size_t i=0; i < SIZE; i++) {
        a[i] = i;
        b[i] = (i % 255) + 1;
    }

    auto names = function_names();
    const size_t repeat = 100;

    BENCH(scalar_div_u16);

    #ifdef HAVE_AVX2
        BENCH(avx2_div_u16_cvtt);
        BENCH(avx2_div_u16_cvtt_ver2);
        BENCH(avx2_div_u16_cvtt_x4);
        BENCH(avx2_div_u16_cvtt_x2);
        BENCH(avx2_div_u16_rcp);
    #endif

    #ifdef HAVE_AVX512
        BENCH(avx512_div_u16_cvtt);
        BENCH(avx512_div_u16_cvtt_x4);
        BENCH(avx512_div_u16_cvtt_x2);
    #endif
}
