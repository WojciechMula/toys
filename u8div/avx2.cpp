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
