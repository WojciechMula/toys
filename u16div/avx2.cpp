#include "../000helpers/avx2-dump.h"

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
        const __m256  c_f32   = _mm256_mul_ps(a_f32, b_inv_f32);
        const __m256i c_i32   = _mm256_cvttps_epi32(c_f32);

        const __m256i c_u16   = _mm256_shuffle_epi8(c_i32, u32_u8);

        const uint64_t lo = _mm256_extract_epi64(c_u16, 0);
        const uint64_t hi = _mm256_extract_epi64(c_u16, 2);

        memcpy(&out[i],     &lo, 8);
        memcpy(&out[i + 4], &hi, 8);
    }
}
