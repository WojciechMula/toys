// copy of avx512bw.cpp, but use masked writes instead of explicit bit-or operations

#include <cstdint>
#include <immintrin.h>

void jpeg_zigzag_avx512bw_masks(const uint8_t* in, uint8_t* out) {
    
    const __m512i v = _mm512_loadu_si512((const __m512i*)in);

    // populate lanes -- each lane represents pair of output rows
    const __m512i A = _mm512_permutexvar_epi32(
                      _mm512_setr_epi32(0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3), v);
    const __m512i B = _mm512_permutexvar_epi32(
                      _mm512_setr_epi32(4, 5, 6, 7, 4, 5, 6, 7, 4, 5, 6, 7, 4, 5, 6, 7), v);
    const __m512i C = _mm512_permutexvar_epi32(
                      _mm512_setr_epi32(8, 9, 10, 11, 8, 9, 10, 11, 8, 9, 10, 11, 8, 9, 10, 11), v);
    const __m512i D = _mm512_permutexvar_epi32(
                      _mm512_setr_epi32(12, 13, 14, 15, 12, 13, 14, 15, 12, 13, 14, 15, 12, 13, 14, 15), v);
    
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

    __m512i result = _mm512_shuffle_epi8(A, _mm512_load_si512((const __m512i*)shuffle_A));
    result = _mm512_mask_shuffle_epi8(result, 0x00201b00c3061b08lu,
                                      B, _mm512_load_si512((const __m512i*)shuffle_B));
    result = _mm512_mask_shuffle_epi8(result, 0x10d860c300d80400lu,
                                      C, _mm512_load_si512((const __m512i*)shuffle_C));
    result = _mm512_mask_shuffle_epi8(result, 0xef07803c00200000lu,
                                      D, _mm512_load_si512((const __m512i*)shuffle_D));

    _mm512_storeu_si512((__m512i*)out, result);
}
