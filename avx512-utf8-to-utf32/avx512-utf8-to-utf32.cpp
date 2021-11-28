#include "avx512-utf8-to-utf32.h"

__m512i avx512_utf8_to_utf32__aux(__m512i utf8);

static const __m512i indices = _mm512_setr_epi32(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);

size_t avx512_utf8_to_utf32(const char* str, size_t len, uint32_t* dwords) {
    const char* ptr = str;
    const char* end = ptr + len;
    
    uint32_t* output = dwords;

    while (ptr + 16 + 3 < end) {
        /* 1. Load all possible 4-byte substring into an AVX512 register
              For example if we have bytes abcdefgh... we create following 32-bit lanes

              [abcd|bcde|cdef|defg|efgh|...]
               ^                          ^
               byte 0 of reg              byte 63 of reg

              It means, we are touching 16+3 = 19 bytes

              XXX: gather is slow, we may consider some scalar code or -- better --
                   use _mm512_permutex2var_epi8()
        */
        const __m512i input = _mm512_i32gather_epi32(indices, ptr, 1);

        /*
            2. Classify which words contain valid UTF-8 characters.
               We test if the 0th byte is not a continuation byte (0b10xxxxxx) */
        __mmask16 valid;
        {
            const __m512i t0 = _mm512_and_si512(input, _mm512_set1_epi32(0xc0));
            valid = _mm512_cmpneq_epu32_mask(t0, _mm512_set1_epi32(0x80));
        }
        const int valid_count = __builtin_popcount(valid);

        // 3. Convert words into UCS-32
        //    (XXX: would passing `valid` mask speed things up?)
        const __m512i utf32 = avx512_utf8_to_utf32__aux(input);

        // 4. Pack only valid words
        const __m512i out = _mm512_mask_compress_epi32(_mm512_setzero_si512(), valid, utf32);

        // 5. Store them
        _mm512_storeu_si512((__m512i*)output, out);

        output += valid_count;
        ptr += 16;
    }

    // TODO: process the tail

    return output - dwords;
}


