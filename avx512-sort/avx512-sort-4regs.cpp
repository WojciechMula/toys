
void FORCE_INLINE avx512_sort4xreg_update(
    const __m512i b,
    const __m512i v1, const __m512i v2, const __m512i v3, const __m512i v4,
    __m512i& r1, __m512i& r2, __m512i& r3, __m512i& r4) {

    const uint64_t lt1    = _mm512_cmplt_epi32_mask(v1, b);
    const uint64_t lt2    = _mm512_cmplt_epi32_mask(v2, b);
    const uint64_t lt3    = _mm512_cmplt_epi32_mask(v3, b);
    const uint64_t lt4    = _mm512_cmplt_epi32_mask(v4, b);
    const uint64_t lt_cnt = _mm_popcnt_u64(lt1 | (lt2 << 16) | (lt3 << 32) | (lt4 << 48));

    const uint64_t eq1    = _mm512_cmpeq_epi32_mask(v1, b);
    const uint64_t eq2    = _mm512_cmpeq_epi32_mask(v2, b);
    const uint64_t eq3    = _mm512_cmpeq_epi32_mask(v3, b);
    const uint64_t eq4    = _mm512_cmpeq_epi32_mask(v4, b);
    const uint64_t eq_cnt = _mm_popcnt_u64(eq1 | (eq2 << 16) | (eq3 << 32) | (eq4 << 48));

    if (eq_cnt == 64) {
        r1 = r2 = r3 = r4 = b;
        return;
    }

    const uint64_t mask   = (uint64_t(1) << (lt_cnt + eq_cnt)) - (uint64_t(1) << lt_cnt);

    r1 = _mm512_mask_mov_epi32(r1, mask & 0xffff, b);
    r2 = _mm512_mask_mov_epi32(r2, (mask >> 16) & 0xffff, b);
    r3 = _mm512_mask_mov_epi32(r3, (mask >> 32) & 0xffff, b);
    r4 = _mm512_mask_mov_epi32(r4, (mask >> 48) & 0xffff, b);
}


void avx512_sort4xreg_epi32(
    const __m512i v1, const __m512i v2, const __m512i v3, const __m512i v4,
    __m512i& r1, __m512i& r2, __m512i& r3, __m512i& r4) {

    r1 = _mm512_setzero_si512();
    r2 = _mm512_setzero_si512();
    r3 = _mm512_setzero_si512();
    r4 = _mm512_setzero_si512();
    __m512i index;
    __m512i incr  = _mm512_set1_epi32(1);

#define STEP(input) { \
    const __m512i  b = _mm512_permutexvar_epi32(index, input); \
    index  = _mm512_add_epi32(index, incr); \
    avx512_sort4xreg_update(b, v1, v2, v3, v4, r1, r2, r3, r4); \
}

#define STEPx4(input) \
    STEP(input); STEP(input); STEP(input); STEP(input);

#define STEPx16(input) \
    index = _mm512_setzero_si512(); \
    STEPx4(input); STEPx4(input); STEPx4(input); STEPx4(input);

    STEPx16(v1);
    STEPx16(v2);
    STEPx16(v3);
    STEPx16(v4);

#undef STEP
#undef STEPx4
#undef STEPx16
}
