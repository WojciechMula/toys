#include "sse.h"

#include <immintrin.h>

void sse_mult_vector(size_t n, float* a, float* b, float* out) {
    
    for (size_t i=0; i < n; i += 4) {
        
        const __m128 ai = _mm_loadu_ps(a + i);
        const __m128 bi = _mm_loadu_ps(b + i);

        const __m128 v = _mm_mul_ps(ai, bi);

        _mm_storeu_ps(out + i, v);
    }
}
