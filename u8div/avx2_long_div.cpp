void avx2_long_div_u8_ver2(const uint8_t* A, const uint8_t* B, uint8_t* C, size_t n) {
    const __m256i even_mask = _mm256_set1_epi16(0x00ff);

    for (size_t i=0; i < n; i += 32) {
        const __m256i a_u8 = _mm256_loadu_si256((__m256i*)(&A[i]));
        const __m256i b_u8 = _mm256_loadu_si256((__m256i*)(&B[i]));

        __m256i a_even = _mm256_and_si256(even_mask, a_u8);
        __m256i b_even = _mm256_and_si256(even_mask, b_u8);
        b_even = _mm256_slli_epi32(b_even, 7);

        __m256i a_odd = _mm256_andnot_si256(even_mask, a_u8);
        a_odd = _mm256_srli_epi32(a_odd, 8);

        __m256i b_odd = _mm256_andnot_si256(even_mask, b_u8);
        b_odd = _mm256_srli_epi32(b_odd, 1);

        __m256i bit    = _mm256_set1_epi8((int8_t)0x80);
        __m256i c_even = _mm256_set1_epi16(0);
        __m256i c_odd  = _mm256_set1_epi16(0);

        for (int j=0; j < 8; j++) {
            const __m256i gt_even = _mm256_cmpgt_epi16(b_even, a_even);
            const __m256i gt_odd  = _mm256_cmpgt_epi16(b_odd, a_odd);

            const __m256i b0_even = _mm256_andnot_si256(gt_even, b_even);
            const __m256i b0_odd  = _mm256_andnot_si256(gt_odd, b_odd);
            const __m256i c0_even = _mm256_andnot_si256(gt_even, bit);
            const __m256i c0_odd  = _mm256_andnot_si256(gt_odd, bit);

            a_even = _mm256_sub_epi16(a_even, b0_even);
            a_odd  = _mm256_sub_epi16(a_odd, b0_odd);
            c_even = _mm256_or_si256(c_even, c0_even);
            c_odd  = _mm256_or_si256(c_odd, c0_odd);

            bit    = _mm256_srli_epi32(bit, 1);
            b_even = _mm256_srli_epi32(b_even, 1);
            b_odd  = _mm256_srli_epi32(b_odd, 1);
        }

        const __m256i t0 = _mm256_blendv_epi8(c_odd, c_even, even_mask);
        _mm256_storeu_si256((__m256i*)(&C[i]), t0);
    }
}

void avx2_long_div_u8_ver3(const uint8_t* A, const uint8_t* B, uint8_t* C, size_t n) {
    const __m256i msb = _mm256_set1_epi8(int8_t(0x80));
    const __m256i lsb = _mm256_set1_epi8(0x01);

    for (size_t i=0; i < n; i += 32) {
        __m256i aa = _mm256_loadu_si256((__m256i*)(&A[i]));

        const __m256i b   = _mm256_loadu_si256((__m256i*)(&B[i]));
        __m256i b_shifted = _mm256_xor_si256(b, msb);

        __m256i bit = _mm256_set1_epi8((int8_t)0x80);
        __m256i a   = _mm256_set1_epi16(0);
        __m256i c   = _mm256_set1_epi16(0);
        for (int j=0; j < 8; j++) {
            {
                const __m256i t0 = _mm256_and_si256(aa, msb);
                const __m256i t1 = _mm256_min_epu8(t0, lsb);
                aa = _mm256_add_epi8(aa, aa);
                a  = _mm256_add_epi8(a, t1);
            }

            const __m256i a_shifted = _mm256_xor_si256(a, msb);
            const __m256i gt = _mm256_cmpgt_epi8(b_shifted, a_shifted);

            const __m256i b0 = _mm256_andnot_si256(gt, b);
            const __m256i c0 = _mm256_andnot_si256(gt, bit);

            a = _mm256_sub_epi16(a, b0);
            c = _mm256_or_si256(c, c0);

            bit = _mm256_srli_epi32(bit, 1);
            a = _mm256_add_epi32(a, a);
        }

        _mm256_storeu_si256((__m256i*)(&C[i]), c);
    }
}
