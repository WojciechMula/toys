#include <algorithm>
#include <random>
#include <cstdint>

#include "is_heap_scalar.h"
#include "is_heap_sse.cpp"
#include "is_heap_avx2.cpp"

using Type = int32_t;

    bool is_heap_fwd_wrapper(const Type* begin, const Type* end) {
        return is_heap_fwd(begin, end, std::less<Type>());
    }

    bool is_heap_rnd_wrapper(const Type* begin, const Type* end) {
        return is_heap_rnd(begin, end, std::less<Type>());
    }

class Application {

    std::vector<size_t> test_sizes;
    std::vector<Type> heap;

public:
    Application(std::vector<size_t> test_sizes)
     : test_sizes(std::move(test_sizes)) {}

    bool run() {
        bool all_ok = true;
        for (size_t size: test_sizes) {
            
            bool ok = true;
            
            printf("Testing for input size %lu... ", size); fflush(stdout);
            prepare_input_data(size);

            // test a valid heap
            const bool reference = std::is_heap(heap.cbegin(), heap.cend());
            ok = test("is_heap_fwd", is_heap_fwd_wrapper, reference) and ok;

            // test non-heap sequences
            auto copy = heap;
            for (size_t i=0; i < size; i++) {
                heap = copy;
                heap[i] = -1;

                const bool reference = std::is_heap(heap.cbegin(), heap.cend());
                ok = test("is_heap_fwd", is_heap_fwd_wrapper, reference) and ok;
                ok = test("is_heap_rnd", is_heap_rnd_wrapper, reference) and ok;
                ok = test("SSE",         is_heap_sse_epi32, reference) and ok;
                ok = test("AVX2",        is_heap_avx2_epi32, reference) and ok;
            }

            if (ok)
                puts("OK");
            else
                all_ok = false;
        }

        return all_ok;
    }

private:
    template <typename Function>
    bool test(const std::string& name, Function function, bool reference) const {
        const bool result = function(heap.data(), heap.data() + heap.size());
        if (result != reference) {
            printf("%s failed: result=%d reference=%d\n", name.c_str(), result, reference);
            return false;
        }
        else {
            return true;
        }
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
