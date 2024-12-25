void avx512_div_u16_cvtt(const uint16_t* a, const uint16_t* b, uint16_t* out, size_t n) {
    const __m512i mask_lo = _mm512_set1_epi32(0x0000ffff);

    for (size_t i=0; i < n; i += 16) {
        const __m512i a_u16 = _mm512_loadu_si512((const __m512i*)(&a[i]));
        const __m512i b_u16 = _mm512_loadu_si512((const __m512i*)(&b[i]));

        const __m512i a_lo_u32 = _mm512_and_si512(a_u16, mask_lo);
        const __m512i b_lo_u32 = _mm512_and_si512(b_u16, mask_lo);

        const __m512i a_hi_u32 = _mm512_srli_epi32(a_u16, 16);
        const __m512i b_hi_u32 = _mm512_srli_epi32(b_u16, 16);

        const __m512  a_lo_f32 = _mm512_cvtepi32_ps(a_lo_u32);
        const __m512  a_hi_f32 = _mm512_cvtepi32_ps(a_hi_u32);
        const __m512  b_lo_f32 = _mm512_cvtepi32_ps(b_lo_u32);
        const __m512  b_hi_f32 = _mm512_cvtepi32_ps(b_hi_u32);

        const __m512  c_lo_f32 = _mm512_div_ps(a_lo_f32, b_lo_f32);
        const __m512  c_hi_f32 = _mm512_div_ps(a_hi_f32, b_hi_f32);

        const __m512i c_lo_i32   = _mm512_cvttps_epi32(c_lo_f32); // values in the u16 range
        const __m512i c_hi_i32_0 = _mm512_cvttps_epi32(c_hi_f32); // values in the u16 range
        const __m512i c_hi_i32   = _mm512_slli_epi32(c_hi_i32_0, 16);

        const __m512i c_u16 = _mm512_or_si512(c_lo_i32, c_hi_i32);

        _mm512_storeu_si512((__m512i*)(&out[i]), c_u16);
    }
}
