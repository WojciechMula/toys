// included in avx512-validate-utf8.cpp

/*
AVX512VBMI validation of leading byte and subsequent continuation byte

The main ingridient is instruction VPERMB that does a 6-bit lookup in an AVX512 register.
Note that that VPERM ignores two highest bits, so no masking is needed as in VPSHUFB case.

Let's rewrite the UTF-8 validity rules with respect of 6 lower words of the leading
byte and the following continuation byte. Please refer to `avx512-validate-leading-bytes.cpp`
for more details.

1. ASCII and continuation bytes are handled separetly

Notation for 2-, 3-, 4-byte chars:

    11_xx_xxxx 10_yy_yyyy
    ^^ ^^^^^^^ ^^ ^^^^^^^
    |  |       |  |
    |  |       |  +- 6-bit 'y' subword (continuation byte)
    |  |       |
    +----------+--- fixed
       |
       + 6-bit 'x' subword (leading byte)

2. 2-byte characters

    11_00_0000 10_yy_yyyy   -> y - none
    11_00_0001 10_yy_yyyy   -> y - none
    11_00_0010 10_yy_yyyy   -> y - any
    ...
    11_01_1111 10_yy_yyyy   -> y - any

3. 3-byte characters

    11_10_0000 10_yy_yyyy   -> y in range 0b10_0000 .. 0b11_1111
    11_10_0001 10_yy_yyyy   -> y - any
    11_10_0010 10_yy_yyyy   -> y - any
    11_10_0011 10_yy_yyyy   -> y - any
    11_10_0100 10_yy_yyyy   -> y - any
    11_10_0101 10_yy_yyyy   -> y - any
    11_10_0110 10_yy_yyyy   -> y - any
    11_10_0111 10_yy_yyyy   -> y - any
    11_10_1000 10_yy_yyyy   -> y - any
    11_10_1001 10_yy_yyyy   -> y - any
    11_10_1010 10_yy_yyyy   -> y - any
    11_10_1011 10_yy_yyyy   -> y - any
    11_10_1100 10_yy_yyyy   -> y - any
    11_10_1101 10_yy_yyyy   -> y in range 0b00_0000 .. 0b01_1111
    11_10_1110 10_yy_yyyy   -> y - any
    11_10_1111 10_yy_yyyy   -> y - any

4. 4-byte characters

    11_11_0000 10_yy_yyyy   -> y in range 0b01_1111 .. 0b11_1111
    11_11_0001 10_yy_yyyy   -> any
    11_11_0010 10_yy_yyyy   -> any
    11_11_0011 10_yy_yyyy   -> any
    11_11_0100 10_yy_yyyy   -> y in range 0b00_0000 .. 0b00_1111
    11_11_0101 10_yy_yyyy   -> none
    11_11_0110 10_yy_yyyy   -> none
    11_11_0111 10_yy_yyyy   -> none
    11_11_1000 10_yy_yyyy   -> none
    11_11_1001 10_yy_yyyy   -> none
    11_11_1010 10_yy_yyyy   -> none
    11_11_1011 10_yy_yyyy   -> none
    11_11_1100 10_yy_yyyy   -> none
    11_11_1101 10_yy_yyyy   -> none
    11_11_1110 10_yy_yyyy   -> none
    11_11_1111 10_yy_yyyy   -> none

Idea is to encode y values in 4 ranges: [0b00_0000 .. 0b01_1111],
[range 0b10_0000 .. 0b11_1111], , [0b01_1111 .. 0b11_1111] and
[0b00_0000 .. 0b00_1111] as 4-bit bitmask.

Then, the value of x word (6 lowest bits of leading byte) would be
encoded as:

- any       = 0b1111
- none      = 0b0000
- 3_byte_0  = 0b0001
- 3_byte_d  = 0b0010
- 4_byte_0  = 0b0100
- 4_byte_4  = 0b1000
*/
namespace {
    /** pshufb

        range0 = (0b10_0000, 0b11_1111) # 3-byte x = 0x0
        range1 = (0b00_0000, 0b01_1111) # 3-byte x = 0xe
        range2 = (0b01_0000, 0b11_1111) # 4-byte x = 0x0
        range3 = (0b00_0000, 0b00_1111) # 4-byte x = 0x4

        y_lookup = []
        for y in range(0, 64):
            value = 0
            for bit, (lo, hi) in enumerate((range0, range1, range2, range3)):
                mask = 1 << bit
                if lo <= y <= hi:
                    value |= mask

            y_lookup.append(value)
    */
    const __m512i y_lookup = _mm512_setr_epi64(
        0x0a0a0a0a0a0a0a0a,
        0x0a0a0a0a0a0a0a0a,
        0x0606060606060606,
        0x0606060606060606,
        0x0505050505050505,
        0x0505050505050505,
        0x0505050505050505,
        0x0505050505050505
    );

    /** pshufb

        # consts
        any         = 0b1111
        none        = 0b0000
        _3byte_0    = 0b0001
        _3byte_d    = 0b0010
        _4byte_0    = 0b0100
        _4byte_4    = 0b1000

        x_lookup = [none] * 64

        # 2-byte chars
        for x in range(0b00_0000, 0b01_1111 + 1):
            if x >= 2:
                x_lookup[x] = any

        # 3-byte chars
        for x in range(0b10_0000, 0b10_1111 + 1):
            if x == 0b10_0000:
                x_lookup[x] = _3byte_0
            elif x == 0b10_1101:
                x_lookup[x] = _3byte_d
            else:
                x_lookup[x] = any

        # 4-byte chars
        for x in range(0b11_0000, 0b11_1111 + 1):
            if x == 0b11_0000:
                x_lookup[x] = _4byte_0
            elif x == 0b11_0100:
                x_lookup[x] = _4byte_4
            elif x in (0b11_0001, 0b11_0010, 0b11_0011):
                x_lookup[x] = any
            else:
                x_lookup[x] = none
    */
    const __m512i x_lookup = _mm512_setr_epi64(
        0x0f0f0f0f0f0f0000,
        0x0f0f0f0f0f0f0f0f,
        0x0f0f0f0f0f0f0f0f,
        0x0f0f0f0f0f0f0f0f,
        0x0f0f0f0f0f0f0f01,
        0x0f0f020f0f0f0f0f,
        0x000000080f0f0f04,
        0x0000000000000000
    );
}

bool avx512vbmi_validate_leading_bytes(__m512i leading_bytes, __m512i continuation1, __mmask64 tested_chars) {
    // 1. consider only leading bytes (0b11_xx_xxxx)
    __mmask64 valid_leading;
    {
        const __m512i t0 = _mm512_and_si512(leading_bytes, v_c0);
        valid_leading = _mm512_mask_cmpeq_epi8_mask(tested_chars, t0, v_c0);
    }

    // 2. get mask for leading byte (x-bits)
    const __m512i x = _mm512_permutexvar_epi8(leading_bytes, x_lookup);

    // 3. get value ranges bitmask for continuation bytes (y-bits)
    const __m512i y = _mm512_permutexvar_epi8(continuation1, y_lookup);

    const __mmask64 match = _mm512_mask_test_epi8_mask(tested_chars, x, y);

    // 4. check validity
#if 1
    {
        const __mmask64 m0 = _kand_mask64(match, valid_leading);
        const __mmask64 m1 = _kxor_mask64(m0, valid_leading);

        return m1 == 0;
    }
#else
    return (valid_leading & match) == valid_leading;
#endif
}
