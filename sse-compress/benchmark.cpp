#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <immintrin.h>

#include "benchmark.h"

#include "scalar.cpp"
#include "simdutf.cpp"
#include "simdutf_ver2.cpp"

class Benchmark {
    std::vector<uint16_t> neg_masks;
    std::string input;
    std::string output;

public:
    Benchmark(size_t size) {
        for (size_t i=0; i < size; i++) {
            neg_masks.push_back(rand());
        }

        input.resize(size * 16);
        output.resize(size * 16);
    }

    void run() {
        benchmark("simdutf", simdutf_compress);
        benchmark("simdutf - variant 2", simdutf_compress2);
    }

private:
    template <typename Compress>
    void benchmark(const char* name, Compress compress) {
        volatile int sink = 0;

        auto fn = [this, compress, &sink]() {
            const size_t size = neg_masks.size();
            auto masks = neg_masks.data();
            auto in = input.data();
            auto out = input.data();
            for (size_t i=0; i < size; i++) {
                compress(masks[i], in + i * 16, out + i * 16);
            }
        };

        const size_t repeat = 1000;
        const size_t size = neg_masks.size();
        BEST_TIME(/**/, fn(), name, repeat, size);
    }
};


int main() {
    Benchmark bench{1024*1024};

    bench.run();

    return 0;
}
