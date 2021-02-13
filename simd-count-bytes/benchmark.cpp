#include <cstdio>

#include "benchmark.h"
#include "all.h"

class Benchamark {

    static const size_t size = 1024 * 4;
    uint8_t table[size];

public:
    void run() {
        
        const size_t repeat = 10000;

#define RUN(name, procedure) \
    BEST_TIME(/**/, procedure((const uint8_t*)table, size, 42), name, repeat, size);

        RUN("scalar",               scalar_count_bytes);
#ifdef HAVE_SSE
        RUN("SSE",                  sse_count_byte);
        RUN("SSE (popcount)",       sse_count_byte_popcount);
#endif
#ifdef HAVE_AVX2
        RUN("AVX2",                 avx2_count_byte);
        RUN("AVX2 (popcount)",      avx2_count_byte_popcount);
#endif
#ifdef HAVE_AVX512BW
        RUN("AVX512BW",             avx512bw_count_bytes);
        RUN("AVX512BW (unrolled)",  avx512bw_count_bytes_unrolled);
        RUN("AVX512BW (version 2)", avx512bw_count_bytes__version2);
#endif
    }

};

int main() {

    Benchamark bench;
    bench.run();
}
