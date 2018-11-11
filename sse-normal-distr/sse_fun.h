#pragma once

namespace sse_trig {

    __m128 sin_4terms(__m128 x) {
        // The Taylor's series for sin(x) is:
        // x - x^3/3! + x^5/5! - x^7/7! + x^9/9! 
        const __m128 coef3 = _mm_set1_ps(-1.0/6);
        const __m128 coef5 = _mm_set1_ps(+1.0/120);
        const __m128 coef7 = _mm_set1_ps(-1.0/5040);
        const __m128 coef9 = _mm_set1_ps(+1.0/362880);

        const __m128 x2 = _mm_mul_ps(x, x);
        const __m128 x3 = _mm_mul_ps(x, x2);
        const __m128 x5 = _mm_mul_ps(x2, x3);
        const __m128 x7 = _mm_mul_ps(x2, x5);
        const __m128 x9 = _mm_mul_ps(x2, x7);

        const __m128 t3 = _mm_mul_ps(x3, coef3);
        const __m128 t5 = _mm_mul_ps(x5, coef5);
        const __m128 t7 = _mm_mul_ps(x7, coef7);
        const __m128 t9 = _mm_mul_ps(x9, coef9);

        __m128 result = x;
        result = _mm_add_ps(result, t3);
        result = _mm_add_ps(result, t5);
        result = _mm_add_ps(result, t7);
        result = _mm_add_ps(result, t9);

        return result;
    }

    __m128 cos_4terms(__m128 x) {
        // The Taylor's series for sin(x) is:
        // x - x^2/2! + x^4/4! - x^6/6! + x^8/8!
        const __m128 coef2 = _mm_set1_ps(-1.0/2);
        const __m128 coef4 = _mm_set1_ps(+1.0/24);
        const __m128 coef6 = _mm_set1_ps(-1.0/720);
        const __m128 coef8 = _mm_set1_ps(+1.0/40320);

        const __m128 x2 = _mm_mul_ps(x, x);
        const __m128 x4 = _mm_mul_ps(x2, x2);
        const __m128 x6 = _mm_mul_ps(x2, x4);
        const __m128 x8 = _mm_mul_ps(x2, x6);

        const __m128 t2 = _mm_mul_ps(x2, coef2);
        const __m128 t4 = _mm_mul_ps(x4, coef4);
        const __m128 t6 = _mm_mul_ps(x6, coef6);
        const __m128 t8 = _mm_mul_ps(x8, coef8);

        __m128 result = x;
        result = _mm_add_ps(result, t2);
        result = _mm_add_ps(result, t4);
        result = _mm_add_ps(result, t6);
        result = _mm_add_ps(result, t8);

        return result;
    }

} // namespace sse_trig

namespace sse_math {

    __m128 log_4terms(__m128 x) {
        // The Taylor series:
        // (x - 1) - (x - 1)^2/2 + (x - 1)^3/3 - (x - 1)^4/4 + ...
        // x \in (0, 2]
        const __m128 xs = _mm_sub_ps(x, _mm_set1_ps(1.0f));

        const __m128 coef2 = _mm_set1_ps(-1.0/2);
        const __m128 coef3 = _mm_set1_ps(+1.0/3);
        const __m128 coef4 = _mm_set1_ps(-1.0/4);
        const __m128 coef5 = _mm_set1_ps(+1.0/5);

        const __m128 x2 = _mm_mul_ps(xs, xs);
        const __m128 x3 = _mm_mul_ps(xs, x2);
        const __m128 x4 = _mm_mul_ps(x2, x2);
        const __m128 x5 = _mm_mul_ps(xs, x4);

        const __m128 t2 = _mm_mul_ps(x2, coef2);
        const __m128 t3 = _mm_mul_ps(x3, coef3);
        const __m128 t4 = _mm_mul_ps(x4, coef4);
        const __m128 t5 = _mm_mul_ps(x5, coef5);

        __m128 result = xs;
        result = _mm_add_ps(result, t2);
        result = _mm_add_ps(result, t3);
        result = _mm_add_ps(result, t4);
        result = _mm_add_ps(result, t5);

        return result;
    }


} // namespace sse_math
