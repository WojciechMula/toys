#include <cstdint>
#include <immintrin.h>

void jpeg_zigzag_avx512bw(const uint16_t* in, uint16_t* out) {
    
    const __m512i A = _mm512_loadu_si512((const __m512i*)(in + 0*32));
    const __m512i B = _mm512_loadu_si512((const __m512i*)(in + 1*32));

    const __m512i shuf0 = _mm512_loadu_si512((const __m512i*)(zigzag_shuffle + 0*32));
    const __m512i res0  = _mm512_permutex2var_epi16(A, shuf0, B);
    const __m512i shuf1 = _mm512_loadu_si512((const __m512i*)(zigzag_shuffle + 1*32));
    const __m512i res1  = _mm512_permutex2var_epi16(A, shuf1, B);
    
    _mm512_storeu_si512((__m512i*)(out + 0*32), res0);
    _mm512_storeu_si512((__m512i*)(out + 1*32), res1);
}

