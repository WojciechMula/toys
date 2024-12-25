void avx2_div_u16_cvtt(const uint16_t* a, const uint16_t* b, uint16_t* out, size_t n) {
    const __m128i t0 = _mm_setr_epi8(
        0, 1, 4, 5,
        8, 9, 12, 13,
        -1, -1, -1, -1,
        -1, -1, -1, -1
    );

    const __m256i u32_u8 = _mm256_set_m128i(t0, t0);

    for (size_t i=0; i < n; i += 8) {
        const __m128i a_u16 = _mm_loadu_si128((const __m128i*)(&a[i]));
        const __m128i b_u16 = _mm_loadu_si128((const __m128i*)(&b[i]));

        const __m256i a_u32 = _mm256_cvtepu16_epi32(a_u16);
        const __m256  a_f32 = _mm256_cvtepi32_ps(a_u32);

        const __m256i b_u32 = _mm256_cvtepu16_epi32(b_u16);
        const __m256  b_f32 = _mm256_cvtepi32_ps(b_u32);

        const __m256  c_f32   = _mm256_div_ps(a_f32, b_f32);
        const __m256i c_i32   = _mm256_cvttps_epi32(c_f32);

        const __m256i c_u16   = _mm256_shuffle_epi8(c_i32, u32_u8);

        const uint64_t lo = _mm256_extract_epi64(c_u16, 0);
        const uint64_t hi = _mm256_extract_epi64(c_u16, 2);

        memcpy(&out[i],     &lo, 8);
        memcpy(&out[i + 4], &hi, 8);
    }
}

void avx2_div_u16_cvtt_ver2(const uint16_t* a, const uint16_t* b, uint16_t* out, size_t n) {
    const __m256i mask_lo = _mm256_set1_epi32(0x0000ffff);

    for (size_t i=0; i < n; i += 16) {
        const __m256i a_u16 = _mm256_loadu_si256((const __m256i*)(&a[i]));
        const __m256i b_u16 = _mm256_loadu_si256((const __m256i*)(&b[i]));

        const __m256i a_lo_u32 = _mm256_and_si256(a_u16, mask_lo);
        const __m256i b_lo_u32 = _mm256_and_si256(b_u16, mask_lo);

        const __m256i a_hi_u32 = _mm256_srli_epi32(a_u16, 16);
        const __m256i b_hi_u32 = _mm256_srli_epi32(b_u16, 16);

        const __m256  a_lo_f32 = _mm256_cvtepi32_ps(a_lo_u32);
        const __m256  a_hi_f32 = _mm256_cvtepi32_ps(a_hi_u32);
        const __m256  b_lo_f32 = _mm256_cvtepi32_ps(b_lo_u32);
        const __m256  b_hi_f32 = _mm256_cvtepi32_ps(b_hi_u32);

        const __m256  c_lo_f32 = _mm256_div_ps(a_lo_f32, b_lo_f32);
        const __m256  c_hi_f32 = _mm256_div_ps(a_hi_f32, b_hi_f32);

        const __m256i c_lo_i32   = _mm256_cvttps_epi32(c_lo_f32); // values in the u16 range
        const __m256i c_hi_i32_0 = _mm256_cvttps_epi32(c_hi_f32); // values in the u16 range
        const __m256i c_hi_i32   = _mm256_slli_epi32(c_hi_i32_0, 16);

        const __m256i c_u16 = _mm256_or_si256(c_lo_i32, c_hi_i32);

        _mm256_storeu_si256((__m256i*)(&out[i]), c_u16);
    }
}

