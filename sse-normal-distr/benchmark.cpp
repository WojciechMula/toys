#include <cstdio>
#include <cstdlib>

#include <vector>
#include <string>
#include <numeric>

#include "benchmark.h"

#include "noop.h"
#include "scalar.h"
#include "sse.h"

// --------------------------------------------------------------------------------

struct StdRand {
    float operator()() const {
        return rand() % 10000;
    }
};

class Benchmark {
protected:
    std::vector<float> output;
    volatile float sink;

protected:
    StdRand random;

public:
    Benchmark(size_t size) : output(size) {}

public:
    void run() {
        {
            auto function = [this]() {
                noop(random, output.size(), &output[0]);
            };

            test("no-op", function);
        }
        {
            auto function = [this]() {
                scalar_normal_distr(random, output.size(), &output[0]);
            };

            test("scalar (naive)", function);
        }
        {
            auto function = [this]() {
                scalar_normal_distr_sin_cos(random, output.size(), &output[0]);
            };

            test("scalar (sincos)", function);
        }
        {
            auto function = [this]() {
                sse_normal_distr_boxmuller(random, output.size(), &output[0]);
            };

            test("SSE (Box-Muller)", function);
        }
        {
            auto function = [this]() {
                sse_normal_distr_boxmuller_variant2(random, output.size(), &output[0]);
            };

            test("SSE (Box-Muller, v2)", function);
        }
        {
            auto function = [this]() {
                sse_normal_distr_boxmuller_variant3(random, output.size(), &output[0]);
            };

            test("SSE (Box-Muller, v3)", function);
        }
    }

protected:
    template <typename T>
    void test(const char* name, T function) {
        BEST_TIME(/**/, function(), name, 100, output.size());
        sink = std::accumulate(output.begin(), output.end(), 0.0f);
    }
};

// --------------------------------------------------------------------------------

int main() {
    
    for (size_t size: {1024, 1024*4, 1024*8, 1024*16}) {
        printf("size %lu\n", size);
        Benchmark test(size);
        test.run();
    }
}
