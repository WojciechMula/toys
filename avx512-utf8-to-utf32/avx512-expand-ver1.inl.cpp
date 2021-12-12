// included directly

__m512i avx512_expand__version1(const char* ptr) {
    const __m512i indices = _mm512_setr_epi32(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
    return _mm512_i32gather_epi32(indices, ptr, 1);
}
