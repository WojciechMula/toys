void avx512_swap_align_masks(__mmask16& a, __mmask16& b, __mmask16& rem_a, __mmask16& rem_b) {

    assert(a != 0);
    assert(b != 0);

    uint16_t tmpA = a;
    uint16_t tmpB = b;
        
    while (tmpA != 0 && tmpB != 0) {
        tmpA = tmpA & (tmpA - 1);
        tmpB = tmpB & (tmpB - 1);
    }

    a = a ^ tmpA;
    b = b ^ tmpB;

    assert(a != 0);
    assert(b != 0);
    assert(_mm_popcnt_u64(a) == _mm_popcnt_u64(b));

    rem_a = tmpA;
    rem_b = tmpB;
}

void avx512_swap_epi32(__m512i& a, __m512i& b, __mmask16 mask_a, __mmask16 mask_b) {
    
    assert(mask_a != 0);
    assert(mask_b != 0);
    assert(_mm_popcnt_u64(mask_a) == _mm_popcnt_u64(mask_b));

    const __m512i to_swap_b = _mm512_mask_compress_epi32(_mm512_setzero_si512(), mask_a, a);
    const __m512i to_swap_a = _mm512_mask_compress_epi32(_mm512_setzero_si512(), mask_b, b);

    a = _mm512_mask_expand_epi32(a, mask_a, to_swap_a);
    b = _mm512_mask_expand_epi32(b, mask_b, to_swap_b);
}


void avx512_partition_epi32(uint32_t* array, uint32_t pv, int& left, int& right) {

    const int N = 16;

    __m512i L;
    __m512i R;
    __mmask16 maskL = 0;
    __mmask16 maskR = 0;
    const __m512i pivot = _mm512_set1_epi32(pv);

    while (right - left + 1 >= 2*N) {

        while (maskL == 0) {
            if (right - (left + N) + 1 < 2*N) {
                goto end;
            }

            L = _mm512_loadu_si512(array + left);
            maskL = _mm512_cmpge_epi32_mask(L, pivot);
            if (maskL == 0) {
                left += N;
            }
        }

        while (maskR == 0) {
            if ((right - N) - left + 1 < 2*N) {
                goto end;
            }

            R = _mm512_loadu_si512(array + right - N + 1);
            maskR = _mm512_cmple_epi32_mask(R, pivot);
            if (maskR == 0) {
                right -= N;
            }
        }

        assert(left <= right);
        assert(maskL != 0);
        assert(maskR != 0);
        
        __mmask16 mL;
        __mmask16 mR;

        avx512_swap_align_masks(maskL, maskR, mL, mR);
        avx512_swap_epi32(L, R, maskL, maskR);

        maskL = mL;
        maskR = mR;

        if (maskL == 0) {
            _mm512_storeu_si512(array + left, L);
            left += N;
        }

        if (maskR == 0) {
            _mm512_storeu_si512(array + right - N + 1, R);
            right -= N;
        }

    } // while

end:

    if (maskL != 0) {
        _mm512_storeu_si512(array + left, L);
    }

    if (maskR != 0) {
        _mm512_storeu_si512(array + right - N + 1, R); 
    }

    if (left < right) {
        partition_epi32(array, pv, left, right);
    }
}

