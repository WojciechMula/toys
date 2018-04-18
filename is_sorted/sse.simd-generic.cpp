#include <immintrin.h>

bool is_sorted_sse_generic(int32_t* a, size_t n) {

    size_t i = 0;
    if (n > 4) {
        for (/**/; i < n - 4; i += 4) {
            const __m128i curr = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + i));
            const __m128i next = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + i + 1));

            const __m128i mask = _mm_cmpgt_epi32(curr, next);
            if (!_mm_test_all_zeros(mask, mask)) {
                return false;
            }
        }
    }

    for (/**/; i + 1 < n; i++) {
        if (a[i] > a[i + 1])
            return false;
    }

    return true;
}


bool is_sorted_sse_generic_unrolled4(int32_t* a, size_t n) {

    size_t i = 0;
    if (n > 4*4) {
        for (/**/; i < n - 4*4; i += 4*4) {
            const __m128i curr0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + 0*4 + i));
            const __m128i curr1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + 1*4 + i));
            const __m128i curr2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + 2*4 + i));
            const __m128i curr3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + 3*4 + i));
            const __m128i next0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + 0*4 + i + 1));
            const __m128i next1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + 1*4 + i + 1));
            const __m128i next2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + 2*4 + i + 1));
            const __m128i next3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + 3*4 + i + 1));

            const __m128i mask0 = _mm_cmpgt_epi32(curr0, next0);
            const __m128i mask1 = _mm_cmpgt_epi32(curr1, next1);
            const __m128i mask2 = _mm_cmpgt_epi32(curr2, next2);
            const __m128i mask3 = _mm_cmpgt_epi32(curr3, next3);
            const __m128i mask  = _mm_or_si128(mask0,
                                  _mm_or_si128(mask1,
                                  _mm_or_si128(mask2, mask3)));

            if (!_mm_test_all_zeros(mask, mask)) {
                return false;
            }
        }
    }

    for (/**/; i + 1 < n; i++) {
        if (a[i] > a[i + 1])
            return false;
    }

    return true;
}
