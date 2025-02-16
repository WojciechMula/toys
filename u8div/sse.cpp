void sse_div_u8(const uint8_t* a, const uint8_t* b, uint8_t* out, size_t n) {
    for (size_t i=0; i < n; i += 4) {
        uint32_t buf_a;
        memcpy(&buf_a, &a[i], 4);
        const __m128i a_u8  = _mm_cvtsi32_si128(buf_a);
        const __m128i a_u32 = _mm_cvtepu8_epi32(a_u8);
        const __m128  a_f32 = _mm_cvtepi32_ps(a_u32);

        uint32_t buf_b;
        memcpy(&buf_b, &b[i], 4);
        const __m128i b_u8  = _mm_cvtsi32_si128(buf_b);
        const __m128i b_u32 = _mm_cvtepu8_epi32(b_u8);
        const __m128  b_f32 = _mm_cvtepi32_ps(b_u32);

        const __m128  c_f32   = _mm_div_ps(a_f32, b_f32);
        const __m128  c_f32_2 = _mm_round_ps(c_f32, _MM_FROUND_TO_ZERO |_MM_FROUND_NO_EXC);
        const __m128i c_i32 = _mm_cvtps_epi32(c_f32_2);

        const __m128i c_u8  = _mm_shuffle_epi8(c_i32, _mm_setr_epi8(
            0, 4, 8, 12,
            -1, -1, -1, -1,
            -1, -1, -1, -1,
            -1, -1, -1, -1
        ));

        const uint32_t buf = _mm_cvtsi128_si32(c_u8);
        memcpy(&out[i], &buf, 4);
    }
}

void sse_div_u8_no_rounding(const uint8_t* a, const uint8_t* b, uint8_t* out, size_t n) {
    for (size_t i=0; i < n; i += 4) {
        uint32_t buf_a;
        memcpy(&buf_a, &a[i], 4);
        const __m128i a_u8  = _mm_cvtsi32_si128(buf_a);

        // convert (u8 << 8) into u32
        const __m128i a_u32 = _mm_shuffle_epi8(a_u8, _mm_setr_epi8(
            -1, 0, -1, -1,
            -1, 1, -1, -1,
            -1, 2, -1, -1,
            -1, 3, -1, -1
        ));
        const __m128  a_f32 = _mm_cvtepi32_ps(a_u32);

        uint32_t buf_b;
        memcpy(&buf_b, &b[i], 4);
        const __m128i b_u8  = _mm_cvtsi32_si128(buf_b);
        const __m128i b_u32 = _mm_cvtepu8_epi32(b_u8);
        const __m128  b_f32 = _mm_cvtepi32_ps(b_u32);

        const __m128  c_f32 = _mm_div_ps(a_f32, b_f32);
        const __m128i c_i32 = _mm_cvtps_epi32(c_f32);

        const __m128i c_u8  = _mm_shuffle_epi8(c_i32, _mm_setr_epi8(
            0 + 1, 4 + 1, 8 + 1, 12 + 1,
            -1, -1, -1, -1,
            -1, -1, -1, -1,
            -1, -1, -1, -1
        ));

        const uint32_t buf = _mm_cvtsi128_si32(c_u8);
        memcpy(&out[i], &buf, 4);
    }
}

void sse_div_u8_cvtt(const uint8_t* a, const uint8_t* b, uint8_t* out, size_t n) {
    for (size_t i=0; i < n; i += 4) {
        uint32_t buf_a;
        memcpy(&buf_a, &a[i], 4);
        const __m128i a_u8  = _mm_cvtsi32_si128(buf_a);
        const __m128i a_u32 = _mm_cvtepu8_epi32(a_u8);
        const __m128  a_f32 = _mm_cvtepi32_ps(a_u32);

        uint32_t buf_b;
        memcpy(&buf_b, &b[i], 4);
        const __m128i b_u8  = _mm_cvtsi32_si128(buf_b);
        const __m128i b_u32 = _mm_cvtepu8_epi32(b_u8);
        const __m128  b_f32 = _mm_cvtepi32_ps(b_u32);

        const __m128  c_f32   = _mm_div_ps(a_f32, b_f32);
        const __m128i c_i32 = _mm_cvttps_epi32(c_f32);

        const __m128i c_u8  = _mm_shuffle_epi8(c_i32, _mm_setr_epi8(
            0, 4, 8, 12,
            -1, -1, -1, -1,
            -1, -1, -1, -1,
            -1, -1, -1, -1
        ));

        const uint32_t buf = _mm_cvtsi128_si32(c_u8);
        memcpy(&out[i], &buf, 4);
    }
}

void sse_div_u8_rcp(const uint8_t* a, const uint8_t* b, uint8_t* out, size_t n) {
    // Note: The magic constant 1.00025* was devised from rcp_test utility output.
    //       This tiny correction applied for the dividend masks RPC errors for
    //       small divisors (1..28) and fortunatelly does not affect the remaining
    //       divisors.
    //
    //       * anything between 1.00024 and 1.00199 works
    const __m128 coef = _mm_set1_ps(1.00025 * 256);
    for (size_t i=0; i < n; i += 4) {
        uint32_t buf_a;
        memcpy(&buf_a, &a[i], 4);
        const __m128i a_u8    = _mm_cvtsi32_si128(buf_a);
        const __m128i a_u32   = _mm_cvtepu8_epi32(a_u8);
        const __m128  a_f32_0 = _mm_cvtepi32_ps(a_u32);
        const __m128  a_f32   = _mm_mul_ps(a_f32_0, coef);

        uint32_t buf_b;
        memcpy(&buf_b, &b[i], 4);
        const __m128i b_u8  = _mm_cvtsi32_si128(buf_b);
        const __m128i b_u32 = _mm_cvtepu8_epi32(b_u8);
        const __m128  b_f32 = _mm_cvtepi32_ps(b_u32);
        const __m128  b_inv_f32 = _mm_rcp_ps(b_f32);

        const __m128  c_f32 = _mm_mul_ps(a_f32, b_inv_f32);
        const __m128i c_i32 = _mm_cvtps_epi32(c_f32);

        const __m128i c_u8  = _mm_shuffle_epi8(c_i32, _mm_setr_epi8(
            0 + 1, 4 + 1, 8 + 1, 12 + 1,
            -1, -1, -1, -1,
            -1, -1, -1, -1,
            -1, -1, -1, -1
        ));

        const uint32_t buf = _mm_cvtsi128_si32(c_u8);
        memcpy(&out[i], &buf, 4);
    }
}
