#include "binary_search.h"

#include <algorithm>

float binary_search(float x, float* x_boundary, float* a, float* b) {
    // 1. find sub-function index
    float* begin = x_boundary;
    float* end = x_boundary + 7;
    float* pos = std::upper_bound(begin, end, x);

    int index;
    if (pos != end) {
        index = pos - begin;
    } else {
        index = 7;
    }

    // 2. evaluate linear function
    return a[index] * x + b[index];
}

