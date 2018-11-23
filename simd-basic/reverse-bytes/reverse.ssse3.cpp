__m128i reverse_ssse3(const __m128i v) {

    // reverse all bytes at once
    const __m128i indices = _mm_set_epi8(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);

    return _mm_shuffle_epi8(indices, v);
}

