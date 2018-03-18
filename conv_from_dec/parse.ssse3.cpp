
uint64_t parse_ssse3(const char* s) {
    //assert(strlen(s) >= 16);

    const __m128i ascii0      = _mm_set1_epi8('0');
    const __m128i mul_1_10    = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 10, 1, 10, 1, 10, 1, 10, 1);
    const __m128i mul_1_100   = _mm_setr_epi16(100, 1, 100, 1, 100, 1, 100, 1); 
    const __m128i mul_1_10000 = _mm_setr_epi16(10000, 1, 10000, 1, 10000, 1, 10000, 1);

    // =--------------

    const __m128i input   = _mm_sub_epi8(_mm_loadu_si128((__m128i*)s), ascii0);

    const __m128i t1      = _mm_maddubs_epi16(input, mul_1_10);
    const __m128i t2      = _mm_madd_epi16(t1, mul_1_100);
    const __m128i t3      = _mm_packus_epi32(t2, t2);
    const __m128i t4      = _mm_madd_epi16(t3, mul_1_10000);

    uint32_t p[4];
    _mm_storeu_si128((__m128i*)p, t4);

    return uint64_t(p[0]) * 100000000u + uint64_t(p[1]);
}
