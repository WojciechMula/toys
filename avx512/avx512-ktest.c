#include <immintrin.h>
#include <stdio.h>

int anynonzero_epi32(__m512i x) {
    const __m512i   zero = _mm512_setzero_si512();
    const __mmask16 mask = _mm512_cmpneq_epi32_mask(x, zero);
    return mask != 0;
}

int anynonzero_epi32_asm(__m512i x) {
    __asm__ __volatile__(
        "vpxor      %xmm1, %xmm1, %xmm1\n"
        "vpcmpneqd	%zmm1, %zmm0, %k1\n"
        "xor        %eax, %eax\n"
        "ktestw     %k1, %k1\n"
        "setne      %al\n"
    );
}

int main() {
    __m512i a = _mm512_setzero_si512();
    __m512i b = _mm512_set1_epi32(42);

    printf("C function:   %d %d\n", anynonzero_epi32(a), anynonzero_epi32(b));
    printf("asm function: %d %d\n", anynonzero_epi32_asm(a), anynonzero_epi32_asm(b));
}

