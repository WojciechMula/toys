void sse_long_div_u8(const uint8_t* A, const uint8_t* B, uint8_t* C, size_t n) {
    const __m128i msb  = _mm_set1_epi8(int8_t(0x80));
    const __m128i zero = _mm_set1_epi8(0x00);

    for (size_t i=0; i < n; i += 16) {
        __m128i dividend = _mm_loadu_si128((const __m128i*)(&A[i]));

        const __m128i divisor = _mm_loadu_si128((const __m128i*)(&B[i]));
        __m128i divisor_xored = _mm_xor_si128(divisor, msb);

        __m128i bit      = msb;
        __m128i reminder = _mm_set1_epi16(0);
        __m128i quotient = _mm_set1_epi16(0);
        for (int j=0; j < 8; j++) {
            // copy msb of dividend into reminder
            const __m128i t0 = _mm_cmplt_epi8(dividend, zero);
            reminder = _mm_sub_epi8(reminder, t0);

            // unsigned comparison of divisor and reminder
            const __m128i reminder_xored = _mm_xor_si128(reminder, msb);
            const __m128i gt = _mm_cmpgt_epi8(divisor_xored, reminder_xored);

            // derive condition subtract and quotient bit
            const __m128i cond_divisor      = _mm_andnot_si128(gt, divisor);
            const __m128i cond_quotient_bit = _mm_andnot_si128(gt, bit);

            // conditionally update reminder and quotient
            reminder = _mm_sub_epi16(reminder, cond_divisor);
            quotient = _mm_or_si128(quotient, cond_quotient_bit);

            // next bit for quotient
            bit = _mm_srli_epi32(bit, 1);

            // put the next bit from dividend to MSB
            dividend = _mm_add_epi8(dividend, dividend);

            // make room for bit from dividend
            reminder = _mm_add_epi32(reminder, reminder);
        }

        _mm_storeu_si128((__m128i*)(&C[i]), quotient);
    }
}
