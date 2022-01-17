#include "algorithm2.h"

#include <immintrin.h>

uint64_t hex_to_u64_sse_v2(const char* string, bool& ok) {
    
    /*
        '0' .. '9' = 0x30 .. 0x39
        'a' .. 'f' = 0x61 .. 0x66
        'A' .. 'F' = 0x41 .. 0x46
    */

    __m128i input = _mm_loadu_si128((const __m128i*)string);
    const __m128i mask  = _mm_set1_epi8(0x0f);
    const __m128i hi_nibbles = _mm_and_si128(_mm_srli_epi32(input, 4), mask);
    const __m128i lo_nibbles = _mm_and_si128(input, mask);

    const __m128i lower_bound = _mm_setr_epi8(
        /* 0x00 */ char(0xff),
        /* 0x10 */ char(0xff),
        /* 0x20 */ char(0xff),
        /* 0x30 */    0,
        /* 0x40 */    1,
        /* 0x50 */ char(0xff),
        /* 0x60 */    1,
        /* 0x70 */ char(0xff),
        /* 0x80 */ char(0xff),
        /* 0x90 */ char(0xff),
        /* 0xa0 */ char(0xff),
        /* 0xb0 */ char(0xff),
        /* 0xc0 */ char(0xff),
        /* 0xd0 */ char(0xff),
        /* 0xe0 */ char(0xff),
        /* 0xf0 */ char(0xff)
    );

    const __m128i upper_bound = _mm_setr_epi8(
        /* 0x00 */ char(0xff),
        /* 0x10 */ char(0xff),
        /* 0x20 */ char(0xff),
        /* 0x30 */    9,
        /* 0x40 */    6,
        /* 0x50 */ char(0xff),
        /* 0x60 */    6,
        /* 0x70 */ char(0xff),
        /* 0x80 */ char(0xff),
        /* 0x90 */ char(0xff),
        /* 0xa0 */ char(0xff),
        /* 0xb0 */ char(0xff),
        /* 0xc0 */ char(0xff),
        /* 0xd0 */ char(0xff),
        /* 0xe0 */ char(0xff),
        /* 0xf0 */ char(0xff)
    );

    // get lower and upper bounds based on the higher nibbles
    const __m128i lo = _mm_shuffle_epi8(lower_bound, hi_nibbles);
    const __m128i hi = _mm_shuffle_epi8(upper_bound, hi_nibbles);

    const __m128i gt_hi = _mm_cmplt_epi8(hi, lo_nibbles); // lo_nibble > hi_bound
    const __m128i lt_lo = _mm_cmplt_epi8(lo_nibbles, lo); // lo_nibble < lo_bound
    const __m128i error = _mm_or_si128(gt_hi, lt_lo);

    if (_mm_movemask_epi8(error)) {
        ok = false;
        return 0;
    }

    // hi is either 9 or 6:
    // - for 9 (digits) the shift must be equal 0
    // - for 6 (letters) the shift must be equal 9
    // shift = ~hi & 9
    const __m128i shift = _mm_andnot_si128(hi, _mm_set1_epi8(9));
    const __m128i result = _mm_add_epi8(lo_nibbles, shift);

    // now each byte of result have value 0 .. 15, we're going to merge nibbles:
    const __m128i t0 = _mm_maddubs_epi16(result, _mm_set1_epi16(0x0110));
    const __m128i t1 = _mm_setr_epi8(
        14, 12, 10, 8, 6, 4, 2, 0,
        -1, -1, -1, -1, -1, -1, -1, -1);
    const __m128i t3 = _mm_shuffle_epi8(t0, t1);

    ok = true;
    return _mm_cvtsi128_si64x(t3);
}
