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

// --------------------------------------------------

void avx2_pext_u32_mixed_ver1(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    const __m256i magic1 = _mm256_set1_epi32(33);
    const __m256i magic2 = _mm256_set1_epi32(42);

    uint32_t data_tmp[8];
    for (size_t i=0; i < n; i += 8) {
        __m256i data = _mm256_loadu_si256((const __m256i*)(&data_arr[i]));
        __m256i out  = _mm256_set1_epi32(0);

        // some artifical calculations on data
        data = _mm256_srli_epi32(data, 1);
        data = _mm256_add_epi32(data, magic1);
        // end

        // do pext
        _mm256_storeu_si256((__m256i*)data_tmp, data);
        for (int j=0; j < 8; j++) {
            data_tmp[j] = _pext_u32(data_tmp[j], mask_arr[i + j]);
        }
        data = _mm256_loadu_si256((const __m256i*)data_tmp);
        // end

        // get back to the vector world
        out = _mm256_sub_epi32(data, magic2);
        // end

        _mm256_storeu_si256((__m256i*)(&out_arr[i]), out);
    }
}

void avx2_pext_u32_mixed_ver2(const uint32_t* data_arr, const uint32_t* mask_arr, uint32_t* out_arr, size_t n) {
    const __m256i magic1 = _mm256_set1_epi32(33);
    const __m256i magic2 = _mm256_set1_epi32(42);

    for (size_t i=0; i < n; i += 8) {
        __m256i data = _mm256_loadu_si256((const __m256i*)(&data_arr[i]));
        __m256i out  = _mm256_set1_epi32(0);

        // some artifical calculations on data
        data = _mm256_srli_epi32(data, 1);
        data = _mm256_add_epi32(data, magic1);
        // end

        // do pext
        const uint32_t r0 = _pext_u32(_mm256_extract_epi32(data, 0), mask_arr[i + 0]);
        const uint32_t r1 = _pext_u32(_mm256_extract_epi32(data, 1), mask_arr[i + 1]);
        const uint32_t r2 = _pext_u32(_mm256_extract_epi32(data, 2), mask_arr[i + 2]);
        const uint32_t r3 = _pext_u32(_mm256_extract_epi32(data, 3), mask_arr[i + 3]);
        const uint32_t r4 = _pext_u32(_mm256_extract_epi32(data, 4), mask_arr[i + 4]);
        const uint32_t r5 = _pext_u32(_mm256_extract_epi32(data, 5), mask_arr[i + 5]);
        const uint32_t r6 = _pext_u32(_mm256_extract_epi32(data, 6), mask_arr[i + 6]);
        const uint32_t r7 = _pext_u32(_mm256_extract_epi32(data, 7), mask_arr[i + 7]);

        data = _mm256_insert_epi32(data, r0, 0);
        data = _mm256_insert_epi32(data, r1, 1);
        data = _mm256_insert_epi32(data, r2, 2);
        data = _mm256_insert_epi32(data, r3, 3);
        data = _mm256_insert_epi32(data, r4, 4);
        data = _mm256_insert_epi32(data, r5, 5);
        data = _mm256_insert_epi32(data, r6, 6);
        data = _mm256_insert_epi32(data, r7, 7);
        // end

        // get back to the vector world
        out = _mm256_sub_epi32(data, magic2);
        // end

        _mm256_storeu_si256((__m256i*)(&out_arr[i]), out);
    }
}
