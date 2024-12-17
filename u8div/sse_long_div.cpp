void sse_long_div_u8(const uint8_t* A, const uint8_t* B, uint8_t* C, size_t n) {
    const __m128i msb = _mm_set1_epi8(int8_t(0x80));
    const __m128i lsb = _mm_set1_epi8(0x01);

    for (size_t i=0; i < n; i += 16) {
        __m128i aa = _mm_loadu_si128((__m128i*)(&A[i]));

        const __m128i b   = _mm_loadu_si128((__m128i*)(&B[i]));
        __m128i b_shifted = _mm_xor_si128(b, msb);

        __m128i bit = _mm_set1_epi8((int8_t)0x80);
        __m128i a   = _mm_set1_epi16(0);
        __m128i c   = _mm_set1_epi16(0);
        for (int j=0; j < 8; j++) {
            {
                const __m128i t0 = _mm_and_si128(aa, msb);
                const __m128i t1 = _mm_min_epu8(t0, lsb);
                a  = _mm_add_epi8(a, t1);
            }

            const __m128i a_shifted = _mm_xor_si128(a, msb);
            const __m128i gt = _mm_cmpgt_epi8(b_shifted, a_shifted);

            const __m128i b0 = _mm_andnot_si128(gt, b);
            const __m128i c0 = _mm_andnot_si128(gt, bit);

            a = _mm_sub_epi16(a, b0);
            c = _mm_or_si128(c, c0);

            bit = _mm_srli_epi32(bit, 1);
            aa  = _mm_add_epi8(aa, aa);
            a   = _mm_add_epi32(a, a);
        }

        _mm_storeu_si128((__m128i*)(&C[i]), c);
    }
}
