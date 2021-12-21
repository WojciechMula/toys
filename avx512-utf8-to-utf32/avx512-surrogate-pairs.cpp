#include "avx512-surrogate-pairs.h"

#include <cstdint>

#if 0
template <typename T>
bool test_and_clear_bit(T& val, int bitpos) {
    const T bitmask = T(1) << bitpos;

    const bool ret = (val & bitmask);

    val &= ~bitmask;

    return ret;
}
#else
bool test_and_clear_bit(uint32_t& val, int bitpos) {
    uint32_t flag = 0;

    asm (
        "btr  %[bitpos], %[val]    \n"
        "setc %b[flag]       \n"
        : [val] "=r" (val),
          [flag] "=r" (flag)
        : [bitpos] "r" (bitpos),
          "0" (val),
          "1" (flag)
        : "cc"
    );

    return flag;
}
#endif

namespace {
    const __m512i v_0000_ffff = _mm512_set1_epi32(0x0000'ffff);
    const __m512i v_ffff_0000 = _mm512_set1_epi32(0xffff'0000);
    const __m512i v_0001_0000 = _mm512_set1_epi32(0x0001'0000);
    const __m512i v_fc00_fc00 = _mm512_set1_epi32(0xfc00'fc00);
    const __m512i v_d800_dc00 = _mm512_set1_epi32(0xd800'dc00);
}

size_t avx512_utf32_to_utf16(__m512i utf32, char16_t* output) {
    // 1. check if we have any surrogate pair
    const __mmask16 sp = _mm512_cmpgt_epu32_mask(utf32, v_0000_ffff);
    if (sp == 0) {
        _mm256_storeu_si256((__m256i*)output, _mm512_cvtepi32_epi16(utf32));
        return 16;
    }

    union {
        uint16_t words[32];
        uint32_t dwords[16];
    };

    {
        // 2. build surrogate pair words in 32-bit lan

        //    t0 = 8 x [000000000000aaaa|aaaaaabbbbbbbbbb]
        const __m512i t0 = _mm512_sub_epi32(utf32, v_0001_0000);

        //    t1 = 8 x [000000aaaaaaaaaa|bbbbbbbbbb000000]
        const __m512i t1 = _mm512_slli_epi32(t0, 6);

        //    t2 = 8 x [000000aaaaaaaaaa|aaaaaabbbbbbbbbb] -- copy hi word from t1 to t0
        //         0xe4 = (t1 and v_ffff_0000) or (t0 and not v_ffff_0000)
        const __m512i t2 = _mm512_ternarylogic_epi32(t1, t0, v_ffff_0000, 0xe4);

        //    t2 = 8 x [110110aaaaaaaaaa|110111bbbbbbbbbb] -- copy hi word from t1 to t0
        //         0xba = (t2 and not v_fc00_fc000) or v_d800_dc00
        const __m512i t3 = _mm512_maskz_ternarylogic_epi32(sp, t2, v_fc00_fc00, v_d800_dc00, 0xba);

        _mm512_storeu_si512((__m512i*)dwords, t3);
    }

    // 3. store valid 16-bit values
    _mm256_storeu_si256((__m256i*)output, _mm512_cvtepi32_epi16(utf32));

    int count = __builtin_popcount(sp);

    // 4. copy surrogate pairs
    uint32_t mask = sp;
    for (int i=15; i >= 0 && mask != 0; i--) {
        if (test_and_clear_bit(mask, i)) {
            output[i + count] = words[2*i + 0];
            count -= 1;
            output[i + count] = words[2*i + 1];
        } else {
            output[i + count] = output[i];
        }
    }

    return 16 + __builtin_popcount(sp);
}
