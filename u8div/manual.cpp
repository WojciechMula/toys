#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <immintrin.h>

void manual_div_u8(const uint8_t* A, const uint8_t* B, uint8_t* C, size_t n) {
    for (size_t i=0; i < n; i += 8) {
        const __m128i a_u8 = _mm_loadu_si128((__m128i*)(&A[i]));
        const __m128i b_u8 = _mm_loadu_si128((__m128i*)(&B[i]));

        __m128i a = _mm_cvtepu8_epi16(a_u8);

        const __m128i b0 = _mm_cvtepu8_epi16(b_u8);
        __m128i b = _mm_slli_epi16(b0, 7);

        __m128i bit = _mm_set1_epi16(0x0080);
        __m128i c   = _mm_set1_epi16(0);

        for (int j=0; j < 8; j++) {
            const __m128i gt = _mm_cmpgt_epi16(b, a);

            const __m128i b0 = _mm_andnot_si128(gt, b);
            const __m128i c0 = _mm_andnot_si128(gt, bit);

            a = _mm_sub_epi16(a, b0);
            c = _mm_or_si128(c, c0);

            bit = _mm_srli_epi32(bit, 1);
            b   = _mm_srli_epi32(b, 1);
        }

        const __m128i t0 = _mm_packus_epi16(c, c);
        _mm_storeu_si128((__m128i*)(&C[i]), t0);
    }
}

void manual_div_u8_ver2(const uint8_t* A, const uint8_t* B, uint8_t* C, size_t n) {
    const __m128i even_mask = _mm_set1_epi16(0x00ff);

    for (size_t i=0; i < n; i += 16) {
        const __m128i a_u8 = _mm_loadu_si128((__m128i*)(&A[i]));
        const __m128i b_u8 = _mm_loadu_si128((__m128i*)(&B[i]));

        __m128i a_even = _mm_and_si128(even_mask, a_u8);
        __m128i b_even = _mm_and_si128(even_mask, b_u8);
        b_even = _mm_slli_epi32(b_even, 7);

        __m128i a_odd = _mm_andnot_si128(even_mask, a_u8);
        a_odd = _mm_srli_epi32(a_odd, 8);

        __m128i b_odd = _mm_andnot_si128(even_mask, b_u8);
        b_odd = _mm_srli_epi32(b_odd, 1);

        __m128i bit    = _mm_set1_epi8((int8_t)0x80);
        __m128i c_even = _mm_set1_epi16(0);
        __m128i c_odd  = _mm_set1_epi16(0);

        for (int j=0; j < 8; j++) {
            const __m128i gt_even = _mm_cmpgt_epi16(b_even, a_even);
            const __m128i gt_odd  = _mm_cmpgt_epi16(b_odd, a_odd);

            const __m128i b0_even = _mm_andnot_si128(gt_even, b_even);
            const __m128i b0_odd  = _mm_andnot_si128(gt_odd, b_odd);
            const __m128i c0_even = _mm_andnot_si128(gt_even, bit);
            const __m128i c0_odd  = _mm_andnot_si128(gt_odd, bit);

            a_even = _mm_sub_epi16(a_even, b0_even);
            a_odd  = _mm_sub_epi16(a_odd, b0_odd);
            c_even = _mm_or_si128(c_even, c0_even);
            c_odd  = _mm_or_si128(c_odd, c0_odd);

            bit    = _mm_srli_epi32(bit, 1);
            b_even = _mm_srli_epi32(b_even, 1);
            b_odd  = _mm_srli_epi32(b_odd, 1);
        }

        const __m128i t0 = _mm_blendv_epi8(c_odd, c_even, even_mask);
        _mm_storeu_si128((__m128i*)(&C[i]), t0);
    }
}
