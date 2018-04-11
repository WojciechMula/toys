#include <immintrin.h>

bool is_sorted_avx2_generic(int32_t* a, size_t n) {

    if (n < 2) {
        return true;
    }

    size_t i = 0;
    if (n > 8) {
        for (/**/; i < n - 8; i += 8) {
            const __m256i curr = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(a + i));
            const __m256i next = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(a + i + 1));

            const __m256i mask = _mm256_cmpgt_epi32(curr, next);
            if (!_mm256_testz_si256(mask, mask)) {
                return false;
            }
        }
    }

    for (/**/; i < n - 1; i++) {
        if (a[i] > a[i + 1])
            return false;
    }

    return true;
}
