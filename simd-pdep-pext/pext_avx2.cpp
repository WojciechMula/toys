template <int MAX_MASK_BITS, bool EARLY_EXIT>
void avx2_pext_u32_reference(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    static_assert(MAX_MASK_BITS > 0);
    static_assert(MAX_MASK_BITS <= 32);

    const __m256i one  = _mm256_set1_epi32(1);
    const __m256i zero = _mm256_set1_epi32(0);
    for (size_t i=0; i < n; i += 8) {
        __m256i data = _mm256_loadu_si256((const __m256i*)(&data_arr[i]));
        __m256i mask = _mm256_loadu_si256((const __m256i*)(&mask_arr[i]));
        __m256i out  = _mm256_set1_epi32(0);

        __m256i bit = one;

        for (int j=0; j < MAX_MASK_BITS; j++) {
            // 1. isolate the first non-zero bit set of mask

            //                                                 mask = [0101_1001_1100_0000|...]
            const __m256i m0 = _mm256_sub_epi32(mask, one); // m0   = [0101_1001_1011_1111|...]
            const __m256i m1 = _mm256_and_si256(mask, m0);  // m1   = [0101_1001_1000_0000|...]
            const __m256i m2 = _mm256_xor_si256(mask, m1);  // m2   = [0000_0000_0100_0000|...]

            // 2. isolate that bit from data                   data = [1100_0000_1111_0000|...]
            const __m256i d0 = _mm256_and_si256(data, m2);  //   d0 = [0000_0000_0100_0000|...]

            // 3. move that bit on the next position in out
            const __m256i o0 = _mm256_min_epu32(d0, bit);   //   o0 = [0000_0000_0000_0001|...]
            out = _mm256_or_si256(out, o0);

            // 4. reset selected bit in mask
            mask = m1;

            // 5. the next bit in mask to check
            bit = _mm256_add_epi32(bit, bit);

            // 6. all are zeros?
            if (EARLY_EXIT && _mm256_testc_si256(zero, mask)) {
                break;
            }
        }

        _mm256_storeu_si256((__m256i*)(&out_arr[i]), out);
    }
}

void avx2_pext_u32(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    avx2_pext_u32_reference<32, no_early_exit>(data_arr, mask_arr, out_arr, n);
}

void avx2_pext_u32_6bits(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    avx2_pext_u32_reference<6, no_early_exit>(data_arr, mask_arr, out_arr, n);
}

void avx2_pext_u32_8bits(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    avx2_pext_u32_reference<8, no_early_exit>(data_arr, mask_arr, out_arr, n);
}

void avx2_pext_u32_16bits(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    avx2_pext_u32_reference<16, no_early_exit>(data_arr, mask_arr, out_arr, n);
}

void avx2_pext_u32_24bits(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    avx2_pext_u32_reference<24, no_early_exit>(data_arr, mask_arr, out_arr, n);
}

void avx2_pext_u32_ee(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    avx2_pext_u32_reference<32, early_exit>(data_arr, mask_arr, out_arr, n);
}

void avx2_pext_u32_6bits_ee(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    avx2_pext_u32_reference<6, early_exit>(data_arr, mask_arr, out_arr, n);
}

void avx2_pext_u32_8bits_ee(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    avx2_pext_u32_reference<8, early_exit>(data_arr, mask_arr, out_arr, n);
}

void avx2_pext_u32_16bits_ee(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    avx2_pext_u32_reference<16, early_exit>(data_arr, mask_arr, out_arr, n);
}

void avx2_pext_u32_24bits_ee(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    avx2_pext_u32_reference<24, early_exit>(data_arr, mask_arr, out_arr, n);
}