#define STEP(unused) { \
    const __m512i  b    = _mm512_permutexvar_epi32(index, v); \
    const uint16_t lt   = _mm_popcnt_u32(_mm512_mask_cmplt_epi32_mask(sort_mask, v, b)); \
    const uint16_t eq   = _mm_popcnt_u32(_mm512_mask_cmpeq_epi32_mask(sort_mask, v, b)); \
    const uint16_t mask = (uint32_t(1) << (lt + eq)) - (uint32_t(1) << lt); \
    result = _mm512_mask_mov_epi32(result, mask, b); \
    index  = _mm512_add_epi32(index, incr); \
}

__m512i avx512_sort16_epi32(const __m512i v) {

    __m512i result = v;
    __m512i index = _mm512_setzero_si512();
    __m512i incr  = _mm512_set1_epi32(1);

    const uint16_t sort_mask = 0xffff;
    STEP(0);
    STEP(1);
    STEP(2);
    STEP(3);
    STEP(4);
    STEP(5);
    STEP(6);
    STEP(7);
    STEP(8);
    STEP(9);
    STEP(10);
    STEP(11);
    STEP(12);
    STEP(13);
    STEP(14);
    STEP(15);

    return result;
}

__m512i avx512_sort15_epi32(const __m512i v) {

    __m512i result = v;
    __m512i index = _mm512_setzero_si512();
    __m512i incr  = _mm512_set1_epi32(1);

    const uint16_t sort_mask = 0x7fff;
    STEP(0);
    STEP(1);
    STEP(2);
    STEP(3);
    STEP(4);
    STEP(5);
    STEP(6);
    STEP(7);
    STEP(8);
    STEP(9);
    STEP(10);
    STEP(11);
    STEP(12);
    STEP(13);
    STEP(14);

    return result;
}

__m512i avx512_sort14_epi32(const __m512i v) {

    __m512i result = v;
    __m512i index = _mm512_setzero_si512();
    __m512i incr  = _mm512_set1_epi32(1);

    const uint16_t sort_mask = 0x3fff;
    STEP(0);
    STEP(1);
    STEP(2);
    STEP(3);
    STEP(4);
    STEP(5);
    STEP(6);
    STEP(7);
    STEP(8);
    STEP(9);
    STEP(10);
    STEP(11);
    STEP(12);
    STEP(13);

    return result;
}

__m512i avx512_sort13_epi32(const __m512i v) {

    __m512i result = v;
    __m512i index = _mm512_setzero_si512();
    __m512i incr  = _mm512_set1_epi32(1);

    const uint16_t sort_mask = 0x1fff;
    STEP(0);
    STEP(1);
    STEP(2);
    STEP(3);
    STEP(4);
    STEP(5);
    STEP(6);
    STEP(7);
    STEP(8);
    STEP(9);
    STEP(10);
    STEP(11);
    STEP(12);

    return result;
}

__m512i avx512_sort12_epi32(const __m512i v) {

    __m512i result = v;
    __m512i index = _mm512_setzero_si512();
    __m512i incr  = _mm512_set1_epi32(1);

    const uint16_t sort_mask = 0x0fff;
    STEP(0);
    STEP(1);
    STEP(2);
    STEP(3);
    STEP(4);
    STEP(5);
    STEP(6);
    STEP(7);
    STEP(8);
    STEP(9);
    STEP(10);
    STEP(11);

    return result;
}

__m512i avx512_sort11_epi32(const __m512i v) {

    __m512i result = v;
    __m512i index = _mm512_setzero_si512();
    __m512i incr  = _mm512_set1_epi32(1);

    const uint16_t sort_mask = 0x07ff;
    STEP(0);
    STEP(1);
    STEP(2);
    STEP(3);
    STEP(4);
    STEP(5);
    STEP(6);
    STEP(7);
    STEP(8);
    STEP(9);
    STEP(10);

    return result;
}

__m512i avx512_sort10_epi32(const __m512i v) {

    __m512i result = v;
    __m512i index = _mm512_setzero_si512();
    __m512i incr  = _mm512_set1_epi32(1);

    const uint16_t sort_mask = 0x03ff;
    STEP(0);
    STEP(1);
    STEP(2);
    STEP(3);
    STEP(4);
    STEP(5);
    STEP(6);
    STEP(7);
    STEP(8);
    STEP(9);

    return result;
}

__m512i avx512_sort9_epi32(const __m512i v) {

    __m512i result = v;
    __m512i index = _mm512_setzero_si512();
    __m512i incr  = _mm512_set1_epi32(1);

    const uint16_t sort_mask = 0x01ff;
    STEP(0);
    STEP(1);
    STEP(2);
    STEP(3);
    STEP(4);
    STEP(5);
    STEP(6);
    STEP(7);
    STEP(8);

    return result;
}

__m512i avx512_sort8_epi32(const __m512i v) {

    __m512i result = v;
    __m512i index = _mm512_setzero_si512();
    __m512i incr  = _mm512_set1_epi32(1);

    const uint16_t sort_mask = 0x00ff;
    STEP(0);
    STEP(1);
    STEP(2);
    STEP(3);
    STEP(4);
    STEP(5);
    STEP(6);
    STEP(7);

    return result;
}

__m512i avx512_sort7_epi32(const __m512i v) {

    __m512i result = v;
    __m512i index = _mm512_setzero_si512();
    __m512i incr  = _mm512_set1_epi32(1);

    const uint16_t sort_mask = 0x007f;
    STEP(0);
    STEP(1);
    STEP(2);
    STEP(3);
    STEP(4);
    STEP(5);
    STEP(6);

    return result;
}

__m512i avx512_sort6_epi32(const __m512i v) {

    __m512i result = v;
    __m512i index = _mm512_setzero_si512();
    __m512i incr  = _mm512_set1_epi32(1);

    const uint16_t sort_mask = 0x003f;
    STEP(0);
    STEP(1);
    STEP(2);
    STEP(3);
    STEP(4);
    STEP(5);

    return result;
}

__m512i avx512_sort5_epi32(const __m512i v) {

    __m512i result = v;
    __m512i index = _mm512_setzero_si512();
    __m512i incr  = _mm512_set1_epi32(1);

    const uint16_t sort_mask = 0x001f;
    STEP(0);
    STEP(1);
    STEP(2);
    STEP(3);
    STEP(4);

    return result;
}

__m512i avx512_sort4_epi32(const __m512i v) {

    __m512i result = v;
    __m512i index = _mm512_setzero_si512();
    __m512i incr  = _mm512_set1_epi32(1);

    const uint16_t sort_mask = 0x000f;
    STEP(0);
    STEP(1);
    STEP(2);
    STEP(3);

    return result;
}

__m512i avx512_sort3_epi32(const __m512i v) {

    __m512i result = v;
    __m512i index = _mm512_setzero_si512();
    __m512i incr  = _mm512_set1_epi32(1);

    const uint16_t sort_mask = 0x0007;
    STEP(0);
    STEP(1);
    STEP(2);

    return result;
}

#undef STEP
