__m512i reverse_avx512bw(const __m512i v) {

    // 1. reverse order of 128-bit lanes
    const __m512i indices = _mm512_setr_epi32(
                                12, 13, 14, 15,
                                 8,  9, 10, 11,
                                 4,  5,  6,  7,
                                 0,  1,  2,  3);
    const __m512i swap_128 = _mm512_permutexvar_epi32(indices, v);

    // 2. reverse order of bytes within 128-bit lanes
    const __m512i indices_byte = _mm512_set_epi64(
        0x0001020304050607llu, 0x08090a0b0c0d0e0fllu,
        0x0001020304050607llu, 0x08090a0b0c0d0e0fllu,
        0x0001020304050607llu, 0x08090a0b0c0d0e0fllu,
        0x0001020304050607llu, 0x08090a0b0c0d0e0fllu
    );

    return _mm512_shuffle_epi8(swap_128, indices_byte);
}

