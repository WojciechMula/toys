template <int MAX_MASK_BITS, bool EARLY_EXIT>
void avx512_pdep_u32_reference(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    static_assert(MAX_MASK_BITS > 0);
    static_assert(MAX_MASK_BITS <= 32);

    const __m512i one  = _mm512_set1_epi32(1);
    const __m512i zero = _mm512_set1_epi32(0);
    for (size_t i=0; i < n; i += 16) {
        __m512i data = _mm512_loadu_si512((const __m512i*)(&data_arr[i]));
        __m512i mask = _mm512_loadu_si512((const __m512i*)(&mask_arr[i]));
        __m512i out  = _mm512_set1_epi32(0);

        __m512i bit = one;

        /*  for m = 0 .. 31 loop
                if mask[m] == 1 then
                    out[m] = data[k]
                    k := k + 1          -- invariant: k is never greater than m
                fi
            end
        */
        for (int j=0; j < MAX_MASK_BITS; j++) {
            // 1. isolate the first non-zoro bit set of mask (at m)

            //                                                 mask = [0101_1001_1100_0000|0000_1110_1100_1000|...]
            const __m512i m0 = _mm512_sub_epi32(mask, one); // m0   = [0101_1001_1011_1111|0000_1110_1100_0111|...]
            const __m512i m1 = _mm512_and_si512(mask, m0);  // m1   = [0101_1001_1000_0000|0000_1110_1100_0000|...]
            const __m512i m2 = _mm512_xor_si512(mask, m1);  // m2   = [0000_0000_0100_0000|0000_0000_0000_1000|...]
            // the above and & xor should be fused to a single ternarylogic instruction


            // 2. isolate k-th bit from data                   data = [1100_0000_1111_1110|0000_0000_1000_0000|...]
            //                                                  bit = [0000_0000_0001_0000]0000_0000_0001_0000|...]
            const __m512i d0 = _mm512_and_si512(data, bit); //   d0 = [0000_0000_0001_0000|0000_0000_0000_0000|...]
                                                            //                      ^                   ^
            // 4. move k-th bit to n-th position, possible since k <= n
            const __m512i d1 = _mm512_add_epi32(d0, m0);    //   d1 = [0101_1001_1100_1111|0000_1110_1100_0111|...]
            const __m512i d2 = _mm512_and_si512(d1, m2);    //   d2 = [0000_0000_0100_0000|0000_0000_0000_0000|...]

            // 6. update the out
            out = _mm512_or_si512(out, d2);
            // the above and & or should be fused to a single ternarylogic instruction
            mask = m1;

            // 7. the next bit in data to check
            bit = _mm512_add_epi32(bit, bit);

            // 8. all are zeros?
            if (EARLY_EXIT && (_mm512_cmpeq_epi32_mask(zero, mask) == 0xffff)) {
                break;
            }
        }

        _mm512_storeu_si512((__m512i*)(&out_arr[i]), out);
    }
}

void avx512_pdep_u32(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    avx512_pdep_u32_reference<32, no_early_exit>(data_arr, mask_arr, out_arr, n);
}

void avx512_pdep_u32_6bits(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    avx512_pdep_u32_reference<6, no_early_exit>(data_arr, mask_arr, out_arr, n);
}

void avx512_pdep_u32_8bits(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    avx512_pdep_u32_reference<8, no_early_exit>(data_arr, mask_arr, out_arr, n);
}

void avx512_pdep_u32_16bits(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    avx512_pdep_u32_reference<16, no_early_exit>(data_arr, mask_arr, out_arr, n);
}

void avx512_pdep_u32_24bits(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    avx512_pdep_u32_reference<24, no_early_exit>(data_arr, mask_arr, out_arr, n);
}

void avx512_pdep_u32_ee(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    avx512_pdep_u32_reference<32, early_exit>(data_arr, mask_arr, out_arr, n);
}

void avx512_pdep_u32_6bits_ee(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    avx512_pdep_u32_reference<6, early_exit>(data_arr, mask_arr, out_arr, n);
}

void avx512_pdep_u32_8bits_ee(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    avx512_pdep_u32_reference<8, early_exit>(data_arr, mask_arr, out_arr, n);
}

void avx512_pdep_u32_16bits_ee(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    avx512_pdep_u32_reference<16, early_exit>(data_arr, mask_arr, out_arr, n);
}

void avx512_pdep_u32_24bits_ee(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    avx512_pdep_u32_reference<24, early_exit>(data_arr, mask_arr, out_arr, n);
}