void avx2_div_u16_cvtt_x2(const uint16_t* a, const uint16_t* b, uint16_t* out, size_t n) {
    const __m256i mask_lo = _mm256_set1_epi32(0x0000ffff);

    for (size_t i=0; i < n; i += 16*2) {
        const __m256i a0_u16 = _mm256_loadu_si256((const __m256i*)(&a[i]));
        const __m256i b0_u16 = _mm256_loadu_si256((const __m256i*)(&b[i]));
        const __m256i a1_u16 = _mm256_loadu_si256((const __m256i*)(&a[i + 1*16]));
        const __m256i b1_u16 = _mm256_loadu_si256((const __m256i*)(&b[i + 1*16]));

        const __m256i a0_lo_u32 = _mm256_and_si256(a0_u16, mask_lo);
        const __m256i b0_lo_u32 = _mm256_and_si256(b0_u16, mask_lo);
        const __m256i a1_lo_u32 = _mm256_and_si256(a1_u16, mask_lo);
        const __m256i b1_lo_u32 = _mm256_and_si256(b1_u16, mask_lo);

        const __m256i a0_hi_u32 = _mm256_srli_epi32(a0_u16, 16);
        const __m256i b0_hi_u32 = _mm256_srli_epi32(b0_u16, 16);
        const __m256i a1_hi_u32 = _mm256_srli_epi32(a1_u16, 16);
        const __m256i b1_hi_u32 = _mm256_srli_epi32(b1_u16, 16);

        const __m256  a0_lo_f32 = _mm256_cvtepi32_ps(a0_lo_u32);
        const __m256  a0_hi_f32 = _mm256_cvtepi32_ps(a0_hi_u32);
        const __m256  b0_lo_f32 = _mm256_cvtepi32_ps(b0_lo_u32);
        const __m256  b0_hi_f32 = _mm256_cvtepi32_ps(b0_hi_u32);
        const __m256  a1_lo_f32 = _mm256_cvtepi32_ps(a1_lo_u32);
        const __m256  a1_hi_f32 = _mm256_cvtepi32_ps(a1_hi_u32);
        const __m256  b1_lo_f32 = _mm256_cvtepi32_ps(b1_lo_u32);
        const __m256  b1_hi_f32 = _mm256_cvtepi32_ps(b1_hi_u32);

        const __m256  c0_lo_f32 = _mm256_div_ps(a0_lo_f32, b0_lo_f32);
        const __m256  c0_hi_f32 = _mm256_div_ps(a0_hi_f32, b0_hi_f32);
        const __m256  c1_lo_f32 = _mm256_div_ps(a1_lo_f32, b1_lo_f32);
        const __m256  c1_hi_f32 = _mm256_div_ps(a1_hi_f32, b1_hi_f32);

        const __m256i c0_lo_i32   = _mm256_cvttps_epi32(c0_lo_f32);
        const __m256i c0_hi_i32_0 = _mm256_cvttps_epi32(c0_hi_f32);
        const __m256i c0_hi_i32   = _mm256_slli_epi32(c0_hi_i32_0, 16);
        const __m256i c1_lo_i32   = _mm256_cvttps_epi32(c1_lo_f32);
        const __m256i c1_hi_i32_0 = _mm256_cvttps_epi32(c1_hi_f32);
        const __m256i c1_hi_i32   = _mm256_slli_epi32(c1_hi_i32_0, 16);

        const __m256i c0_u16 = _mm256_or_si256(c0_lo_i32, c0_hi_i32);
        const __m256i c1_u16 = _mm256_or_si256(c1_lo_i32, c1_hi_i32);

        _mm256_storeu_si256((__m256i*)(&out[i]), c0_u16);
        _mm256_storeu_si256((__m256i*)(&out[i + 1*16]), c1_u16);
    }
}

