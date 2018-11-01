#include "scalar.h"

void scalar_mult_vectors(size_t n, float* a, float* b, float* out) {
    for (size_t i=0; i < n; i++) {
        out[i] = a[i] * b[i];
    }
}
