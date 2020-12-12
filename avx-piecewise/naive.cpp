#include "naive.h"

float naive(float x, float* x_boudary, float* a, float* b) {
    // 1. find sub-function index
    int index=0;
    for (int i=0; i < 7; i++) {
        if (x >= x_boudary[i])
            index = i + 1;
    }

    // 2. evaluate linear function
    return a[index] * x + b[index];
}
