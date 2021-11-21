#include "itoa_divless_sse.h"

#include "itoa_divless_sse_table.h"

#include <immintrin.h>

void itoa_divless_sse(uint32_t x, char* buffer) {
    __m128i BCD = _mm_setzero_si128();

    // 1. obtain BCD representation of all bytes
    {
        const uint8_t byte0 = x & 0xff;
        BCD = _mm_add_epi8(BCD, _mm_loadu_si128((const __m128i*)&lookup0[byte0][0]));
    }
    {
        const uint8_t byte1 = (x >> 8) & 0xff;
        BCD = _mm_add_epi8(BCD, _mm_loadu_si128((const __m128i*)&lookup1[byte1][0]));
    }
    {
        const uint8_t byte2 = (x >> 16) & 0xff;
        BCD = _mm_add_epi8(BCD, _mm_loadu_si128((const __m128i*)&lookup2[byte2][0]));
    }
    {
        const uint8_t byte3 = (x >> 24) & 0xff;
        BCD = _mm_add_epi8(BCD, _mm_loadu_si128((const __m128i*)&lookup3[byte3][0]));
    }

    // 2. fixup BCD & store result
    const __m128i shift_right_1 = _mm_setr_epi8(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, -1);

    while (true) {
        const __m128i mask = _mm_cmpgt_epi8(BCD, _mm_set1_epi8(9));
        if (_mm_movemask_epi8(mask) == 0)
            break;

        // carry[i] = 0 or -1
        const __m128i carry = _mm_shuffle_epi8(mask, shift_right_1);

        // byte[i] -= 10 if byte[i] >= 10
        BCD = _mm_sub_epi8(BCD, _mm_and_si128(mask, _mm_set1_epi8(10)));

        // byte[i] += carry[i - 1]
        BCD = _mm_sub_epi8(BCD, carry);
    }

    const __m128i ascii = _mm_add_epi8(BCD, _mm_set1_epi8('0'));

    _mm_storeu_si128((__m128i*)buffer, ascii);
}
