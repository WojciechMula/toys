#include <cstdint>
#include <immintrin.h>

void jpeg_zigzag_avx512f(const uint16_t* in, uint16_t* out) {
    
    const __m512i A = _mm512_loadu_si512((const __m512i*)(in + 0*32));
    const __m512i B = _mm512_loadu_si512((const __m512i*)(in + 1*32));

#   include "avx512f.inl"

    _mm512_storeu_si512((__m512i*)(out + 0*32), row0);
    _mm512_storeu_si512((__m512i*)(out + 1*32), row1);
}

