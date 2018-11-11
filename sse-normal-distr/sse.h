#pragma once

#include <cstdlib>
#include <immintrin.h>

#include "sse_fun.h"

template <typename Random>
void sse_normal_distr_boxmuller(Random random, size_t size, float* output) {
    for (size_t i=0; i < size; i += 8) {
        const float a0 = random();
        const float b0 = random();
        const float a1 = random();
        const float b1 = random();
        const float a2 = random();
        const float b2 = random();
        const float a3 = random();
        const float b3 = random();

        const __m128 r1 = _mm_set_ps(a0, a1, a2, a3);
        const __m128 A  = _mm_mul_ps(r1, _mm_set1_ps(2 * M_PI));

        const __m128 r2 = _mm_set_ps(b0, b1, b2, b3);
        __m128 B = sse_math::log_4terms(r2);
        B = _mm_mul_ps(_mm_set1_ps(-2.0f), B);
        B = _mm_sqrt_ps(B);

        const __m128 sinA = sse_trig::sin_4terms(A);
        const __m128 cosA = sse_trig::cos_4terms(A);

        const __m128 V1 = _mm_mul_ps(B, sinA);
        const __m128 V2 = _mm_mul_ps(B, cosA);

        _mm_storeu_ps((output + i + 0*4), V1);
        _mm_storeu_ps((output + i + 1*4), V2);
    }
}


