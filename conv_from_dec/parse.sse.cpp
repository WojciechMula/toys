#include <cstdint>

#define SIMD_ALIGN __attribute__((aligned(16)))

#define packed_byte(b) {uint8_t(b), uint8_t(b), uint8_t(b), uint8_t(b), \
                        uint8_t(b), uint8_t(b), uint8_t(b), uint8_t(b), \
                        uint8_t(b), uint8_t(b), uint8_t(b), uint8_t(b), \
                        uint8_t(b), uint8_t(b), uint8_t(b), uint8_t(b)}

#define packed_word(w) {uint16_t(w), uint16_t(w), uint16_t(w), uint16_t(w), \
                        uint16_t(w), uint16_t(w), uint16_t(w), uint16_t(w)}

uint16_t mul_1_100[8]   SIMD_ALIGN = {  100,      1,    100,      1,
                                        100,      1,    100,      1};

uint16_t mul_10_1000[8] SIMD_ALIGN = { 1000,     10,   1000,     10,
                                       1000,     10,   1000,     10};

uint16_t mul_1_10000[8] SIMD_ALIGN = {10000,      1,      0,      0,
                                      10000,      1,      0,      0};

uint8_t ascii0[16] SIMD_ALIGN = {'0', '0', '0', '0', '0', '0', '0', '0',
                                 '0', '0', '0', '0', '0', '0', '0', '0'};

uint32_t result[4] SIMD_ALIGN;


// ------------------------------------------------------------------------


uint64_t parse_sse(char* s) {
    //assert(strlen(s) >= 16);

    __asm__ __volatile__(
        "movdqu (%%eax), %%xmm0         \n"
        "psubb  ascii0,  %%xmm0         \n"
        "movdqa %%xmm0, %%xmm1          \n"

        // t2_odd  = xmm1
        "psrlw $8, %%xmm1               \n"

        // t2_even = xmm0
        "psllw $8, %%xmm0               \n"
        "psrlw $8, %%xmm0               \n"

        // t3_even = xmm0
        "pmaddwd mul_10_1000, %%xmm0    \n"
        // t4_odd  = xmm1
        "pmaddwd mul_1_100, %%xmm1      \n"

        // t5 = xmm0
        "paddd %%xmm1, %%xmm0           \n"

        // t6 = xmm0
        "movdqa %%xmm0, %%xmm1          \n"
        "psrlq  $16,    %%xmm1          \n"
        "por    %%xmm1, %%xmm0          \n"
        "pmaddwd mul_1_10000, %%xmm0    \n"

        // save result
        "movdqa %%xmm0, result          \n"
        :
        : "a" (s)
        : "memory"
    );

    return uint64_t(result[0]) * 100000000 + result[2];
}


