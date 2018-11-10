#include "scalar.h"
#include <cmath>

float scalar_dist_vectors(size_t n, float* a, float* b) {

    float ret = 0.0f;

    for (size_t i=0; i < n; i++) {
        const float d = a[i] - b[i];
        ret += d*d;
    }

    return ret;
}
