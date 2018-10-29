#include <cstdio>

#include "benchmark.h"
#include "all.cpp"

class Benchmark {
    uint8_t in[64];
    uint8_t out[64];

public:
    Benchmark() {
        for (int i=0; i < 64; i++) {
            in[i] = zigzag_reference[i];
        }
    }

public:
    void run() {
        test("scalar",              jpeg_zigzag_scalar);
        test("scalar (unrolled)",   jpeg_zigzag_scalar_unrolled4);
        test("SSE",                 jpeg_zigzag_sse);
#ifdef HAVE_AVX512BW
        test("AVX512BW",            jpeg_zigzag_avx512bw);
        test("AVX512BW (masks)",    jpeg_zigzag_avx512bw_masks);
        test("AVX512BW (perm16)",   jpeg_zigzag_avx512bw_permute16);
#endif
#ifdef HAVE_AVX512VBMI
        test("AVX512VBMI",  jpeg_zigzag_avx512vbmi);
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
