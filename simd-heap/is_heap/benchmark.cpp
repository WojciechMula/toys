#include <algorithm>
#include <random>
#include <cstdint>

#include "benchmark.h"

#include "is_heap_scalar.h"
#include "is_heap_sse.cpp"
#include "is_heap_avx2.cpp"

using Type = int32_t;

bool is_heap_std_wrapper(const Type* begin, const Type* end) {
    return std::is_heap(begin, end);
}

bool is_heap_fwd_wrapper(const Type* begin, const Type* end) {
    return is_heap_fwd(begin, end, std::less<Type>());
}

bool is_heap_rnd_wrapper(const Type* begin, const Type* end) {
    return is_heap_rnd(begin, end, std::less<Type>());
}


class Application {

    const size_t repeat = 1000;
    std::vector<size_t> test_sizes;
    std::vector<Type> heap;
    volatile bool result;

public:
    Application(std::vector<size_t> test_sizes)
     : test_sizes(std::move(test_sizes)) {}

    bool run() {
        for (size_t size: test_sizes) {
      
            printf("Input size %lu\n", size);
            prepare_input_data(size);

            benchmark("std",        is_heap_std_wrapper);
            benchmark("fwd scalar", is_heap_fwd_wrapper);
            benchmark("rnd scalar", is_heap_rnd_wrapper);
            benchmark("fwd SSE",    is_heap_sse_epi32);
            benchmark("fwd AVX2",   is_heap_avx2_epi32);
        }

        return true;
    }

private:
    template <typename Function>
    void benchmark(const std::string& name, Function function) {
        const size_t size = heap.size();
        const Type* begin = heap.data();
        const Type* end   = begin + size;
        BEST_TIME(/**/, result=function(begin, end), name.c_str(), repeat, size);
    }

    void prepare_input_data(size_t size) {
        std::random_device rd;
        std::mt19937 eng(rd());
        eng.seed(0);

        std::uniform_int_distribution<Type> random(0, 10'000);

        heap.clear();
        heap.reserve(size);
        for (size_t i=0; i < size; i++)
            heap.push_back(random(eng));

        std::make_heap(heap.begin(), heap.end());
    }
};

std::vector<size_t> parse_args(int argc, char* argv[]);

int main(int argc, char* argv[]) {
    std::vector<size_t> sizes;
    try {
        sizes = parse_args(argc, argv);
    } catch (const std::exception& e) {
        printf("%s\n", e.what());
        return EXIT_FAILURE;
    }

    Application app{sizes};

    return app.run() ? EXIT_SUCCESS : EXIT_FAILURE;
}

std::vector<size_t> parse_args(int argc, char* argv[]) {
    std::vector<size_t> sizes;
    for (int i=1; i < argc; i++) {
        const long tmp = atol(argv[i]);
        if (tmp <= 0) {
            printf("Dropping %ld\n", tmp);
        }
        sizes.push_back(tmp);
    }

    if (sizes.empty())
        sizes.push_back(1024);

    return sizes;
}

