#include "itoa_divless_sse_v2.h"

#include "itoa_divless_sse_v2_table.h"

#include <immintrin.h>

typedef unsigned __int128 uint128_t;

static uint128_t from_sse(__m128i v) {
    union {
        __m128i vec;
        uint128_t val;
    };

    vec = v;
    return val;
}

static __m128i to_sse(uint128_t v) {
    union {
        __m128i vec;
        uint128_t val;
    };

    val = v;
    return vec;
}

void itoa_divless_sse_v2(uint32_t x, char* buffer) {
    const __m128i shift = _mm_set1_epi8(255 - 9);

    // 1. obtain BCD representation of all bytes
    const uint8_t byte0 = x & 0xff;
    const uint8_t byte1 = (x >> 8) & 0xff;

    // 1. add BCD[byte0] and modified-BCD[byte1]
    // The sum never exceeds 8 decimal digits, it's safe to use only 64-bit addition in this case
    const uint64_t sum_01 = *(uint64_t*)&lookup0[byte0][0] +
                            *(uint64_t*)&lookup1[byte1][0];

    // 2. convert back the sum into BCD
    __m128i BCD_01;
    {
        BCD_01 = _mm_set_epi64x(0, sum_01);
        const __m128i mask = _mm_cmplt_epi8(BCD_01, _mm_setzero_si128());
        const __m128i corr = _mm_and_si128(mask, shift);
        BCD_01 = _mm_sub_epi8(BCD_01, corr);
    }

    // 3. add two 16-digit numbers (BCD and modified-BCD)
    const uint8_t byte2 = (x >> 16) & 0xff;
    const uint8_t byte3 = (x >> 24) & 0xff;

    const uint128_t sum_23 = *(uint128_t*)&lookup2[byte2][0] +
                             *(uint128_t*)&lookup3[byte3][0];

    // 4. convert back the sum into BCD
    __m128i BCD_23;
    {
        BCD_23 = to_sse(sum_23);
        const __m128i mask = _mm_cmplt_epi8(BCD_23, _mm_setzero_si128());
        const __m128i corr = _mm_and_si128(mask, shift);
        BCD_23 = _mm_sub_epi8(BCD_23, corr);
    }

    // 5. add sum_01 and sum_23 (now both sums are again in BCD format)
    const uint128_t sum_01a = from_sse(BCD_01);

    BCD_23 = _mm_add_epi8(BCD_23, shift); // denormalize one operand before addition
    const uint128_t sum_23a = from_sse(BCD_23);

    const uint128_t sum = sum_01a + sum_23a;

    // 6. convert back the final sum into BCD
    __m128i BCD;
    {
        BCD = to_sse(sum);
        const __m128i mask = _mm_cmplt_epi8(BCD, _mm_setzero_si128());
        const __m128i corr = _mm_and_si128(mask, _mm_set1_epi8(255 - 9));
        BCD = _mm_sub_epi8(BCD, corr);
    }

    // 7. convert to ASCII and make it printable
    const __m128i ascii = _mm_add_epi8(BCD, _mm_set1_epi8('0'));
    const __m128i reversed = _mm_shuffle_epi8(ascii,
                                              _mm_set_epi8(0, 1, 2, 3, 4, 5, 6, 7, 8,
                                                           9, 10, 11, 12, 13, 14, 15));

    _mm_storeu_si128((__m128i*)buffer, reversed);
}
