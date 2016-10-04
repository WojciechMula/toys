/*
    string - pointer to the string
    count  - string length in 64-byte blocks [!!!]
    needle - pointer to another string
    n      - needle length in bytes [!!!]
*/
size_t avx512f_strfind_gt4(const char* string, size_t count, const char* needle, size_t n) {

    assert(n > 4);

    __m512i curr;
    __m512i next;
    __m512i v0, v1, v2, v3;

    char* haystack = const_cast<char*>(string);

    const uint32_t prf   = *(uint32_t*)needle; // the first 4 bytes of needle
    const __m512i prefix = _mm512_set1_epi32(prf);

    next = _mm512_loadu_si512(haystack);

    for (size_t i=0; i < count; i++) {

        curr = next;
        next = _mm512_loadu_si512(haystack + 64);
        const __m512i shft = _mm512_alignr_epi32(next, curr, 1);

        v0 = curr;

        {
            const __m512i t1 = _mm512_srli_epi32(curr, 8);
            const __m512i t2 = _mm512_slli_epi32(shft, 24);
            v1 = _mm512_or_si512(t1, t2);
        }
        {
            const __m512i t1 = _mm512_srli_epi32(curr, 16);
            const __m512i t2 = _mm512_slli_epi32(shft, 16);
            v2 = _mm512_or_si512(t1, t2);
        }
        {
            const __m512i t1 = _mm512_srli_epi32(curr, 24);
            const __m512i t2 = _mm512_slli_epi32(shft, 8);
            v3 = _mm512_or_si512(t1, t2);
        }

        uint16_t m0 = _mm512_cmpeq_epi32_mask(v0, prefix);
        uint16_t m1 = _mm512_cmpeq_epi32_mask(v1, prefix);
        uint16_t m2 = _mm512_cmpeq_epi32_mask(v2, prefix);
        uint16_t m3 = _mm512_cmpeq_epi32_mask(v3, prefix);

        int index = 64;
        while (m0 | m1 | m2 | m3) {
            if (m0) {
                int pos = __builtin_ctz(m0) * 4 + 0;
                m0 = m0 & (m0 - 1);

                if (pos < index && memcmp(haystack + pos + 4, needle + 4, n - 4) == 0) {
                    index = pos;
                }
            }

            if (m1) {
                int pos = __builtin_ctz(m1) * 4 + 1;
                m1 = m1 & (m1 - 1);

                if (pos < index && memcmp(haystack + pos + 4, needle + 4, n - 4) == 0) {
                    index = pos;
                }
            }

            if (m2) {
                int pos = __builtin_ctz(m2) * 4 + 2;
                m2 = m2 & (m2 - 1);

                if (pos < index && memcmp(haystack + pos + 4, needle + 4, n - 4) == 0) {
                    index = pos;
                }
            }

            if (m3) {
                int pos = __builtin_ctz(m3) * 4 + 3;
                m3 = m3 & (m3 - 1);

                if (pos < index && memcmp(haystack + pos + 4, needle + 4, n - 4) == 0) {
                    index = pos;
                }
            }
        }

        if (index < 64) {
            return (haystack - string) + index;
        }

        haystack += 64;
    }

    return size_t(-1);
}

