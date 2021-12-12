// included directly

__m512i avx512_utf8_to_utf32__aux__version2(__m512i utf8) {
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
    /** pshufb

        bswap_lookup = 4 * [3, 2, 1, 0,
                            7, 6, 5, 4,
                            11, 10, 9, 8,
                            15, 14, 13, 12] */
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
    /* 2. Shift continuation byte B (byte #2) left by 2 and isolate the field

        |0000.0000|bbbb.bb00|0000.0000|0000.0000|
        |0000.0000|bbbb.bb00|0000.0000|0000.0000|
        |0000.0000|bbbb.bb00|0000.0000|0000.0000|
        |0000.0000|????.??00|0000.0000|0000.0000| */

    __m512i B;
    B = _mm512_slli_epi32(values, 2);
    B = _mm512_and_si512(B, _mm512_set1_epi32(0x00fc0000));

    /* 3. Shift continuation byte C (byte #1) left by 4 and isolate the field

        |0000.0000|0000.00cc|cccc.0000|0000.0000|
        |0000.0000|0000.00cc|cccc.0000|0000.0000|
        |0000.0000|0000.00??|????.0000|0000.0000|
        |0000.0000|0000.00??|????.0000|0000.0000| */
    __m512i C;
    C = _mm512_slli_epi32(values, 4);
    C = _mm512_and_si512(C, _mm512_set1_epi32(0x0003f000));

    /* 4. Shift continuation byte D (byte #0) left by 6 and isolate the field

        |0000.0000|0000.0000|0000.dddd|dd00.0000|
        |0000.0000|0000.0000|0000.????|??00.0000|
        |0000.0000|0000.0000|0000.????|??00.0000|
        |0000.0000|0000.0000|0000.????|??00.0000| */
    __m512i D;
    D = _mm512_slli_epi32(values, 6);
    D = _mm512_and_si512(D, _mm512_set1_epi32(0x00000fc0));

    // 5. Merge fields B, C and D
    const uint8_t or_all = 0xfe; // B | C | D
    __m512i BCD;
    BCD = _mm512_ternarylogic_epi32(B, C, D, or_all);

    // 6. Put merged field into values
    {
        const __m512i mask = _mm512_set1_epi32(0x00ffffc0);
        const uint8_t merge_function = 0xca; // ((mask and value) or (not mask and field))
        values = _mm512_ternarylogic_epi32(mask, BCD, values, merge_function);
    }

    /* 7. Get the 4 most significant bits from byte #0 -- these values
          will be used by to distinguish character classes

        |0000.0000|0000.0000|0000.0000|0000.1111|
        |0000.0000|0000.0000|0000.0000|0000.1110|
        |0000.0000|0000.0000|0000.0000|0000.110a|
        |0000.0000|0000.0000|0000.0000|0000.0aaa| */
    const __m512i char_class = _mm512_and_si512(_mm512_srli_epi32(utf8, 4),
                                               _mm512_set1_epi32(0x0000000f));

    /* 8. Shift left the values by variable amounts to reset highest UTF-8 bits

        |aaab.bbbb|bccc.cccd|dddd.d???|???0.0000| shift left by 5
        |aaaa.bbbb|bbcc.cccc|????.????|????.0000| shift left by 4
        |aaaa.abbb|bbb?.????|????.????|????.?000| shift left by 3
        |aaaa.aaa?|????.????|????.????|????.???0| shift left by 1 */
    {
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

        __m512i shift = _mm512_shuffle_epi8(shift_left, char_class);
        shift = _mm512_and_si512(shift, _mm512_set1_epi32(0xff));
        values = _mm512_sllv_epi32(values, shift);
    }

    /* 9. Shift right the values by variable amounts to reset lowest bits

        |0000.0000|000a.aabb|bbbb.cccc|ccdd.dddd| shift right by 11
        |0000.0000|0000.0000|aaaa.bbbb|bbcc.cccc| shift right by 16
        |0000.0000|0000.0000|0000.0aaa|aabb.bbbb| shift right by 21
        |0000.0000|0000.0000|0000.0000|0aaa.aaaa| shift right by 25 */
    {
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

        __m512i shift = _mm512_shuffle_epi8(shift_right, char_class);
        shift = _mm512_and_si512(shift, _mm512_set1_epi32(0xff));
        values = _mm512_srlv_epi32(values, shift);
    }

    return values;
}

