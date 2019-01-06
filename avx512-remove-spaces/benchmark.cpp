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
        BEST_TIME(/**/, remove_spaces__scalar(input, output, 64),     "scalar    ", repeat, size);
        BEST_TIME(/**/, remove_spaces__avx512vbmi(input, output, 64), "AVX512VBMI", repeat, size);
        BEST_TIME(/**/, remove_spaces__avx512vbmi__travis(input, output, 64), "AVX512VBMI (Travis)", repeat, size);
        BEST_TIME(/**/, remove_spaces__avx512vbmi__zach(input, output, 64), "AVX512VBMI (Zach)", repeat, size);
    }
};

int main() {

    Benchmark benchmark;
    benchmark.run();

    return EXIT_SUCCESS;
}
