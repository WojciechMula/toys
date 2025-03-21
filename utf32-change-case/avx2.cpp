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

size_t avx2_utf32_uppercase_compressed_v3(const uint32_t* input, size_t n, uint32_t* output) {
    size_t j=0;
    size_t i=0;

    const __m256i fallback_key = _mm256_set1_epi32(UTF32_UPPERCASE_V3_MAX_HI_BITS);
    const __m256i mask_00ff    = _mm256_set1_epi32(0x00ff);
    const __m256i mask_000f    = _mm256_set1_epi32(0x000f);

    for (i=0; i < 8*(n / 8); i += 8) {
        const __m256i src = _mm256_loadu_si256((const __m256i*)(&input[i]));

        if (_mm256_testz_si256(src, _mm256_set1_epi32(0xffffff80))) {
            const __m256i ge_a = _mm256_cmpgt_epi32(src, _mm256_set1_epi32('a' - 1)); // char >= 'a'
            const __m256i le_z = _mm256_cmpgt_epi32(_mm256_set1_epi32('z' + 1), src); // char <= 'z'

            const __m256i v0 = _mm256_and_si256(ge_a, le_z);
            const __m256i v1 = _mm256_and_si256(v0, _mm256_set1_epi32(0x20));
            const __m256i v2 = _mm256_xor_si256(src, v1);

            _mm256_storeu_si256((__m256i*)(&output[j]), v2);
            j += 8;
            continue;
        }

        // key = min((src >> 4), UTF32_LOWERCASE_V3_MAX_HI_BITS)
        const __m256i key_0       = _mm256_srli_epi32(src, 4);
        const __m256i key         = _mm256_min_epi32(key_0, fallback_key);

        // group_id = lookup[key] & 0xff
        const __m256i group_id_0  = _mm256_i32gather_epi32((const int*)UTF32_UPPERCASE_V3_LOOKUP, key, 1);
        const __m256i group_id    = _mm256_and_si256(group_id_0, mask_00ff);

        // ofs = src & 0xf
        const __m256i ofs         = _mm256_and_si256(src, mask_000f);

        // const uint32_t diff = UTF32_UPPERCASE_V3_DATA[group_id * 16 + ofs];
        const __m256i indices     = _mm256_add_epi32(_mm256_slli_epi32(group_id, 4), ofs);
        const __m256i diff        = _mm256_i32gather_epi32((const int*)UTF32_UPPERCASE_V3_DATA, indices, 4);
        const __m256i out         = _mm256_xor_si256(diff, src);

        _mm256_storeu_si256((__m256i*)(&output[j]), out);
        if (_mm256_movemask_ps(_mm256_castsi256_ps(diff))) {
            const size_t d = utf32_uppercase_compressed_v3(input + i, 8, output + j);
            j += d;
        } else {
            j += 8;
        }
    }

    const size_t d = utf32_uppercase_compressed_v3(input + i, n - i, output + j);

    return d + j;
}

size_t avx2_utf32_lowercase_compressed_v3(const uint32_t* input, size_t n, uint32_t* output) {
    size_t j=0;
    size_t i=0;

    const __m256i fallback_key = _mm256_set1_epi32(UTF32_LOWERCASE_V3_MAX_HI_BITS);
    const __m256i mask_00ff    = _mm256_set1_epi32(0x00ff);
    const __m256i mask_000f    = _mm256_set1_epi32(0x000f);

    for (i=0; i < 8*(n / 8); i += 8) {
        const __m256i src = _mm256_loadu_si256((const __m256i*)(&input[i]));

        if (_mm256_testz_si256(src, _mm256_set1_epi32(0xffffff80))) {
            const __m256i ge_a = _mm256_cmpgt_epi32(src, _mm256_set1_epi32('A' - 1)); // char >= 'a'
            const __m256i le_z = _mm256_cmpgt_epi32(_mm256_set1_epi32('Z' + 1), src); // char <= 'z'

            const __m256i v0 = _mm256_and_si256(ge_a, le_z);
            const __m256i v1 = _mm256_and_si256(v0, _mm256_set1_epi32(0x20));
            const __m256i v2 = _mm256_xor_si256(src, v1);

            _mm256_storeu_si256((__m256i*)(&output[j]), v2);
            j += 8;
            continue;
        }

        // key = min((src >> 4), UTF32_LOWERCASE_V3_MAX_HI_BITS)
        const __m256i key_0       = _mm256_srli_epi32(src, 4);
        const __m256i key         = _mm256_min_epi32(key_0, fallback_key);

        // group_id = lookup[key] & 0xff
        const __m256i group_id_0  = _mm256_i32gather_epi32((const int*)UTF32_LOWERCASE_V3_LOOKUP, key, 1);
        const __m256i group_id    = _mm256_and_si256(group_id_0, mask_00ff);

        // ofs = src & 0xf
        const __m256i ofs         = _mm256_and_si256(src, mask_000f);

        // const uint32_t diff = UTF32_LOWERCASE_V3_DATA[group_id * 16 + ofs];
        const __m256i indices     = _mm256_add_epi32(_mm256_slli_epi32(group_id, 4), ofs);
        const __m256i diff        = _mm256_i32gather_epi32((const int*)UTF32_LOWERCASE_V3_DATA, indices, 4);
        const __m256i out         = _mm256_xor_si256(diff, src);

        _mm256_storeu_si256((__m256i*)(&output[j]), out);
        if (_mm256_movemask_ps(_mm256_castsi256_ps(diff))) {
            const size_t d = utf32_lowercase_compressed_v3(input + i, 8, output + j);
            j += d;
        } else {
            j += 8;
        }
    }

    const size_t d = utf32_lowercase_compressed_v3(input + i, n - i, output + j);

    return d + j;
}

