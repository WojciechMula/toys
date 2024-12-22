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

static __m512i divlo_u8_i32x16(__m512i a, __m512i b, float mul) {
    __m512 af = _mm512_cvtepi32_ps(a);
    __m512 bf = _mm512_cvtepi32_ps(b);
    __m512 m1 = _mm512_mul_ps(af, _mm512_set1_ps(1.001f * mul));
    __m512 m2 = _mm512_rcp14_ps(bf);
    return _mm512_cvttps_epi32(_mm512_mul_ps(m1, m2));
}
static __m512i div_u8x64(__m512i a, __m512i b) {
    __m512i m0 = _mm512_set1_epi32(0x000000ff);
    __m512i m1 = _mm512_set1_epi32(0x0000ff00);
    __m512i m2 = _mm512_set1_epi32(0x00ff0000);

    __m512i r0 = divlo_u8_i32x16(_mm512_and_si512(a, m0), _mm512_and_si512(b, m0), 1);
    __m512i r1 = divlo_u8_i32x16(_mm512_and_si512(a, m1), _mm512_and_si512(b, m1), 1<<8);


    __m512i r2 = divlo_u8_i32x16(_mm512_and_si512(a, m2), _mm512_and_si512(b, m2), 1<<16);
    __m512i r3 = divlo_u8_i32x16(_mm512_srli_epi32(a, 24), _mm512_srli_epi32(b, 24), 1);
    r3 = _mm512_slli_epi32(r3, 24);

    __m512i r01 = _mm512_mask_blend_epi8(0xAAAAAAAAAAAAAAAA, r0, r1);
    __m512i r23 = _mm512_or_si512(r2, r3);
    return _mm512_mask_blend_epi16(0xAAAAAAAA, r01, r23);
}
void avx512_div_u8_rcp_4x(const uint8_t* a, const uint8_t* b, uint8_t* out, size_t n) {
    for (size_t i=0; i < n; i += 64) {
        __m512i av = _mm512_loadu_epi8(a+i);
        __m512i bv = _mm512_loadu_epi8(b+i);
        __m512i rv = div_u8x64(av, bv);
        _mm512_storeu_epi8(out+i, rv);
    }
}
