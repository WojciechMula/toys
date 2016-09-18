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

    int         count;
    InputData&  input;
    uint32_t*   tmp;

public:
    PerformanceTest(int n, InputData& input)
        : count(n)
        , input(input) {
        
        assert(count > 0);
        tmp = new uint32_t[n];
    }

    ~PerformanceTest() {
        delete[] tmp;
    }

public:
    template <typename SORT_FUNCTION>
    uint32_t run(SORT_FUNCTION sort) {

        uint32_t time = 0;

        int k = count;
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

    printf("%20s ... ", name); fflush(stdout);
    uint32_t time = test.run(sort);
    if (ref > 0) {
        printf("%0.4f s (%0.2f)\n", time/1000000.0, ref/double(time));
    } else {
        printf("%0.4f s\n", time/1000000.0);
    }

    return time;
}


int main() {

#define M 1000000
    const size_t count = 20*M;
    const size_t size  = count * sizeof(uint32_t);

    InputRandom data(size);

    printf("items count: %lu (%lu bytes)\n", count, size);

    uint32_t ref = 0;
    ref = measure("std::sort",            std_sort_wrapper,   data, 0);
    measure("quick sort",           quicksort,          data, ref);
    measure("AVX512 quick sort",    avx512_quicksort,   data, ref);
}
