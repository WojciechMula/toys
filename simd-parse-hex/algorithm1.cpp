#include "algorithm1.h"

#include <immintrin.h>

uint64_t hex_to_u64_sse_v1(const char* string, bool& ok) {
    
    /*
        '0' .. '9' = 0x30 .. 0x39
        'a' .. 'f' = 0x61 .. 0x66
        'A' .. 'F' = 0x41 .. 0x46
    */

    __m128i input = _mm_loadu_si128((const __m128i*)string);
    const __m128i mask  = _mm_set1_epi8(0x0f);
    const __m128i hi_nibbles = _mm_and_si128(_mm_srli_epi32(input, 4), mask);
    const __m128i lo_nibbles = _mm_and_si128(input, mask);

    const int error   = 0x80;
    const int digits  = 0x40;
    const int letters = 0x20;

    // pretend that input & 0xf0 == 0x30
    const __m128i lookup1 = _mm_setr_epi8(
        /* 0 */ char(0 + digits),
        /* 1 */ char(1 + digits),
        /* 2 */ char(2 + digits),
        /* 3 */ char(3 + digits),
        /* 4 */ char(4 + digits),
        /* 5 */ char(5 + digits),
        /* 6 */ char(6 + digits),
        /* 7 */ char(7 + digits),
        /* 8 */ char(8 + digits),
        /* 9 */ char(9 + digits),
        /* a */ char(error),
        /* b */ char(error),
        /* c */ char(error),
        /* d */ char(error),
        /* e */ char(error),
        /* f */ char(error));
    const __m128i lo_ascii_09 = _mm_shuffle_epi8(lookup1, input);

    // pretend that input & 0xf0 == 0x40 or 0x60
    const __m128i lookup2 = _mm_setr_epi8(
        /* 0 */ char(error),
        /* 1 */ char(10 + letters),
        /* 2 */ char(11 + letters),
        /* 3 */ char(12 + letters),
        /* 4 */ char(13 + letters),
        /* 5 */ char(14 + letters),
        /* 6 */ char(15 + letters),
        /* 7 */ char(error),
        /* 8 */ char(error),
        /* 9 */ char(error),
        /* a */ char(error),
        /* b */ char(error),
        /* c */ char(error),
        /* d */ char(error),
        /* e */ char(error),
        /* f */ char(error));
    const __m128i lo_ascii_af = _mm_shuffle_epi8(lookup2, lo_nibbles);
    
    // check value of higher nibble 
    const __m128i lookup3 = _mm_setr_epi8(
        /* 0 */ char(error),
        /* 1 */ char(error),
        /* 2 */ char(error),
        /* 3 */ char(digits),
        /* 4 */ char(letters),
        /* 5 */ char(error),
        /* 6 */ char(letters),
        /* 7 */ char(error),
        /* 8 */ char(error),
        /* 9 */ char(error),
        /* a */ char(error),
        /* b */ char(error),
        /* c */ char(error),
        /* d */ char(error),
        /* e */ char(error),
        /* f */ char(error));
    const __m128i hi_class = _mm_shuffle_epi8(lookup3, hi_nibbles);

    // and find out which preposition was true
    const __m128i ascii_09_mask = _mm_cmpeq_epi8(_mm_and_si128(hi_class, lo_ascii_09), hi_class);
    const __m128i ascii_af_mask = _mm_cmpeq_epi8(_mm_and_si128(hi_class, lo_ascii_af), hi_class);
    const __m128i ascii_09 = _mm_and_si128(ascii_09_mask, lo_ascii_09);
    const __m128i ascii_af = _mm_and_si128(ascii_af_mask, lo_ascii_af);

    const __m128i res = _mm_or_si128(ascii_09, ascii_af);
    const __m128i err = _mm_or_si128(hi_class, res);
    if (_mm_movemask_epi8(err)) {
        ok = false;
        return 0;
    }

    const __m128i result = _mm_and_si128(res, mask);

    // now each byte of result have value 0 .. 15, we're going to merge nibbles:
    const __m128i t0 = _mm_maddubs_epi16(result, _mm_set1_epi16(0x0110));
    const __m128i t1 = _mm_setr_epi8(
        14, 12, 10, 8, 6, 4, 2, 0,
        -1, -1, -1, -1, -1, -1, -1, -1);
    const __m128i t3 = _mm_shuffle_epi8(t0, t1);

    ok = true;
    return _mm_cvtsi128_si64x(t3);
}
