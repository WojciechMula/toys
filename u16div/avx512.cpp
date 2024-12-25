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


void avx512_div_u16_cvtt_x4(const uint16_t* a, const uint16_t* b, uint16_t* out, size_t n) {
    const __m512i mask_lo = _mm512_set1_epi32(0x0000ffff);

    for (size_t i=0; i < n; i += 16*4) {
        const __m512i a0_u16 = _mm512_loadu_si512((const __m512i*)(&a[i]));
        const __m512i b0_u16 = _mm512_loadu_si512((const __m512i*)(&b[i]));
        const __m512i a1_u16 = _mm512_loadu_si512((const __m512i*)(&a[i + 1*16]));
        const __m512i b1_u16 = _mm512_loadu_si512((const __m512i*)(&b[i + 1*16]));
        const __m512i a2_u16 = _mm512_loadu_si512((const __m512i*)(&a[i + 2*16]));
        const __m512i b2_u16 = _mm512_loadu_si512((const __m512i*)(&b[i + 2*16]));
        const __m512i a3_u16 = _mm512_loadu_si512((const __m512i*)(&a[i + 3*16]));
        const __m512i b3_u16 = _mm512_loadu_si512((const __m512i*)(&b[i + 3*16]));

        const __m512i a0_lo_u32 = _mm512_and_si512(a0_u16, mask_lo);
        const __m512i b0_lo_u32 = _mm512_and_si512(b0_u16, mask_lo);
        const __m512i a1_lo_u32 = _mm512_and_si512(a1_u16, mask_lo);
        const __m512i b1_lo_u32 = _mm512_and_si512(b1_u16, mask_lo);
        const __m512i a2_lo_u32 = _mm512_and_si512(a2_u16, mask_lo);
        const __m512i b2_lo_u32 = _mm512_and_si512(b2_u16, mask_lo);
        const __m512i a3_lo_u32 = _mm512_and_si512(a3_u16, mask_lo);
        const __m512i b3_lo_u32 = _mm512_and_si512(b3_u16, mask_lo);

        const __m512i a0_hi_u32 = _mm512_srli_epi32(a0_u16, 16);
        const __m512i b0_hi_u32 = _mm512_srli_epi32(b0_u16, 16);
        const __m512i a1_hi_u32 = _mm512_srli_epi32(a1_u16, 16);
        const __m512i b1_hi_u32 = _mm512_srli_epi32(b1_u16, 16);
        const __m512i a2_hi_u32 = _mm512_srli_epi32(a2_u16, 16);
        const __m512i b2_hi_u32 = _mm512_srli_epi32(b2_u16, 16);
        const __m512i a3_hi_u32 = _mm512_srli_epi32(a3_u16, 16);
        const __m512i b3_hi_u32 = _mm512_srli_epi32(b3_u16, 16);

        const __m512  a0_lo_f32 = _mm512_cvtepi32_ps(a0_lo_u32);
        const __m512  a0_hi_f32 = _mm512_cvtepi32_ps(a0_hi_u32);
        const __m512  b0_lo_f32 = _mm512_cvtepi32_ps(b0_lo_u32);
        const __m512  b0_hi_f32 = _mm512_cvtepi32_ps(b0_hi_u32);
        const __m512  a1_lo_f32 = _mm512_cvtepi32_ps(a1_lo_u32);
        const __m512  a1_hi_f32 = _mm512_cvtepi32_ps(a1_hi_u32);
        const __m512  b1_lo_f32 = _mm512_cvtepi32_ps(b1_lo_u32);
        const __m512  b1_hi_f32 = _mm512_cvtepi32_ps(b1_hi_u32);
        const __m512  a2_lo_f32 = _mm512_cvtepi32_ps(a2_lo_u32);
        const __m512  a2_hi_f32 = _mm512_cvtepi32_ps(a2_hi_u32);
        const __m512  b2_lo_f32 = _mm512_cvtepi32_ps(b2_lo_u32);
        const __m512  b2_hi_f32 = _mm512_cvtepi32_ps(b2_hi_u32);
        const __m512  a3_lo_f32 = _mm512_cvtepi32_ps(a3_lo_u32);
        const __m512  a3_hi_f32 = _mm512_cvtepi32_ps(a3_hi_u32);
        const __m512  b3_lo_f32 = _mm512_cvtepi32_ps(b3_lo_u32);
        const __m512  b3_hi_f32 = _mm512_cvtepi32_ps(b3_hi_u32);

        const __m512  c0_lo_f32 = _mm512_div_ps(a0_lo_f32, b0_lo_f32);
        const __m512  c0_hi_f32 = _mm512_div_ps(a0_hi_f32, b0_hi_f32);
        const __m512  c1_lo_f32 = _mm512_div_ps(a1_lo_f32, b1_lo_f32);
        const __m512  c1_hi_f32 = _mm512_div_ps(a1_hi_f32, b1_hi_f32);
        const __m512  c2_lo_f32 = _mm512_div_ps(a2_lo_f32, b2_lo_f32);
        const __m512  c2_hi_f32 = _mm512_div_ps(a2_hi_f32, b2_hi_f32);
        const __m512  c3_lo_f32 = _mm512_div_ps(a3_lo_f32, b3_lo_f32);
        const __m512  c3_hi_f32 = _mm512_div_ps(a3_hi_f32, b3_hi_f32);

        const __m512i c0_lo_i32   = _mm512_cvttps_epi32(c0_lo_f32);
        const __m512i c0_hi_i32_0 = _mm512_cvttps_epi32(c0_hi_f32);
        const __m512i c0_hi_i32   = _mm512_slli_epi32(c0_hi_i32_0, 16);
        const __m512i c1_lo_i32   = _mm512_cvttps_epi32(c1_lo_f32);
        const __m512i c1_hi_i32_0 = _mm512_cvttps_epi32(c1_hi_f32);
        const __m512i c1_hi_i32   = _mm512_slli_epi32(c1_hi_i32_0, 16);
        const __m512i c2_lo_i32   = _mm512_cvttps_epi32(c2_lo_f32);
        const __m512i c2_hi_i32_0 = _mm512_cvttps_epi32(c2_hi_f32);
        const __m512i c2_hi_i32   = _mm512_slli_epi32(c2_hi_i32_0, 16);
        const __m512i c3_lo_i32   = _mm512_cvttps_epi32(c3_lo_f32);
        const __m512i c3_hi_i32_0 = _mm512_cvttps_epi32(c3_hi_f32);
        const __m512i c3_hi_i32   = _mm512_slli_epi32(c3_hi_i32_0, 16);

        const __m512i c0_u16 = _mm512_or_si512(c0_lo_i32, c0_hi_i32);
        const __m512i c1_u16 = _mm512_or_si512(c1_lo_i32, c1_hi_i32);
        const __m512i c2_u16 = _mm512_or_si512(c2_lo_i32, c2_hi_i32);
        const __m512i c3_u16 = _mm512_or_si512(c3_lo_i32, c3_hi_i32);

        _mm512_storeu_si512((__m512i*)(&out[i]), c0_u16);
        _mm512_storeu_si512((__m512i*)(&out[i + 1*16]), c1_u16);
        _mm512_storeu_si512((__m512i*)(&out[i + 2*16]), c2_u16);
        _mm512_storeu_si512((__m512i*)(&out[i + 3*16]), c3_u16);
    }
}