__m512i avx512_utf8_to_utf32__aux(__m512i utf8) {
    /*
        Input:
        - utf8: bytes stored at separate 32-bit words
        - valid: which words have valid UTF-8 characters

        Bit layout of single word. We show 4 cases for each possible
        UTF-8 character encoding. The `?` denotes bits we must not
        assume their value.

        |10dd.dddd|10cc.cccc|10bb.bbbb|1111.0aaa| 4-byte char
        |????.????|10cc.cccc|10bb.bbbb|1110.aaaa| 3-byte char
        |????.????|????.????|10bb.bbbb|110a.aaaa| 2-byte char
        |????.????|????.????|????.????|0aaa.aaaa| ASCII char
          byte 3    byte 2    byte 1     byte 0
    */

    /* 1. Swap bytes within the 32-bit lanes

        |1111.0aaa|10bb.bbbb|10cc.cccc|10dd.dddd|
        |1110.aaaa|10bb.bbbb|10cc.cccc|????.????|
        |110a.aaaa|10bb.bbbb|????.????|????.????|
        |0aaa.aaaa|????.????|????.????|????.????| */
    __m512i values;
    // 4 * [3, 2, 1, 0, 7, 6, 5, 4, 11, 10, 9, 8, 15, 14, 13, 12]
    const __m512i bswap_lookup = _mm512_setr_epi64(
        0x0405060700010203,
        0x0c0d0e0f08090a0b,
        0x0405060700010203,
        0x0c0d0e0f08090a0b,
        0x0405060700010203,
        0x0c0d0e0f08090a0b,
        0x0405060700010203,
        0x0c0d0e0f08090a0b
    );

    values = _mm512_shuffle_epi8(utf8, bswap_lookup);

    /* 2. Shift continuation byte B (byte #2) left by 2 and merge with the value

        |1111.0aaa|bbbb.bb??|10cc.cccc|10dd.dddd|
        |1110.aaaa|bbbb.bb??|10cc.cccc|????.????|
        |110a.aaaa|bbbb.bb??|????.????|????.????|
        |0aaa.aaaa|????.????|????.????|????.????| */
    const uint8_t merge_function = 0xca; // ((mask and value) or (not mask and field))
    {
        const __m512i mask = _mm512_set1_epi32(0x00fc0000);
        __m512i B = _mm512_slli_epi32(values, 2);
        values = _mm512_ternarylogic_epi32(mask, B, values, merge_function);
    }

    /* 3. Shift continuation byte C (byte #1) left by 4 and merge with the value

        |1111.0aaa|bbbb.bbcc|cccc.????|10dd.dddd|
        |1110.aaaa|bbbb.bbcc|cccc.????|????.????|
        |110a.aaaa|bbbb.bb??|????.????|????.????|
        |0aaa.aaaa|????.????|????.????|????.????| */
    {
        const __m512i mask = _mm512_set1_epi32(0x0003f000);
        __m512i C = _mm512_slli_epi32(values, 4);
        values = _mm512_ternarylogic_epi32(mask, C, values, merge_function);
    }

    /* 4. Shift continuation byte D (byte #0) left by 6 and merge with the value

        |1111.0aaa|bbbb.bbcc|cccc.dddd|dd??.????|
        |1110.aaaa|bbbb.bbcc|cccc.????|????.????|
        |110a.aaaa|bbbb.bb??|????.????|????.????|
        |0aaa.aaaa|????.????|????.????|????.????| */
    {
        const __m512i mask = _mm512_set1_epi32(0x00000fc0);
        __m512i D = _mm512_slli_epi32(values, 6);
        values = _mm512_ternarylogic_epi32(mask, D, values, merge_function);
    }

    /* 5. Get the 4 most significant bits from byte #0 -- these values
          will be used by to distinguish character classes

        |0000.0000|0000.0000|0000.0000|0000.1111|
        |0000.0000|0000.0000|0000.0000|0000.1110|
        |0000.0000|0000.0000|0000.0000|0000.110a|
        |0000.0000|0000.0000|0000.0000|0000.0aaa| */
    const __m512i char_type = _mm512_and_si512(_mm512_srli_epi32(utf8, 4),
                                               _mm512_set1_epi32(0x0000000f));

    /* 6. Shift left the values by variable amounts to reset highest UTF-8 bits 

        |aaab.bbbb|bccc.cccd|dddd.d???|???0.0000| shift left by 5
        |aaaa.bbbb|bbcc.cccc|????.????|????.0000| shift left by 4
        |aaaa.abbb|bbb?.????|????.????|????.?000| shift left by 3
        |aaaa.aaa?|????.????|????.????|????.???0| shift left by 1 */
    {
        // 4 * [1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 3, 3, 4, 5]
        const __m512i shift_left = _mm512_setr_epi64(
            0x0101010101010101,
            0x0504030300000000,
            0x0101010101010101,
            0x0504030300000000,
            0x0101010101010101,
            0x0504030300000000,
            0x0101010101010101,
            0x0504030300000000
        );

        __m512i shift = _mm512_shuffle_epi8(shift_left, char_type);
        shift = _mm512_and_si512(shift, _mm512_set1_epi32(0xff));
        values = _mm512_sllv_epi32(values, shift);
    }

    /* 7. Shift right the values by variable amounts to reset lowest bits

        |0000.0000|000a.aabb|bbbb.cccc|ccdd.dddd| shift right by 11
        |0000.0000|0000.0000|aaaa.bbbb|bbcc.cccc| shift right by 16
        |0000.0000|0000.0000|0000.0aaa|aabb.bbbb| shift right by 21
        |0000.0000|0000.0000|0000.0000|0aaa.aaaa| shift right by 25 */
    {
        // 4 * [25, 25, 25, 25, 25, 25, 25, 25, 0, 0, 0, 0, 21, 21, 16, 11]
        const __m512i shift_right = _mm512_setr_epi64(
            0x1919191919191919,
            0x0b10151500000000,
            0x1919191919191919,
            0x0b10151500000000,
            0x1919191919191919,
            0x0b10151500000000,
            0x1919191919191919,
            0x0b10151500000000
        );

        __m512i shift = _mm512_shuffle_epi8(shift_right, char_type);
        shift = _mm512_and_si512(shift, _mm512_set1_epi32(0xff));
        values = _mm512_srlv_epi32(values, shift);
    }

    /*
        Note about shifts: since the left shift max is 5, and right shift max is 25,
        we may pack them in single lookup: 3 bits for left, and 5 bits for right shift.
        Then we would need only one _mm512_shuffle_epi8(). But still we need
        _mm512_and_si512() to convert the lookup result into 32-bit numbers. It would
        look like:

        __m512i shift = _mm512_shuffle_epi8(shift_left_right, char_type);

        __m512i shift_left = _mm512_and_si512(shift, _mm512_set1_epi32(0x03));
        __m512i shift_right = _mm512_srli_epi32(shift, 3);
        shift_right _mm512_and_si512(shift_right, _mm512_set1_epi32(0x1f));

        values = _mm512_sllv_epi32(values, shift_left);
        values = _mm512_srlv_epi32(values, shift_right);

        We would replace _mm512_shuffle_epi8() with _mm512_srli_epi32().
    */

    return values;
}
