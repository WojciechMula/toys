__m512i broadcast_avx512f(uint8_t b) {
    
    // 1. broadcast byte in an SSE vector
    const __m128i v = broadcast_ssse3(b);

    // 2. broadcast its lowest 64-bit word in register
    return _mm512_broadcastq_epi64(v);
}

