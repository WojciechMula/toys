#include <cstdlib>
#include <vector>

#include "time_utils.h"
#include "lcm.h"
#include "sse_variant1.cpp"
#include "sse_variant2.cpp"


class Benchmark {
 
    const size_t size;
    const size_t iterations;
    std::vector<uint32_t> output;

    uint32_t seed;
    __m128i sse_seed;

public:
    Benchmark(size_t size, size_t iterations)
        : size{size}
        , iterations{iterations}
        , seed{12345} {

        sse_seed = _mm_set1_epi32(seed);
        output.resize(size);
    }

    void run_all() {
        measure_total_time("scalar: ", [this](){return test_lcm();}, iterations);
        measure_total_time("SSE:    ", [this](){return test_sse_variant1();}, iterations);
        measure_total_time("SSE(2): ", [this](){return test_sse_variant2();}, iterations);
    }

private:
    uint32_t test_lcm() {
        for (size_t i=0; i < size; i++) {
            seed = rnd::scalar(seed);

            // consume result: 1 number
            output[i] = seed;
        }

        return output.size();
    }

    uint32_t test_sse_variant1() {
        uint32_t tmp[4];
        for (size_t i=0; i < size; i += 4) {
            sse_seed = rnd::sse_variant1(sse_seed);

            // consume output: 4 numbers
            _mm_store_si128((__m128i*)tmp, sse_seed);
            output[i + 0] = tmp[0];
            output[i + 1] = tmp[1];
            output[i + 2] = tmp[2];
            output[i + 3] = tmp[3];
        }

        return output.size();
    }

    uint32_t test_sse_variant2() {
        uint32_t tmp[4];
        for (size_t i=0; i < size; i += 5) {
            rnd::sse_variant2(sse_seed, seed);

            // consume output: 5 numbers
            _mm_store_si128((__m128i*)tmp, sse_seed);
            output[i + 0] = tmp[0];
            output[i + 1] = tmp[1];
            output[i + 2] = tmp[2];
            output[i + 3] = tmp[3];
            output[i + 4] = seed;
        }

        return output.size();
    }
};

int main(int argc, char* argv[]) {

    int tmp;

    tmp = 0;
    if (argc > 1) {
        tmp = atoi(argv[1]);
    }

    const size_t size = (tmp > 0) ? tmp : 1024;

    tmp = 0;
    if (argc > 2) {
        tmp = atoi(argv[2]);
    }

    const int iterations = (tmp > 0) ? tmp : 10;

    Benchmark b(size, iterations);
    b.run_all();

    return EXIT_SUCCESS;
}
