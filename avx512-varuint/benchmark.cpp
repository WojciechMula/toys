#include <cstdint>
#include <cstdio>
#include <vector>

#include "benchmark.h"

#include "sse_varuint.h"
#include "avx512vbmi2_varuint.h"


class Benchmark {

    std::vector<uint32_t> input;

    std::string input_sse;
    std::vector<uint32_t> output_sse;
    std::string input_avx512vbmi2;
    std::vector<uint32_t> output_avx512vbmi2;

public:
    Benchmark(size_t size) {
        input.resize(size);
        prepare_input();
        encode_for_sse();
        encode_for_avx512vbmi();
    }

    void run() {
        benchmark("SSE",
                  sse_unsafe_unpack,
                  input_sse,
                  &output_sse[0]);
        benchmark("AVX512VBMI2",
                  avx512vbmi2_unsafe_unpack16,
                  input_avx512vbmi2,
                  &output_avx512vbmi2[0]);
    }

private:
    template <typename FUN>
    void benchmark(const char* name, FUN unpack_fun, const std::string& buf, uint32_t* output) {
        const size_t size = input.size();
        constexpr size_t iterations = 100;
        BEST_TIME(/**/, unpack_fun(buf, size, output), name, iterations, size);
    }

    void prepare_input() {
        srand(42);
        for (size_t i=0; i < input.size(); i++) {
            const uint32_t v = rand();
            switch (rand() % 4) {
                case 0:
                    input[i] = v & 0xff;
                    break;
                case 1:
                    input[i] = v & 0xffff;
                    break;
                case 2:
                    input[i] = v & 0xffffff;
                    break;
                case 3:
                    input[i] = v;
                    break;
            }
        }

        constexpr size_t align = 512;
        size_t output_size = align * (input.size() + align - 1) / align;

        output_sse.resize(output_size);
        output_avx512vbmi2.resize(output_size);
    }

    void encode_for_sse() {
        PackedVarUintBuilder builder;
        for (const uint32_t v: input) {
            builder.add(v);
        }

        input_sse = builder.capture();
    }

    void encode_for_avx512vbmi() {
        Packed16VarUintBuilder builder;
        for (const uint32_t v: input) {
            builder.add(v);
        }

        input_avx512vbmi2 = builder.capture();
    }
};


int main() {
    const std::vector<size_t> sizes{100'000, 1'000'000, 10'000'000};

    for (const size_t size: sizes) {
        printf("Input size %ld\n", size);
        Benchmark bench{size};
        bench.run();
    }
}