#include "compressed_v4.cpp.inl"

static __m256i select(__m256i c, __m256i a, __m256i b) {
    return _mm256_or_si256(
        _mm256_and_si256(c, a),
        _mm256_andnot_si256(c, b)
    );
}

static __m256i _mm256_set1_m128i(__m128i v) {
    return _mm256_set_m128i(v, v);
}

size_t avx2_utf32_uppercase_compressed_v4(const uint32_t* input, size_t n, uint32_t* output) {
    size_t j=0;
    size_t i=0;

    const __m256i mask_0fff = _mm256_set1_epi32(0x0fff);
    const __m256i mask_00ff = _mm256_set1_epi32(0x00ff);
    const __m256i mask_000f = _mm256_set1_epi32(0x000f);

    const __m256i lo_lookup = _mm256_set1_m128i(_mm_loadu_si128((const __m128i*)&UTF32_UPPERCASE_V4_LOOKUP[0]));
    const __m256i hi_lookup = _mm256_set1_m128i(_mm_loadu_si128((const __m128i*)&UTF32_UPPERCASE_V4_LOOKUP[16]));

    for (i=0; i < 8*(n / 8); i += 8) {
        const __m256i src = _mm256_loadu_si256((const __m256i*)(&input[i]));

        if (_mm256_testz_si256(src, _mm256_set1_epi32(0xffffff80))) {
            const __m256i ge_a = _mm256_cmpgt_epi32(src, _mm256_set1_epi32('a' - 1)); // char >= 'a'
            const __m256i le_z = _mm256_cmpgt_epi32(_mm256_set1_epi32('z' + 1), src); // char <= 'z'

            const __m256i v0 = _mm256_and_si256(ge_a, le_z);
            const __m256i v1 = _mm256_and_si256(v0, _mm256_set1_epi32(0x20));
            const __m256i v2 = _mm256_xor_si256(src, v1);

            _mm256_storeu_si256((__m256i*)(&output[j]), v2);
            j += 8;
            continue;
        }

        // key = min((src >> 12), UTF32_LOWERCASE_V4_MAX_HI_BITS)
        const __m256i key_0       = _mm256_srli_epi32(src, 12);
        const __m256i key         = _mm256_min_epi32(key_0, _mm256_set1_epi32(UTF32_LOWERCASE_V4_MAX_HI_BITS));

        // lo = lookup for bits 15:12, where bit #16 is 0
        const __m256i lo          = _mm256_shuffle_epi8(lo_lookup, key);

        // hi = lookup for bits 15:12, where bit #16 is 1
        const __m256i hi          = _mm256_shuffle_epi8(hi_lookup, key);

        // mask: bit #16 to mask
        const __m256i mask        = _mm256_cmpgt_epi32(key, mask_000f);

        // group_id = lookup[key] & 0xff
        const __m256i ofs_0       = select(mask, hi, lo);
        const __m256i ofs_1       = _mm256_and_si256(ofs_0, mask_00ff);
        const __m256i ofs_2       = _mm256_slli_epi32(ofs_1, 12);
        const __m256i ofs_3       = _mm256_and_si256(src, mask_0fff);

        // indices = (group_id << 12) + (src_code & 0xfff)
        const __m256i indices     = _mm256_add_epi32(ofs_3, ofs_2);

        // const uint32_t diff = UTF32_UPPERCASE_V4_DATA[indices];
        const __m256i diff        = _mm256_i32gather_epi32((const int*)UTF32_UPPERCASE_V4_DATA, indices, 4);
        const __m256i out         = _mm256_xor_si256(diff, src);

        _mm256_storeu_si256((__m256i*)(&output[j]), out);
        if (_mm256_movemask_ps(_mm256_castsi256_ps(diff))) {
            const size_t d = utf32_uppercase_compressed_v3(input + i, 8, output + j);
            j += d;
        } else {
            j += 8;
        }
    }

    const size_t d = utf32_uppercase_compressed_v3(input + i, n - i, output + j);

    return d + j;
}

