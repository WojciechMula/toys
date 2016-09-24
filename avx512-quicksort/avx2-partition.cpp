namespace qs {

    namespace avx2 {

        __m256i FORCE_INLINE bitmask_to_bytemask_epi32(uint8_t bm) {

            const __m256i mask = _mm256_set1_epi32(bm);
            const __m256i bits = _mm256_setr_epi32(0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80);
            const __m256i tmp  = _mm256_and_si256(mask, bits);

            return _mm256_cmpeq_epi32(tmp, bits);
        }


        void FORCE_INLINE align_masks(uint8_t& a, uint8_t& b, uint8_t& rem_a, uint8_t& rem_b, __m256i& shuffle_a, __m256i& shuffle_b) {

            assert(a != 0);
            assert(b != 0);

            uint8_t tmpA = a;
            uint8_t tmpB = b;

            uint32_t __attribute__((__aligned__(32))) tmpshufa[8];
            uint32_t __attribute__((__aligned__(32))) tmpshufb[8];

            while (tmpA != 0 && tmpB != 0) {
                int idx_a = __builtin_ctz(tmpA);
                int idx_b = __builtin_ctz(tmpB);

                tmpA = tmpA & (tmpA - 1);
                tmpB = tmpB & (tmpB - 1);

                tmpshufb[idx_a] = idx_b;
                tmpshufa[idx_b] = idx_a;
            }

            a = a ^ tmpA;
            b = b ^ tmpB;

            assert(a != 0);
            assert(b != 0);
            assert(_mm_popcnt_u64(a) == _mm_popcnt_u64(b));

            rem_a = tmpA;
            rem_b = tmpB;

            shuffle_a = _mm256_load_si256((__m256i*)tmpshufa);
            shuffle_b = _mm256_load_si256((__m256i*)tmpshufb);
        }


        __m256i FORCE_INLINE merge(const __m256i mask, const __m256i a, const __m256i b) {

            return _mm256_or_si256(
                    _mm256_and_si256(mask, a),
                    _mm256_andnot_si256(mask, b)
            );
        }


        void dump(const char* name, const __m256i v) {
            uint32_t tmp[8];

            printf("%-10s = [", name);
            _mm256_storeu_si256((__m256i*)tmp, v);
            for (int i=0; i < 8; i++) {
                if (i > 0) {
                    putchar(' ');
                }

                printf("%08x", tmp[i]);
            }

            printf("]\n");
        }


       void FORCE_INLINE swap_epi32(
            __m256i& a, __m256i& b,
            uint8_t mask_a, const __m256i shuffle_a,
            uint8_t mask_b, const __m256i shuffle_b) {

            const __m256i to_swap_b = _mm256_permutevar8x32_epi32(a, shuffle_a);
            const __m256i to_swap_a = _mm256_permutevar8x32_epi32(b, shuffle_b);
            const __m256i ma    = bitmask_to_bytemask_epi32(mask_a);
            const __m256i mb    = bitmask_to_bytemask_epi32(mask_b);

            a = merge(ma, to_swap_a, a);
            b = merge(mb, to_swap_b, b);
        }



#define _mm256_iszero(vec) (_mm256_testz_si256(vec, vec) != 0)

        void partition_epi32(uint32_t* array, uint32_t pv, int& left, int& right) {

            const int N = 8; // the number of items in a register (256/32)

            __m256i L;
            __m256i R;
            uint8_t maskL = 0;
            uint8_t maskR = 0;

            const __m256i pivot = _mm256_set1_epi32(pv);

            while (right - left + 1 >= 2*N) {

                if (maskL == 0) {
                    while (true) {
                        if (right - (left + N) + 1 < 2*N) {
                            goto end;
                        }

                        L = _mm256_loadu_si256((__m256i*)(array + left));
                        const __m256i bytemask = _mm256_or_si256(
                            _mm256_cmpgt_epi32(L, pivot),
                            _mm256_cmpeq_epi32(L, pivot)
                        );

                        if (_mm256_iszero(bytemask)) {
                            left += N;
                        } else {
                            maskL = _mm256_movemask_ps((__m256)bytemask);
                            break;
                        }
                    }

                }

                if (maskR == 0) {
                    while (true) {
                        if ((right - N) - left + 1 < 2*N) {
                            goto end;
                        }

                        R = _mm256_loadu_si256((__m256i*)(array + right - N + 1));
                        const __m256i bytemask = _mm256_cmpgt_epi32(pivot, R);
                        if (_mm256_iszero(bytemask)) {
                            right -= N;
                        } else {
                            maskR = _mm256_movemask_ps((__m256)bytemask);
                            break;
                        }
                    }

                }

                assert(left <= right);
                assert(maskL != 0);
                assert(maskR != 0);

                uint8_t mL;
                uint8_t mR;
                __m256i shuffleL;
                __m256i shuffleR;

                align_masks(maskL, maskR, mL, mR, shuffleL, shuffleR);
                swap_epi32(L, R, maskL, shuffleL, maskR, shuffleR);

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
                scalar_partition_epi32(array, pv, left, right);
            }
        }

    } // namespace avx2

} // namespace qs
