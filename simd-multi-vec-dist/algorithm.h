#pragma once

#include <cstdlib>

template <typename VEC_MULT_FUN>
void dist_vector_many(VEC_MULT_FUN function, size_t n, float const_vector[], size_t k, float* in[], float out[]) {

    for (size_t i=0; i < k; i++) {
        out[i] = function(n, in[i], const_vector);
    }
}
