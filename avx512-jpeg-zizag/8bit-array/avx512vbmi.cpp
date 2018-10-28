void jpeg_zigzag_avx512vbmi(const uint8_t* in, uint8_t* out) {
    
    const __m512i t0 = _mm512_loadu_si512((const __m512i*)in);
    const __m512i t1 = _mm512_loadu_si512((const __m512i*)zigzag_shuffle);

    const __m512i t2 = _mm512_permutexvar_epi8(t1, t0);

    _mm512_storeu_si512((__m512i*)out, t2);
}

