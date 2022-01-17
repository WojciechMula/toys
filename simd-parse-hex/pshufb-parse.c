#include <immintrin.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>

uint64_t hex_to_u64_sse(const uint8_t* string) {
    
    /*
        '0' .. '9' = 0x30 .. 0x39
        'a' .. 'f' = 0x61 .. 0x66
        'A' .. 'F' = 0x41 .. 0x46

        shift   : 1
        pshufb  : 3
        and     : 7
        or      : 1
        cmp     : 2
        add     : 0
    */

    __m128i input = _mm_loadu_si128((const __m128i*)string);
    const __m128i mask  = _mm_set1_epi8(0x0f);
    const __m128i hi_nibbles = _mm_and_si128(_mm_srli_epi32(input, 4), mask);
    const __m128i lo_nibbles = _mm_and_si128(input, mask);

    const int error1  = 0x10;
    const int error2  = 0x20;
    const int letters = 0x40;
    const int digits  = 0x80;

    // pretend that input & 0xf0 == 0x30
    const __m128i lo_ascii_09 = _mm_shuffle_epi8(_mm_setr_epi8(
                                   0 + digits,
                                   1 + digits,
                                   2 + digits,
                                   3 + digits,
                                   4 + digits,
                                   5 + digits,
                                   6 + digits,
                                   7 + digits,
                                   8 + digits,
                                   9 + digits,
                                   error1, error1, error1, error1, error1, error1), input);

    // pretend that input & 0xf0 == 0x40 or 0x60
    const __m128i lo_ascii_af = _mm_shuffle_epi8(_mm_setr_epi8(
                                   error1,
                                   10 + letters,
                                   11 + letters,
                                   12 + letters,
                                   13 + letters,
                                   14 + letters,
                                   15 + letters,
                                   error1,
                                   error1,
                                   error1,
                                   error1, error1, error1, error1, error1, error1), lo_nibbles);
    
    // check value of higher nibble 
    const __m128i hi_class = _mm_shuffle_epi8(_mm_setr_epi8(
                                            error2, error2, error2, digits /* 0x30 */,
                                            letters /* 0x40 */, error2, letters /* 0x60 */, error2,
                                            error2, error2, error2, error2,
                                            error2, error2, error2, error2), hi_nibbles);

    // and find out which preposition was true
    const __m128i ascii_09_mask = _mm_cmpeq_epi8(_mm_and_si128(hi_class, lo_ascii_09), hi_class);
    const __m128i ascii_af_mask = _mm_cmpeq_epi8(_mm_and_si128(hi_class, lo_ascii_af), hi_class);
    const __m128i ascii_09 = _mm_and_si128(ascii_09_mask, lo_ascii_09);
    const __m128i ascii_af = _mm_and_si128(ascii_af_mask, lo_ascii_af);

#if 0
    // MSBs of error vector indicates invalid characters
    const __m128i errorvec = _mm_xor_si128(ascii_09_mask | ascii_af_mask, _mm_set1_epi8(-1));
    if (_mm_movemask_epi8(errorvec))
        abort();
#endif

    const __m128i result = _mm_and_si128(_mm_or_si128(ascii_09, ascii_af), mask);

    // now each byte of result have value 0 .. 15, we're going to merge nibbles:

#if 0
    const __m128i t0 = result;
    const __m128i t1 = _mm_srli_epi32(result, 4);
    const __m128i t3 = _mm_or_si128(t0, t1);
    const __m128i t4 = _mm_and_si128(t3, _mm_set1_epi16(0x00ff)); // keep just lower bytes in words
    const __m128i t5 = _mm_packus_epi16(t4, t4); // now lower part of the reg has 8-byte value

    return _mm_cvtsi128_si64x(t5);
#else
    const __m128i t3 = _mm_maddubs_epi16(result, _mm_set1_epi16(0x0110));
    const __m128i t5 = _mm_shuffle_epi8(t3, _mm_setr_epi8(14, 12, 10, 8, 6, 4, 2, 0, -1, -1, -1, -1, -1, -1, -1, -1));

    return _mm_cvtsi128_si64x(t5);
#endif
}

