size_t avx2_utf32_uppercase_plain(const uint32_t* input, size_t n, uint32_t* output) {
    size_t j=0;
    size_t i=0;

    for (i=0; i < 8*(n / 8); i += 8) {
        const __m256i t0      = _mm256_loadu_si256((const __m256i*)(&input[i]));
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
        const __m256i t0          = _mm256_loadu_si256((const __m256i*)(&input[i]));
        const __m256i key_0       = _mm256_srli_epi32(t0, 7);
        const __m256i key_indices = _mm256_min_epi32(key_0, fallback_key);

        const __m256i indices     = _mm256_i32gather_epi32((const int*)UTF32_UPPERCASE_OFFSET_AVX2, key_indices, 4);
        const __m256i t1          = _mm256_and_si256(t0, _mm256_set1_epi32(0x7f));
        const __m256i offsets     = _mm256_add_epi32(indices, t1);

        const __m256i t2          = _mm256_i32gather_epi32((const int*)UTF32_UPPERCASE_DATA_AVX2, offsets, 4);
        const __m256i t3          = _mm256_xor_si256(t2, t0);

        _mm256_storeu_si256((__m256i*)(&output[j]), t3);
        if (_mm256_movemask_ps(_mm256_castsi256_ps(t2))) {
            const size_t d = utf32_uppercase_compressed(input + i, 8, output + j);
            j += d;
        } else {
            j += 8;
        }
    }

    const size_t d = utf32_uppercase_compressed(input + i, n - i, output + j);

    return d + j;
}
