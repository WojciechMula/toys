void avx512_div_u8_cvtt(const uint8_t* A, const uint8_t* B, uint8_t* out, size_t n) {
    const __m128i t0 = _mm_setr_epi8(
        0, 4, 8, 12,
        -1, -1, -1, -1,
        -1, -1, -1, -1,
        -1, -1, -1, -1
    );

    const __m512i u32_u8 = _mm512_broadcast_i64x2(t0);

    for (size_t i=0; i < n; i += 8) {
        const __m128i a_u8  = _mm_loadu_si128((const __m128i*)&A[i]);
        const __m512i a_u32 = _mm512_cvtepu8_epi32(a_u8);
        const __m512  a_f32 = _mm512_cvtepi32_ps(a_u32);

        const __m128i b_u8  = _mm_loadu_si128((const __m128i*)&B[i]);
        const __m512i b_u32 = _mm512_cvtepu8_epi32(b_u8);
        const __m512  b_f32 = _mm512_cvtepi32_ps(b_u32);

        const __m512  c_f32 = _mm512_div_ps(a_f32, b_f32);
        const __m512i c_i32 = _mm512_cvttps_epi32(c_f32);

        // convert u32 -> u8 within lanes
        const __m512i c_u8_0 = _mm512_shuffle_epi8(c_i32, u32_u8);

        // gather lower u32 words from the lanes
        const __m512i indices = _mm512_setr_epi32(
            0, 4, 8, 12,
            -1, -1, -1, -1,
            -1, -1, -1, -1,
            -1, -1, -1, -1
        );
        const __m512i c_u8_1 = _mm512_permutexvar_epi32(indices, c_u8_0);
        const __m128i c_u8   = _mm512_castsi512_si128(c_u8_1);

        _mm_storeu_si128((__m128i*)&out[i], c_u8);
    }
}

void avx512_div_u8_rcp(const uint8_t* A, const uint8_t* B, uint8_t* out, size_t n) {
    const __m128i t0 = _mm_setr_epi8(
        0 + 1, 4 + 1, 8 + 1, 12 + 1,
        -1, -1, -1, -1,
        -1, -1, -1, -1,
        -1, -1, -1, -1
    );

    const __m512 coef    = _mm512_set1_ps(1.00025 * 256);
    const __m512i u32_u8 = _mm512_broadcast_i64x2(t0);

    for (size_t i=0; i < n; i += 8) {
        const __m128i a_u8    = _mm_loadu_si128((const __m128i*)&A[i]);
        const __m512i a_u32   = _mm512_cvtepu8_epi32(a_u8);
        const __m512  a_f32_0 = _mm512_cvtepi32_ps(a_u32);
        const __m512  a_f32   = _mm512_mul_ps(coef, a_f32_0);

        const __m128i b_u8  = _mm_loadu_si128((const __m128i*)&B[i]);
        const __m512i b_u32 = _mm512_cvtepu8_epi32(b_u8);
        const __m512  b_f32 = _mm512_cvtepi32_ps(b_u32);

        const __m512  b_inv_f32 = _mm512_rcp14_ps(b_f32);

        const __m512  c_f32 = _mm512_mul_ps(a_f32, b_inv_f32);
        const __m512i c_i32 = _mm512_cvttps_epi32(c_f32);

        // convert u32 -> u8 within lanes
        const __m512i c_u8_0 = _mm512_shuffle_epi8(c_i32, u32_u8);

        // gather lower u32 words from the lanes
        const __m512i indices = _mm512_setr_epi32(
            0, 4, 8, 12,
            -1, -1, -1, -1,
            -1, -1, -1, -1,
            -1, -1, -1, -1
        );
        const __m512i c_u8_1 = _mm512_permutexvar_epi32(indices, c_u8_0);
        const __m128i c_u8   = _mm512_castsi512_si128(c_u8_1);

        _mm_storeu_si128((__m128i*)&out[i], c_u8);
    }
}
