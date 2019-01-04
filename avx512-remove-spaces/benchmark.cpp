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
        test_1_gap();
        test_2_gaps();
        test_3_gaps();
        //test_4_gaps();
    }

private:
    void test_1_gap() {
        puts("test 1 gap");
        for (size_t i=0; i < size; i++) {
            init_input();
            input[i] = ' ';
            compare();
        }
    }


    void test_2_gaps() {
        puts("test 2 gaps");
        for (size_t i=0; i < size; i++) {
            for (size_t j=i + 1; j < size; j++) {
                init_input();
                input[i] = ' ';
                input[j] = ' ';
                compare();
            }
        }
    }


    void test_3_gaps() {
        puts("test 3 gaps");
        for (size_t i=0; i < size; i++) {
            for (size_t j=i + 1; j < size; j++) {
                for (size_t k=j + 1; k < size; k++) {
                    init_input();
                    input[i] = ' ';
                    input[j] = ' ';
                    input[k] = ' ';
                    compare();
                }
            }
        }
    }


    void test_4_gaps() {
        puts("test 4 gaps");
        for (size_t i=0; i < size; i++) {
            for (size_t j=i + 1; j < size; j++) {
                for (size_t k=j + 1; k < size; k++) {
                    for (size_t l=k + 1; l < size; l++) {
                        init_input();
                        input[i] = ' ';
                        input[j] = ' ';
                        input[k] = ' ';
                        input[l] = ' ';
                        compare();
                    }
                }
            }
        }
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
