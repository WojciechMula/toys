
namespace qs {

    namespace avx2 {

        void FORCE_INLINE align_masks(uint8_t& a, uint8_t& b, uint8_t& rem_a, uint8_t& rem_b) {

            assert(a != 0);
            assert(b != 0);

            uint8_t tmpA = a;
            uint8_t tmpB = b;
                
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


        namespace precalc {

            uint32_t shuffle[256];

        } // namespace precalc


        void prepare_masks() {
        }


        __m256i FORCE_INLINE merge(const __m256i negmask, const __m256i a, const __m256i b) {
            
            return _mm256_or_si256(
                    _mm256_and_si256(negmask, a),
                    _mm256_andnot_si256(negmask, b)
            );
        }


        void FORCE_INLINE swap_epi32(__m256i& a, __m256i& b, uint8_t mask_a, const __m256i negmask_a, uint8_t mask_b, const __m256i negmask_b) {
            
            assert(mask_a != 0);
            assert(mask_b != 0);
            assert(_mm_popcnt_u64(mask_a) == _mm_popcnt_u64(mask_b));

            const __m256i shuffle_a = _mm256_set1_epi32(precalc::shuffle[mask_a]);
            const __m256i shuffle_b = _mm256_set1_epi32(precalc::shuffle[mask_b]);

            const __m256i to_swap_b = _mm256_permutevar8x32_epi32(a, shuffle_a);
            const __m256i to_swap_a = _mm256_permutevar8x32_epi32(b, shuffle_b);

            a = merge(negmask_a, a, to_swap_a);
            b = merge(negmask_b, b, to_swap_b);
        }


        void partition_epi32(uint32_t* array, uint32_t pv, int& left, int& right) {

            const int N = 8; // the number of items in a register (256/32)

            __m256i L;
            __m256i R;
            __m256i negbytemaskL;
            __m256i negbytemaskR;
            uint8_t maskL = 0;
            uint8_t maskR = 0;

            const __m256i pivot = _mm256_set1_epi32(pv);

            while (right - left + 1 >= 2*N) {

                if (maskL == 0) {
                    while (true) {
                        if (right - (left + N) + 1 < 2*N) {
                            goto end;
                        }

                        L = _mm256_loadu_si256((__m256i*)(array + left + N));
                        negbytemaskL = _mm256_cmpgt_epi32(L, pivot);
                        if (_mm256_testnzc_si256(negbytemaskL, negbytemaskL)) { // maskL != 0
                            break;
                        } else {
                            left += N;
                        }
                    }

                    maskL = ~_mm256_movemask_ps((__m256)negbytemaskL);
                }

                if (maskR == 0) {
                    while (true) {
                        if ((right - N) - left + 1 < 2*N) {
                            goto end;
                        }

                        R = _mm256_loadu_si256((__m256i*)(array + right - N + 1));
                        negbytemaskR = _mm256_cmpgt_epi32(pivot, R);
                        if (_mm256_testnzc_si256(negbytemaskR, negbytemaskR)) { // maskR != 0
                            break;
                        } else {
                            right -= N;
                        }
                    }

                    maskL = ~_mm256_movemask_ps((__m256)negbytemaskR);
                }

                assert(left <= right);
                assert(maskL != 0);
                assert(maskR != 0);
                
                uint8_t mL;
                uint8_t mR;

                align_masks(maskL, maskR, mL, mR);
                swap_epi32(L, R, maskL, negbytemaskL, maskR, negbytemaskR);

                maskL = mL;
                maskR = mR;

                if (maskL == 0) {
                    _mm256_storeu_si256((__m256i*)(array + left), L);
                    left += N;
                }

                if (maskR == 0) {
                    _mm256_storeu_si256((__m256i*)(array + right - N + 1), R);
                    right -= N;
                }

            } // while

        end:

            if (maskL != 0) {
                _mm256_storeu_si256((__m256i*)(array + left), L);
            }

            if (maskR != 0) {
                _mm256_storeu_si256((__m256i*)(array + right - N + 1), R); 
            }

            if (left < right) {
                partition_epi32(array, pv, left, right);
            }
        }

    } // namespace avx2

} // namespace qs
