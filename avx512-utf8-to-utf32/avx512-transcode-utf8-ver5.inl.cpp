// included directly

// This is slightly modified verison3.

#include "dump.h"

/*
    32-bit lanes in `char_class` have form 0x8080800N, where N is 4 higest
    bits from the leading byte; 0x80 resets corresponding bytes during pshufb.
*/
__m512i avx512_utf8_to_utf32__aux__version5(__m512i char_class, __m512i utf8) {
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

    /* 1. Reset higher bits in the leading bytes and two MSB in
          continuation bytes

        |00dd.dddd|00cc.cccc|00bb.bbbb|0000.0aaa| 4-byte char
         ^^        ^^        ^^        ^^^^
        |00??.????|00cc.cccc|00bb.bbbb|0000.aaaa| 3-byte char
         ^^        ^^        ^^        ^^^^
        |00??.????|00??.????|00bb.bbbb|000a.aaaa| 2-byte char
         ^^        ^^        ^^        ^^^
        |00??.????|00??.????|00??.????|0aaa.aaaa| ASCII char
         ^^        ^^        ^^        ^
    */
    /** pshufb

        continuation = 0
        ascii    = 0x7f
        _2_bytes = 0x1f
        _3_bytes = 0x0f
        _4_bytes = 0x0f # keep 4th byte (it's 0 for valid UTF-8,
                        # if 1 then we detect invalid values)

        mask_leading_bytes = 4 * [ # mask for byte 0
            ascii, # 0000
            ascii, # 0001
            ascii, # 0010
            ascii, # 0011
            ascii, # 0100
            ascii, # 0101
            ascii, # 0110
            ascii, # 0111
            continuation, # 1000
            continuation, # 1001
            continuation, # 1010
            continuation, # 1011
            _2_bytes, # 1100
            _2_bytes, # 1101
            _3_bytes, # 1110
            _4_bytes, # 1111
        ] */
    __m512i values;

    const __m512i mask_leading_bytes = _mm512_setr_epi64(
        0x7f7f7f7f7f7f7f7f,
        0x0f0f1f1f00000000,
        0x7f7f7f7f7f7f7f7f,
        0x0f0f1f1f00000000,
        0x7f7f7f7f7f7f7f7f,
        0x0f0f1f1f00000000,
        0x7f7f7f7f7f7f7f7f,
        0x0f0f1f1f00000000
    );

    {
        __m512i mask;
        mask = _mm512_shuffle_epi8(mask_leading_bytes, char_class);

        // values = utf8 & (mask | v_3f3f_3f00)
        values = _mm512_ternarylogic_epi32(utf8, mask, v_3f3f_3f00, 0xe0);
    }

    /* 2. Swap and join fields A-B and C-D

        |0000.cccc|ccdd.dddd|0000.000a|aabb.bbbb| 4-byte char
        |0000.cccc|cc??.????|0000.00aa|aabb.bbbb| 3-byte char
        |0000.????|????.????|0000.0aaa|aabb.bbbb| 2-byte char
        |0000.????|????.????|000a.aaaa|aa??.????| ASCII char */
    values = _mm512_maddubs_epi16(values, v_0140_0140);

    /* 3. Swap and join field AB & CD

        |0000.0000|000a.aabb|bbbb.cccc|ccdd.dddd| 4-byte char
        |0000.0000|00aa.aabb|bbbb.cccc|cc??.????| 3-byte char
        |0000.0000|0aaa.aabb|bbbb.????|????.????| 2-byte char
        |0000.000a|aaaa.aa??|????.????|????.????| ASCII char */
    values = _mm512_madd_epi16(values, v_0001_1000);

    /* 4. Shift right the values by variable amounts to reset lowest bits

        |0000.0000|000a.aabb|bbbb.cccc|ccdd.dddd| 4-byte char -- no change
        |0000.0000|0000.0000|aaaa.bbbb|bbcc.cccc| 3-byte char -- shift by 6
        |0000.0000|0000.0000|0000.0aaa|aabb.bbbb| 2-byte char -- shift by 12
        |0000.0000|0000.0000|0000.0000|0aaa.aaaa| ASCII char  -- shift by 18
    */
    {
    /** pshufb

        continuation = 0
        ascii    = 18
        _2_bytes = 12
        _3_bytes = 6
        _4_bytes = 0

        shift_right = 4 * [
            ascii, # 0000
            ascii, # 0001
            ascii, # 0010
            ascii, # 0011
            ascii, # 0100
            ascii, # 0101
            ascii, # 0110
            ascii, # 0111
            continuation, # 1000
            continuation, # 1001
            continuation, # 1010
            continuation, # 1011
            _2_bytes, # 1100
            _2_bytes, # 1101
            _3_bytes, # 1110
            _4_bytes, # 1111
        ] */
        const __m512i shift_right = _mm512_setr_epi64(
            0x1212121212121212,
            0x00060c0c00000000,
            0x1212121212121212,
            0x00060c0c00000000,
            0x1212121212121212,
            0x00060c0c00000000,
            0x1212121212121212,
            0x00060c0c00000000
        );

        const __m512i shift = _mm512_shuffle_epi8(shift_right, char_class);
        values = _mm512_srlv_epi32(values, shift);
    }

    return values;
}

__m512i avx512_utf8_to_utf32__aux__version5(__m512i utf8) {
    /* 1. Classify leading bytes */
    __m512i char_class;
    char_class = _mm512_srli_epi32(utf8, 4);
    char_class = _mm512_and_si512(char_class, v_0000_000f);
    char_class = _mm512_or_si512(char_class, v_8080_8000);

    return avx512_utf8_to_utf32__aux__version5(char_class, utf8);
}
