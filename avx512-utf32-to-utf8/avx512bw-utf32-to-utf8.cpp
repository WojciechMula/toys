#include "avx512bw-utf32-to-utf8.h"

#include <cstdint>

namespace {
    const __m512i v_000000000_000000ff = _mm512_set1_epi64(0xff);
    const __m512i v_08 = _mm512_set1_epi8(8);
}

size_t avx512bw_compress_utf8(__m512i expanded_utf8, __m512i length, char* output) {
    /*
        [     4     |     3     |     2     |     1     ] length (uint32 array)
        [a3|a2|a1|a0|00|b2|b1|b0|00|00|c1|c0|00|00|00|d0] expanded_utf8 (uint8 array)

        | 4B char   |  3B char  |  2B char  |   ASCII   |
        |                                               |
        |                  128-bit lane                 |
    */

    /* 1. Compact adjacent 32-bit words */
    /** pshufb

        invalid = 0

        lane_lookup = [0] * 16

        lane_lookup[1] = 8*3
        lane_lookup[2] = 8*2
        lane_lookup[3] = 8*1
        lane_lookup[4] = 8*0

        shift_lookup = 4 * lane_lookup
    */
	const __m512i shift_lookup = _mm512_setr_epi64(
		0x0000000008101800,
		0x0000000000000000,
		0x0000000008101800,
		0x0000000000000000,
		0x0000000008101800,
		0x0000000000000000,
		0x0000000008101800,
		0x0000000000000000
	);

    __m512i merged_u64;
    {
        __m512i shift = _mm512_shuffle_epi8(shift_lookup, length);
        shift = _mm512_and_si512(shift, v_000000000_000000ff);

        // merged_u64 = [a3|a2|a1|a0|b2|b1|b0|00|00|00|c1|c0|d0|00|00|00] * 4
        //                           ^^^^^^^^^^^             ^^^^^^^^^^^  active 32-bit lanes
        merged_u64 = _mm512_sllv_epi32(expanded_utf8, shift);

        // merged_u64 = [00|a3|a2|a1|a0|b2|b1|b0|00|00|00|00|00|c1|c0|d0] * 4
        //
        merged_u64 = _mm512_srlv_epi64(merged_u64, shift);
    }

    /** pshufb
        seq = list(range(16))

        v_sequence_0_to_15 = 4 * seq
    */
    const __m512i v_sequence_0_to_15 = _mm512_setr_epi64(
        0x0706050403020100,
        0x0f0e0d0c0b0a0908,
        0x0706050403020100,
        0x0f0e0d0c0b0a0908,
        0x0706050403020100,
        0x0f0e0d0c0b0a0908,
        0x0706050403020100,
        0x0f0e0d0c0b0a0908
    );

    /* 2. Compact 16-byte lanes */
    __m512i shuffled;
    __m512i half_lane_size;
    {
        // cnt = the number of active bytes in lower 64-bit lanes
        const __m512i t0 = _mm512_srli_epi64(length, 32);
        half_lane_size = _mm512_maskz_add_epi32(0x5555, length, t0);

        // make lookup mask
        // m0 = [0, 1, 2, 3, 4, 5, 6,  7,  8,  9, 10, 11, 12, 13, 14, 15] * 4
        const __m512i m0 = v_sequence_0_to_15;
        // m1 = [3, 3, 3, 3, 3, 3, 3,  3,  3,  3,  3,  3,  3,  3,  3,  3] * 4a
        const __m512i populate_0th_byte_of_lane = _mm512_setzero_si512();
        __m512i m1 = _mm512_shuffle_epi8(half_lane_size, populate_0th_byte_of_lane);
        const __m512i m2 = _mm512_sub_epi8(v_08, m1);

        // ge = m1[i] > byte(length)
        // ge = [0, 0, 0, 1, 1, 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1] * 4
        const __mmask64 ge = _mm512_cmpge_epu8_mask(m0, m1);

        // m2 = [0, 1, 2, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20] * 4
        const __m512i m3 = _mm512_mask_add_epi8(m0, ge, m0, m2);

        shuffled = _mm512_shuffle_epi8(merged_u64, m3);
    }

    /* 3. store lanes */
    char* orig = output;

    uint64_t len[8];
    _mm512_storeu_si512((__m512i*)len, half_lane_size);
    {
        const __m256i h0 = _mm512_castsi512_si256(shuffled);
        const __m256i h1 = _mm512_extracti32x8_epi32(shuffled, 1);

        const __m128i t0 = _mm256_castsi256_si128(h0);
        const __m128i t1 = _mm256_extracti32x4_epi32(h0, 1);
        const __m128i t2 = _mm256_castsi256_si128(h1);
        const __m128i t3 = _mm256_extracti32x4_epi32(h1, 1);

        _mm_storeu_si128((__m128i*)output, t0);
        output += len[0] + len[1];

        _mm_storeu_si128((__m128i*)output, t1);
        output += len[2] + len[3];

        _mm_storeu_si128((__m128i*)output, t2);
        output += len[4] + len[5];

        _mm_storeu_si128((__m128i*)output, t3);
        output += len[6] + len[7];
    }

    return output - orig;
}
