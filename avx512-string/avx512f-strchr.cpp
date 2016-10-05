char* avx512f_strchr__reference_implementation(const char* s, char c) {

    const __m512i v01 = _mm512_set1_epi32(0x01010101u);
    const __m512i v80 = _mm512_set1_epi32(0x80808080u);
    const __m512i ccc = _mm512_set1_epi32(uint32_t(c) | (uint32_t(c) << 8) | (uint32_t(c) << 16) | (uint32_t(c) << 24));

    char* ptr = const_cast<char*>(s);

    while (true) {

        const __m512i v = _mm512_loadu_si512(ptr);

        // locate the first '\0' within register
        const __m512i   v1        = _mm512_sub_epi32(v, v01);
        const __m512i   tmp1      = _mm512_ternarylogic_epi32(v1, v, v80, 0x20);
        const __mmask16 zero_mask = _mm512_test_epi32_mask(tmp1, tmp1);

        // locate the first c within register
        const __m512i   vc        = _mm512_xor_si512(v,  ccc);
        const __m512i   vc1       = _mm512_sub_epi32(vc, v01);
        const __m512i   tmp2      = _mm512_ternarylogic_epi32(vc1, vc, v80, 0x20);
        const __mmask16 char_mask = _mm512_test_epi32_mask(tmp2, tmp2);

        const __mmask16 mask = zero_mask | char_mask;
        if (mask) {
            /*
                Perhaps better approach: get number of dword separately
                for zero_mask and char_mask. If the numbers are different
                we could choose a faster path where comparison just with
                zero or char is done.
            */
            const size_t n = __builtin_ctz(mask); // number of dword

            char t;

            t = ptr[4*n + 0];
            if (t == 0) return NULL;
            if (t == c) return ptr + 4*n + 0;

            t = ptr[4*n + 1];
            if (t == 0) return NULL;
            if (t == c) return ptr + 4*n + 1;

            t = ptr[4*n + 2];
            if (t == 0) return NULL;
            if (t == c) return ptr + 4*n + 2;

            t = ptr[4*n + 3];
            if (t == 0) return NULL;
            if (t == c) return ptr + 4*n + 3;

            assert(false && "unxpected invocation");
        }

        ptr += 64;
    }
}


char* avx512f_strchr(const char* s, char c) {

    const __m512i v01 = _mm512_set1_epi32(0x01010101u);
    const __m512i v80 = _mm512_set1_epi32(0x80808080u);
    const __m512i ccc = _mm512_set1_epi32(0x01010101u * uint32_t(c));

    char* ptr = const_cast<char*>(s);

    while (true) {

        const __m512i v = _mm512_loadu_si512(ptr);

        const __m512i   vc        = _mm512_xor_si512(v,  ccc);
        const __m512i   v1        = _mm512_sub_epi32(v, v01);
        const __m512i   vc1       = _mm512_sub_epi32(vc, v01);
        const __m512i   tmp1      = _mm512_ternarylogic_epi32(v1, v, v80, 0x20);
        const __m512i   tmp2      = _mm512_ternarylogic_epi32(vc1, vc, v80, 0x20);
        const __mmask16 zero_mask = _mm512_test_epi32_mask(tmp1, tmp1);
        const __mmask16 char_mask = _mm512_test_epi32_mask(tmp2, tmp2);

        if (!_mm512_kortestz(zero_mask, char_mask)) {
            const size_t n = __builtin_ctz(zero_mask | char_mask); // number of dword

            char t;

            t = ptr[4*n + 0];
            if (t == 0) return NULL;
            if (t == c) return ptr + 4*n + 0;

            t = ptr[4*n + 1];
            if (t == 0) return NULL;
            if (t == c) return ptr + 4*n + 1;

            t = ptr[4*n + 2];
            if (t == 0) return NULL;
            if (t == c) return ptr + 4*n + 2;

            t = ptr[4*n + 3];
            if (t == 0) return NULL;
            if (t == c) return ptr + 4*n + 3;

            assert(false && "unxpected invocation");
        }

        ptr += 64;
    }
}
