size_t avx512f_strlen(const char* s) {

    const __m512i v01 = _mm512_set1_epi32(0x01010101u);
    const __m512i v80 = _mm512_set1_epi32(0x80808080u);
    size_t len = 0;

    while (true) {

        const __m512i v = _mm512_loadu_si512(s + len);

        // from https://graphics.stanford.edu/~seander/bithacks.html#ZeroInWord
        // haszero(v) (((v) - 0x01010101UL) & ~(v) & 0x80808080UL)
        const __m512i v1 = _mm512_sub_epi32(v, v01);
        /*
            v1  v  m  v1 & ~v & m
             0  0  0  0
             0  0  1  0
             0  1  0  0
             0  1  1  0
             1  0  0  0
             1  0  1  1
             1  1  0  0
             1  1  1  0
        */
        const __m512i   haszero = _mm512_ternarylogic_epi32(v1, v, v80, 0x20);
        const __mmask16 mask    = _mm512_test_epi32_mask(haszero, haszero);
        if (mask) {
            const size_t n = __builtin_ctz(mask); // number of dword

            if (s[len + 4*n + 0] == 0) return len + 4*n + 0;
            if (s[len + 4*n + 1] == 0) return len + 4*n + 1;
            if (s[len + 4*n + 2] == 0) return len + 4*n + 2;

            assert(s[len + 4*n + 3] == 0);
            return len + 4*n + 3;
        }

        len += 64;
    }
}
