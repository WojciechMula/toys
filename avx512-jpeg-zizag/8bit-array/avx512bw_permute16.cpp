#include <cstdint>
#include <immintrin.h>

void jpeg_zigzag_avx512bw_permute16(const uint8_t* in, uint8_t* out) {
    
    const __m512i v = _mm512_loadu_si512((const __m512i*)in);

    // crosslane 16-bit shuffle #1:
    //   [ 0, 1][ 2, 3][ 4, 5][ 8, 9][10,11][16,17][18,19][24,25] -- lane 0: missing: 32
    //   [ 6, 7][12,13][14,15][20,21][26,27][28,29][32,33][34,35] -- lane 1: missing: 19, 34, 40, 41, 48
    //   [22,23][30,31][36,37][42,43][44,45][48,49][50,51][56,57] -- lane 2: missing: 15, 29, 35
    //   [38,39][46,47][52,53][54,55][58,59][60,61][62,63][62,62] -- lane 3: missing: 31, 45
    static const int16_t crosslane_shuffle1[32] __attribute__((aligned(64))) = {
         0,  1,  2,  4,  5,  8,  9, 12,
         3,  6,  7, 10, 13, 14, 16, 17,
        11, 15, 18, 21, 22, 24, 25, 28,
        19, 23, 26, 27, 29, 30, 31, 31
    };

    const __m512i shuf1 = _mm512_permutexvar_epi16(_mm512_load_si512((__m512i*)crosslane_shuffle1), v);

    // in-lane 8-bit shuffle #1
    static const int8_t inlane_shuffle1[64] __attribute__((aligned(64))) = {
        /* lane 0 */  0,  1,  6, 10,  7,  2,  3,  8, 11, 14, -1, 15, 12,  9,  4,  5,
        /* lane 1 */  2, -1,  8, 13, -1, -1, -1, 14,  9,  6,  3,  0,  1,  4,  7, 10,
        /* lane 2 */ -1,  6, 11, 14, 15, 12,  7,  4, -1,  0, -1,  1,  2,  5,  8, 13,
        /* lane 3 */  8,  9,  4, -1,  0, -1,  1,  2,  5, 10, 11,  6,  3,  7, 12, 13
    };

    const __m512i t0 = _mm512_shuffle_epi8(shuf1, _mm512_load_si512(inlane_shuffle1));

    // crosslane 16-bit shuffle #2 -- we need to get values not available in step #1
    //   [32,33][32,33][32,33][32,33][32,33][32,33][32,33][32,33] -- lane 0: missing: 32
    //   [18,19][34,35][40,41][48,49][48,49][48,49][48,49][48,49] -- lane 1: missing: 19, 34, 40, 41, 48
    //   [14,15][28,29][34,35][34,35][34,35][34,35][34,35][34,35] -- lane 2: missing: 15, 29, 35
    //   [30,31][44,45][44,45][44,45][44,45][44,45][44,45][44,45] -- lane 2: missing: 31, 45
    static const int16_t crosslane_shuffle2[32] __attribute__((aligned(64))) = {
        /* lane 0*/ 16, 16, 16, 16, 16, 16, 16, 16,
        /* lane 1*/  9, 17, 20, 24, 24, 24, 24, 24,
        /* lane 2*/  7, 14, 17, 17, 17, 17, 17, 17,
        /* lane 3*/ 15, 22, 22, 22, 22, 22, 22, 22
    };
    const __m512i shuf2 = _mm512_permutexvar_epi16(_mm512_load_si512((__m512i*)crosslane_shuffle2), v);

    // in-lane 8-bit shuffle #2
    static const int8_t inlane_shuffle2[64] __attribute__((aligned(64))) = {
        /* lane 0 */ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  0, -1, -1, -1, -1, -1,
        /* lane 1 */ -1,  1, -1, -1,  4,  6,  5,  2, -1, -1, -1, -1, -1, -1, -1, -1,
        /* lane 2 */  5, -1, -1, -1, -1, -1, -1, -1,  3, -1,  1, -1, -1, -1, -1, -1,
        /* lane 3 */ -1, -1, -1,  3, -1,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
    };

    const __m512i t1 = _mm512_shuffle_epi8(shuf2, _mm512_load_si512(inlane_shuffle2));

    const __m512i res = _mm512_or_si512(t0, t1);
    _mm512_storeu_si512((__m512i*)out, res);
}

