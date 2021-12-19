// included in avx512-validate-utf8.cpp

/*
This is a direct translation of branchy algorithm from
"Validating UTF-8 In Less Than One Instruction Per Byte".

See the implementation in reference.cpp.

There are following observations:

1. ASCII bytes do not need handling
2. Continuation bytes are rejected instantly
3. For 2-/3-/4-byte chars it's sufficient to check the values
   of leading byte and the first continuation byte. The
   subsequent continuation bytes may have any values

a) For 2-byte chars we have one rule:

- The leading byte must not be 0xc0 nor 0xc1.

b) For 3-byte chars we decide based on the lower nibble of the leading byte:

- 0: valid if (continuation1 & 0x3f) > 0x1f
- 14: valid if (continuation1 & 0x3f) <= 0x1f [negation of the above case]
- 0..13, 14, 15: always valid

We calculate the following expression:

    c = (continuation1 & 0x3f)
    x = (c ^ fixup) > 0x1f

    where `fixup` is a function of nibble value:

        fixup[nibble] = 0  => 0x00
                        14 => 0x40
                        _  => 0xc0

    case 1 fixup = 0x00:
                                                          c ^ fixup > 0x1f
    c <= 0x1f: 0b000x_xxxx ^ 0xb0000_0000 = 0xb000x_xxxx  false
    c >  0x1f: 0b001x_xxxx ^ 0xb0000_0000 = 0xb001x_xxxx  true

    case 2 fixup = 0x40:
                                                          c ^ fixup > 0x1f
    c <= 0x1f: 0b000x_xxxx ^ 0xb0010_0000 = 0xb001x_xxxx  true
    c >  0x1f: 0b001x_xxxx ^ 0xb0010_0000 = 0xb000x_xxxx  false

    case 3 fixup = 0x40:
                                                          c ^ fixup > 0x1f
    c <= 0x1f: 0b000x_xxxx ^ 0xb1100_0000 = 0xb110x_xxxx  true
    c >  0x1f: 0b001x_xxxx ^ 0xb1100_0000 = 0xb111x_xxxx  true


c) For 4-byte chars we decide based on the lower nibble of the leading byte:

- 0: valid if (continuation1 & 0x3f) > 0x0f
- 1, 2, 3: always valid
- 4: valid if (continuation1 & 0x3f) <= 0x0f [negation of case #0]
- 5, 15: always invalid

In this case we build a 2-bit values where one bit stores result of
(continuation1 & 0x3f) > 0x0f and another is negation of that bit.  Then case
#0 is encoded as mask 0b01, case #4 is encoded as 0b10, cases #{1,2,3} as 0b11
and the remaining cases as 0b00. The validity of chars is checked with the
following expression:

    value & mask != 0

To create a 2-bit value we subtract from c = (continuation1 & 0x3f) the number
0x10. If c = 0b0000_xxxx (<= 0x0f) then the result of the subtraction is always
in form 0b1111_xxxx. The two most significant bits encodes condition (c <= 0x0f).
Now we negate 6th bit, and then the these two most significant bits represents
the required combination which is later tested.
*/
__mmask64 avx512_validate_leading_bytes(__m512i leading_bytes, __m512i continuation1, __mmask64 tested_chars) {

    const __m512i nibble0 = _mm512_and_si512(leading_bytes, v_0f);

    // 1. Assume all non-continuation bytes are valid leading bytes
    //    We unset all continuation bytes (0b10xx_xxxx) and ASCII chars
    //    (0b0xxx_xxxx) --- so we looking for 0b11xx_xxxx chars.
    //
    //    (We may mask-out some leading bytes via `tested_chars`).
    __mmask64 valid;
    {
        const __m512i t0 = _mm512_and_si512(leading_bytes, v_c0);
        valid = _mm512_cmpeq_epi8_mask(t0, v_c0);
    }

    __mmask64 _2bytes;
    {
        const __m512i t0 = _mm512_and_si512(leading_bytes, v_e0);
        _2bytes = _mm512_cmpeq_epi8_mask(t0, v_c0);
    }

    __mmask64 _3bytes;
    {
        const __m512i t0 = _mm512_and_si512(leading_bytes, v_f0);
        _3bytes = _mm512_cmpeq_epi8_mask(t0, v_e0);
    }

    __mmask64 _4bytes;
    {
        const __m512i t0 = _mm512_and_si512(leading_bytes, v_f8);
        _4bytes = _mm512_cmpeq_epi8_mask(t0, v_f0);
    }

    // 1. Handle 2-byte chars
    //    Valid if leading byte is greater than 0xc2
    __mmask64 valid_2bytes = _mm512_mask_cmpge_epu8_mask(_2bytes, leading_bytes, v_c2);

    // 4. Handle 3-byte chars
    //    let M = (continuation1 & 03f) > 0x1f
    continuation1 = _mm512_and_si512(continuation1, v_3f);
    __mmask64 valid_3bytes;
    {
        /** pshufb 
            M     = 0b0000_0000 # we test 5th bit
            notM  = 0b0010_0000
            true  = 0b1100_0000

            fixup_lookup = 4 * [
                M,      # 0b0000
                true,   # 0b0001
                true,   # 0b0010
                true,   # 0b0011
                true,   # 0b0100
                true,   # 0b0101
                true,   # 0b0110
                true,   # 0b0111
                true,   # 0b1000
                true,   # 0b1001
                true,   # 0b1010
                true,   # 0b1011
                true,   # 0b1100
                notM,   # 0b1101
                true,   # 0b1110
                true,   # 0b1111
        ] */
        const __m512i fixup_lookup = _mm512_setr_epi64(
            0xc0c0c0c0c0c0c000,
            0xc0c020c0c0c0c0c0,
            0xc0c0c0c0c0c0c000,
            0xc0c020c0c0c0c0c0,
            0xc0c0c0c0c0c0c000,
            0xc0c020c0c0c0c0c0,
            0xc0c0c0c0c0c0c000,
            0xc0c020c0c0c0c0c0
        );

        const __m512i fixup = _mm512_shuffle_epi8(fixup_lookup, nibble0);
        const __m512i t0 = _mm512_xor_si512(fixup, continuation1);
        valid_3bytes = _mm512_mask_cmpgt_epu8_mask(_3bytes, t0, v_1f);
    }

    // 5. Handle 4-byte chars
    __mmask64 valid_4bytes;
    {
        // continuation1 in range [0..63] (0b0000_0000 .. 0b0011_1111)
        //
        // case 1: c1 <= 0xf:  0b0000_xxxx - 0x10 = 0b1111_yyyy
        // case 2: c1  > 0xf:  0b00xx_xxxx - 0x10 = 0b00yy_yyyy
        __m512i t0;
        t0 = _mm512_sub_epi8(continuation1, v_10);
        t0 = _mm512_xor_si512(t0, v_40);
        // bit 7th of c: continuation1 <= 0x0f
        // bit 6th of c: continuation1 >  0x0f

        /** pshufb 
            le_0f   = 0x80  # c1[7] = continuation1 <= 0xf0
            gt_0f   = 0x40  # c1[6] = not c1[7]
            true    = gt_0f | le_0f
            false   = 0x00

            mask_lookup = 4 * [
                gt_0f,  # 0b0000
                true,   # 0b0001
                true,   # 0b0010
                true,   # 0b0011
                le_0f,  # 0b0100
                false,  # 0b0101
                false,  # 0b0110
                false,  # 0b0111
                false,  # 0b1000
                false,  # 0b1001
                false,  # 0b1010
                false,  # 0b1011
                false,  # 0b1100
                false,  # 0b1101
                false,  # 0b1110
                false,  # 0b1111
        ] */
        const __m512i mask_lookup = _mm512_setr_epi64(
            0x00000080c0c0c040,
            0x0000000000000000,
            0x00000080c0c0c040,
            0x0000000000000000,
            0x00000080c0c0c040,
            0x0000000000000000,
            0x00000080c0c0c040,
            0x0000000000000000
        );
        const __m512i mask = _mm512_shuffle_epi8(mask_lookup, nibble0);

        valid_4bytes = _mm512_mask_test_epi8_mask(_4bytes, mask, t0);
    }

    {
        // all: marks all valid leading bytes
        __mmask64 all = _kor_mask64(valid_2bytes, _kor_mask64(valid_3bytes, valid_4bytes));

        // reset leading byte marks from input
        valid = _kxor_mask64(valid, all);
        valid = _kand_mask64(valid, tested_chars);
    }

    return valid == 0;
}
