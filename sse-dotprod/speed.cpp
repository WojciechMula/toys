#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <sys/time.h>
#include <immintrin.h>

#include "scalar.c"
#include "sse-naive.c"
#include "sse-naive-unrolled.c"
#include "sse-dpps.c"

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
        uint32_t best_time = UINT32_MAX;
        for (size_t i=0; i < ITERATIONS; i++) {
            const uint32_t t1 = get_time();
            const float r = fun(input1, input2, SIZE);
            const uint32_t t2 = get_time();
            result += r;

            const uint32_t dt = t2 - t1;
            if (dt < best_time) {
                best_time = dt;
            }
        }

        printf("%-20s: %d ms (result = %0.5f)\n", name, best_time, result);
    }

private:
    float get_random() {
        return (rand()/float(RAND_MAX) - 0.5) * 1000;
    }

    uint32_t get_time(void) {
        static struct timeval T;
        gettimeofday(&T, NULL);

        return (T.tv_sec * 1000000) + T.tv_usec;
    }
    
};


int main() {
    TestCase test;

    test.run("scalar",          scalar);
    test.run("SSE (naive)",     sse_naive);
    test.run("SSE (unrolled)",  sse_naive_unrolled);
    test.run("SSE (DPPS)",      sse_dpps);
}
