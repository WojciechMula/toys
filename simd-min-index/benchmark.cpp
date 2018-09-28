#include <cstdio>
#include <vector>

#include "benchmark.h"
#include "all.cpp"

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
    }

private:
    template <typename FUN>
    void test(const char* name, FUN function) {

        const size_t repeat = 10000;
        const size_t size = input.size();

        BEST_TIME(/**/, function(&input[0], input.size(), &result), name, repeat, size);
    }

};

int main() {

    std::vector<size_t> sizes = {1024*4, 1024*16, 1024*32};

    for (size_t size: sizes) {
        printf("element count %d\n", size);
        Benchmark bench(size);
        bench.run();
    }

    return 0;
}
