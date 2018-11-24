__m256i broadcast_avx2__version1(uint8_t b) {
    
    // 1. broadcast byte in an SSE vector
    const __m128i v = broadcast_ssse3(b);

    // 2. build the new AVX2 vector
    __m256i res = _mm256_castsi128_si256(v);
    res = _mm256_inserti128_si256(res, v, 1);

    return res;
}

__m256i broadcast_avx2__version2(uint8_t b) {
    
    // 1. store byte in an SSE vector
    const __m128i v = _mm_cvtsi32_si128(b);

    // 2. build the new AVX2 vector
    __m256i res = _mm256_castsi128_si256(v);
    res = _mm256_inserti128_si256(res, v, 1);

    // 2. shuffle 0th byte in each 128-byte lane
    res = _mm256_shuffle_epi8(res, _mm256_setzero_si256());

    return res;
}
