#include "sse_mult_vector_many.h"

#include <immintrin.h>
#include <cstdio>

void sse_mult_vector_many(size_t n, float const_vector[], size_t k, float* in[], float* out[]) {

    for (size_t j=0; j < k; j += 4) {

        float* in0 = in[j + 0];
        float* in1 = in[j + 1];
        float* in2 = in[j + 2];
        float* in3 = in[j + 3];

        float* out0 = out[j + 0];
        float* out1 = out[j + 1];
        float* out2 = out[j + 2];
        float* out3 = out[j + 3];

        for (size_t i=0; i < n; i += 4) {
            const __m128 vc = _mm_loadu_ps(const_vector + i);

            const __m128 x0 = _mm_loadu_ps(in0 + i);
            const __m128 x1 = _mm_loadu_ps(in1 + i);
            const __m128 x2 = _mm_loadu_ps(in2 + i);
            const __m128 x3 = _mm_loadu_ps(in3 + i);

            _mm_storeu_ps(out0 + i, _mm_mul_ps(x0, vc));
            _mm_storeu_ps(out1 + i, _mm_mul_ps(x1, vc));
            _mm_storeu_ps(out2 + i, _mm_mul_ps(x2, vc));
            _mm_storeu_ps(out3 + i, _mm_mul_ps(x3, vc));
        }
    }
}
