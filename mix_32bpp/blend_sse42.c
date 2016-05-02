void SSE42_blend() {
	int n = width * height * 4;
	int dummy __attribute__((unused));

    const uint8_t alpha2 = alpha/2;
    __m128i alpha_np = _mm_set1_epi16(alpha2 | ((uint16_t)(alpha2 ^ 0x7f) << 8));

    for (size_t i=0; i < n; i += 32) {
        __m128i A0 = _mm_load_si128((__m128i*)(imgA + i));
        __m128i B0 = _mm_load_si128((__m128i*)(imgB + i));

        __m128i A1 = _mm_load_si128((__m128i*)(imgA + i + 16));
        __m128i B1 = _mm_load_si128((__m128i*)(imgB + i + 16));

        __m128i lo0 = _mm_unpacklo_epi8(A0, B0);
        __m128i hi0 = _mm_unpackhi_epi8(A0, B0);

        __m128i lo1 = _mm_unpacklo_epi8(A1, B1);
        __m128i hi1 = _mm_unpackhi_epi8(A1, B1);

        lo0 = _mm_maddubs_epi16(lo0, alpha_np);
        lo1 = _mm_maddubs_epi16(lo1, alpha_np);
        hi0 = _mm_maddubs_epi16(hi0, alpha_np);
        hi1 = _mm_maddubs_epi16(hi1, alpha_np);

        lo0 = _mm_srli_epi16(lo0, 7);
        lo1 = _mm_srli_epi16(lo1, 7);
        hi0 = _mm_srli_epi16(hi0, 7);
        hi1 = _mm_srli_epi16(hi1, 7);

        __m128i res0 = _mm_packus_epi16(lo0, hi0);
        __m128i res1 = _mm_packus_epi16(lo1, hi1);

        _mm_store_si128((__m128i*)(data + i +  0), res0);
        _mm_store_si128((__m128i*)(data + i + 16), res1);
    }
}

