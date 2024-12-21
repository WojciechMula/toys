void avx512_long_div_u8(const uint8_t* A, const uint8_t* B, uint8_t* C, size_t n) {
    const __m512i one = _mm512_set1_epi8(1);

    for (size_t i=0; i < n; i += 64) {
        const __m512i dividend = _mm512_loadu_si512((const __m512*)(&A[i]));
        const __m512i divisor  = _mm512_loadu_si512((const __m512*)(&B[i]));

        const __m512i dividend_bit7 = _mm512_and_epi32(_mm512_srli_epi32(dividend, 7), one);
        const __m512i dividend_bit6 = _mm512_and_epi32(_mm512_srli_epi32(dividend, 6), one);
        const __m512i dividend_bit5 = _mm512_and_epi32(_mm512_srli_epi32(dividend, 5), one);
        const __m512i dividend_bit4 = _mm512_and_epi32(_mm512_srli_epi32(dividend, 4), one);
        const __m512i dividend_bit3 = _mm512_and_epi32(_mm512_srli_epi32(dividend, 3), one);
        const __m512i dividend_bit2 = _mm512_and_epi32(_mm512_srli_epi32(dividend, 2), one);
        const __m512i dividend_bit1 = _mm512_and_epi32(_mm512_srli_epi32(dividend, 1), one);
        const __m512i dividend_bit0 = _mm512_and_epi32(_mm512_srli_epi32(dividend, 0), one);

        __m512i quotient = _mm512_set1_epi32(0);
        __m512i reminder = dividend_bit7;

        {
            const __mmask64 ge = _mm512_cmpge_epu8_mask(reminder, divisor);
            reminder = _mm512_mask_sub_epi8(reminder, ge, reminder, divisor);
            quotient = _mm512_mask_add_epi8(quotient, ge, quotient, one);
        }

        reminder = _mm512_add_epi32(reminder, reminder);
        reminder = _mm512_or_epi32(reminder, dividend_bit6);

        {
            const __mmask64 ge = _mm512_cmpge_epu8_mask(reminder, divisor);
            reminder = _mm512_mask_sub_epi8(reminder, ge, reminder, divisor);
            quotient = _mm512_add_epi32(quotient, quotient);
            quotient = _mm512_mask_add_epi8(quotient, ge, quotient, one);
        }

        reminder = _mm512_add_epi32(reminder, reminder);
        reminder = _mm512_or_epi32(reminder, dividend_bit5);

        {
            const __mmask64 ge = _mm512_cmpge_epu8_mask(reminder, divisor);
            reminder = _mm512_mask_sub_epi8(reminder, ge, reminder, divisor);
            quotient = _mm512_add_epi32(quotient, quotient);
            quotient = _mm512_mask_add_epi8(quotient, ge, quotient, one);
        }

        reminder = _mm512_add_epi32(reminder, reminder);
        reminder = _mm512_or_epi32(reminder, dividend_bit4);

        {
            const __mmask64 ge = _mm512_cmpge_epu8_mask(reminder, divisor);
            reminder = _mm512_mask_sub_epi8(reminder, ge, reminder, divisor);
            quotient = _mm512_add_epi32(quotient, quotient);
            quotient = _mm512_mask_add_epi8(quotient, ge, quotient, one);
        }

        reminder = _mm512_add_epi32(reminder, reminder);
        reminder = _mm512_or_epi32(reminder, dividend_bit3);

        {
            const __mmask64 ge = _mm512_cmpge_epu8_mask(reminder, divisor);
            reminder = _mm512_mask_sub_epi8(reminder, ge, reminder, divisor);
            quotient = _mm512_add_epi32(quotient, quotient);
            quotient = _mm512_mask_add_epi8(quotient, ge, quotient, one);
        }

        reminder = _mm512_add_epi32(reminder, reminder);
        reminder = _mm512_or_epi32(reminder, dividend_bit2);

        {
            const __mmask64 ge = _mm512_cmpge_epu8_mask(reminder, divisor);
            reminder = _mm512_mask_sub_epi8(reminder, ge, reminder, divisor);
            quotient = _mm512_add_epi32(quotient, quotient);
            quotient = _mm512_mask_add_epi8(quotient, ge, quotient, one);
        }

        reminder = _mm512_add_epi32(reminder, reminder);
        reminder = _mm512_or_epi32(reminder, dividend_bit1);

        {
            const __mmask64 ge = _mm512_cmpge_epu8_mask(reminder, divisor);
            reminder = _mm512_mask_sub_epi8(reminder, ge, reminder, divisor);
            quotient = _mm512_add_epi32(quotient, quotient);
            quotient = _mm512_mask_add_epi8(quotient, ge, quotient, one);
        }

        reminder = _mm512_add_epi32(reminder, reminder);
        reminder = _mm512_or_epi32(reminder, dividend_bit0);


        {
            const __mmask64 ge = _mm512_cmpge_epu8_mask(reminder, divisor);
            reminder = _mm512_mask_sub_epi8(reminder, ge, reminder, divisor);
            quotient = _mm512_add_epi8(quotient, quotient);
            quotient = _mm512_mask_add_epi8(quotient, ge, quotient, one);
        }

        _mm512_storeu_si512((__m512*)&C[i], quotient);
    }
}
