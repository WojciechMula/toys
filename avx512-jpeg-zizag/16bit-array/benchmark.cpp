#include <cstdio>

#include "benchmark.h"
#include "all.cpp"

class Benchmark {
    uint16_t in[64];
    uint16_t out[64];

public:
    Benchmark() {
        for (int i=0; i < 64; i++) {
            in[i] = zigzag_reference[i];
        }
    }

public:
    void run() {
        test("scalar",              jpeg_zigzag_scalar);
        test("SSE",                 jpeg_zigzag_sse);
        test("SSE (copy single)",   jpeg_zigzag_sse_copy_single);
#ifdef HAVE_AVX512F
        test("AVX512F",             jpeg_zigzag_avx512f);
#endif
#ifdef HAVE_AVX512BW
        test("AVX512BW",            jpeg_zigzag_avx512bw);
#endif
    }

private:
    template <typename FUN>
    void test(const char* name, FUN jpeg_zigzag_fun) {

        const size_t repeat = 1000000;
        const size_t size = 1;

        BEST_TIME(/**/, jpeg_zigzag_fun(in, out), name, repeat, size);
    }

};

int main() {

    Benchmark bench;
    bench.run();

    return 0;
}
