#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <chrono>
#include <limits>
#include <immintrin.h>

#include "scalar.c"
#include "sse-naive.c"
#include "sse-naive-unrolled.c"
#include "sse-dpps.c"
#include "sse-dpps-unrolled.c"

using Clock = std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::microseconds;

class TestCase {

    const size_t SIZE = 1024*1024*10;
    float* input1;
    float* input2;

public:
    TestCase() {
        input1 = new float[SIZE];
        input2 = new float[SIZE];
        for (size_t i=0; i < SIZE; i++) {
            input1[i] = get_random();
            input2[i] = get_random();
        }
    }

    ~TestCase() {
        delete[] input1;
        delete[] input2;
    }

    template <typename FUNCTION>
    void run(const char* name, FUNCTION fun) {
        const size_t ITERATIONS = 15;

        volatile float result = 0.0;
        Clock::rep best_time = std::numeric_limits<Clock::rep>::max();
        for (size_t i=0; i < ITERATIONS; i++) {
            const auto t1 = Clock::now();
            const float r = fun(input1, input2, SIZE);
            const auto t2 = Clock::now();
            result += r;

            const Clock::rep dt = duration_cast<microseconds>(t2 - t1).count();
            if (dt < best_time) {
                best_time = dt;
            }
        }

        printf("%-20s: %lu us (result = %0.5f)\n", name, best_time, result);
    }

private:
    float get_random() {
        return (rand()/float(RAND_MAX) - 0.5) * 1000;
    }
};


int main() {
    TestCase test;

    test.run("scalar",              scalar);
    test.run("SSE (naive)",         sse_naive);
    test.run("SSE (unrolled)",      sse_naive_unrolled);
    test.run("SSE (DPPS)",          sse_dpps);
    test.run("SSE (DPPS unrolled)", sse_dpps_unrolled);
}
