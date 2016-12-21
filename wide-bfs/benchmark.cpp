#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <cassert>

#include "config.h"
#include "benchmark.h"

#include "scalar.cpp"
#include "x86.cpp"
#ifdef HAVE_AVX512_INSTRUCTIONS
#   include "avx512f.cpp"
#endif

void demo(size_t size) {

    const size_t N = 1024;

    assert(size <= N);
    assert(size > 0);

    static uint64_t tab[N];
    memset(tab, 0, sizeof(tab));
    tab[size - 1] = 0x8000000000000000llu;

    const size_t expected = scalar_bfs(tab, size);

    printf("size = %lu\n", size);
    BEST_TIME(scalar_bfs(tab, size),    100000, expected, size);
    BEST_TIME(x86_bfs(tab, size),       100000, expected, size);
#ifdef HAVE_AVX512_INSTRUCTIONS
    BEST_TIME(avx512f_bfs(tab, size),   100000, expected, size);
#endif
}

int main() {

    for (size_t n=3; n <= 10; n++) {
        demo(1llu << n);
    }

    return EXIT_SUCCESS;
}

