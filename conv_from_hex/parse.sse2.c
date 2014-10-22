uint8_t first_letter[16] SIMD_ALIGN  = packed_byte('a' - 1);
uint8_t correction_09[16] SIMD_ALIGN = packed_byte('0');
uint8_t correction_af[16] SIMD_ALIGN = packed_byte('a' - 10 - '0');
uint16_t mask[8] SIMD_ALIGN          = packed_word(0x00ff);


uint64_t parse_sse_16chars(char* s) {

    uint64_t result;
    uint32_t reversed[4];

    // 0 swap the byte order
    {
        uint32_t* buf = reinterpret_cast<uint32_t*>(s);
        for (int i=0; i < 4; i++) {
            reversed[3 - i] = bswap(buf[i]);
        }
    }

    __asm__ __volatile__(
        "movdqu   (%1),   %%xmm0  \n"
        "movdqa   %%xmm0, %%xmm1  \n"

        // 1. convert from ASCII to nibbles
        "pcmpgtb  %2,     %%xmm1  \n"
        "pand     %4,     %%xmm1  \n"

        "psubb    %3,     %%xmm0  \n"
        "psubb    %%xmm1, %%xmm0  \n"

        // 2. merge nibbles
        "movdqa   %%xmm0, %%xmm1  \n"
        "psrlw    $4,     %%xmm1  \n"

        "por      %%xmm1, %%xmm0  \n"
        "pand     %5,     %%xmm0  \n"
        "packuswb %%xmm0, %%xmm0  \n"

        // 3. store result
        "movq     %%xmm0, %0      \n"
        : "=m" (result)
        : "r" (reversed)
        , "m" (first_letter)  // %2
        , "m" (correction_09) // %3
        , "m" (correction_af) // %4
        , "m" (mask)          // %5

    );
    
    return result;
}


uint64_t parse_sse_16chars_reverse_result(char* s) {

    union {
        uint64_t qword;
        uint32_t dword[2];
    } result;

    __asm__ __volatile__(
        "movdqu   (%1),   %%xmm0  \n"
        "movdqa   %%xmm0, %%xmm1  \n"

        // 1. convert from ASCII to nibbles
        "pcmpgtb  %2,     %%xmm1  \n"
        "pand     %4,     %%xmm1  \n"

        "psubb    %3,     %%xmm0  \n"
        "psubb    %%xmm1, %%xmm0  \n"

        // 2. merge nibbles
        "movdqa   %%xmm0, %%xmm1  \n"
        "psllw    $12,     %%xmm1  \n"

        "por      %%xmm1, %%xmm0  \n"
        "psrlw    $8,     %%xmm0  \n"
        "packuswb %%xmm0, %%xmm0  \n"

        // 3. store result
        "movq     %%xmm0, %0      \n"
        : "=m" (result.qword)
        : "r" (s)
        , "m" (first_letter)  // %2
        , "m" (correction_09) // %3
        , "m" (correction_af) // %4

    );

    result.dword[0] = bswap(result.dword[0]);
    result.dword[1] = bswap(result.dword[1]);

    uint32_t tmp = result.dword[0];
    result.dword[0] = result.dword[1];
    result.dword[1] = tmp;
    
    return result.qword;
}


struct uint128_t {
    uint64_t qword[2];
};


uint128_t parse_sse_32chars(char* s) {

    uint128_t result;
    uint32_t reversed[8];

    // 0 swap the byte order
    {
        uint32_t* buf = reinterpret_cast<uint32_t*>(s);
        for (int i=0; i < 8; i++) {
            reversed[7 - i] = bswap(buf[i]);
        }
    }

    __asm__ __volatile__(
        "movdqu   (%1),   %%xmm0  \n"
        "movdqa   %%xmm0, %%xmm1  \n"

        "movdqu   16(%1), %%xmm2  \n"
        "movdqa   %%xmm2, %%xmm3  \n"

        // 1. convert from ASCII to nibbles
        "pcmpgtb  %2,     %%xmm1  \n"
        "pcmpgtb  %2,     %%xmm3  \n"
        "pand     %4,     %%xmm1  \n"
        "pand     %4,     %%xmm3  \n"

        "psubb    %3,     %%xmm0  \n"
        "psubb    %3,     %%xmm2  \n"
        "psubb    %%xmm1, %%xmm0  \n"
        "psubb    %%xmm3, %%xmm2  \n"

        // 2. merge nibbles
        "movdqa   %%xmm0, %%xmm1  \n"
        "movdqa   %%xmm2, %%xmm3  \n"
        "psrlw    $4,     %%xmm1  \n"
        "psrlw    $4,     %%xmm3  \n"

        "por      %%xmm1, %%xmm0  \n"
        "por      %%xmm3, %%xmm2  \n"
        "pand     %5,     %%xmm0  \n"
        "pand     %5,     %%xmm2  \n"
        "packuswb %%xmm2, %%xmm0  \n"

        // 3. store result
        "movdqu   %%xmm0, %0      \n"
        : "=m" (result)
        : "r" (reversed)
        , "m" (first_letter)  // %2
        , "m" (correction_09) // %3
        , "m" (correction_af) // %4
        , "m" (mask)          // %5

    );
    
    return result;
}
