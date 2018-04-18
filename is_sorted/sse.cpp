#include <immintrin.h>

bool is_sorted_sse(int32_t* a, size_t n) {

    size_t i = 0;
    if (n >= 8) {
        __m128i chunk0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a));
        do {
            const __m128i chunk1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + i + 4));
            const __m128i curr = chunk0;
            const __m128i next = _mm_alignr_epi8(chunk1, chunk0, 4);

            const __m128i mask = _mm_cmpgt_epi32(curr, next);
            if (!_mm_test_all_zeros(mask, mask)) {
                return false;
            }

            chunk0 = chunk1;
            i += 4;
        } while (i < n - 4);
    }

    for (/**/; i + 1 < n; i++) {
        if (a[i] > a[i + 1])
            return false;
    }

    return true;
}
