#include <cstddef>
#include <cstdint>
#include <cassert>
#include <cstdlib>
#include <cstdio>
#include "functions.cpp"
#include "benchmark.h"

/*
    Algorithm:

          / fun1(x) if x < 0
      y = | fun2(x) if x >= 0 and x < 1.0
          \ fun3(x) otherwise

 */

#define _mm256_cmplt_ps(x, y) _mm256_cmp_ps((x), (y), _CMP_LT_OS)
#define _mm256_cmpge_ps(x, y) _mm256_cmp_ps((x), (y), _CMP_GE_OS)
#define _mm256_not_ps(x) _mm256_xor_ps((x), (__m256)_mm256_set1_epi32(-1))

void process1(const float* input, size_t size, float* output) {
    assert(size % 8 == 0);

    for (size_t i=0; i < size; i += 8) {

        const __m256 x = _mm256_loadu_ps(input + i);

        const __m256 mask1 = _mm256_cmplt_ps(x, _mm256_set1_ps(0.0)); // x < 0.0
        const __m256 mask2 = _mm256_cmplt_ps(x, _mm256_set1_ps(1.0)); // x < 1.0

        const __m256 y1 = fun1(x);
        const __m256 y2 = fun2(x);
        const __m256 y3 = fun3(x);

        // (mask1 & y1) | (~mask1 & ((mask2 & y2) | (~mask2 & y3)))
        const __m256 y23 = _mm256_blendv_ps(y3, y2, mask2);
        const __m256 y   = _mm256_blendv_ps(y23, y1, mask1);

        _mm256_storeu_ps(output + i, y);
    }
}


void process2(const float* input, size_t size, float* output) {
    assert(size % 8 == 0);

    for (size_t i=0; i < size; i += 8) {

        const __m256 x = _mm256_loadu_ps(input + i);

        const __m256 mask1 = _mm256_cmplt_ps(x, _mm256_set1_ps(0.0)); // x < 0.0
        const int mask1num = _mm256_movemask_ps(mask1);

        __m256 y = _mm256_setzero_ps();

        if (mask1num == 0xff) {
            _mm256_storeu_ps(output + i, fun1(x));
            continue;
        }

        if (mask1num != 0) {
            y = fun1(x);
        }

        const __m256 mask2 = _mm256_cmplt_ps(x, _mm256_set1_ps(1.0)); // x < 1.0
        const int mask2num = _mm256_movemask_ps(mask2);

        const int mask_fun2 =  mask2num & ~mask1num;
        if (mask_fun2 == 0xff) {
            _mm256_storeu_ps(output + i, fun2(x));
            continue;
        }

        const int mask_fun3 = ~mask2num & ~mask1num;
        if (mask_fun3 == 0xff) {
            _mm256_storeu_ps(output + i, fun3(x));
            continue;
        }

        if (mask_fun2 != 0) {
            const __m256 y2       = fun2(x);
            const __m256 y2masked = _mm256_and_ps(y2, _mm256_andnot_ps(mask1, mask2));
            y = _mm256_or_ps(y, y2masked);
        }

        if (mask_fun3 != 0) {
            const __m256 y3       = fun3(x);
            const __m256 y3masked = _mm256_and_ps(y3, _mm256_andnot_ps(mask1, _mm256_not_ps(mask2)));
            y = _mm256_or_ps(y, y3masked);
        }

        _mm256_storeu_ps(output + i, y);
    }
}


void process3(const float* input, size_t size, float* output) {
    assert(size % 8 == 0);

    for (size_t i=0; i < size; i += 8) {

        const __m256 x = _mm256_loadu_ps(input + i);

        const __m256 mask = _mm256_cmplt_ps(x, _mm256_set1_ps(0.0)); // x < 0.0
        if (_mm256_movemask_ps(mask) == 0)
            continue;

        const __m256 y = fun1(x);

        _mm256_storeu_ps(output + i, y);
    }

    for (size_t i=0; i < size; i += 8) {

        __m256 x = _mm256_loadu_ps(input + i);

        const __m256 mask1 = _mm256_cmplt_ps(x, _mm256_set1_ps(0.0)); // x < 0.0
        if (_mm256_movemask_ps(mask1) == 0xff)
            continue;

        const __m256 mask2 = _mm256_cmplt_ps(x, _mm256_set1_ps(1.0)); // x < 1.0
        if (_mm256_movemask_ps(mask2) == 0)
            continue;

        x = _mm256_loadu_ps(output + i);

        const __m256 y2 = fun2(x);
        const __m256 y  = _mm256_or_ps(x, _mm256_and_ps(y2, _mm256_andnot_ps(mask1, mask2)));

        _mm256_storeu_ps(output + i, y);
    }

    for (size_t i=0; i < size; i += 8) {

        __m256 x = _mm256_loadu_ps(input + i);

        const __m256 mask = _mm256_cmpge_ps(x, _mm256_set1_ps(1.0)); // x >= 1.0
        if (_mm256_movemask_ps(mask) == 0)
            continue;

        x = _mm256_loadu_ps(output + i);

        const __m256 y3 = fun3(x);
        const __m256 y  = _mm256_or_ps(x, _mm256_and_ps(y3, mask));

        _mm256_storeu_ps(output + i, y);
    }
}

void initialize(float* data, size_t size) {
    for (size_t i=0; i < size; i++) {
        data[i] = (float(rand()) / RAND_MAX - 0.5) * 100.0;
    }
}

int main(int argc, char* argv[]) {

    if (argc != 3) {
        printf("%s megabytes repeats\n", argv[0]);
        return EXIT_FAILURE;
    }

    const size_t megabytes = atoi(argv[1]);
    const size_t repeat    = atoi(argv[2]);

    printf("Input size %ld MB, repeat %ld times\n", megabytes, repeat);

    float* input;
    float* output;

    const size_t count = 1024 * 1024 * megabytes / sizeof(float);

    input  = (float*)malloc(sizeof(float) * count);
    output = (float*)malloc(sizeof(float) * count);

    srand(0);
    initialize(input, count);

    BEST_TIME(/**/, process1(input, count, output), "process1", repeat, count);
    BEST_TIME(/**/, process2(input, count, output), "process2", repeat, count);
    BEST_TIME(/**/, process3(input, count, output), "process3", repeat, count);

    return EXIT_SUCCESS;
}

