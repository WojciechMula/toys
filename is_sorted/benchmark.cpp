#include <cstdio>
#include <cstdlib>
#include <cassert>

#include <vector>
#include "time_utils.h"

#include "all-procedures.cpp"

class Benchmark {

    std::vector<int32_t> input;
    int32_t* array;
    size_t size;
    int iterations;

public:
    Benchmark(size_t size_, int iterations_)
        : size(size_)
        , iterations(iterations_) {

        fill_ascending();
        array = &input[0];
    }

    void run_all() {
        printf("input size %lu, iterations %d\n", size, iterations);

        measure_total_time("scalar  : ", [this]{return is_sorted(array, size);}, iterations);
        measure_total_time("SSE     : ", [this]{return is_sorted_sse(array, size);}, iterations);
        measure_total_time("SSE (2) : ", [this]{return is_sorted_sse_2(array, size);}, iterations);
#ifdef HAVE_AVX2
        measure_total_time("AVX2    : ", [this]{return is_sorted_avx2(array, size);}, iterations);
#endif // HAVE_AVX2
    }

private:
    void fill_ascending() {
        input.reserve(size);
        for (size_t i=0; i < size; i++) {
            input[i] = i;
        }
    }
};

int main(int argc, char* argv[]) {

    int tmp;

    tmp = 0;
    if (argc > 1) {
        tmp = atoi(argv[1]);
    }

    const size_t size = (tmp > 0) ? tmp : 1024;

    tmp = 0;
    if (argc > 2) {
        tmp = atoi(argv[2]);
    }

    const int iterations = (tmp > 0) ? tmp : 10;

    Benchmark b(size, iterations);
    b.run_all();

    return EXIT_SUCCESS;
}
