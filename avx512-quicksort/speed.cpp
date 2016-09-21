#include <cstdlib>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <cassert>
#include <algorithm>

#include "input_data.cpp"
#include "gettime.cpp"
#include "quicksort.cpp"


class PerformanceTest final {

    int         iterations;
    InputData&  input;
    uint32_t*   tmp;

public:
    PerformanceTest(int n, InputData& input)
        : iterations(n)
        , input(input) {
        
        assert(iterations > 0);
        tmp = new uint32_t[input.count()];
    }

    ~PerformanceTest() {
        delete[] tmp;
    }

public:
    template <typename SORT_FUNCTION>
    uint32_t run(SORT_FUNCTION sort) {

        uint32_t time = 0;

        int k = iterations;
        while (k--) {
            memcpy(tmp, input.pointer(), input.size());

            const uint32_t t1 = get_time();
            sort(input.pointer(), 0, input.count() - 1);
            const uint32_t t2 = get_time();

            const uint32_t dt = t2 - t1;

            if (time == 0) {
                time = dt;
            } else if (dt < time) {
                time = dt;
            }
        }

        return time;
    }
};


void std_sort_wrapper(uint32_t* array, int left, int right) {
    
    std::sort(array + left, array + right + 1);
}


template <typename SORT_FUNCTION>
uint32_t measure(const char* name, SORT_FUNCTION sort, InputData& data, uint32_t ref) {

    PerformanceTest test(3, data);

    printf("%30s ... ", name); fflush(stdout);
    uint32_t time = test.run(sort);
    if (ref > 0) {
        printf("%0.4f s (%0.2f)\n", time/1000000.0, ref/double(time));
    } else {
        printf("%0.4f s\n", time/1000000.0);
    }

    return time;
}


int main(int argc, char* argv[]) {

#define M 1000000
    size_t count = 10*M;

    if (argc > 1 && atoi(argv[1]) > 0) {
        count = atoi(argv[1]) * M;
    }

    InputRandom data(count);

    printf("items count: %lu (%lu bytes)\n", data.count(), data.size());

    uint32_t ref = 0;
    ref = measure("std::sort",              std_sort_wrapper,        data, 0);
    measure("quick sort",                   quicksort,               data, ref);
    measure("AVX512 quick sort",            avx512_quicksort,        data, ref);
    measure("AVX512 + popcnt quick sort",   avx512_popcnt_quicksort, data, ref);
}
