#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <cstring>

#include "config.h"

#include "scalar.cpp"
#include "x86.cpp"
#ifdef HAVE_AVX512_INSTRUCTIONS
#   include "avx512f.cpp"
#endif

template <typename FUN>
void validate(const char* name, FUN fun) {
    
    printf("%s...", name);
    fflush(stdout);

    const size_t N = 12;
    uint64_t tab[N];

    for (size_t size=0; size < N + 1; size++) {

        memset(tab, 0, sizeof(tab));
        const uint64_t result = fun(tab, size);
        if (result != uint64_t(-1)) {
            printf("failed for an empty table, returned %lu\n", result);
            exit(1);
        }

        for (size_t bit=0; bit < 64*size; bit++) {
            memset(tab, 0, sizeof(tab));
            tab[bit / 64] = 1llu << (bit % 64);

            const uint64_t result = fun(tab, size);
            if (result != bit) {
                printf("failed for %lu, returned %lu\n", bit, result);
                exit(1);
            }
        }
    }

    puts("OK");
}


int main() {

    validate("scalar",  scalar_bfs);
#ifndef HAVE_AVX512_INSTRUCTIONS
    validate("x86",     x86_bfs);
#endif
#ifdef HAVE_AVX512_INSTRUCTIONS
    validate("AVX512F", avx512f_bfs);
#endif

    return EXIT_SUCCESS;
}
