void avx512_long_div_u8(const uint8_t* A, const uint8_t* B, uint8_t* C, size_t n) {
    const __m512i one = _mm512_set1_epi8(1);

    for (size_t i=0; i < n; i += 64) {
        const __m512i a = _mm512_loadu_si512((const __m512*)(&A[i]));
        const __m512i b = _mm512_loadu_si512((const __m512*)(&B[i]));

        const __m512i a_bit7 = _mm512_and_epi32(_mm512_srli_epi32(a, 7), one);
        const __m512i a_bit6 = _mm512_and_epi32(_mm512_srli_epi32(a, 6), one);
        const __m512i a_bit5 = _mm512_and_epi32(_mm512_srli_epi32(a, 5), one);
        const __m512i a_bit4 = _mm512_and_epi32(_mm512_srli_epi32(a, 4), one);
        const __m512i a_bit3 = _mm512_and_epi32(_mm512_srli_epi32(a, 3), one);
        const __m512i a_bit2 = _mm512_and_epi32(_mm512_srli_epi32(a, 2), one);
        const __m512i a_bit1 = _mm512_and_epi32(_mm512_srli_epi32(a, 1), one);
        const __m512i a_bit0 = _mm512_and_epi32(_mm512_srli_epi32(a, 0), one);

        __m512i res = _mm512_set1_epi32(0);
        __m512i tmp = a_bit7;

        {
            const __mmask64 ge = _mm512_cmpge_epu8_mask(tmp, b);
            tmp = _mm512_mask_sub_epi8(tmp, ge, tmp, b);
            res = _mm512_mask_add_epi8(res, ge, res, one);
        }

        tmp = _mm512_add_epi32(tmp, tmp);
        tmp = _mm512_or_epi32(tmp, a_bit6);

        {
            const __mmask64 ge = _mm512_cmpge_epu8_mask(tmp, b);
            tmp = _mm512_mask_sub_epi8(tmp, ge, tmp, b);
            res = _mm512_add_epi32(res, res);
            res = _mm512_mask_add_epi8(res, ge, res, one);
        }

        tmp = _mm512_add_epi32(tmp, tmp);
        tmp = _mm512_or_epi32(tmp, a_bit5);

        {
            const __mmask64 ge = _mm512_cmpge_epu8_mask(tmp, b);
            tmp = _mm512_mask_sub_epi8(tmp, ge, tmp, b);
            res = _mm512_add_epi32(res, res);
            res = _mm512_mask_add_epi8(res, ge, res, one);
        }

        tmp = _mm512_add_epi32(tmp, tmp);
        tmp = _mm512_or_epi32(tmp, a_bit4);

        {
            const __mmask64 ge = _mm512_cmpge_epu8_mask(tmp, b);
            tmp = _mm512_mask_sub_epi8(tmp, ge, tmp, b);
            res = _mm512_add_epi32(res, res);
            res = _mm512_mask_add_epi8(res, ge, res, one);
        }

        tmp = _mm512_add_epi32(tmp, tmp);
        tmp = _mm512_or_epi32(tmp, a_bit3);

        {
            const __mmask64 ge = _mm512_cmpge_epu8_mask(tmp, b);
            tmp = _mm512_mask_sub_epi8(tmp, ge, tmp, b);
            res = _mm512_add_epi32(res, res);
            res = _mm512_mask_add_epi8(res, ge, res, one);
        }

        tmp = _mm512_add_epi32(tmp, tmp);
        tmp = _mm512_or_epi32(tmp, a_bit2);

        {
            const __mmask64 ge = _mm512_cmpge_epu8_mask(tmp, b);
            tmp = _mm512_mask_sub_epi8(tmp, ge, tmp, b);
            res = _mm512_add_epi32(res, res);
            res = _mm512_mask_add_epi8(res, ge, res, one);
        }

        tmp = _mm512_add_epi32(tmp, tmp);
        tmp = _mm512_or_epi32(tmp, a_bit1);

        {
            const __mmask64 ge = _mm512_cmpge_epu8_mask(tmp, b);
            tmp = _mm512_mask_sub_epi8(tmp, ge, tmp, b);
            res = _mm512_add_epi32(res, res);
            res = _mm512_mask_add_epi8(res, ge, res, one);
        }

        tmp = _mm512_add_epi32(tmp, tmp);
        tmp = _mm512_or_epi32(tmp, a_bit0);


        {
            const __mmask64 ge = _mm512_cmpge_epu8_mask(tmp, b);
            tmp = _mm512_mask_sub_epi8(tmp, ge, tmp, b);
            res = _mm512_add_epi8(res, res);
            res = _mm512_mask_add_epi8(res, ge, res, one);
        }

        _mm512_storeu_si512((__m512*)&C[i], res);
    }
}
