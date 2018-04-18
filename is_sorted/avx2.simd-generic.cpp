#include <immintrin.h>

bool is_sorted_avx2_generic(int32_t* a, size_t n) {

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

    for (/**/; i + 1 < n; i++) {
        if (a[i] > a[i + 1])
            return false;
    }

    return true;
}

bool is_sorted_avx2_generic_unrolled4(int32_t* a, size_t n) {

    size_t i = 0;
    if (n > 8*4) {
        for (/**/; i < n - 8*4; i += 8*4) {
            const __m256i curr0 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(a + 0*8 + i));
            const __m256i curr1 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(a + 1*8 + i));
            const __m256i curr2 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(a + 2*8 + i));
            const __m256i curr3 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(a + 3*8 + i));

            const __m256i next0 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(a + 0*8 + i + 1));
            const __m256i next1 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(a + 1*8 + i + 1));
            const __m256i next2 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(a + 2*8 + i + 1));
            const __m256i next3 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(a + 3*8 + i + 1));

            const __m256i mask0 = _mm256_cmpgt_epi32(curr0, next0);
            const __m256i mask1 = _mm256_cmpgt_epi32(curr1, next1);
            const __m256i mask2 = _mm256_cmpgt_epi32(curr2, next2);
            const __m256i mask3 = _mm256_cmpgt_epi32(curr3, next3);

            const __m256i mask = _mm256_or_si256(mask0, 
                                 _mm256_or_si256(mask1, 
                                 _mm256_or_si256(mask2, mask3)));

            if (!_mm256_testz_si256(mask, mask)) {
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
