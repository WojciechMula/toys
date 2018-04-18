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
