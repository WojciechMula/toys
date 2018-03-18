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


// #define INLINE_ASM # 32-bit code
#if defined(INLINE_ASM)
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
#else

#include <immintrin.h>


uint64_t parse_sse(const char* s) {
    //assert(strlen(s) >= 16);

    const __m128i ascii0 = _mm_set1_epi8('0');
    const __m128i mul_1_100   = _mm_setr_epi16(  100,  1,  100,  1,
                                                 100,  1,  100,  1);
    const __m128i mul_10_1000 = _mm_setr_epi16( 1000, 10, 1000, 10,
                                                1000, 10, 1000, 10);
    const __m128i mul_1_10000 = _mm_setr_epi16(10000,  1,    0,  0,
                                               10000,  1,    0,  0);

    // =--------------

    const __m128i input   = _mm_sub_epi8(_mm_loadu_si128((__m128i*)s), ascii0);

    const __m128i t2_even = _mm_srli_epi16(_mm_slli_epi16(input, 8), 8);
    const __m128i t3_even = _mm_madd_epi16(t2_even, mul_10_1000);

    const __m128i t2_odd  = _mm_srli_epi16(input, 8);
    const __m128i t4_odd  = _mm_madd_epi16(t2_odd, mul_1_100);

    const __m128i t5      = _mm_add_epi32(t3_even, t4_odd);
    const __m128i t6      = _mm_or_si128(t5, _mm_srli_epi64(t5, 16));
    const __m128i t7      = _mm_madd_epi16(t6, mul_1_10000);

    union packed_dword {
        __m128i  vector;
        uint32_t element[4];
    } p;

    p.vector = t7;

    return uint64_t(p.element[0]) * uint64_t(100000000) + p.element[2];
}

#endif //defined(INLINE_ASM)

