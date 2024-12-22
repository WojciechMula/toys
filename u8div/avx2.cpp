void avx2_div_u8(const uint8_t* a, const uint8_t* b, uint8_t* out, size_t n) {
    const __m128i t0 = _mm_setr_epi8(
        0, 4, 8, 12,
        -1, -1, -1, -1,
        -1, -1, -1, -1,
        -1, -1, -1, -1
    );

    const __m256i u32_u8 = _mm256_set_m128i(t0, t0);

    for (size_t i=0; i < n; i += 8) {
        uint64_t buf_a;
        memcpy(&buf_a, &a[i], 8);
        const __m128i a_u8  = _mm_cvtsi64_si128(buf_a);
        const __m256i a_u32 = _mm256_cvtepu8_epi32(a_u8);
        const __m256  a_f32 = _mm256_cvtepi32_ps(a_u32);

        uint64_t buf_b;
        memcpy(&buf_b, &b[i], 8);
        const __m128i b_u8  = _mm_cvtsi64_si128(buf_b);
        const __m256i b_u32 = _mm256_cvtepu8_epi32(b_u8);
        const __m256  b_f32 = _mm256_cvtepi32_ps(b_u32);

        const __m256  c_f32   = _mm256_div_ps(a_f32, b_f32);
        const __m256  c_f32_2 = _mm256_round_ps(c_f32, _MM_FROUND_TO_ZERO |_MM_FROUND_NO_EXC);
        const __m256i c_i32   = _mm256_cvtps_epi32(c_f32_2);

        const __m256i c_u8 = _mm256_shuffle_epi8(c_i32, u32_u8);

        const uint64_t lo = (uint32_t)_mm256_extract_epi32(c_u8, 0);
        const uint64_t hi = (uint32_t)_mm256_extract_epi32(c_u8, 4);

        const uint64_t buf = lo | (hi << 32);
        memcpy(&out[i], &buf, 8);
    }
}

void avx2_div_u8_cvtt(const uint8_t* a, const uint8_t* b, uint8_t* out, size_t n) {
    const __m128i t0 = _mm_setr_epi8(
        0, 4, 8, 12,
        -1, -1, -1, -1,
        -1, -1, -1, -1,
        -1, -1, -1, -1
    );

    const __m256i u32_u8 = _mm256_set_m128i(t0, t0);

    for (size_t i=0; i < n; i += 8) {
        uint64_t buf_a;
        memcpy(&buf_a, &a[i], 8);
        const __m128i a_u8  = _mm_cvtsi64_si128(buf_a);
        const __m256i a_u32 = _mm256_cvtepu8_epi32(a_u8);
        const __m256  a_f32 = _mm256_cvtepi32_ps(a_u32);

        uint64_t buf_b;
        memcpy(&buf_b, &b[i], 8);
        const __m128i b_u8  = _mm_cvtsi64_si128(buf_b);
        const __m256i b_u32 = _mm256_cvtepu8_epi32(b_u8);
        const __m256  b_f32 = _mm256_cvtepi32_ps(b_u32);

        const __m256  c_f32   = _mm256_div_ps(a_f32, b_f32);
        const __m256i c_i32   = _mm256_cvttps_epi32(c_f32);

        const __m256i c_u8 = _mm256_shuffle_epi8(c_i32, u32_u8);

        const uint64_t lo = (uint32_t)_mm256_extract_epi32(c_u8, 0);
        const uint64_t hi = (uint32_t)_mm256_extract_epi32(c_u8, 4);

        const uint64_t buf = lo | (hi << 32);
        memcpy(&out[i], &buf, 8);
    }
}

void avx2_div_u8_rcp(const uint8_t* a, const uint8_t* b, uint8_t* out, size_t n) {
    const __m128i t0 = _mm_setr_epi8(
        0 + 1, 4 + 1, 8 + 1, 12 + 1,
        -1, -1, -1, -1,
        -1, -1, -1, -1,
        -1, -1, -1, -1
    );

    const __m256i u32_u8 = _mm256_set_m128i(t0, t0);
    const __m256 coef = _mm256_set1_ps(1.0002403 * 256);

    for (size_t i=0; i < n; i += 8) {
        uint64_t buf_a;
        memcpy(&buf_a, &a[i], 8);
        const __m128i a_u8  = _mm_cvtsi64_si128(buf_a);
        const __m256i a_u32 = _mm256_cvtepu8_epi32(a_u8);
        const __m256  a_f32_0 = _mm256_cvtepi32_ps(a_u32);
        const __m256  a_f32 = _mm256_mul_ps(a_f32_0, coef);

        uint64_t buf_b;
        memcpy(&buf_b, &b[i], 8);
        const __m128i b_u8  = _mm_cvtsi64_si128(buf_b);
        const __m256i b_u32 = _mm256_cvtepu8_epi32(b_u8);
        const __m256  b_f32 = _mm256_cvtepi32_ps(b_u32);
        const __m256  b_inv_f32 = _mm256_rcp_ps(b_f32);

        const __m256  c_f32 = _mm256_mul_ps(a_f32, b_inv_f32);
        const __m256i c_i32 = _mm256_cvtps_epi32(c_f32);

        const __m256i c_u8 = _mm256_shuffle_epi8(c_i32, u32_u8);

        const uint64_t lo = (uint32_t)_mm256_extract_epi32(c_u8, 0);
        const uint64_t hi = (uint32_t)_mm256_extract_epi32(c_u8, 4);

        const uint64_t buf = lo | (hi << 32);
        memcpy(&out[i], &buf, 8);
    }
}

static __m256i divlo_u8_i32x8(__m256i a, __m256i b, float mul) {
    __m256 af = _mm256_cvtepi32_ps(a);
    __m256 bf = _mm256_cvtepi32_ps(b);
    __m256 m1 = _mm256_mul_ps(af, _mm256_set1_ps(1.001f * mul));
    __m256 m2 = _mm256_rcp_ps(bf);
    return _mm256_cvttps_epi32(_mm256_mul_ps(m1, m2));
}
static __m256i div_u8x32(__m256i a, __m256i b) {
    __m256i m0 = _mm256_set1_epi32(0x000000ff);
    __m256i m1 = _mm256_set1_epi32(0x0000ff00);
    __m256i m2 = _mm256_set1_epi32(0x00ff0000);

    __m256i r0 = divlo_u8_i32x8(_mm256_and_si256(a, m0), _mm256_and_si256(b, m0), 1);
    __m256i r1 = divlo_u8_i32x8(_mm256_and_si256(a, m1), _mm256_and_si256(b, m1), 1);
    r1 = _mm256_slli_epi32(r1, 8);

    __m256i r2 = divlo_u8_i32x8(_mm256_and_si256(a, m2), _mm256_and_si256(b, m2), 1<<16);
    __m256i r3 = divlo_u8_i32x8(_mm256_srli_epi32(a, 24), _mm256_srli_epi32(b, 24), 1);
    r3 = _mm256_slli_epi32(r3, 24);

    __m256i r01 = _mm256_or_si256(r0, r1);
    __m256i r23 = _mm256_or_si256(r2, r3);
    return _mm256_blend_epi16(r01, r23, 0xAA);
}
void avx2_div_u8_rcp_4x(const uint8_t* a, const uint8_t* b, uint8_t* out, size_t n) {
    for (size_t i=0; i < n; i += 32) {
        __m256i av = _mm256_loadu_si256((__m256i*)(a+i));
        __m256i bv = _mm256_loadu_si256((__m256i*)(b+i));
        __m256i rv = div_u8x32(av, bv);
        _mm256_storeu_si256((__m256i*)(out+i), rv);
    }
}
