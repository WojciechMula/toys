#include "compressed_v6.cpp.inl"

size_t avx512_utf32_uppercase_compressed_v6(const uint32_t* input, size_t n, uint32_t* output) {
    size_t j=0;
    size_t i=0;

    const __m512i mask_00ff = _mm512_set1_epi32(0x00ff);
    const __m512i mask_03ff = _mm512_set1_epi32(0x03ff);

    const __m512i lo_lookup = _mm512_loadu_si512((const __m512i*)&UTF32_UPPERCASE_V6_LOOKUP[0]);
    const __m512i hi_lookup = _mm512_loadu_si512((const __m512i*)&UTF32_UPPERCASE_V6_LOOKUP[64]);

    for (i=0; i < 16*(n / 16); i += 16) {
        const __m512i src = _mm512_loadu_si512((const __m512i*)(&input[i]));

        if (_mm512_test_epi32_mask(src, _mm512_set1_epi32(0xffffff80)) != 0) {
            const __mmask16 ge_a = _mm512_cmpgt_epi32_mask(src, _mm512_set1_epi32('a' - 1)); // char >= 'a'
            const __mmask16 le_z = _mm512_cmpgt_epi32_mask(_mm512_set1_epi32('z' + 1), src); // char <= 'z'

            const __mmask16 letters = _kand_mask16(ge_a, le_z);

            const __m512i v0 = _mm512_mask_xor_epi32(src, letters, src, _mm512_set1_epi32(0x20));

            _mm512_storeu_si512((__m512i*)(&output[j]), v0);
            j += 16;
            continue;
        }

        // key = min((src >> 4), UTF32_LOWERCASE_V6_MAX_HI_BITS)
        const __m512i key         = _mm512_srli_epi32(src, 10);
        const __m512i group_0     = _mm512_permutex2var_epi8(lo_lookup, key, hi_lookup);
        const __m512i group       = _mm512_and_si512(group_0, mask_00ff);

        const __m512i ofs_0       = _mm512_slli_epi32(group, 10);
        const __m512i ofs_1       = _mm512_and_si512(src, mask_03ff);
        const __m512i indices     = _mm512_add_epi32(ofs_1, ofs_0);

        // const uint32_t diff = UTF32_UPPERCASE_V6_DATA[indices];
        const __m512i diff        = _mm512_i32gather_epi32(indices, (const uint32_t*)UTF32_UPPERCASE_V6_DATA, 4);
        const __m512i out         = _mm512_xor_si512(diff, src);

        _mm512_storeu_si512((__m512i*)(&output[j]), out);
        if (_mm512_movepi32_mask(diff) != 0) {
            const size_t d = utf32_uppercase_compressed_v3(input + i, 8, output + j);
            j += d;
        } else {
            j += 16;
        }
    }

    const size_t d = utf32_uppercase_compressed_v3(input + i, n - i, output + j);

    return d + j;
}
