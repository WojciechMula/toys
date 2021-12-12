// included directly

__m512i avx512_expand__version2(const char* ptr) {
    // load bytes 0..15 (16)
    const __m128i tmp0 = _mm_loadu_si128((const __m128i*)ptr);
    const __m512i t0 = _mm512_broadcast_i64x2(tmp0);

    // load bytes 16..19 (4)
    const uint32_t tmp1 = *(uint32_t*)(ptr + 16);
    const __m512i t1 = _mm512_set1_epi32(tmp1);

    // In the last lane we need bytes 13..19, so we're placing
    // 32-bit word from t1 at 0th position of the lane

    const __m512i t2 = _mm512_mask_mov_epi32(t0, 0x1000, t1);

    /** pshufb
        # lane{0,1,2} have got bytes: [  0,  1,  2,  3,  4,  5,  6,  8,  9, 10, 11, 12, 13, 14, 15]
        # lane3 has got bytes:        [ 16, 17, 18, 19,  4,  5,  6,  8,  9, 10, 11, 12, 13, 14, 15]

        expand_ver2 = [
            # lane 0:
            0, 1, 2, 3,
            1, 2, 3, 4,
            2, 3, 4, 5,
            3, 4, 5, 6,
            # lane 1:
            4, 5, 6, 7,
            5, 6, 7, 8,
            6, 7, 8, 9,
            7, 8, 9, 10,
            # lane 2:
             8,  9, 10, 11,
             9, 10, 11, 12,
            10, 11, 12, 13,
            11, 12, 13, 14,

            # lane 3 order: 13, 14, 15, 16 14, 15, 16, 17, 15, 16, 17, 18, 16, 17, 18, 19
            12, 13, 14, 15,
            13, 14, 15,  0,
            14, 15,  0,  1,
            15,  0,  1,  2,
        ]
    */
    const __m512i expand_ver2 = _mm512_setr_epi64(
        0x0403020103020100,
        0x0605040305040302,
        0x0807060507060504,
        0x0a09080709080706,
        0x0c0b0a090b0a0908,
        0x0e0d0c0b0d0c0b0a,
        0x000f0e0d0f0e0d0c,
        0x0201000f01000f0e
    );

    return _mm512_shuffle_epi8(t2, expand_ver2);
}

