#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <cassert>

#include "config.h"
#include "benchmark.h"

#include "scalar.cpp"
#include "avx512f.cpp"

void demo(size_t size) {

    const size_t N = 64;

    assert(size < N);

    static uint64_t tab[N];
    memset(tab, 0, sizeof(N));
    tab[size - 1] = 0x8000000000000000llu;
 
    printf("size = %lu\n", size);
    BEST_TIME(scalar_bfs(tab, size),    100000, size);
    BEST_TIME(avx512f_bfs(tab, size),   100000, size);
}

int main() {

    for (size_t n=8; n < 64; n++) {
        demo(n);
    }

    return EXIT_SUCCESS;
}