void avx2_div_u16_cvtt_x4(const uint16_t* a, const uint16_t* b, uint16_t* out, size_t n) {
    const __m256i mask_lo = _mm256_set1_epi32(0x0000ffff);

    for (size_t i=0; i < n; i += 16*4) {
        const __m256i a0_u16 = _mm256_loadu_si256((const __m256i*)(&a[i]));
        const __m256i b0_u16 = _mm256_loadu_si256((const __m256i*)(&b[i]));
        const __m256i a1_u16 = _mm256_loadu_si256((const __m256i*)(&a[i + 1*16]));
        const __m256i b1_u16 = _mm256_loadu_si256((const __m256i*)(&b[i + 1*16]));
        const __m256i a2_u16 = _mm256_loadu_si256((const __m256i*)(&a[i + 2*16]));
        const __m256i b2_u16 = _mm256_loadu_si256((const __m256i*)(&b[i + 2*16]));
        const __m256i a3_u16 = _mm256_loadu_si256((const __m256i*)(&a[i + 3*16]));
        const __m256i b3_u16 = _mm256_loadu_si256((const __m256i*)(&b[i + 3*16]));

        const __m256i a0_lo_u32 = _mm256_and_si256(a0_u16, mask_lo);
        const __m256i b0_lo_u32 = _mm256_and_si256(b0_u16, mask_lo);
        const __m256i a1_lo_u32 = _mm256_and_si256(a1_u16, mask_lo);
        const __m256i b1_lo_u32 = _mm256_and_si256(b1_u16, mask_lo);
        const __m256i a2_lo_u32 = _mm256_and_si256(a2_u16, mask_lo);
        const __m256i b2_lo_u32 = _mm256_and_si256(b2_u16, mask_lo);
        const __m256i a3_lo_u32 = _mm256_and_si256(a3_u16, mask_lo);
        const __m256i b3_lo_u32 = _mm256_and_si256(b3_u16, mask_lo);

        const __m256i a0_hi_u32 = _mm256_srli_epi32(a0_u16, 16);
        const __m256i b0_hi_u32 = _mm256_srli_epi32(b0_u16, 16);
        const __m256i a1_hi_u32 = _mm256_srli_epi32(a1_u16, 16);
        const __m256i b1_hi_u32 = _mm256_srli_epi32(b1_u16, 16);
        const __m256i a2_hi_u32 = _mm256_srli_epi32(a2_u16, 16);
        const __m256i b2_hi_u32 = _mm256_srli_epi32(b2_u16, 16);
        const __m256i a3_hi_u32 = _mm256_srli_epi32(a3_u16, 16);
        const __m256i b3_hi_u32 = _mm256_srli_epi32(b3_u16, 16);

        const __m256  a0_lo_f32 = _mm256_cvtepi32_ps(a0_lo_u32);
        const __m256  a0_hi_f32 = _mm256_cvtepi32_ps(a0_hi_u32);
        const __m256  b0_lo_f32 = _mm256_cvtepi32_ps(b0_lo_u32);
        const __m256  b0_hi_f32 = _mm256_cvtepi32_ps(b0_hi_u32);
        const __m256  a1_lo_f32 = _mm256_cvtepi32_ps(a1_lo_u32);
        const __m256  a1_hi_f32 = _mm256_cvtepi32_ps(a1_hi_u32);
        const __m256  b1_lo_f32 = _mm256_cvtepi32_ps(b1_lo_u32);
        const __m256  b1_hi_f32 = _mm256_cvtepi32_ps(b1_hi_u32);
        const __m256  a2_lo_f32 = _mm256_cvtepi32_ps(a2_lo_u32);
        const __m256  a2_hi_f32 = _mm256_cvtepi32_ps(a2_hi_u32);
        const __m256  b2_lo_f32 = _mm256_cvtepi32_ps(b2_lo_u32);
        const __m256  b2_hi_f32 = _mm256_cvtepi32_ps(b2_hi_u32);
        const __m256  a3_lo_f32 = _mm256_cvtepi32_ps(a3_lo_u32);
        const __m256  a3_hi_f32 = _mm256_cvtepi32_ps(a3_hi_u32);
        const __m256  b3_lo_f32 = _mm256_cvtepi32_ps(b3_lo_u32);
        const __m256  b3_hi_f32 = _mm256_cvtepi32_ps(b3_hi_u32);

        const __m256  c0_lo_f32 = _mm256_div_ps(a0_lo_f32, b0_lo_f32);
        const __m256  c0_hi_f32 = _mm256_div_ps(a0_hi_f32, b0_hi_f32);
        const __m256  c1_lo_f32 = _mm256_div_ps(a1_lo_f32, b1_lo_f32);
        const __m256  c1_hi_f32 = _mm256_div_ps(a1_hi_f32, b1_hi_f32);
        const __m256  c2_lo_f32 = _mm256_div_ps(a2_lo_f32, b2_lo_f32);
        const __m256  c2_hi_f32 = _mm256_div_ps(a2_hi_f32, b2_hi_f32);
        const __m256  c3_lo_f32 = _mm256_div_ps(a3_lo_f32, b3_lo_f32);
        const __m256  c3_hi_f32 = _mm256_div_ps(a3_hi_f32, b3_hi_f32);

        const __m256i c0_lo_i32   = _mm256_cvttps_epi32(c0_lo_f32);
        const __m256i c0_hi_i32_0 = _mm256_cvttps_epi32(c0_hi_f32);
        const __m256i c0_hi_i32   = _mm256_slli_epi32(c0_hi_i32_0, 16);
        const __m256i c1_lo_i32   = _mm256_cvttps_epi32(c1_lo_f32);
        const __m256i c1_hi_i32_0 = _mm256_cvttps_epi32(c1_hi_f32);
        const __m256i c1_hi_i32   = _mm256_slli_epi32(c1_hi_i32_0, 16);
        const __m256i c2_lo_i32   = _mm256_cvttps_epi32(c2_lo_f32);
        const __m256i c2_hi_i32_0 = _mm256_cvttps_epi32(c2_hi_f32);
        const __m256i c2_hi_i32   = _mm256_slli_epi32(c2_hi_i32_0, 16);
        const __m256i c3_lo_i32   = _mm256_cvttps_epi32(c3_lo_f32);
        const __m256i c3_hi_i32_0 = _mm256_cvttps_epi32(c3_hi_f32);
        const __m256i c3_hi_i32   = _mm256_slli_epi32(c3_hi_i32_0, 16);

        const __m256i c0_u16 = _mm256_or_si256(c0_lo_i32, c0_hi_i32);
        const __m256i c1_u16 = _mm256_or_si256(c1_lo_i32, c1_hi_i32);
        const __m256i c2_u16 = _mm256_or_si256(c2_lo_i32, c2_hi_i32);
        const __m256i c3_u16 = _mm256_or_si256(c3_lo_i32, c3_hi_i32);

        _mm256_storeu_si256((__m256i*)(&out[i]), c0_u16);
        _mm256_storeu_si256((__m256i*)(&out[i + 1*16]), c1_u16);
        _mm256_storeu_si256((__m256i*)(&out[i + 2*16]), c2_u16);
        _mm256_storeu_si256((__m256i*)(&out[i + 3*16]), c3_u16);
    }
}

