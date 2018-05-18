#include <immintrin.h>
#include <stdio.h>
#ifdef PROFILE_IACA
#include "iacaMarks.h"
#endif

int anynonzero_epi32(__m512i x) {
    const __m512i   zero = _mm512_setzero_si512();
    const __mmask16 mask = _mm512_cmpneq_epi32_mask(x, zero);
    return mask != 0;
}

int anynonzero_epi32_asm(__m512i x) {
#ifdef PROFILE_IACA
    IACA_START
#endif
#if 1
    __asm__ __volatile__(
        "vpxor      %xmm1, %xmm1, %xmm1\n"
        "vpcmpneqd	%zmm1, %zmm0, %k1\n"
        "xor        %eax, %eax\n"
        "ktestw     %k1, %k1\n"
        "setne      %al\n"
    );
#else
    __asm__ __volatile__(
        "vpxor      %xmm1, %xmm1, %xmm1\n"
        "vpcmpneqd	%zmm1, %zmm0, %k1\n"
         // compiled by GCC 8.1
        "kmovw %k1, %eax\n"
        "test %ax, %ax\n"
        "setne %al\n"
        "movzx %al, %eax\n"
    );
#endif
#ifdef PROFILE_IACA
    IACA_END
#endif
}

int main() {
    __m512i a = _mm512_setzero_si512();
    __m512i b = _mm512_set1_epi32(42);

    printf("C function:   %d %d\n", anynonzero_epi32(a), anynonzero_epi32(b));
    printf("asm function: %d %d\n", anynonzero_epi32_asm(a), anynonzero_epi32_asm(b));
}

