#include <immintrin.h>

bool is_sorted_avx512_generic(int32_t* a, size_t n) {

    size_t i = 0;
    if (n > 16) {
        for (/**/; i < n - 16; i += 16) {
            const __m512i curr = _mm512_loadu_si512(reinterpret_cast<const __m512i*>(a + i));
            const __m512i next = _mm512_loadu_si512(reinterpret_cast<const __m512i*>(a + i + 1));

            const __mmask16 mask = _mm512_cmpgt_epi32_mask(curr, next);
            if (mask != 0) {
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

