#include <cstdint>
#include <immintrin.h>

void avx512_u64_to_bin_ver1(uint64_t v, char* buf) {
    // 1. broadcast word
    const __m512i in = _mm512_set1_epi64(v);

    // 2. in each 64-bit lane populate i-th byte
    const __m512i populate = _mm512_set_epi64(
        0x0000000000000000,
        0x0101010101010101,
        0x0202020202020202,
        0x0303030303030303,
        0x0404040404040404,
        0x0505050505050505,
        0x0606060606060606,
        0x0707070707070707
    );

    const __m512i t0 = _mm512_shuffle_epi8(in, populate);

    // 3. keep j-th bit in each 64-bit word
    const __m512i mask = _mm512_set1_epi64(0x0102040810204080);

    const __m512i t1 = _mm512_and_si512(mask, t0);

    // 4. convert bits to byte 0 or 1
    const __m512i t2 = _mm512_min_epu8(t1, _mm512_set1_epi8(1));

    // 5. convert to ASCII ('0' = 0x30 or '1' = 0x31)
    const __m512i t3 = _mm512_add_epi8(t2, _mm512_set1_epi8('0'));

    _mm512_storeu_si512((__m512i*)buf, t3);
}

void avx512_u64_to_bin_ver2(uint64_t v, char* buf) {
    // 1. broadcast word
    const __m512i in = _mm512_set1_epi64(v);

    // 2. in each 64-bit lane populate i-th byte
    const __m512i populate = _mm512_set_epi64(
        0x0000000000000000,
        0x0101010101010101,
        0x0202020202020202,
        0x0303030303030303,
        0x0404040404040404,
        0x0505050505050505,
        0x0606060606060606,
        0x0707070707070707
    );

    const __m512i t0 = _mm512_shuffle_epi8(in, populate);

    // 3. keep j-th bit in each 64-bit word
    const __m512i bits = _mm512_set1_epi64(0x0102040810204080);
    const __mmask64 mask = _mm512_test_epi8_mask(bits, t0);

    // 4. convert to ASCII ('0' = 0x30 or '1' = 0x31)
    const __m512i t2 = _mm512_mask_add_epi8(
        _mm512_set1_epi8('0'),
        mask,
        _mm512_set1_epi8('0'),
        _mm512_set1_epi8(1)
    );

    _mm512_storeu_si512((__m512i*)buf, t2);
}
