#include <immintrin.h>
#include "bit_shuffle.h"

/*
    Following bit shuffling is done for all bytes:

        in:  [0,1,2,3,4,5,6,7]
        out: [0,4,1,5,2,6,3,7]
*/
__m512i interleave_epi8(__m512i input) {

    const __m512i select = _mm512_set1_epi64(bit_shuffle_const(0, 4, 1, 5, 2, 6, 3, 7));

    return _mm512_gf2p8affine_epi64_epi8(input, select, 0x00);
}
