#include <cstdio>
#include <vector>

#include "benchmark.h"
#include "all.h"

class Benchmark {
    std::vector<int32_t> input;
    size_t result;

public:
    Benchmark(size_t size) : input(size) {}

public:
    void run() {
        test("scalar",       min_index_scalar);
        test("SSE",          min_index_sse);
        test("SSE unrolled", min_index_sse_unrolled);
#ifdef HAVE_AVX2
        test("AVX2",         min_index_avx2);
#endif
#ifdef HAVE_AVX512
        test("AVX512F",      min_index_avx512f);
#endif
    }

private:
    template <typename FUN>
    void test(const char* name, FUN function) {

        const size_t repeat = 10000;
        const size_t size = input.size();

        auto wrapper = [this, function]() {
            result = function(&input[0], input.size());
        };

        BEST_TIME(/**/, wrapper(), name, repeat, size);
    }

};

int main() {

    std::vector<size_t> sizes = {1024*4, 1024*16, 1024*32};

    for (size_t size: sizes) {
        printf("element count %lu\n", size);
        Benchmark bench(size);
        bench.run();
    }

    return 0;
}
