#include <vector>
#include <algorithm>
#include <random>
#include <cstdint>

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
    static constexpr size_t size = 65536;
    static constexpr size_t valid_heap_size = 256;
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
        bool all_ok = true;

        printf("Testing for input size from %lu to %lu\n", valid_heap_size, size);
        std::vector<Type> input_data = generate_random_data(size);
        std::make_heap(input_data.begin(), input_data.begin() + valid_heap_size);

        heap = input_data;
        all_ok = test("std::push_heap", push_heap_std_wrapper) and all_ok;

        heap = input_data;
        all_ok = test("scalar push_heap", push_heap_scalar_wrapper) and all_ok;

#ifdef HAVE_AVX2
        heap = input_data;
        all_ok = test("AVX2 push_heap", push_heap_avx2) and all_ok;
#endif

#ifdef HAVE_AVX512
        heap = input_data;
        all_ok = test("AVX512 push_heap", push_heap_avx512) and all_ok;
#endif

        return all_ok;
    }

private:
    template <typename Function>
    bool test(const std::string& name, Function function) {
        printf("%s... ", name.c_str()); fflush(stdout);

        for (size_t i=valid_heap_size; i <= heap.size(); i++) {
            function(heap.data(), i);
            const bool is_heap = std::is_heap(heap.data(), heap.data() + i);
            if (!is_heap) {
                printf("failed at %ld\n", i);
                return false;
            }
        }

        puts("OK");
        return true;
    }

    std::vector<Type> generate_random_data(size_t size) {
        std::random_device rd;
        std::mt19937 eng(rd());
        eng.seed(0);

        std::uniform_int_distribution<Type> random(0, 0x7ff'ffff);

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
