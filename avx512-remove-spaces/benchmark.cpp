#include <cstdio>
#include <cassert>

#include "benchmark.h"
#include "all.cpp"

class Benchmark {

    static const size_t size = 64;
    char input[size];
    char output[size];

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

    uint64_t random(int cardinality) {
        uint64_t v = 0;
        while (__builtin_popcountll(v) != cardinality) {
            v |= uint64_t(1) << (rand() % 64);
        }

        return v;
    }

    void init_input() {
        int i=0;
        for (int j='a'; j <= 'z'; j++)
            input[i++] = j;

        for (int j='A'; j <= 'Z'; j++)
            input[i++] = j;

        for (int j='0'; j <= '9'; j++)
            input[i++] = j;

        input[i++] = '#';
        input[i++] = '@';

        assert(i == size);
    }


    void compare() {
        const size_t repeat = 1000;
        BEST_TIME(/**/, remove_spaces__scalar(input, output, 64),     "scalar    ", repeat, size);
        BEST_TIME(/**/, remove_spaces__avx512vbmi(input, output, 64), "AVX512VBMI", repeat, size);
    }
};

int main() {

    Benchmark benchmark;
    benchmark.run();

    return EXIT_SUCCESS;
}
