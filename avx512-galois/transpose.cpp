#include <immintrin.h>
/*
    Each 64-bit word holds 8x8 bit matrix:

        LSB                   MSB
        [a0|b0|c0|d0|e0|f0|g0|h0] byte 0
        [a1|b1|c1|d1|e1|f1|g1|h1]
        [a2|b2|c2|d2|e2|f2|g2|h2]
        [a3|b3|c3|d3|e3|f3|g3|h3]
        [a4|b4|c4|d4|e4|f4|g4|h4]
        [a5|b5|c5|d5|e5|f5|g5|h5]
        [a6|b6|c6|d6|e6|f6|g6|h6]
        [a7|b7|c7|d7|e7|f7|g7|h7] byte 7
    
    Output is (note that bits from byte 7 are MSBs):

        LSB                   MSB
        [a7|a6|a5|a4|a3|a2|a1|a0] byte 0
        [b7|b6|b5|b4|b3|b2|b1|b0]
        [c7|c6|c5|c4|c3|c2|c1|c0]
        [d7|d6|d5|d4|d3|d2|d1|d0]
        [e7|e6|e5|e4|e3|e2|e1|e0]
        [f7|f6|f5|f4|f3|f2|f1|f0]
        [g7|g6|g5|g4|g3|g2|g1|g0]
        [h7|h6|h5|h4|h3|h2|h1|h0] byte 7
*/


__m512i transpose_8x8_epi64(__m512i input)
{
    const __m512i select = _mm512_set1_epi64(0x8040201008040201ul);
    return _mm512_gf2p8affine_epi64_epi8(select, input, 0x00);
}
