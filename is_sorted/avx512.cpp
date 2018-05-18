#include <immintrin.h>

bool is_sorted_avx512(int32_t* a, size_t n) {

    static const __m512i shuffle_pattern = _mm512_setr_epi32(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 15);

    size_t i = 0;
    while (i < n - 16) {
        const __m512i curr = _mm512_loadu_si512(reinterpret_cast<const __m512i*>(a + i));
        const __m512i next = _mm512_permutexvar_epi32(shuffle_pattern, curr);

        const __mmask16 mask = _mm512_cmpgt_epi32_mask(curr, next);
        if (mask != 0) {
            return false;
        }

        i += 15;
    }

    for (/**/; i + 1 < n; i++) {
        if (a[i] > a[i + 1])
            return false;
    }

    return true;
}

