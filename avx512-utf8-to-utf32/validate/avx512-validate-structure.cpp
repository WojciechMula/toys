// included in avx512-validate-utf8.cpp

bool avx512_validate_utf8_structure(__m512i input) {
    /* 1. bitmask for various character byte classes.

        leading: 111010011100011010001
                 abccdddefgggghiijjjjk   a-k -- 11 UTF8- chars characters

        ascii:   110000011000010000001
                 ab     ef    h      k

        2 bytes: 001000000000001000000
                   cc          ii

        3 bytes: 000010000000000000000
                     ddd              

        4 bytes: 000000000100010010000
                          gggg   jjjj
    */
    uint64_t leading;
    uint64_t ascii;
    uint64_t _2bytes;
    uint64_t _3bytes;
    uint64_t _4bytes;

    // we can valide 60 - 4 leading bytes
    constexpr uint64_t mask  = 0x0ffffffffffffffflu;

    {
        const __m512i t0 = _mm512_and_si512(input, v_c0);
        leading = _mm512_cmpneq_epu8_mask(t0, v_80);
    }
    {
        ascii = _mm512_testn_epi8_mask(input, v_80) & mask;
    }
    {
        const __m512i t0 = _mm512_and_si512(input, v_e0);
        _2bytes = _mm512_cmpeq_epi8_mask(t0, v_c0) & mask;
    }
    {
        const __m512i t0 = _mm512_and_si512(input, v_f0);
        _3bytes = _mm512_cmpeq_epi8_mask(t0, v_e0) & mask;
    }
    {
        const __m512i t0 = _mm512_and_si512(input, v_f8);
        _4bytes = _mm512_cmpeq_epi8_mask(t0, v_f0) & mask;
    }

    const uint64_t next1 = leading >> 1;
    const uint64_t next2 = leading >> 2;
    const uint64_t next3 = leading >> 3;
    const uint64_t next4 = leading >> 4;

    /* 1. validate ascii
        ascii =             110000011000010000001
                            ^^^^^^^^^^^^^^^^^    
                            60 consdered bytes
        next1 =             110100111000110100010
        next & ascii =      100000011000010000000
    */ 
    const uint64_t valid_ascii = ascii & next1;


    /* 2. validate 2-byte chars
    
        2-byte   001000000000001000000 
        ~next1   001011000111001011101 -- expect a contination byte
        next2    101001110001101000100 -- and a leading byte
        ------------------------------
        and-all  001000000000001000000
    */
    const uint64_t valid_2bytes = (_2bytes & next2) & ~next1;

    /* 3. validate 3-byte chars

        3-byte   000010000000000000000
        ~next1   001011000111001011100 -- expect a contination byte
        ~next2   010110001110010111000 -- another contination byte
        next3    010011100011010001000 -- and a leading byte
        ------------------------------
        and-all  000010000000000000000

    */
    const uint64_t valid_3bytes = (_3bytes & next3) & ~(next1 | next2);

    /* 4. validate 4-byte chars

        4-byte   000000000100010010000
        ~next1   001011000111001011100 -- expect a contination byte
        ~next2   010110001110010111000 -- another contination
        ~next3   101100011100101110000 -- another contination
        next4    100111000110100010000 -- and a leading byte
        ------------------------------
        and-all  000000000100000010000

    */
    const uint64_t valid_4bytes = (_4bytes & next4) & ~(next1 | next2 | next3);
    return (valid_ascii == ascii)
       and (valid_2bytes == _2bytes)
       and (valid_3bytes == _3bytes)
       and (valid_4bytes == _4bytes);
}


bool avx512_validate_utf8_structure_xor(__m512i input) {
    uint64_t leading;
    uint64_t ascii;
    uint64_t _2bytes;
    uint64_t _3bytes;
    uint64_t _4bytes;

    const uint64_t mask  = 0x0fffffffffffffff;

    {
        const __m512i t0 = _mm512_and_si512(input, v_c0);
        leading = _mm512_cmpneq_epu8_mask(t0, v_80);
    }
    {
        ascii = _mm512_testn_epi8_mask(input, v_80) & mask;
    }
    {
        const __m512i t0 = _mm512_and_si512(input, v_e0);
        _2bytes = _mm512_cmpeq_epi8_mask(t0, v_c0) & mask;
    }
    {
        const __m512i t0 = _mm512_and_si512(input, v_f0);
        _3bytes = _mm512_cmpeq_epi8_mask(t0, v_e0) & mask;
    }
    {
        const __m512i t0 = _mm512_and_si512(input, v_f8);
        _4bytes = _mm512_cmpeq_epi8_mask(t0, v_f0) & mask;
    }

    const uint64_t next1 = leading >> 1;
    const uint64_t next2 = leading >> 2;
    const uint64_t next3 = leading >> 3;
    const uint64_t next4 = leading >> 4;

    const uint64_t valid_ascii = ascii ^ next1;

    const uint64_t valid_2bytes = _2bytes ^ (next2 & ~next1);
    const uint64_t valid_3bytes = _3bytes ^ (next3 & ~next1 & ~next2);
    const uint64_t valid_4bytes = _4bytes ^ (next4 & ~next1 & ~next2 & ~next3);
    
    return (valid_ascii | valid_2bytes | valid_3bytes | valid_4bytes) == 0;
}
