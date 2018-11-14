#include "algorithm.h"
#include "all.h"

#include "benchmark.h"

#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cassert>


class Test {

    const size_t size;
    const size_t count;

    const size_t iterations = 100;

    float** input;
    float*  output;
    float*  const_vector;

public:
    Test(size_t size_, size_t count_) : size(size_), count(count_) {

        assert(size  % 64 == 0);
        assert(count %  4 == 0);

        input = new float*[count];
        for (size_t i=0; i < count; i++) {
            input[i] = new float[size];
            initialize_vector(input[i]);
        }

        output = new float[count];
        const_vector = new float[size];
        initialize_vector(const_vector);
    }

    ~Test() {
        for (size_t i=0; i < count; i++) {
            delete[] input[i];
        }

        delete[] input;
        delete[] output;
        delete[] const_vector;
    }

    void run() {

        test_scalar("scalar", scalar_dist_vectors);
        test_scalar("SSE",    sse_dist_vector);

        test("SSE (custom)",  sse_dist_vector_many);
    }

private:
    void initialize_vector(float* v) {
        for (size_t i=0; i < size; i++) {
            v[i] = (rand() % 1000)/1000.0 - 0.5;
        }
    }

    template <typename FUNCTION>
    void test_scalar(const char* name, FUNCTION function) {
        
        auto fn = [this, function]() {
            dist_vector_many(function, size, const_vector, count, input, output);
        };

        BEST_TIME(/**/, fn(), name, iterations, size);
    }

    template <typename FUNCTION>
    void test(const char* name, FUNCTION dist_vector_many) {
        
        auto fn = [this, dist_vector_many]() {
            dist_vector_many(size, const_vector, count, input, output);
        };

        BEST_TIME(/**/, fn(), name, iterations, size);
    }
};

int main() {
 
    size_t vector_count[] = {8, 16, 32, 64, 128, 256};
    size_t vector_size[] = {64, 128, 256, 512, 1024, 1024*4, 1024*8};

    for (size_t count: vector_count) {
        for (size_t size: vector_size) {
            printf("vector size=%lu, count=%lu\n", size, count);
            Test test(size, count);

            test.run();
        }
    }

    return EXIT_SUCCESS;
}
