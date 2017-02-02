void bitmask_avx512(uint32_t* ptr, size_t n, uint32_t key, uint8_t* out) {

    uint16_t* output = (uint16_t*)out;

    const size_t chunks = n / 16;
    const size_t tail   = n % 16;

    const __m512i vkey = _mm512_set1_epi32(key);
    
    for (size_t i=0; i < chunks; i++) {

        const __m512i in = _mm512_loadu_si512((const __m512i*)(ptr + i*16));

        const auto mask = _mm512_cmpeq_epi32_mask(in, vkey);
        *output++ = mask;
    }

    if (tail > 0) {
        bitmask_naive(ptr + chunks*16, tail, key, out + chunks*16);
    }
}
