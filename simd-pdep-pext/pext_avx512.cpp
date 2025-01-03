template <int MAX_MASK_BITS, bool EARLY_EXIT>
void avx512_pext_u32_reference(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    static_assert(MAX_MASK_BITS > 0);
    static_assert(MAX_MASK_BITS <= 32);

    const __m512i one  = _mm512_set1_epi32(1);
    const __m512i zero = _mm512_set1_epi32(0);
    for (size_t i=0; i < n; i += 16) {
        __m512i data = _mm512_loadu_si512((const __m512i*)(&data_arr[i]));
        __m512i mask = _mm512_loadu_si512((const __m512i*)(&mask_arr[i]));
        __m512i out  = _mm512_set1_epi32(0);

        __m512i bit = one;

        for (int j=0; j < MAX_MASK_BITS; j++) {
            // 1. isolate the first bit set of mask

            //                                                 mask = [0101_1001_1100_0000|...]
            const __m512i m0 = _mm512_sub_epi32(mask, one); // m0   = [0101_1001_1011_1111|...]
            const __m512i m1 = _mm512_and_si512(mask, m0);  // m1   = [0101_1001_1000_0000|...]
            const __m512i m2 = _mm512_xor_si512(mask, m1);  // m2   = [0000_0000_0100_0000|...]
            // the above and & xor should be fused to a single ternarylogic instruction

            // 2. isolate that bit from data                   data = [1100_0000_1111_0000|...]
            const __m512i d0 = _mm512_and_si512(data, m2);  //   d0 = [0000_0000_0100_0000|...]

            // 3. move that bit on the next position in out
            const __m512i o0 = _mm512_min_epu32(d0, bit);   //   o0 = [0000_0000_0000_0001|...]
            out = _mm512_or_si512(out, o0);

            // 4. reset selected bit in mask
            mask = m1;

            // 5. the next bit to set
            bit = _mm512_add_epi32(bit, bit);

            // 6. all are zeros?
            if (EARLY_EXIT && (_mm512_cmpeq_epi32_mask(zero, mask) == 0xffff)) {
                break;
            }
        }

        _mm512_storeu_si512((__m512i*)(&out_arr[i]), out);
    }
}

void avx512_pext_u32(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    avx512_pext_u32_reference<32, no_early_exit>(data_arr, mask_arr, out_arr, n);
}

void avx512_pext_u32_6bits(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    avx512_pext_u32_reference<6, no_early_exit>(data_arr, mask_arr, out_arr, n);
}

void avx512_pext_u32_8bits(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    avx512_pext_u32_reference<8, no_early_exit>(data_arr, mask_arr, out_arr, n);
}

void avx512_pext_u32_16bits(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    avx512_pext_u32_reference<16, no_early_exit>(data_arr, mask_arr, out_arr, n);
}

void avx512_pext_u32_24bits(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    avx512_pext_u32_reference<24, no_early_exit>(data_arr, mask_arr, out_arr, n);
}

void avx512_pext_u32_ee(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    avx512_pext_u32_reference<32, early_exit>(data_arr, mask_arr, out_arr, n);
}

void avx512_pext_u32_6bits_ee(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    avx512_pext_u32_reference<6, early_exit>(data_arr, mask_arr, out_arr, n);
}

void avx512_pext_u32_8bits_ee(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    avx512_pext_u32_reference<8, early_exit>(data_arr, mask_arr, out_arr, n);
}

void avx512_pext_u32_16bits_ee(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    avx512_pext_u32_reference<16, early_exit>(data_arr, mask_arr, out_arr, n);
}

void avx512_pext_u32_24bits_ee(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    avx512_pext_u32_reference<24, early_exit>(data_arr, mask_arr, out_arr, n);
}


template <int MAX_MASK_BITS, bool EARLY_EXIT>
void avx512_pext_u32_ver2_reference(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    static_assert(MAX_MASK_BITS > 0);
    static_assert(MAX_MASK_BITS <= 32);

    const __m512i one  = _mm512_set1_epi32(1);
    const __m512i zero = _mm512_set1_epi32(0);
    for (size_t i=0; i < n; i += 16) {
        __m512i data = _mm512_loadu_si512((const __m512i*)(&data_arr[i]));
        __m512i mask = _mm512_loadu_si512((const __m512i*)(&mask_arr[i]));
        __m512i out  = _mm512_set1_epi32(0);

        __m512i bit = one;

        for (int j=0; j < MAX_MASK_BITS; j++) {

            // 2. isolate the first bit set of mask

            //                                                 mask = [0101_1001_1100_0000|...]
            const __m512i m0 = _mm512_sub_epi32(mask, one); // m0   = [0101_1001_1011_1111|...]
            const __m512i m1 = _mm512_and_si512(mask, m0);  // m1   = [0101_1001_1000_0000|...]
            const __m512i m2 = _mm512_xor_si512(mask, m1);  // m2   = [0000_0000_0100_0000|...]

            // 2. get m-th data bits in a mask register
            const __mmask64 m = _mm512_test_epi32_mask(data, m2);

            // 3. set k-th bit when m-th bit is set
            out = _mm512_mask_or_epi32(out, m, out, bit);

            // 4. reset selected bit in mask
            mask = m1;

            // 5. the next bit to set
            bit = _mm512_add_epi32(bit, bit);

            // 6. all are zeros?
            if (EARLY_EXIT && (_mm512_cmpeq_epi32_mask(zero, mask) == 0xffff)) {
                break;
            }
        }

        _mm512_storeu_si512((__m512i*)(&out_arr[i]), out);
    }
}

void avx512_pext_u32_ver2(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    avx512_pext_u32_ver2_reference<32, no_early_exit>(data_arr, mask_arr, out_arr, n);
}

void avx512_pext_u32_ver2_6bits(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    avx512_pext_u32_ver2_reference<6, no_early_exit>(data_arr, mask_arr, out_arr, n);
}

void avx512_pext_u32_ver2_8bits(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    avx512_pext_u32_ver2_reference<8, no_early_exit>(data_arr, mask_arr, out_arr, n);
}

void avx512_pext_u32_ver2_16bits(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    avx512_pext_u32_ver2_reference<16, no_early_exit>(data_arr, mask_arr, out_arr, n);
}

void avx512_pext_u32_ver2_24bits(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    avx512_pext_u32_ver2_reference<24, no_early_exit>(data_arr, mask_arr, out_arr, n);
}

void avx512_pext_u32_ver2_ee(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    avx512_pext_u32_ver2_reference<32, early_exit>(data_arr, mask_arr, out_arr, n);
}

void avx512_pext_u32_ver2_6bits_ee(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    avx512_pext_u32_ver2_reference<6, early_exit>(data_arr, mask_arr, out_arr, n);
}

void avx512_pext_u32_ver2_8bits_ee(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    avx512_pext_u32_ver2_reference<8, early_exit>(data_arr, mask_arr, out_arr, n);
}

void avx512_pext_u32_ver2_16bits_ee(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    avx512_pext_u32_ver2_reference<16, early_exit>(data_arr, mask_arr, out_arr, n);
}

void avx512_pext_u32_ver2_24bits_ee(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    avx512_pext_u32_ver2_reference<24, early_exit>(data_arr, mask_arr, out_arr, n);
}

