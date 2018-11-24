namespace {

    uint32_t extract_crosslane(const __m128i hi, const __m128i lo, int shift) {
        switch (shift) {
            case 0: {
                const __m128i tmp = _mm_alignr_epi8(hi, lo, 13);
                return _mm_cvtsi128_si32(tmp);
            }
            case 1: {
                const __m128i tmp = _mm_alignr_epi8(hi, lo, 14);
                return _mm_cvtsi128_si32(tmp);
            }
            case 2: {
                const __m128i tmp = _mm_alignr_epi8(hi, lo, 15);
                return _mm_cvtsi128_si32(tmp);
            }
            default:
                throw std::logic_error("must never be called");
        }
    }

}

uint32_t extract_avx512f(const __m512i v, int index) {
    // AVX512F nor AVX512BW don't allow to extract arbitrary 32-bit word.
    // We have to extract whole 128-bit lanes.

    if (index <= 12) { // lane #0
        const __m128i lane0 = _mm512_extracti32x4_epi32(v, 0);
        return extract_sse41(lane0, index);

    } else if (index >= 13 and index <= 15) { // crosslane #0-#1
        const __m128i lane0 = _mm512_extracti32x4_epi32(v, 0);
        const __m128i lane1 = _mm512_extracti32x4_epi32(v, 1);

        return extract_crosslane(lane1, lane0, index - 13);

    } else if (index >= 16 and index <= 28) { // lane #1
        const __m128i lane1 = _mm512_extracti32x4_epi32(v, 1);
        return extract_sse41(lane1, index - 16);

    } else if (index >= 29 and index <= 31) { // crosslane #1-#2
        const __m128i lane1 = _mm512_extracti32x4_epi32(v, 1);
        const __m128i lane2 = _mm512_extracti32x4_epi32(v, 2);

        return extract_crosslane(lane2, lane1, index - 29);

    } else if (index >= 32 and index <= 44) { // lane #2
        const __m128i lane2 = _mm512_extracti32x4_epi32(v, 2);
        return extract_sse41(lane2, index - 32);

    } else if (index >= 45 and index <= 47) { // crosslane #2-#3
        const __m128i lane2 = _mm512_extracti32x4_epi32(v, 2);
        const __m128i lane3 = _mm512_extracti32x4_epi32(v, 3);

        return extract_crosslane(lane3, lane2, index - 45);

    } else if (index >= 48) { // lane #3
        const __m128i lane3 = _mm512_extracti32x4_epi32(v, 3);
        return extract_sse41(lane3, index - 48);
    }

    return -1;
}


