/*
    AVX512F lacks of byte-level align-right instruction.
    This is an attempt to do this.
*/

#include <cassert>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <immintrin.h>


__m512i _mm512_alignrvar_epi32(const __m512i hi, const __m512i lo, int shift) {
    switch (shift) {
        case 0: return lo; break;
        case 1: return _mm512_alignr_epi32(hi, lo, 1); break;
        case 2: return _mm512_alignr_epi32(hi, lo, 2); break;
        case 3: return _mm512_alignr_epi32(hi, lo, 3); break;
        case 4: return _mm512_alignr_epi32(hi, lo, 4); break;
        case 5: return _mm512_alignr_epi32(hi, lo, 5); break;
        case 6: return _mm512_alignr_epi32(hi, lo, 6); break;
        case 7: return _mm512_alignr_epi32(hi, lo, 7); break;
        case 8: return _mm512_alignr_epi32(hi, lo, 8); break;
        case 9: return _mm512_alignr_epi32(hi, lo, 9); break;
        case 10: return _mm512_alignr_epi32(hi, lo, 10); break;
        case 11: return _mm512_alignr_epi32(hi, lo, 11); break;
        case 12: return _mm512_alignr_epi32(hi, lo, 12); break;
        case 13: return _mm512_alignr_epi32(hi, lo, 13); break;
        case 14: return _mm512_alignr_epi32(hi, lo, 14); break;
        case 15: return _mm512_alignr_epi32(hi, lo, 15); break;
        case 16: return hi; break;
        default:
            assert(false);
    }
}


__m512i _mm512_alignr_epi8(const __m512i hi, const __m512i lo, unsigned shift) {

    assert(shift < 64);

    const int s32 = shift / 4; // shift amount in 32-bit words
    const int s8  = shift % 4; // shift amount within 32-bit word

    if (s8 == 0) {
        return _mm512_alignrvar_epi32(hi, lo, s32);
    } else {
        const __m512i L = _mm512_alignrvar_epi32(hi, lo, s32);
        const __m512i H = _mm512_alignrvar_epi32(hi, lo, s32 + 1);

        // dwords in H have "next" dwords for L
        // L = [a b c d|e f g h|  ... ]
        // H = [e f g h|...    |  ... ]

        return _mm512_or_si512(
                _mm512_srli_epi32(L, s8 * 8),       // shift lower part left
                _mm512_slli_epi32(H, (4 - s8) * 8)  // shift in lower part from the next dword
        );
    }
}


void validate() {

    uint8_t input[128];
    uint8_t output[64];

    for (int i=0; i < 128; i++) {
        input[i] = i;
    }

    for (int shift=0; shift < 64; shift++) {
        
        const __m512i lo = _mm512_loadu_si512((__m512i*)(input + 0));
        const __m512i hi = _mm512_loadu_si512((__m512i*)(input + 64));

        const __m512i res = _mm512_alignr_epi8(hi, lo, shift);

        _mm512_storeu_si512((__m512i*)output, res);

        for (int i=0; i < 64; i++) {
            if (output[i] != input[i + shift]) {
                printf("failed for shift %d\n", shift);
                exit(1);
            }
        }
    }
}


int main() {
    
    validate();
    puts("All OK");
}
