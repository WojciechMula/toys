__m256i reverse_avx2__version_1(const __m256i v) {

    // 1. swap 32-bit words
    const __m256i indices = _mm256_set_epi32(0, 1, 2, 3, 4, 5, 6, 7);
    const __m256i swap_32 = _mm256_permutevar8x32_epi32(v, indices);

    // 2. swap 16-bit words

    // swap_32 = [ a | b | c | d ] x 4
    //   t0_16 = [ c | d | 0 | 0 ] x 4
    //   t1_16 = [ 0 | 0 | a | b ] x 4
    const __m256i t0_16   = _mm256_slli_epi32(swap_32, 16);
    const __m256i t1_16   = _mm256_srli_epi32(swap_32, 16);

    // swap_16 = [ c | d | a | b ] x 4
    const __m256i swap_16 = _mm256_or_si256(t0_16, t1_16);

    // 3. swap bytes

    // swap_16 = [ c | d | a | b ] x 4
    //    t0_8 = [ d | 0 | b | 0 ] x 4
    //    t1_8 = [ 0 | c | 0 | a ] x 4
    const __m256i t0_8    = _mm256_slli_epi16(swap_16, 8);
    const __m256i t1_8    = _mm256_srli_epi16(swap_16, 8);

    //     res = [ c | d | a | b ] x 4
    return _mm256_or_si256(t0_8, t1_8);
}


__m256i reverse_avx2__version_2(const __m256i v) {

    // extract 128-bit lanes
    const __m128i lo = _mm256_extracti128_si256(v, 0);
    const __m128i hi = _mm256_extracti128_si256(v, 1);

    // reverse them using SSE instructions
    const __m128i indices = _mm_set_epi8(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
    const __m128i lo_rev = _mm_shuffle_epi8(lo, indices);
    const __m128i hi_rev = _mm_shuffle_epi8(hi, indices);

    // build the new AVX2 vector
    __m256i res = _mm256_castsi128_si256(hi_rev);
    res = _mm256_inserti128_si256(res, lo_rev, 1);

    return res;
}
