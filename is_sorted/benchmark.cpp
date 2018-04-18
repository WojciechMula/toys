#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <string>

#include <vector>
#include "time_utils.h"

#include "all-procedures.cpp"

class Benchmark {

    std::vector<int32_t> input;
    int32_t* array;
    size_t size;
    int iterations;
    bool csv;

public:
    Benchmark(size_t size_, int iterations_, bool csv_)
        : size(size_)
        , iterations(iterations_)
        , csv(csv_) {

        fill_ascending();
        array = &input[0];
    }

    void run_all() {
        if (csv) {
            printf("%lu, %d", size, iterations);
        } else {
            printf("input size %lu, iterations %d\n", size, iterations);
        }

        measure("scalar",
                [this]{return is_sorted(array, size);});
        measure("SSE (generic)",
                [this]{return is_sorted_sse_generic(array, size);});
        measure("SSE (generic, unrolled 4 times)",
                [this]{return is_sorted_sse_generic_unrolled4(array, size);});
        measure("SSE",
                [this]{return is_sorted_sse(array, size);});
        measure("SSE (unrolled 4 times)",
                [this]{return is_sorted_sse_unrolled4(array, size);});
#ifdef HAVE_AVX2
        measure("AVX2 (generic)",
                [this]{return is_sorted_avx2_generic(array, size);});
        measure("AVX2 (generic, unrolled 4 times)",
                [this]{return is_sorted_avx2_generic_unrolled4(array, size);});
        measure("AVX2",
                [this]{return is_sorted_avx2(array, size);});
        measure("AVX2 (unrolled 4 times)",
                [this]{return is_sorted_avx2_unrolled4(array, size);});
#endif // HAVE_AVX2
#ifdef HAVE_AVX512
        measure("AVX512 (generic)",
                [this]{return is_sorted_avx512_generic(array, size);});
        measure("AVX512",
                [this]{return is_sorted_avx512(array, size);});
#endif // HAVE_AVX512

        if (csv) {
            putchar('\n');
        }
    }

private:
    void fill_ascending() {
        input.reserve(size);
        for (size_t i=0; i < size; i++) {
            input[i] = i;
        }
    }

    template <typename FUN>
    void measure(const char* info, FUN fun) {
        if (!csv) {
            printf("%-40s : ", info);
            fflush(stdout);
        }

        const auto t = measure_total_time(fun, iterations);

        if (csv) {
            printf(", %lu", t);
        } else {
            printf("%6lu us\n", t);
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

    bool csv = false;
    for (int i=1; i < argc; i++) {
        const std::string arg(argv[i]);
        if ((arg == "csv") || (arg == "--csv")) {
            csv = true;
            break;
        }
    }

    const int iterations = (tmp > 0) ? tmp : 10;

    Benchmark b(size, iterations, csv);
    b.run_all();

    return EXIT_SUCCESS;
}