#include "compressed_v5.cpp.inl"

size_t avx2_utf32_uppercase_compressed_v5(const uint32_t* input, size_t n, uint32_t* output) {
    size_t j=0;
    size_t i=0;

    const __m256i mask_000f    = _mm256_set1_epi32(0x000f);
    const __m256i mask_00ff    = _mm256_set1_epi32(0x00ff);
    const __m256i mask_07ff    = _mm256_set1_epi32(0x07ff);

    const __m256i lookup_0 = _mm256_set1_m128i(_mm_loadu_si128((const __m128i*)&UTF32_UPPERCASE_V5_LOOKUP[0*16]));
    const __m256i lookup_1 = _mm256_set1_m128i(_mm_loadu_si128((const __m128i*)&UTF32_UPPERCASE_V5_LOOKUP[1*16]));
    const __m256i lookup_2 = _mm256_set1_m128i(_mm_loadu_si128((const __m128i*)&UTF32_UPPERCASE_V5_LOOKUP[2*16]));
    const __m256i lookup_3 = _mm256_set1_m128i(_mm_loadu_si128((const __m128i*)&UTF32_UPPERCASE_V5_LOOKUP[3*16]));

    for (i=0; i < 8*(n / 8); i += 8) {
        const __m256i src = _mm256_loadu_si256((const __m256i*)(&input[i]));

        if (_mm256_testz_si256(src, _mm256_set1_epi32(0xffffff80))) {
            const __m256i ge_a = _mm256_cmpgt_epi32(src, _mm256_set1_epi32('a' - 1)); // char >= 'a'
            const __m256i le_z = _mm256_cmpgt_epi32(_mm256_set1_epi32('z' + 1), src); // char <= 'z'

            const __m256i v0 = _mm256_and_si256(ge_a, le_z);
            const __m256i v1 = _mm256_and_si256(v0, _mm256_set1_epi32(0x20));
            const __m256i v2 = _mm256_xor_si256(src, v1);

            _mm256_storeu_si256((__m256i*)(&output[j]), v2);
            j += 8;
            continue;
        }

        const __m256i key_0       = _mm256_srli_epi32(src, 11);
        const __m256i key         = _mm256_and_si256(key_0, mask_000f);
        const __m256i selector    = _mm256_srli_epi32(src, 15);

        const __m256i res0_a      = _mm256_shuffle_epi8(lookup_0, key);
        const __m256i selector_0  = _mm256_cmpeq_epi32(selector, _mm256_set1_epi32(0));
        const __m256i res0        = _mm256_and_si256(res0_a, selector_0);

        const __m256i res1_a      = _mm256_shuffle_epi8(lookup_1, key);
        const __m256i selector_1  = _mm256_cmpeq_epi32(selector, _mm256_set1_epi32(1));
        const __m256i res1        = _mm256_and_si256(res1_a, selector_1);

        const __m256i res2_a      = _mm256_shuffle_epi8(lookup_2, key);
        const __m256i selector_2  = _mm256_cmpeq_epi32(selector, _mm256_set1_epi32(2));
        const __m256i res2        = _mm256_and_si256(res2_a, selector_2);

        const __m256i res3_a      = _mm256_shuffle_epi8(lookup_3, key);
        const __m256i selector_3  = _mm256_cmpeq_epi32(selector, _mm256_set1_epi32(3));
        const __m256i res3        = _mm256_and_si256(res3_a, selector_3);

        const __m256i group_0     = _mm256_or4_si256(res0, res1, res2, res3);
        const __m256i group_1     = _mm256_and_si256(group_0, mask_00ff);
        const __m256i group       = _mm256_slli_epi32(group_1, 11);

        const __m256i ofs         = _mm256_and_si256(src, mask_07ff);
        const __m256i indices     = _mm256_add_epi32(ofs, group);

        // const uint32_t diff = UTF32_UPPERCASE_V4_DATA[indices];
        const __m256i diff        = _mm256_i32gather_epi32((const int*)UTF32_UPPERCASE_V5_DATA, indices, 4);
        const __m256i out         = _mm256_xor_si256(diff, src);

        _mm256_storeu_si256((__m256i*)(&output[j]), out);
        if (_mm256_movemask_ps(_mm256_castsi256_ps(diff))) {
            const size_t d = utf32_uppercase_compressed_v3(input + i, 8, output + j);
            j += d;
        } else {
            j += 8;
        }
    }

    const size_t d = utf32_uppercase_compressed_v3(input + i, n - i, output + j);

    return d + j;
}
