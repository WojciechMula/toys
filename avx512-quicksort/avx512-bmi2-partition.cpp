namespace qs {

    namespace avx512 {

        void FORCE_INLINE bmi2_align_masks(__mmask16& a, __mmask16& b, __mmask16& rem_a, __mmask16& rem_b) {

            uint32_t tmpA = _pext_u32(0xffffffff, a);
            uint32_t tmpB = _pext_u32(0xffffffff, b);

            uint32_t tmp  = tmpA & tmpB;

            __mmask16 new_a = _pdep_u32(tmp, a);
            __mmask16 new_b = _pdep_u32(tmp, a);

            rem_a = a ^ new_a;
            rem_b = b ^ new_b;

            a = new_a;
            b = new_b;

            assert(a != 0);
            assert(b != 0);
            assert(_mm_popcnt_u64(a) == _mm_popcnt_u64(b));
        }


        void FORCE_INLINE bmi2_partition_epi32(uint32_t* array, uint32_t pv, int& left, int& right) {

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

                bmi2_align_masks(maskL, maskR, mL, mR);
                swap_epi32(L, R, maskL, maskR);

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

    } // namespace avx512

} // namespace qs