uint64_t hex_to_u64_sse2(const uint8_t* string) {
    
    /*
        '0' .. '9' = 0x30 .. 0x39
        'a' .. 'f' = 0x61 .. 0x66
        'A' .. 'F' = 0x41 .. 0x46

        shift   : 1
        pshufb  : 2
        and     : 3
        or      : 1
        cmp     : 2
        add     : 1
    */

    __m128i input = _mm_loadu_si128((const __m128i*)string);
    const __m128i mask  = _mm_set1_epi8(0x0f);
    const __m128i hi_nibbles = _mm_and_si128(_mm_srli_epi32(input, 4), mask);
    const __m128i lo_nibbles = _mm_and_si128(input, mask);

    const __m128i lower_bound = _mm_setr_epi8(
        /* 0x00 */ 0xff,
        /* 0x10 */ 0xff,
        /* 0x20 */ 0xff,
        /* 0x30 */    0,
        /* 0x40 */    1,
        /* 0x50 */ 0xff,
        /* 0x60 */    1,
        /* 0x70 */ 0xff,
        /* 0x80 */ 0xff,
        /* 0x90 */ 0xff,
        /* 0xa0 */ 0xff,
        /* 0xb0 */ 0xff,
        /* 0xc0 */ 0xff,
        /* 0xd0 */ 0xff,
        /* 0xe0 */ 0xff,
        /* 0xf0 */ 0xff
    );

    const __m128i upper_bound = _mm_setr_epi8(
        /* 0x00 */ 0xff,
        /* 0x10 */ 0xff,
        /* 0x20 */ 0xff,
        /* 0x30 */    9,
        /* 0x40 */    6,
        /* 0x50 */ 0xff,
        /* 0x60 */    6,
        /* 0x70 */ 0xff,
        /* 0x80 */ 0xff,
        /* 0x90 */ 0xff,
        /* 0xa0 */ 0xff,
        /* 0xb0 */ 0xff,
        /* 0xc0 */ 0xff,
        /* 0xd0 */ 0xff,
        /* 0xe0 */ 0xff,
        /* 0xf0 */ 0xff
    );

    // get lower and upper bounds based on the higher nibbles
    const __m128i lo = _mm_shuffle_epi8(lower_bound, hi_nibbles);
    const __m128i hi = _mm_shuffle_epi8(upper_bound, hi_nibbles);

    const __m128i gt_hi = _mm_cmplt_epi8(hi, lo_nibbles); // lo_nibble > hi_bound
    const __m128i lt_lo = _mm_cmplt_epi8(lo_nibbles, lo); // lo_nibble < lo_bound
    const __m128i error = _mm_or_si128(gt_hi, lt_lo);

    if (_mm_movemask_epi8(error)) {
        printf("%x\n", _mm_movemask_epi8(error));
        abort();
    }

    // hi is either 9 or 6:
    // - for 9 (digits) the shift must be equal 0
    // - for 6 (letters) the shift must be equal 9
    // shift = ~hi & 9
    const __m128i shift = _mm_andnot_si128(hi, _mm_set1_epi8(9));
    const __m128i result = _mm_add_epi8(lo_nibbles, shift);

    // now each byte of result have value 0 .. 15, we're going to merge nibbles:
    const __m128i t3 = _mm_maddubs_epi16(result, _mm_set1_epi16(0x0110));
    const __m128i t5 = _mm_shuffle_epi8(t3, _mm_setr_epi8(14, 12, 10, 8, 6, 4, 2, 0, -1, -1, -1, -1, -1, -1, -1, -1));

    return _mm_cvtsi128_si64x(t5);
}

int main() {
    //char var[16] = "123456789AbCdEf0";
    char var[16] = "ABCDEF0123456789";

    printf("%llx\n", hex_to_u64_sse(var));
    printf("%llx\n", hex_to_u64_sse2(var));
}
