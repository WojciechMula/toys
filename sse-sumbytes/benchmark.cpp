#include <cstdio>
#include <vector>

#include "benchmark.h"
#include "all.h"

class Benchmark {
    
    std::vector<uint8_t> input;
    size_t result;

public:
    Benchmark(size_t size) : input(size) {}

public:
    void run() {
        test("scalar",                   scalar_sumbytes);
        test("scalar (C++)",             scalar_cpp_sumbytes);
        test("SSE",                      sse_sumbytes);
        test("SSE (v2)",                 sse_sumbytes_variant2);
        test("SSE (sadbw)",              sse_sadbw_sumbytes);
        test("SSE (sadbw 4 x unrolled)", sse_sadbw_sumbytes);
        test("SSE (16bit accu)",         sse_16bit_sumbytes);
        test("SSE (16bit accu, v2)",     sse_16bit_sumbytes_variant2);
        test("SSE (16bit accu, v2, unrl",
                                         sse_16bit_sumbytes_variant2_unrolled4);
        test("SSE (8bit accu)",          sse_8bit_sumbytes);
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