__m256 nr_step(const __m256 x0, const __m256 a) {
    const __m256 t0 = _mm256_add_ps(x0, x0);
    const __m256 t1 = _mm256_mul_ps(x0, x0);
    const __m256 t2 = _mm256_mul_ps(t1, a);
    const __m256 t3 = _mm256_sub_ps(t0, t2);

    return t3;
}

__m256 nr_inv(const __m256 a) {
    const __m256 x0 = _mm256_rcp_ps(a);
    const __m256 x1 = nr_step(x0, a);
    return x1;
}

void avx2_div_u16_rcp(const uint16_t* a, const uint16_t* b, uint16_t* out, size_t n) {
    const __m128i t0 = _mm_setr_epi8(
        0, 1, 4, 5,
        8, 9, 12, 13,
        -1, -1, -1, -1,
        -1, -1, -1, -1
    );

    const __m256i u32_u8 = _mm256_set_m128i(t0, t0);

    for (size_t i=0; i < n; i += 8) {
        const __m128i a_u16 = _mm_loadu_si128((const __m128i*)(&a[i]));
        const __m128i b_u16 = _mm_loadu_si128((const __m128i*)(&b[i]));

        const __m256i a_u32 = _mm256_cvtepu16_epi32(a_u16);
        const __m256  a_f32 = _mm256_cvtepi32_ps(a_u32);

        const __m256i b_u32 = _mm256_cvtepu16_epi32(b_u16);
        const __m256  b_f32 = _mm256_cvtepi32_ps(b_u32);

        const __m256  b_inv_f32 = nr_inv(b_f32);
        const __m256  as_f32    = _mm256_mul_ps(a_f32, _mm256_set1_ps(1.000001));
        const __m256  c_f32     = _mm256_mul_ps(as_f32, b_inv_f32);
        const __m256i c_i32     = _mm256_cvttps_epi32(c_f32);

        const __m256i c_u16   = _mm256_shuffle_epi8(c_i32, u32_u8);

        const uint64_t lo = _mm256_extract_epi64(c_u16, 0);
        const uint64_t hi = _mm256_extract_epi64(c_u16, 2);

        memcpy(&out[i],     &lo, 8);
        memcpy(&out[i + 4], &hi, 8);
    }
}
