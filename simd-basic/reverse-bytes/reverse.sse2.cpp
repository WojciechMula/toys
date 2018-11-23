__m128i reverse_sse2(const __m128i v) {

    // 1. swap 32-bit words
    const __m128i swap_32 = _mm_shuffle_epi32(v, 0x1b);

    // 2. swap 16-bit words within 32-bit words

    // swap_32 = [ a | b | c | d ] x 4
    //   t0_16 = [ c | d | 0 | 0 ] x 4
    //   t1_16 = [ 0 | 0 | a | b ] x 4
    const __m128i t0_16   = _mm_slli_epi32(swap_32, 16);
    const __m128i t1_16   = _mm_srli_epi32(swap_32, 16);

    // swap_16 = [ c | d | a | b ] x 4
    const __m128i swap_16 = _mm_or_si128(t0_16, t1_16);

    // 3. swap bytes within 16-bit words

    // swap_16 = [ c | d | a | b ] x 4
    //    t0_8 = [ d | 0 | b | 0 ] x 4
    //    t1_8 = [ 0 | c | 0 | a ] x 4
    const __m128i t0_8    = _mm_slli_epi16(swap_16, 8);
    const __m128i t1_8    = _mm_srli_epi16(swap_16, 8);

    //     res = [ c | d | a | b ] x 4
    return _mm_or_si128(t0_8, t1_8);
}
