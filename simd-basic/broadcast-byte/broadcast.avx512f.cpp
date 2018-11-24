__m512i broadcast_avx512f__version_1(uint8_t b) {
    
    // 1. broadcast byte in an SSE vector
    const __m128i v = broadcast_ssse3(b);

    // 2. broadcast its lowest 64-bit word in register
    return _mm512_broadcastq_epi64(v);
}


__m512i broadcast_avx512f__version_2(uint8_t b) {
    
    // maps to instructions:
	//   vpbroadcastb   byte, %ymm0
	//   vinserti64x4   $0x1, %ymm0, %zmm0, %zmm0
    return _mm512_set1_epi8(b);
}
