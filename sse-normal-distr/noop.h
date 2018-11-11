#pragma once

#include <cmath>

template <typename Random>
void noop(Random random, size_t size, float* output) {
    for (size_t i=0; i < size; i += 2) {
        output[i + 0] = random();
        output[i + 1] = random();
    }
}

