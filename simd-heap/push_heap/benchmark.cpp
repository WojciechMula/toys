#include <vector>
#include <algorithm>
#include <random>
#include <cstdint>

#include "benchmark.h"
#include "push_heap.h"

#ifdef HAVE_AVX2
#   include "push_heap_avx2.h"
#endif

#ifdef HAVE_AVX512
#   include "push_heap_avx512.h"
#endif


using Type = int32_t;

namespace {
    void push_heap_std_wrapper(Type* start, size_t size) {
        std::push_heap(start, start + size);
    }

    void push_heap_scalar_wrapper(Type* start, size_t size) {
        push_heap_scalar(start, start + size, std::less<Type>());
    }
}

class Application {

    const size_t repeat = 1000;

    const size_t size = 65535;
    const size_t valid_heap_size = 256;
    std::vector<Type> heap;

public:
    Application() {
#ifdef HAVE_AVX2
        push_heap_avx2_setup();
#endif
#ifdef HAVE_AVX512
        push_heap_avx512_setup();
#endif
    }

    bool run() {
        std::vector<Type> input_data = generate_random_data(size);
        std::make_heap(input_data.begin(), input_data.begin() + valid_heap_size);

        heap = input_data;
        benchmark("std::push_heap", push_heap_std_wrapper);

        heap = input_data;
        benchmark("scalar push_heap", push_heap_scalar_wrapper);

#ifdef HAVE_AVX2
        heap = input_data;
        benchmark("AVX2 push_heap", push_heap_avx2);
#endif

#ifdef HAVE_AVX512
        heap = input_data;
        benchmark("AVX512 push_heap", push_heap_avx512);
#endif

        return true;
    }

private:
    template <typename Function>
    void benchmark(const std::string& name, Function function) {

        auto wrapper = [this, function]() {
            for (size_t i=valid_heap_size; i <= heap.size(); i++)
                function(heap.data(), i);
        };

        BEST_TIME(/**/, wrapper(), name.c_str(), repeat, valid_heap_size);

        const bool is_heap = std::is_heap(heap.data(), heap.data() + heap.size());
        printf("%s: %s\n", name.c_str(), (is_heap) ? "OK" : "failed");
    }

    std::vector<Type> generate_random_data(size_t size) {
        std::random_device rd;
        std::mt19937 eng(rd());
        eng.seed(0);

        std::uniform_int_distribution<Type> random(0, 0x7fffffff);

        std::vector<Type> heap;
        heap.reserve(size);
        for (size_t i=0; i < size; i++) {
            heap.push_back(random(eng));
        }

        return heap;
    }
};

int main() {
    Application app{};

    return app.run() ? EXIT_SUCCESS : EXIT_FAILURE;
}

