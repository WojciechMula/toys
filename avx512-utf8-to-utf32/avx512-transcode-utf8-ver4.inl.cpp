// included directly

__m512i avx512_utf8_to_utf32__aux__version4(__m512i utf8) {
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

    /* 1. Reset control bits of continuation bytes and the MSB
          of the leading byte; this makes all bytes unsigned (and
          does not alter ASCII char).

        |00dd.dddd|00cc.cccc|00bb.bbbb|0111.0aaa| 4-byte char
        |00??.????|00cc.cccc|00bb.bbbb|0110.aaaa| 3-byte char
        |00??.????|00??.????|00bb.bbbb|010a.aaaa| 2-byte char
        |00??.????|00??.????|00??.????|0aaa.aaaa| ASCII char
         ^^        ^^        ^^        ^
    */
    __m512i values;
    values = _mm512_and_si512(utf8, _mm512_set1_epi32(0x3f3f3f7f));

    /* 2. Swap and join fields A-B and C-D

        |0000.cccc|ccdd.dddd|0001.110a|aabb.bbbb| 4-byte char
        |0000.cccc|cc??.????|0001.10aa|aabb.bbbb| 3-byte char
        |0000.????|????.????|0001.0aaa|aabb.bbbb| 2-byte char
        |0000.????|????.????|000a.aaaa|aa??.????| ASCII char */
    values = _mm512_maddubs_epi16(values, _mm512_set1_epi32(0x01400140));

    /* 3. Swap and join field AB & CD

        |0000.0001|110a.aabb|bbbb.cccc|ccdd.dddd| 4-byte char
        |0000.0001|10aa.aabb|bbbb.cccc|cc??.????| 3-byte char
        |0000.0001|0aaa.aabb|bbbb.????|????.????| 2-byte char
        |0000.000a|aaaa.aa??|????.????|????.????| ASCII char */
    values = _mm512_madd_epi16(values, _mm512_set1_epi32(0x00011000));

    /* 4. Get the 4 most significant bits from byte #0 -- these values
          will be used by to distinguish character classes

        |0000.0000|0000.0000|0000.0000|0000.1111|
        |0000.0000|0000.0000|0000.0000|0000.1110|
        |0000.0000|0000.0000|0000.0000|0000.110a|
        |0000.0000|0000.0000|0000.0000|0000.0aaa| */
    const __m512i char_class = _mm512_and_si512(_mm512_srli_epi32(utf8, 4),
                                               _mm512_set1_epi32(0x0000000f));

    /* 5. Get packed shift amounts to use in the following steps */
    /** pshufb

    ascii_left_v3    = 7
    _2_bytes_left_v3 = 9
    _3_bytes_left_v3 = 10
    _4_bytes_left_v3 = 11

    ascii_right      = 25
    _2_bytes_right   = 21
    _3_bytes_right   = 16
    _4_bytes_right   = 11

    def build(left, right):
        return (right << 3) | (max(left - 7, 0))

    continuation = 0
    ascii    = build(ascii_left_v3, ascii_right)
    _2_bytes = build(_2_bytes_left_v3, _2_bytes_right)
    _3_bytes = build(_3_bytes_left_v3, _3_bytes_right)
    _4_bytes = build(_4_bytes_left_v3, _4_bytes_right)

    shift_left_right_v4 = 4 * [
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
    const __m512i shift_left_right_v4 = _mm512_setr_epi64(
        0xc8c8c8c8c8c8c8c8,
        0x5c83aaaa00000000,
        0xc8c8c8c8c8c8c8c8,
        0x5c83aaaa00000000,
        0xc8c8c8c8c8c8c8c8,
        0x5c83aaaa00000000,
        0xc8c8c8c8c8c8c8c8,
        0x5c83aaaa00000000
    );
    const __m512i shifts = _mm512_shuffle_epi8(shift_left_right_v4, char_class);

    /* 5. Shift left the values by variable amounts to reset highest UTF-8 bits
        |aaab.bbbb|bccc.cccd|dddd.d000|0000.0000| 4-byte char -- by 11
        |aaaa.bbbb|bbcc.cccc|????.??00|0000.0000| 3-byte char -- by 10
        |aaaa.abbb|bbb?.????|????.???0|0000.0000| 2-byte char -- by 9
        |aaaa.aaa?|????.????|????.????|?000.0000| ASCII char -- by 7 */
    {
        const __m512i c7 = _mm512_set1_epi32(7);
        __m512i shift = _mm512_and_si512(shifts, c7);
        shift = _mm512_add_epi32(shift, c7);
        values = _mm512_sllv_epi32(values, shift);
    }

    /* 5. Shift right the values by variable amounts to reset lowest bits
        |aaab.bbbb|bccc.cccd|dddd.d000|0000.0000| 4-byte char -- by 11
        |aaaa.bbbb|bbcc.cccc|????.??00|0000.0000| 3-byte char -- by 16
        |aaaa.abbb|bbb?.????|????.???0|0000.0000| 2-byte char -- by 21
        |aaaa.aaa?|????.????|????.????|?000.0000| ASCII char -- by 25 */
    {
        __m512i shift = _mm512_srli_epi32(shifts, 3);
        shift = _mm512_and_si512(shift, _mm512_set1_epi32(0x1f));
        values = _mm512_srlv_epi32(values, shift);
    }

    return values;
}
