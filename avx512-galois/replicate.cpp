#include <immintrin.h>
#include <cassert>
#include "bit_shuffle.h"

__m512i replicate_bit_epi8(__m512i input, int bit) {

    assert(bit >= 0);
    assert(bit < 8);

    const __m512i select = _mm512_set1_epi8(1 << bit);

    return _mm512_gf2p8affine_epi64_epi8(input, select, 0x00);
}
