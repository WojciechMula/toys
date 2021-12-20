// included in avx512-validate-utf8.cpp

// Similarly to `avx512_utf8_structure_validate_16_bytes`
// from ../avx512-utf8-validate.cpp we compare up to four
// bits from comparison result. Unlike AVX512F version,
// we're able to perform comparison for 64 possible leading
// bytes, not only 16.
bool avx512vbmi_validate_utf8_structure(__m512i input) {
    // 1. build bitmask
    __mmask64 continuation;
    {
        const __m512i t0 = _mm512_and_si512(input, v_c0);
        continuation = _mm512_cmpeq_epi8_mask(t0, v_80);
    }
    
    // 2. Populate the mask in register
    const __m512i v_continuation = _mm512_set1_epi64(continuation);

    // 3. Shift 4-bit sub-bitmasks to separate bytes
    /** pshufb
        shuffle_shifts = list(range(1, 64+1))
        
        # 8-byte lane #0: 1..8
        # 8-byte lane #1: 9..16
        # ...
        # 8-byte lane #7: 48..64
    */
    const __m512i shuffle_shifts = _mm512_setr_epi64(
        0x0807060504030201,
        0x100f0e0d0c0b0a09,
        0x1817161514131211,
        0x201f1e1d1c1b1a19,
        0x2827262524232221,
        0x302f2e2d2c2b2a29,
        0x3837363534333231,
        0x403f3e3d3c3b3a39
    );

    const __m512i shuffled = _mm512_multishift_epi64_epi8(shuffle_shifts, v_continuation);

    // 4. Match the k continuation bytes followed by leading byte
    /** pshufb
        
        continuation    = 0
        ascii           = 0b0001    # leading + 0 * continuation + leading byte
        _2_bytes        = 0b0011    # leading + 1 * continuation + leading byte
        _3_bytes        = 0b0111    # leading + 2 * continuation + leading byte
        _4_bytes        = 0b1111    # leading + 3 * continuation + leading byte

        mask_lookup = 4 * [
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
        ]
    */
    const __m512i mask_lookup = _mm512_setr_epi64(
        0x0101010101010101,
        0x0f07030300000000,
        0x0101010101010101,
        0x0f07030300000000,
        0x0101010101010101,
        0x0f07030300000000,
        0x0101010101010101,
        0x0f07030300000000
    );

    __m512i mask;
    {
        const __m512i t0 = _mm512_srli_epi32(input, 4);
        const __m512i t1 = _mm512_and_si512(t0, v_0f);
        mask = _mm512_shuffle_epi8(mask_lookup, t1);
    }

    __m512i expected;
    {
        const __m512i t0 = _mm512_srli_epi32(mask, 1);
        expected = _mm512_and_si512(t0, v_0f);
    }

    const __m512i t0 = _mm512_and_si512(shuffled, mask);
    const __mmask64 matched = _mm512_cmpeq_epi8_mask(t0, expected);

    // we can validate 60 - 4 leading bytes
    constexpr uint64_t input_mask = 0x0ffffffffffffffflu;

    const uint64_t valid = (~continuation) & input_mask;
    return (matched & valid) == valid;
}
