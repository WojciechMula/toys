__m128i bit_to_byte_sse2(const __m128i x, const __m128i mask) {
    const __m128i t0 = _mm_and_si128(x, mask);
    const __m128i t1 = _mm_cmpeq_epi8(t0, mask);

    return t1;
}
