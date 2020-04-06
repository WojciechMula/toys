__mmask16 FORCE_INLINE zero_byte_mask(const __m512i v) {

    const __m512i v01  = _mm512_set1_epi32(0x01010101u);
    const __m512i v80  = _mm512_set1_epi32(0x80808080u);

    const __m512i v1   = _mm512_sub_epi32(v, v01);
    const __m512i tmp1 = _mm512_ternarylogic_epi32(v1, v, v80, 0x20);

    return _mm512_test_epi32_mask(tmp1, tmp1);
}


int avx512f_strcmp(const char* s1, const char* s2) {


    char* c1 = const_cast<char*>(s1);
    char* c2 = const_cast<char*>(s2);

    __mmask16 zero1;
    __mmask16 diff;
    __mmask16 either;

    while (true) {

        const __m512i v1 = _mm512_loadu_si512(c1);
        const __m512i v2 = _mm512_loadu_si512(c2);

        // locate in s1 dwords having '\0'
        zero1 = zero_byte_mask(v1);
	// a '\0' in v2 will trigger a diff or a 1 bit in zero1
        diff  = _mm512_cmpneq_epi32_mask(v1, v2);

	// use lowest order 1 bit of either/both ops
	either = zero1 | diff;
        if (either) {
            break;
        }

        c1 += 64;
        c2 += 64;
    }

    const size_t n = __builtin_ctz(either);

    // move pointers to the first dword with diff and/or eos
    c1 += n * 4;
    c2 += n * 4;
    
    // strncmp resolves which byte wins
    for (int i=0; i < 4; i++) {
        int a = c1[i];
        int b = c2[i];

        if (a != b || !a) {
            return a - b;
        }
    }

    assert(false);

}

