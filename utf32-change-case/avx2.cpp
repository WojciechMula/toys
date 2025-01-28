size_t avx2_utf32_uppercase_plain(const uint32_t* input, size_t n, uint32_t* output) {
    size_t j=0;
    size_t i=0;

    for (i=0; i < 8*(n / 8); i += 8) {
        const __m256i t0 = _mm256_loadu_si256((const __m256i*)(&input[i]));

        if (_mm256_testz_si256(t0, _mm256_set1_epi32(0xffffff80))) {
            const __m256i ge_a = _mm256_cmpgt_epi32(t0, _mm256_set1_epi32('a' - 1)); // char >= 'a'
            const __m256i le_z = _mm256_cmpgt_epi32(_mm256_set1_epi32('z' + 1), t0); // char <= 'z'

            const __m256i v0 = _mm256_and_si256(ge_a, le_z);
            const __m256i v1 = _mm256_and_si256(v0, _mm256_set1_epi32(0x20));
            const __m256i v2 = _mm256_xor_si256(t0, v1);

            _mm256_storeu_si256((__m256i*)(&output[j]), v2);
            j += 8;
            continue;
        }

        const __m256i hi      = _mm256_and_si256(t0, _mm256_set1_epi32((int32_t)0xfffe'0000));
        const __m256i below   = _mm256_cmpeq_epi32(hi, _mm256_setzero_si256());
        const __m256i indices = _mm256_and_si256(below, t0);
        const __m256i t1      = _mm256_i32gather_epi32((const int*)UTF32_UPPERCASE_PLAIN, indices, 4);

        const __m256i above = _mm256_andnot_si256(below, t0);
        const __m256i t2    = _mm256_and_si256(below, t1);
        const __m256i t3    = _mm256_or_si256(above, t2);

        _mm256_storeu_si256((__m256i*)(&output[j]), t3);
        if (_mm256_movemask_ps(_mm256_castsi256_ps(t1))) {
            const size_t d = utf32_uppercase_plain(input + i, 8, output + j);
            j += d;
        } else {
            j += 8;
        }
    }

    const size_t d = utf32_uppercase_plain(input + i, n - i, output + j);

    return d + j;
}

#include "compressed_avx2.cpp.inl"

size_t avx2_utf32_uppercase_compressed(const uint32_t* input, size_t n, uint32_t* output) {
    size_t j=0;
    size_t i=0;

    const __m256i fallback_key = _mm256_set1_epi32(UTF32_UPPERCASE_MAX_HI_BITS_AVX2);

    for (i=0; i < 8*(n / 8); i += 8) {
        const __m256i t0 = _mm256_loadu_si256((const __m256i*)(&input[i]));

        if (_mm256_testz_si256(t0, _mm256_set1_epi32(0xffffff80))) {
            const __m256i ge_a = _mm256_cmpgt_epi32(t0, _mm256_set1_epi32('a' - 1)); // char >= 'a'
            const __m256i le_z = _mm256_cmpgt_epi32(_mm256_set1_epi32('z' + 1), t0); // char <= 'z'

            const __m256i v0 = _mm256_and_si256(ge_a, le_z);
            const __m256i v1 = _mm256_and_si256(v0, _mm256_set1_epi32(0x20));
            const __m256i v2 = _mm256_xor_si256(t0, v1);

            _mm256_storeu_si256((__m256i*)(&output[j]), v2);
            j += 8;
            continue;
        }

        const __m256i key_0       = _mm256_srli_epi32(t0, 7);
        const __m256i key_indices = _mm256_min_epi32(key_0, fallback_key);

        const __m256i indices     = _mm256_i32gather_epi32((const int*)UTF32_UPPERCASE_OFFSET_AVX2, key_indices, 4);
        const __m256i t1          = _mm256_and_si256(t0, _mm256_set1_epi32(0x7f));
        const __m256i offsets     = _mm256_add_epi32(indices, t1);

        const __m256i t2          = _mm256_i32gather_epi32((const int*)UTF32_UPPERCASE_DATA_AVX2, offsets, 4);
        const __m256i t3          = _mm256_xor_si256(t2, t0);

        _mm256_storeu_si256((__m256i*)(&output[j]), t3);
        if (_mm256_movemask_ps(_mm256_castsi256_ps(t2))) {
            const size_t d = utf32_uppercase_compressed_v2(input + i, 8, output + j);
            j += d;
        } else {
            j += 8;
        }
    }

    const size_t d = utf32_uppercase_compressed_v2(input + i, n - i, output + j);

    return d + j;
}

__m256i _mm256_or4_si256(__m256i a, __m256i b, __m256i c, __m256i d) {
    return _mm256_or_si256(
        _mm256_or_si256(a, b),
        _mm256_or_si256(c, d)
    );
}

size_t avx2_utf32_uppercase_compressed_unrolled4(const uint32_t* input_ptr, size_t n, uint32_t* output) {
    size_t j=0;
    size_t i=0;

    const __m256i fallback_key = _mm256_set1_epi32(UTF32_UPPERCASE_MAX_HI_BITS_AVX2);

    for (i=0; i < 32*(n / 32); i += 32) {
        const __m256i input0 = _mm256_loadu_si256((const __m256i*)(&input_ptr[i + 0*8]));
        const __m256i input1 = _mm256_loadu_si256((const __m256i*)(&input_ptr[i + 1*8]));
        const __m256i input2 = _mm256_loadu_si256((const __m256i*)(&input_ptr[i + 2*8]));
        const __m256i input3 = _mm256_loadu_si256((const __m256i*)(&input_ptr[i + 3*8]));

        __m256i result0 = _mm256_setzero_si256();
        __m256i result1 = _mm256_setzero_si256();
        __m256i result2 = _mm256_setzero_si256();
        __m256i result3 = _mm256_setzero_si256();

        if (_mm256_testz_si256(input0, _mm256_set1_epi32(0xffffff80))) {
            const __m256i ge_a = _mm256_cmpgt_epi32(input0, _mm256_set1_epi32('a' - 1)); // char >= 'a'
            const __m256i le_z = _mm256_cmpgt_epi32(_mm256_set1_epi32('z' + 1), input0); // char <= 'z'

            const __m256i v0 = _mm256_and_si256(ge_a, le_z);
            const __m256i v1 = _mm256_and_si256(v0, _mm256_set1_epi32(0x20));
            const __m256i v2 = _mm256_xor_si256(input0, v1);

            _mm256_storeu_si256((__m256i*)(&output[j]), v2);
            j += 8;
        } else {
            const __m256i key_0       = _mm256_srli_epi32(input0, 7);
            const __m256i key_indices = _mm256_min_epi32(key_0, fallback_key);

            const __m256i indices     = _mm256_i32gather_epi32((const int*)UTF32_UPPERCASE_OFFSET_AVX2, key_indices, 4);
            const __m256i t1          = _mm256_and_si256(input0, _mm256_set1_epi32(0x7f));
            const __m256i offsets     = _mm256_add_epi32(indices, t1);

            const __m256i t2          = _mm256_i32gather_epi32((const int*)UTF32_UPPERCASE_DATA_AVX2, offsets, 4);
            result0                   = _mm256_xor_si256(t2, input0);

            _mm256_storeu_si256((__m256i*)(&output[j]), result0);
            j += 8;
        }

        if (_mm256_testz_si256(input1, _mm256_set1_epi32(0xffffff80))) {
            const __m256i ge_a = _mm256_cmpgt_epi32(input1, _mm256_set1_epi32('a' - 1)); // char >= 'a'
            const __m256i le_z = _mm256_cmpgt_epi32(_mm256_set1_epi32('z' + 1), input1); // char <= 'z'

            const __m256i v0 = _mm256_and_si256(ge_a, le_z);
            const __m256i v1 = _mm256_and_si256(v0, _mm256_set1_epi32(0x20));
            const __m256i v2 = _mm256_xor_si256(input1, v1);

            _mm256_storeu_si256((__m256i*)(&output[j]), v2);
            j += 8;
        } else {
            const __m256i key_0       = _mm256_srli_epi32(input1, 7);
            const __m256i key_indices = _mm256_min_epi32(key_0, fallback_key);

            const __m256i indices     = _mm256_i32gather_epi32((const int*)UTF32_UPPERCASE_OFFSET_AVX2, key_indices, 4);
            const __m256i t1          = _mm256_and_si256(input1, _mm256_set1_epi32(0x7f));
            const __m256i offsets     = _mm256_add_epi32(indices, t1);

            const __m256i t2          = _mm256_i32gather_epi32((const int*)UTF32_UPPERCASE_DATA_AVX2, offsets, 4);
            result1                   = _mm256_xor_si256(t2, input1);

            _mm256_storeu_si256((__m256i*)(&output[j]), result1);
            j += 8;
        }

        if (_mm256_testz_si256(input2, _mm256_set1_epi32(0xffffff80))) {
            const __m256i ge_a = _mm256_cmpgt_epi32(input2, _mm256_set1_epi32('a' - 1)); // char >= 'a'
            const __m256i le_z = _mm256_cmpgt_epi32(_mm256_set1_epi32('z' + 1), input2); // char <= 'z'

            const __m256i v0 = _mm256_and_si256(ge_a, le_z);
            const __m256i v1 = _mm256_and_si256(v0, _mm256_set1_epi32(0x20));
            const __m256i v2 = _mm256_xor_si256(input2, v1);

            _mm256_storeu_si256((__m256i*)(&output[j]), v2);
            j += 8;
        } else {
            const __m256i key_0       = _mm256_srli_epi32(input2, 7);
            const __m256i key_indices = _mm256_min_epi32(key_0, fallback_key);

            const __m256i indices     = _mm256_i32gather_epi32((const int*)UTF32_UPPERCASE_OFFSET_AVX2, key_indices, 4);
            const __m256i t1          = _mm256_and_si256(input2, _mm256_set1_epi32(0x7f));
            const __m256i offsets     = _mm256_add_epi32(indices, t1);

            const __m256i t2          = _mm256_i32gather_epi32((const int*)UTF32_UPPERCASE_DATA_AVX2, offsets, 4);
            result2                   = _mm256_xor_si256(t2, input2);

            _mm256_storeu_si256((__m256i*)(&output[j]), result2);
            j += 8;
        }

        if (_mm256_testz_si256(input3, _mm256_set1_epi32(0xffffff80))) {
            const __m256i ge_a = _mm256_cmpgt_epi32(input3, _mm256_set1_epi32('a' - 1)); // char >= 'a'
            const __m256i le_z = _mm256_cmpgt_epi32(_mm256_set1_epi32('z' + 1), input3); // char <= 'z'

            const __m256i v0 = _mm256_and_si256(ge_a, le_z);
            const __m256i v1 = _mm256_and_si256(v0, _mm256_set1_epi32(0x20));
            const __m256i v2 = _mm256_xor_si256(input3, v1);

            _mm256_storeu_si256((__m256i*)(&output[j]), v2);
            j += 8;
        } else {
            const __m256i key_0       = _mm256_srli_epi32(input3, 7);
            const __m256i key_indices = _mm256_min_epi32(key_0, fallback_key);

            const __m256i indices     = _mm256_i32gather_epi32((const int*)UTF32_UPPERCASE_OFFSET_AVX2, key_indices, 4);
            const __m256i t1          = _mm256_and_si256(input3, _mm256_set1_epi32(0x7f));
            const __m256i offsets     = _mm256_add_epi32(indices, t1);

            const __m256i t2          = _mm256_i32gather_epi32((const int*)UTF32_UPPERCASE_DATA_AVX2, offsets, 4);
            result3                   = _mm256_xor_si256(t2, input3);

            _mm256_storeu_si256((__m256i*)(&output[j]), result3);
            j += 8;
        }

        const __m256i tmp = _mm256_or4_si256(result0, result1, result2, result3);
        if (_mm256_movemask_ps(_mm256_castsi256_ps(tmp))) {
            j -= 32;
            const size_t d = utf32_uppercase_compressed_v2(input_ptr + i, 32, output + j);
            j += d;
        }
    }

    const size_t d = utf32_uppercase_compressed_v2(input_ptr + i, n - i, output + j);

    return d + j;
}
