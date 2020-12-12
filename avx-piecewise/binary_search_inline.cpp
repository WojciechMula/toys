#include "binary_search_inline.h"

float binary_search_inline(float x, float* x_boundary, float* a, float* b) {
    // 1. find the range (precomputed binary tree search)
    int index = 0;

    if (x < x_boundary[3]) {
        if (x < x_boundary[1]) {
            if (x < x_boundary[0])
                index = 0;
            else
                index = 1;
        } else {
            if (x < x_boundary[2])
                index = 2;
            else
                index = 3;
        }
    }
    else {
        if (x < x_boundary[5]) {
            if (x < x_boundary[4])
                index = 4;
            else
                index = 5;
        } else {
            if (x < x_boundary[6])
                index = 6;
            else
                index = 7;
        }
    }

    // 2. evaluate
    return a[index] * x + b[index];
}
