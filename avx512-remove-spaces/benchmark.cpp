#include <cstdio>
#include <cassert>

#include "benchmark.h"
#include "all.cpp"
#include "application_base.cpp"

class Benchmark: public ApplicationBase {

public:
    void run() {
        for (int cardinality=1; cardinality <= 64; cardinality++) {
            for (int k=0; k < 10; k++) {
                printf("cardinality=%d, run=%d\n", cardinality, k);
                test(random(cardinality));
            }
        }
    }

private:
    void test(uint64_t v) {
        init_input();
        while (v) {
            const int k = __builtin_ctzll(v);
            input[k] = ' ';

            v ^= (v & -v);
        }

        compare();
    }

    void compare() {
        const size_t repeat = 1000;

#define RUN(__name__, __procedure__) \
        BEST_TIME(/**/, __procedure__(input, output, 64), __name__, repeat, size);

        RUN("scalar",                       remove_spaces__scalar);
        RUN("AVX512VBMI",                   remove_spaces__avx512vbmi);
        RUN("AVX512VBMI (Travis)",          remove_spaces__avx512vbmi__travis);
        RUN("AVX512VBMI (Zach)",            remove_spaces__avx512vbmi__zach);
        RUN("despacer_bitmap (aqrit)",      despacer_bitmap);
        RUN("despace_block_mux (aqrit)",    despace_block_mux);
        RUN("despace_ssse3_cumsum (aqrit)", despace_ssse3_cumsum);
        RUN("despace_avx2_vpermd (aqrit)",  despace_avx2_vpermd);
    }
};

int main() {

    Benchmark benchmark;
    benchmark.run();

    return EXIT_SUCCESS;
}
