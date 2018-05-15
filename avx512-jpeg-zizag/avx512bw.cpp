// this is translation of SSE code

#include <cstdint>
#include <immintrin.h>

void jpeg_zigzag_avx512bw(const uint8_t* in, uint8_t* out) {
    

    // populate lanes -- each lane represents pair of output rows
#if 1
    // as proposed by InstLatX64
    // https://twitter.com/InstLatX64/status/996370932238307329
    const __m512i A = _mm512_broadcast_i32x4(_mm_loadu_si128((const __m128i*)(in + 0 * 16)));
    const __m512i B = _mm512_broadcast_i32x4(_mm_loadu_si128((const __m128i*)(in + 1 * 16)));
    const __m512i C = _mm512_broadcast_i32x4(_mm_loadu_si128((const __m128i*)(in + 2 * 16)));
    const __m512i D = _mm512_broadcast_i32x4(_mm_loadu_si128((const __m128i*)(in + 3 * 16)));
#else
    const __m512i v = _mm512_loadu_si512((const __m512i*)in);

    const __m512i A = _mm512_permutexvar_epi32(
                      _mm512_setr_epi32(0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3), v);
    const __m512i B = _mm512_permutexvar_epi32(
                      _mm512_setr_epi32(4, 5, 6, 7, 4, 5, 6, 7, 4, 5, 6, 7, 4, 5, 6, 7), v);
    const __m512i C = _mm512_permutexvar_epi32(
                      _mm512_setr_epi32(8, 9, 10, 11, 8, 9, 10, 11, 8, 9, 10, 11, 8, 9, 10, 11), v);
    const __m512i D = _mm512_permutexvar_epi32(
                      _mm512_setr_epi32(12, 13, 14, 15, 12, 13, 14, 15, 12, 13, 14, 15, 12, 13, 14, 15), v);
#endif

    // perform shuffling within lanes
    static const int8_t shuffle_A[64] __attribute__((aligned(64))) = {
         0,  1,  8, -1,  9,  2,  3, 10, -1, -1, -1, -1, -1, 11,  4,  5,
        12, -1, -1, -1, -1, -1, -1, -1, -1, -1, 13,  6,  7, 14, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 15, -1, -1, -1, -1, -1, 
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
    };

    static const int8_t shuffle_B[64] __attribute__((aligned(64))) = {
        -1, -1, -1,  0, -1, -1, -1, -1,  1,  8, -1,  9,  2, -1, -1, -1,
        -1,  3, 10, -1, -1, -1, -1, -1, 11,  4, -1, -1, -1, -1,  5, 12,
        -1, -1, -1, -1, -1, -1, -1, -1, 13,  6, -1,  7, 14, -1, -1, -1,
        -1, -1, -1, -1, -1, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
    };

    static const int8_t shuffle_C[64] __attribute__((aligned(64))) = {
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  0, -1, -1, -1, -1, -1,
        -1, -1, -1,  1,  8, -1,  9,  2, -1, -1, -1, -1, -1, -1, -1, -1,
         3, 10, -1, -1, -1, -1, 11,  4, -1, -1, -1, -1, -1,  5, 12, -1,
        -1, -1, -1, 13,  6, -1,  7, 14, -1, -1, -1, -1, 15, -1, -1, -1
    };

    static const int8_t shuffle_D[64] __attribute__((aligned(64))) = {
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1,  0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1,  1,  8,  9,  2, -1, -1, -1, -1, -1, -1, -1, -1, -1,  3,
        10, 11,  4, -1, -1, -1, -1, -1,  5, 12, 13,  6, -1,  7, 14, 15
    };

    const __m512i shufA = _mm512_shuffle_epi8(A, _mm512_load_si512((const __m512i*)shuffle_A));
    const __m512i shufB = _mm512_shuffle_epi8(B, _mm512_load_si512((const __m512i*)shuffle_B));
    const __m512i shufC = _mm512_shuffle_epi8(C, _mm512_load_si512((const __m512i*)shuffle_C));
    const __m512i shufD = _mm512_shuffle_epi8(D, _mm512_load_si512((const __m512i*)shuffle_D));

    // merge all shufX vectors
    const uint8_t OR_ALL = 0xfe;
    const __m512i res = _mm512_or_si512(shufD,
                        _mm512_ternarylogic_epi32(shufA, shufB, shufC, OR_ALL));

    _mm512_storeu_si512((__m512i*)out, res);
}
