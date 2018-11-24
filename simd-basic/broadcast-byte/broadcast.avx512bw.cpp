__m512i broadcast_avx512bw(uint8_t b) {

    // 1. store byte in an SSE vector
    const __m128i v = _mm_cvtsi32_si128(b);
    
    // 1. broadcast 0th byte using dedicated instruction
    return _mm512_broadcastb_epi8(v);
}

