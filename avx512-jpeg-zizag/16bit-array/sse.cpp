#include <cstdint>
#include <immintrin.h>

void jpeg_zigzag_sse(const uint16_t* in, uint16_t* out) {
    
    const __m128i A = _mm_loadu_si128((const __m128i*)(in + 0*8));
    const __m128i B = _mm_loadu_si128((const __m128i*)(in + 1*8));
    const __m128i C = _mm_loadu_si128((const __m128i*)(in + 2*8));
    const __m128i D = _mm_loadu_si128((const __m128i*)(in + 3*8));
    const __m128i E = _mm_loadu_si128((const __m128i*)(in + 4*8));
    const __m128i F = _mm_loadu_si128((const __m128i*)(in + 5*8));
    const __m128i G = _mm_loadu_si128((const __m128i*)(in + 6*8));
    const __m128i H = _mm_loadu_si128((const __m128i*)(in + 7*8));
    
#   include "sse.inl"

    _mm_storeu_si128((__m128i*)(out + 0*8), row0);
    _mm_storeu_si128((__m128i*)(out + 1*8), row1);
    _mm_storeu_si128((__m128i*)(out + 2*8), row2);
    _mm_storeu_si128((__m128i*)(out + 3*8), row3);
    _mm_storeu_si128((__m128i*)(out + 4*8), row4);
    _mm_storeu_si128((__m128i*)(out + 5*8), row5);
    _mm_storeu_si128((__m128i*)(out + 6*8), row6);
    _mm_storeu_si128((__m128i*)(out + 7*8), row7);
}

void jpeg_zigzag_sse_copy_single(const uint16_t* in, uint16_t* out) {
    
    const __m128i A = _mm_loadu_si128((const __m128i*)(in + 0*8));
    const __m128i B = _mm_loadu_si128((const __m128i*)(in + 1*8));
    const __m128i C = _mm_loadu_si128((const __m128i*)(in + 2*8));
    const __m128i D = _mm_loadu_si128((const __m128i*)(in + 3*8));
    const __m128i E = _mm_loadu_si128((const __m128i*)(in + 4*8));
    const __m128i F = _mm_loadu_si128((const __m128i*)(in + 5*8));
    const __m128i G = _mm_loadu_si128((const __m128i*)(in + 6*8));
    const __m128i H = _mm_loadu_si128((const __m128i*)(in + 7*8));
    
#   include "sse-copy-single.inl"

    _mm_storeu_si128((__m128i*)(out + 0*8), row0);
    _mm_storeu_si128((__m128i*)(out + 1*8), row1);
    _mm_storeu_si128((__m128i*)(out + 2*8), row2);
    _mm_storeu_si128((__m128i*)(out + 3*8), row3);
    _mm_storeu_si128((__m128i*)(out + 4*8), row4);
    _mm_storeu_si128((__m128i*)(out + 5*8), row5);
    _mm_storeu_si128((__m128i*)(out + 6*8), row6);
    _mm_storeu_si128((__m128i*)(out + 7*8), row7);
}
