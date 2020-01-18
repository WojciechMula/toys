#include <immintrin.h>
#include "bit_shuffle.h"

__m512i reverse_epi8(__m512i input) {

    const __m512i select = _mm512_set1_epi64(bit_shuffle_const(7, 6, 5, 4, 3, 2, 1, 0));

    return _mm512_gf2p8affine_epi64_epi8(input, select, 0x00);
}
