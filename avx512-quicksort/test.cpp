#include <cstdlib>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <cassert>
#include <immintrin.h>

#include "input_data.cpp"
#include "quicksort.cpp"


bool is_sorted(uint32_t* array, size_t n) {
    assert(n > 0);
    for (size_t i=1; i < n; i++) {
        if (array[i - 1] > array[i]) {
            printf("mismatch at %lu\n", i);
            return false;
        }
    }

    return true;
}


const size_t AVX512_REGISTER_SIZE = 16;


class Test {

public:
    template <typename SORT_FN>
    bool run(SORT_FN sort) {
        for (size_t size=2*AVX512_REGISTER_SIZE; size < 256*AVX512_REGISTER_SIZE; size += 1) {

            InputAscending  asc(size);
            InputDescending dsc(size);
            InputRandom     rnd(size);

            if (!test(sort, asc)) {
                printf("failed for size %lu, intput ascending\n", size);
                return false;
            }

            if (!test(sort, dsc)) {
                printf("failed for size %lu, intput descending\n", size);
                return false;
            }

            if (!test(sort, dsc)) {
                printf("failed for size %lu, intput random\n", size);
                return false;
            }
        } // for

        return true;
    }


private:
    template <typename SORT_FN>
    bool test(SORT_FN sort, InputData& data) {
        sort(data.pointer(), 0, data.count() - 1);

        return is_sorted(data.pointer(), data.count());
    }
};


int main() {

    puts("Please wait, it might take a while...");
    puts("");

    Test test;
    int ret = EXIT_SUCCESS;

    {
        printf("AVX512 base version... "); fflush(stdout);
        if (test.run(avx512_quicksort)) {
            puts("OK");
        } else {
            puts("FAILED");
            ret = EXIT_FAILURE;
        }
    }

    {
        printf("AVX512 + popcnt version... "); fflush(stdout);
        if (test.run(avx512_popcnt_quicksort)) {
            puts("OK");
        } else {
            puts("FAILED");
            ret = EXIT_FAILURE;
        }
    }

    {
        printf("AVX512 + bmi2 version ... "); fflush(stdout);
        if (test.run(avx512_bmi2_quicksort)) {
            puts("OK");
        } else {
            puts("FAILED");
            ret = EXIT_FAILURE;
        }
    }

    return ret;
}
