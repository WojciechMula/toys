__m512i bit_to_byte_avx512bw(const __m512i x, const __m512i mask) {
    const __m512i  t0 = _mm512_and_si512(x, mask);
    const __mmask64 m = _mm512_cmpeq_epi8_mask(t0, mask);
    const __m512i  t1 = _mm512_movm_epi8(m);

    return t1;
}
