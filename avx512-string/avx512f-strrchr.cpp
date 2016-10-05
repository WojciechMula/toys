char* avx512f_strrchr(const char* s, char c) {

    const __m512i v01 = _mm512_set1_epi32(0x01010101u);
    const __m512i v80 = _mm512_set1_epi32(0x80808080u);
    const __m512i ccc = _mm512_set1_epi32(0x01010101u * uint32_t(c));

    char* ptr = const_cast<char*>(s);
    char* result = NULL;

    while (true) {

        const __m512i v = _mm512_loadu_si512(ptr);

        // locate the first '\0' within register
        const __m512i   v1        = _mm512_sub_epi32(v, v01);
        const __m512i   tmp1      = _mm512_ternarylogic_epi32(v1, v, v80, 0x20);
        const __mmask16 zero_mask = _mm512_test_epi32_mask(tmp1, tmp1);

        // locate any occurrence of c within register
        const __m512i   vc        = _mm512_xor_si512(v,  ccc);
        const __m512i   vc1       = _mm512_sub_epi32(vc, v01);
        const __m512i   tmp2      = _mm512_ternarylogic_epi32(vc1, vc, v80, 0x20);
        const __mmask16 char_mask = _mm512_test_epi32_mask(tmp2, tmp2);

        if (!_mm512_kortestz(zero_mask, char_mask)) {

            if (zero_mask == 0) {

                // simply update last occurrence of c withing current chunk

                const size_t n = 31 - __builtin_clz(char_mask);

                if (ptr[4*n + 3] == c) result = ptr + 4*n + 3; else
                if (ptr[4*n + 2] == c) result = ptr + 4*n + 2; else
                if (ptr[4*n + 1] == c) result = ptr + 4*n + 1; else
                if (ptr[4*n + 0] == c) result = ptr + 4*n + 0; else assert(false);

            } else if (char_mask == 0) {

                // no character c within the current chunk --- simply return

                return result;
            } else {

                // there are both terminating zero and c, more tests are needed

                const uint16_t first_zero = zero_mask & -zero_mask;

                if (first_zero & char_mask) {

                    // there is a dword having both zero and c
                    const size_t n = __builtin_ctz(first_zero);
                    bool set = false;

                    for (int i=0; i < 4; i++) {
                        if (ptr[4*n + i] == 0) {
                            break;
                        } else if (ptr[4*n + i] == c) {
                            result = ptr + 4*n + i;
                            set = true;
                        }
                    }

                    if (set) {
                        // if c was found in this dword it's not need to process preceding dwords
                        return result;
                    }
                }

                // clear char_mask after the first zero
                const uint32_t char_before_zero = char_mask & (first_zero - 1);

                if (char_before_zero) {
                    const size_t n = 31 - __builtin_clz(char_before_zero);

                    if (ptr[4*n + 3] == c) result = ptr + 4*n + 3; else
                    if (ptr[4*n + 2] == c) result = ptr + 4*n + 2; else
                    if (ptr[4*n + 1] == c) result = ptr + 4*n + 1; else
                    if (ptr[4*n + 0] == c) result = ptr + 4*n + 0; else assert(false);
                }
            }

        }

        ptr += 64;
    }
}

