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

// as suggested by HeroicKatamor on reddit:
// https://www.reddit.com/r/cpp/comments/8bkaj3/is_sorted_using_simd_instructions/dx7jj8u/
bool is_sorted_sse_unrolled4(int32_t* a, size_t n) {

    size_t i = 0;
    if (n >= 4*(4 + 1)) {
        __m128i chunk0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a));
        do {
            const __m128i chunk1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + i + 1*4));
            const __m128i chunk2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + i + 2*4));
            const __m128i chunk3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + i + 3*4));
            const __m128i chunk4 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(a + i + 4*4));

            const __m128i next0 = _mm_alignr_epi8(chunk1, chunk0, 4);
            const __m128i next1 = _mm_alignr_epi8(chunk2, chunk1, 4);
            const __m128i next2 = _mm_alignr_epi8(chunk3, chunk2, 4);
            const __m128i next3 = _mm_alignr_epi8(chunk4, chunk3, 4);

            const __m128i mask0 = _mm_cmpgt_epi32(chunk0, next0);
            const __m128i mask1 = _mm_cmpgt_epi32(chunk1, next1);
            const __m128i mask2 = _mm_cmpgt_epi32(chunk2, next2);
            const __m128i mask3 = _mm_cmpgt_epi32(chunk3, next3);
            const __m128i mask  = _mm_or_si128(mask0,
                                  _mm_or_si128(mask1,
                                  _mm_or_si128(mask2, mask3)));

            if (!_mm_test_all_zeros(mask, mask)) {
                return false;
            }

            chunk0 = chunk4;
            i += 4*4;
        } while (i < n - 4*4);
    }

    for (/**/; i + 1 < n; i++) {
        if (a[i] > a[i + 1])
            return false;
    }

    return true;
}

