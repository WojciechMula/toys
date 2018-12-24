__m512i bit_to_byte_avx512f(const __m512i x, const __m512i mask) {

    const __m512i low = _mm512_set1_epi32(0x7f7f7f7f);
    const __m512i msb = _mm512_set1_epi32(0x80808080);
    const __m512i lsb = _mm512_set1_epi32(0x01010101);

    // x    = [ 0001_1111 | 0000_0111 | 1011_1100 | 0000_1111 | ... ]
    // mask = [ 0010_0000 | 0000_1000 | 1000_0000 | 1000_0000 | ... ]
    // t0   = [ 0010_0000 | 0000_0000 | 1000_0000 | 0000_0000 | ... ]
    const __m512i  t0 = _mm512_and_si512(x, mask);

    // transfer i-th bit to MSB position
    // t1   = [ 1101_1111 | 0111_1111 | 1111_1111 | 0111_1111 | ... ]
    const __m512i  t1 = _mm512_add_epi32(t0, low);

    // leave only MSB
    // t2   = [ 1000_0000 | 0000_0000 | 1000_0000 | 0000_0000 | ... ]
    const __m512i  t2 = _mm512_and_si512(t1, msb);

    // move MSB to 0th
    // t3   = [ 0000_0001 | 0000_0000 | 0000_0001 | 0000_0000 | ... ]
    const __m512i  t3 = _mm512_and_si512(_mm512_srli_epi32(t2, 7), lsb);

    // t4   = (t2 - t3) --- conditionally fill bits 6:0
    // t4   = [ 0111_1111 | 0000_0000 | 0111_1111 | 0000_0000 | ... ]
    const __m512i  t4 = _mm512_sub_epi32(t2, t3);

    // t5   = t5 | t2 --- complete MSB
    // t5   = [ 1111_1111 | 0000_0000 | 1111_1111 | 0000_0000 | ... ]
    const __m512i t5 = _mm512_or_epi32(t4, t2);

    return t5;
}
