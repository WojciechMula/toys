#include "sse_dist_vector_many.h"

#include <immintrin.h>
#include <cstdio>

void sse_dist_vector_many(size_t n, float const_vector[], size_t k, float* in[], float out[]) {

    for (size_t j=0; j < k; j += 4) {

        float* in0 = in[j + 0];
        float* in1 = in[j + 1];
        float* in2 = in[j + 2];
        float* in3 = in[j + 3];

        __m128 out0 = _mm_setzero_ps();
        __m128 out1 = _mm_setzero_ps();
        __m128 out2 = _mm_setzero_ps();
        __m128 out3 = _mm_setzero_ps();

        for (size_t i=0; i < n; i += 4) {
            const __m128 vc = _mm_loadu_ps(const_vector + i);

            const __m128 x0 = _mm_loadu_ps(in0 + i);
            const __m128 x1 = _mm_loadu_ps(in1 + i);
            const __m128 x2 = _mm_loadu_ps(in2 + i);
            const __m128 x3 = _mm_loadu_ps(in3 + i);

            const __m128 d0   = _mm_sub_ps(x0, vc);
            const __m128 d0_2 = _mm_mul_ps(d0, d0);
            const __m128 d1   = _mm_sub_ps(x1, vc);
            const __m128 d1_2 = _mm_mul_ps(d1, d1);
            const __m128 d2   = _mm_sub_ps(x2, vc);
            const __m128 d2_2 = _mm_mul_ps(d2, d2);
            const __m128 d3   = _mm_sub_ps(x3, vc);
            const __m128 d3_2 = _mm_mul_ps(d3, d3);

            out0 = _mm_add_ps(out0, d0_2);
            out1 = _mm_add_ps(out1, d1_2);
            out2 = _mm_add_ps(out2, d2_2);
            out3 = _mm_add_ps(out3, d3_2);
        }

        float v[4];

        _mm_storeu_ps(v, out0);
        out[j + 0] = v[0] + v[1] + v[2] + v[3];

        _mm_storeu_ps(v, out1);
        out[j + 1] = v[0] + v[1] + v[2] + v[3];

        _mm_storeu_ps(v, out2);
        out[j + 2] = v[0] + v[1] + v[2] + v[3];

        _mm_storeu_ps(v, out3);
        out[j + 3] = v[0] + v[1] + v[2] + v[3];
    }
}
