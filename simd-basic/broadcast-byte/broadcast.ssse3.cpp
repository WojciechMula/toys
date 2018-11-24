__m128i broadcast_ssse3(uint8_t b) {
    
    // res   = [ 00 | 00 | 00 | 00 | 00 | 00 | 00 | 00 | 00 | 00 | 00 | 00 | 00 | 00 | 00 | xx ]
    __m128i res = _mm_cvtsi32_si128(b);

    // res   = [ xx | xx | xx | xx | xx | xx | xx | xx | xx | xx | xx | xx | xx | xx | xx | xx ]
    res = _mm_shuffle_epi8(res, _mm_setzero_si128());

    return res;
}

