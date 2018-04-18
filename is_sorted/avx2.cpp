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

