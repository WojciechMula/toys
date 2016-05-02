void SSE4_blend() {
	size_t n = width * height * 4;

    __m128i alpha_pos = _mm_set1_epi16(256 * (uint16_t)alpha);
    __m128i alpha_neg = _mm_set1_epi16(256 * (uint16_t)(~alpha));

    for (size_t i=0; i < n; i += 16) {
        __m128i A = _mm_load_si128((__m128i*)(imgA + i));
        __m128i B = _mm_load_si128((__m128i*)(imgB + i));

        __m128i A0 = _mm_cvtepu8_epi16(A);
        __m128i B0 = _mm_cvtepu8_epi16(B);
        __m128i A1 = _mm_cvtepu8_epi16(_mm_srli_si128(A, 8));
        __m128i B1 = _mm_cvtepu8_epi16(_mm_srli_si128(B, 8));

        A0 = _mm_mulhi_epu16(A0, alpha_pos);
        A1 = _mm_mulhi_epu16(A1, alpha_pos);
        B0 = _mm_mulhi_epu16(B0, alpha_neg);
        B1 = _mm_mulhi_epu16(B1, alpha_neg);

        A  = _mm_packus_epi16(A0, A1);
        B  = _mm_packus_epi16(B0, B1);

        _mm_store_si128((__m128i*)(data + i), _mm_adds_epu8(A, B));
    }
}

