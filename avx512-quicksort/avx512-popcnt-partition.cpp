namespace qs {

    namespace avx512 {

        void FORCE_INLINE popcnt_partition_epi32(uint32_t* array, uint32_t pv, int& left, int& right) {

            const int N = 16;

            __m512i L;
            __m512i R;
            __mmask16 maskL = 0;
            __mmask16 maskR = 0;
            int popcntL;
            int popcntR;

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

                    popcntL = _mm_popcnt_u32(maskL);
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

                    popcntR = _mm_popcnt_u32(maskR);
                }

                assert(left <= right);
                assert(maskL != 0);
                assert(maskR != 0);

                if (popcntL == popcntR) {
                    // fast path
                    swap_epi32(L, R, maskL, maskR);
                    maskL = maskR = 0;

                    _mm512_storeu_si512(array + left, L);
                    left += N;

                    _mm512_storeu_si512(array + right - N + 1, R);
                    right -= N;
                } else {
                    if (popcntL < popcntR) {
                        int n = popcntR - popcntL;
                        int k = n;

                        __mmask16 tmp = maskR;
                        while (k--) {
                            maskR = maskR & (maskR - 1);
                        }

                        swap_epi32(L, R, maskL, maskR);
                        maskR = tmp ^ maskR;

                        popcntR = n;

                        _mm512_storeu_si512(array + left, L);
                        left += N;
                        maskL = 0;
                    } else {
                        int n = popcntL - popcntR;
                        int k = n;

                        __mmask16 tmp = maskL;
                        while (k--) {
                            maskL = maskL & (maskL - 1);
                        }

                        swap_epi32(L, R, maskL, maskR);
                        maskL = tmp ^ maskL;

                        popcntL = n;

                        _mm512_storeu_si512(array + right - N + 1, R);
                        right -= N;
                        maskR  = 0;
                    }
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
                scalar_partition_epi32(array, pv, left, right);
            }
        }

    } // namespace avx512

} // namespace qs
