template <int MAX_MASK_BITS, bool EARLY_EXIT>
void avx2_pdep_u32_reference(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    static_assert(MAX_MASK_BITS > 0);
    static_assert(MAX_MASK_BITS <= 32);

    const __m256i one  = _mm256_set1_epi32(1);
    const __m256i zero = _mm256_set1_epi32(0);
    for (size_t i=0; i < n; i += 8) {
        __m256i data = _mm256_loadu_si256((const __m256i*)(&data_arr[i]));
        __m256i mask = _mm256_loadu_si256((const __m256i*)(&mask_arr[i]));
        __m256i out  = _mm256_set1_epi32(0);

        __m256i bit = one;

        /*  for m = 0 .. 31 loop
                if mask[m] == 1 then
                    out[m] = data[k]
                    k := k + 1
                fi
            end
        */
        for (int j=0; j < MAX_MASK_BITS; j++) {
            // 1. isolate the first non-zoro bit set of mask (at m)

            //                                                 mask = [0101_1001_1100_0000|0000_1110_1100_1000|...]
            const __m256i m0 = _mm256_sub_epi32(mask, one); // m0   = [0101_1001_1011_1111|0000_1110_1100_0111|...]
            const __m256i m1 = _mm256_and_si256(mask, m0);  // m1   = [0101_1001_1000_0000|0000_1110_1100_0000|...]
            const __m256i m2 = _mm256_xor_si256(mask, m1);  // m2   = [0000_0000_0100_0000|0000_0000_0000_1000|...]

            // 2. isolate k-th bit from data                   data = [1100_0000_1111_1110|0000_0000_1000_0000|...]
            //                                                  bit = [0000_0000_0001_0000]0000_0000_0001_0000|...]
            const __m256i d0 = _mm256_and_si256(data, bit); //   d0 = [0000_0000_0001_0000|0000_0000_0000_0000|...]
                                                            //                      ^                   ^
            // 4. fill word with *negation* of data bit
            const __m256i d1 = _mm256_cmpeq_epi32(d0, zero);//   d1 = [0000_0000_0000_0000|1111_1111_1111_1111|...]

            // 5. keep the mask bit, iff data[k] == 1
            const __m256i m3 = _mm256_andnot_si256(d1, m2); //   m3 = [0000_0000_0100_0000|0000_0000_0000_0000|...]

            // 6. update the out
            out = _mm256_or_si256(out, m3);
            mask = m1;

            // 7. the next bit in data to check
            bit = _mm256_add_epi32(bit, bit);

            // 8. all are zeros?
            if (EARLY_EXIT && _mm256_testc_si256(zero, mask)) {
                break;
            }
        }

        _mm256_storeu_si256((__m256i*)(&out_arr[i]), out);
    }
}

void avx2_pdep_u32(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    avx2_pdep_u32_reference<32, no_early_exit>(data_arr, mask_arr, out_arr, n);
}

void avx2_pdep_u32_6bits(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    avx2_pdep_u32_reference<6, no_early_exit>(data_arr, mask_arr, out_arr, n);
}

void avx2_pdep_u32_8bits(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    avx2_pdep_u32_reference<8, no_early_exit>(data_arr, mask_arr, out_arr, n);
}

void avx2_pdep_u32_16bits(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    avx2_pdep_u32_reference<16, no_early_exit>(data_arr, mask_arr, out_arr, n);
}

void avx2_pdep_u32_24bits(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    avx2_pdep_u32_reference<24, no_early_exit>(data_arr, mask_arr, out_arr, n);
}

void avx2_pdep_u32_ee(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    avx2_pdep_u32_reference<32, early_exit>(data_arr, mask_arr, out_arr, n);
}

void avx2_pdep_u32_6bits_ee(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    avx2_pdep_u32_reference<6, early_exit>(data_arr, mask_arr, out_arr, n);
}

void avx2_pdep_u32_8bits_ee(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    avx2_pdep_u32_reference<8, early_exit>(data_arr, mask_arr, out_arr, n);
}

void avx2_pdep_u32_16bits_ee(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    avx2_pdep_u32_reference<16, early_exit>(data_arr, mask_arr, out_arr, n);
}

void avx2_pdep_u32_24bits_ee(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    avx2_pdep_u32_reference<24, early_exit>(data_arr, mask_arr, out_arr, n);
}
