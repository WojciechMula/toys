#include <immintrin.h>

bool is_sorted_avx2(int32_t* a, size_t n) {

    const __m256i shuffle_pattern = _mm256_setr_epi32(1, 2, 3, 4, 5, 6, 7, 7);

    size_t i = 0;
    while (i < n - 8) {
        // curr = [ a0 | a1 | a2 | a3 | a4 | a5 | a6 | a7 ]
        const __m256i curr = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(a + i));
        // next = [ a1 | a2 | a3 | a4 | a5 | a6 | a7 | a7 ]
        const __m256i next = _mm256_permutevar8x32_epi32(curr, shuffle_pattern);

        // Note: the last element of curr and next is a7, thus for this element 
        //       the comparison result is always zero.
        //
        // In fact, the first 7 elements are being tested.
        const __m256i mask = _mm256_cmpgt_epi32(curr, next);
        if (!_mm256_testz_si256(mask, mask)) {
            return false;
        }

        i += 7;
    }

    for (/**/; i + 1 < n; i++) {
        if (a[i] > a[i + 1])
            return false;
    }

    return true;
}


bool is_sorted_avx2_unrolled4(int32_t* a, size_t n) {

    const __m256i shuffle_pattern = _mm256_setr_epi32(1, 2, 3, 4, 5, 6, 7, 7);

    size_t i = 0;
    while (i < n - (4*7 + 1)) {
        const __m256i curr0 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(a + i + 0*7));
        const __m256i curr1 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(a + i + 1*7));
        const __m256i curr2 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(a + i + 2*7));
        const __m256i curr3 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(a + i + 3*7));

        const __m256i next0 = _mm256_permutevar8x32_epi32(curr0, shuffle_pattern);
        const __m256i next1 = _mm256_permutevar8x32_epi32(curr1, shuffle_pattern);
        const __m256i next2 = _mm256_permutevar8x32_epi32(curr2, shuffle_pattern);
        const __m256i next3 = _mm256_permutevar8x32_epi32(curr3, shuffle_pattern);

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

        i += 7*4;
    }

    for (/**/; i + 1 < n; i++) {
        if (a[i] > a[i + 1])
            return false;
    }

    return true;
}
