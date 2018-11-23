__m512i reverse_avx512f(const __m512i v) {

    // 1. reverse order of 32-bit words in register
    const __m512i indices = _mm512_set_epi32(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
    const __m512i swap_32 = _mm512_permutexvar_epi32(indices, v);

    // 2. reverse order of 16-bit words within 32-bit lanes
    // swap_32 = [ a | b | c | d ] x 16
    // swap_16 = [ c | d | a | b ] x 16
    const __m512i swap_16 = _mm512_rol_epi32(swap_32, 16);

    // 3. reverse bytes within 16-bit words

    // swap_16 = [ c | d | a | b ] x 16
    //      t0 = [ 0 | c | d | a ] x 16
    //      t1 = [ d | a | b | 0 ] x 16
    const __m512i t0    = _mm512_srli_epi32(swap_16, 8);
    const __m512i t1    = _mm512_slli_epi32(swap_16, 8);

    //   mask0 = [ 0 | ff| 0 | ff] x 16
    const __m512i mask0 = _mm512_set1_epi32(0x00ff00ff);

    //  result = (mask0 and t0) or (not mask0 and t1)
    //         = [ d | c | b | a]
    return _mm512_ternarylogic_epi32(mask0, t0, t1, 0xca);
}
