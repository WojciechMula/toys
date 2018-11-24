uint32_t extract_avx2(const __m256i v, int index) {
    // AVX2 doesn't have ability to extract arbitrary 32-bit word,
    // we have consider three cases: dword is lower/higher 128-bit lane,
    // dword crosses lane

    if (index <= 12) {
        // lower lane
        const __m128i lo = _mm256_castsi256_si128(v);
        return extract_sse41(lo, index);
    } else
    if (index >= 16) {
        const __m128i hi = _mm256_extracti128_si256(v, 1);
        return extract_sse41(hi, index - 16);
    } else {
        // dword crosses lanes
        const __m128i lo = _mm256_castsi256_si128(v);
        const __m128i hi = _mm256_extracti128_si256(v, 1);

        switch (index) {
            case 13: {
                const __m128i tmp = _mm_alignr_epi8(hi, lo, 13);
                return _mm_cvtsi128_si32(tmp);
            }
            case 14: {
                const __m128i tmp = _mm_alignr_epi8(hi, lo, 14);
                return _mm_cvtsi128_si32(tmp);
            }
            case 15: {
                const __m128i tmp = _mm_alignr_epi8(hi, lo, 15);
                return _mm_cvtsi128_si32(tmp);
            }
            default:
                throw std::logic_error("must never be called");
        }
    } 

    return 0;
}

