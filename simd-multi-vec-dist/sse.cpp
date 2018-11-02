#include "sse.h"

#include <immintrin.h>

float sse_dist_vector(size_t n, float* a, float* b) {
    
    __m128 ret = _mm_setzero_ps();

    for (size_t i=0; i < n; i += 4) {
        
        const __m128 ai = _mm_loadu_ps(a + i);
        const __m128 bi = _mm_loadu_ps(b + i);

        const __m128 d  = _mm_sub_ps(ai, bi);
        const __m128 d2 = _mm_mul_ps(d, d);

        ret = _mm_add_ps(ret, d2);
    }

    float v[4];
    _mm_storeu_ps(v, ret);

    return v[0] + v[1] + v[2] + v[3];
}
