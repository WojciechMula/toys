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
    __mmask16 zero2;
    __mmask16 diff;

    while (true) {

        const __m512i v1 = _mm512_loadu_si512(c1);
        const __m512i v2 = _mm512_loadu_si512(c2);

        // locate in s1 dwords having '\0'
        zero1 = zero_byte_mask(v1);

        // locate in s1 dwords having '\0'
        zero2 = zero_byte_mask(v2);

        // locate differences between s1 and s2
        diff  = _mm512_cmpneq_epi32_mask(_mm512_xor_si512(v1, v2), _mm512_setzero_si512());

        if (zero1 != 0 || zero2 != 0 || diff != 0) {
            break;
        }

        c1 += 64;
        c2 += 64;
    }

    // get result

    const uint16_t zeros = zero1 | zero2;

    if (zeros == 0) {
        
        // no zeros within current chunk
        const size_t n = __builtin_ctz(diff);

        // move pointers to the first dword with diff
        c1 += n * 4;
        c2 += n * 4;
        goto locate_diff;

    } else if (diff == 0) {

        // no explicit diff, but one string might be shorter
        const size_t k = __builtin_ctz(zeros);
        c1 += k * 4;
        c2 += k * 4;
        goto locate_diff_or_eos;

    } else {

        // there is diff and zeros
        const size_t n = __builtin_ctz(diff);
        const size_t k = __builtin_ctz(zeros);
        if (n < k) {
            // first difference is located in dword preceeding dword with zeros
            // move pointers to that dword
            c1 += n * 4;
            c2 += n * 4;
            goto locate_diff;
        } else if (k > n) {
            
            // first difference is past zeros (strings are equal, but garbage after EOS differs)
            return 0;
        } else /* n == k */ {
            
             c1 += k * 4;
             c2 += k * 4;
             goto locate_diff_or_eos;
        }
    }

    assert(false);

locate_diff:
    
    for (int i=0; i < 4; i++) {
        int a = c1[i];
        int b = c2[i];
        if (a != b) {
            return a - b;
        }
    }

    assert(false);

locate_diff_or_eos:

    for (int i=0; i < 4; i++) {
        int a = c1[i];
        int b = c2[i];
        if (a == 0 && b == 0) {
            return 0;
        }

        if (a != b) {
            return a - b;
        }
    }

    assert(false);
}

