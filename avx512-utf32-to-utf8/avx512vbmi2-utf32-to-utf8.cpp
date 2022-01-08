#include "avx512vbmi2-utf32-to-utf8.h"

#include <cstdint>

namespace {
    const __m512i v_04030201 = _mm512_set1_epi32(0x04030201);
}

size_t avx512vbmi2_compress_utf8(__m512i expanded_utf8, __m512i length, char* output) {
    /*
        [     4     |     3     |     2     |     1     ] length (uint32 array)
        [a3|a2|a1|a0|00|b2|b1|b0|00|00|c1|c0|00|00|00|d0] expanded_utf8 (uint8 array)

        | 4B char   |  3B char  |  2B char  |   ASCII   |
        |                                               |
        |                  128-bit lane                 |
    */

    // 1. expand length to each byte
    //    length = [00|00|00|aa|00|00|00|bb|00|00|00|cc|..]
    //    blen   = [aa|aa|aa|aa|bb|bb|bb|bb|cc|cc|cc|cc|..]
    /** pshufb

        lane = [0, 0, 0, 0, 4, 4, 4, 4, 8, 8, 8, 8, 12, 12, 12, 12]
        populate_0th_byte_u32 = 4 * lane
    */
    const __m512i populate_0th_byte_u32 = _mm512_setr_epi64(
        0x0404040400000000,
        0x0c0c0c0c08080808,
        0x0404040400000000,
        0x0c0c0c0c08080808,
        0x0404040400000000,
        0x0c0c0c0c08080808,
        0x0404040400000000,
        0x0c0c0c0c08080808
    );
    const __m512i blen = _mm512_shuffle_epi8(length, populate_0th_byte_u32);

    // 2. build byte mask
    //    idx   = [ 1| 2| 3| 4| 1| 2| 3| 4| 1| 2| 3| 4| 1| 2| 3| 4] * 4
    //    blen  = [ 4| 4| 4| 4| 3| 3| 3| 3| 2| 2| 2| 2| 1| 1| 1| 1] * 4
    //    mask  = idx <= blen
    //          = [ 1| 1| 1| 1| 1| 1| 1| 0| 1| 1| 0| 0| 1| 0| 0| 0] * 4
    const __mmask64 mask = _mm512_cmple_epu8_mask(v_04030201, blen);

    _mm512_mask_compressstoreu_epi8(output, mask, expanded_utf8);

    return __builtin_popcountll(mask);
}
