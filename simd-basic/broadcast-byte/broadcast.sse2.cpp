__m128i broadcast_sse2(uint8_t b) {
    
    // b     = [ xx ]
    // bbbb  = [ xx | xx | xx | xx ]
    uint32_t bbbb = uint32_t(b) * 0x01010101u;

    // res   = [ 00 | 00 | 00 | 00 | 00 | 00 | 00 | 00 | 00 | 00 | 00 | 00 | xx | xx | xx | xx ]
    __m128i res = _mm_cvtsi32_si128(bbbb);

    // res   = [ 00 | 00 | 00 | 00 | 00 | 00 | 00 | 00 | xx | xx | xx | xx | xx | xx | xx | xx ]
    res = _mm_unpacklo_epi32(res, res);

    // res   = [ xx | xx | xx | xx | xx | xx | xx | xx | xx | xx | xx | xx | xx | xx | xx | xx ]
    res = _mm_unpacklo_epi32(res, res);

    return res;
}
