#include <immintrin.h>

#include <cstdio>
#include <cstdint>
#include <cassert>


__m128i blend_epi32(__m128i cond, __m128i true_val, __m128i false_val) {
#if 0
    const __m128i t0 = _mm_and_si128(cond, true_val);
    const __m128i t1 = _mm_andnot_si128(cond, false_val);

    return _mm_or_si128(t0, t1);
#else
    return (__m128i)_mm_blendv_ps((__m128)false_val, (__m128)true_val, (__m128)cond);
#endif
}


__m128i lzcnt_epu32(__m128i x) {
    // 1. convert int to float
    const __m128  fp = _mm_cvtepi32_ps(x);

    // 2. get the exponent part and the sign bit
    const __m128i t0 = _mm_srli_epi32((__m128i)fp, 23);
    const int fp32bias = 127;
    const __m128i t1 = _mm_sub_epi32(_mm_set1_epi32(fp32bias + 31), t0);

    // 3. We need fixup negative numbers, i.e. the MSB set -- lzcnt is 0
    const __m128i msb_set = _mm_cmplt_epi32(x, _mm_set1_epi32(0));
    const __m128i t2 = blend_epi32(msb_set, _mm_set1_epi32(0), t1);

    // 4. there's also need for fixup for lzcnt(0) = 32
    const __m128i is_zero = _mm_cmpeq_epi32(_mm_set1_epi32(0), x);
    const __m128i t3 = blend_epi32(is_zero, _mm_set1_epi32(32), t2);

    return t3;
}


// --------------------------------------------------

int lzcnt_vec(uint32_t value) {
    const __m128i x = _mm_set1_epi32(value);
    const __m128i r = lzcnt_epu32(x);

    return _mm_extract_epi32(r, 0);
}

int lzcnt_scalar(uint32_t value) {
    if (value == 0)
        return 32;

    int result = 0;
    while ((value & 0x80000000) == 0) {
        result += 1;
        value <<= 1;
    }

    return result;
}

void test(uint32_t value) {
    const int vec = lzcnt_vec(value);
    const int ref = lzcnt_scalar(value);
    printf("lzcnt(%08x) = %d (ref = %d)\n", value, vec, ref);
    assert(vec == ref);
}

int main()
{
    test(0);
    test(1243);
    test(7612545);
    for (int i=0; i < 32; i++) {
        test(uint32_t(1) << i);
    }
}
