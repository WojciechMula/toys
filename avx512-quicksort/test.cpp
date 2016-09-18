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


bool test(InputData& data) {
    
    avx512_quicksort(data.pointer(), 0, data.count() - 1);

    return is_sorted(data.pointer(), data.count());
}


int main() {

    const size_t AVX512_REGISTER_SIZE = 16;

    puts("Please wait, it may take a while...");

    for (size_t size=2*AVX512_REGISTER_SIZE; size < 100*AVX512_REGISTER_SIZE; size += 1) {

        InputAscending  asc(size);
        InputDescending dsc(size);
        InputRandom     rnd(size);

        if (!test(asc)) {
            printf("failed for size %lu, intput ascending\n", size);
            return EXIT_FAILURE;
        }

        if (!test(dsc)) {
            printf("failed for size %lu, intput descending\n", size);
            return EXIT_FAILURE;
        }

        if (!test(dsc)) {
            printf("failed for size %lu, intput random\n", size);
            return EXIT_FAILURE;
        }
    }

    puts("All OK");

    return EXIT_SUCCESS;
}
