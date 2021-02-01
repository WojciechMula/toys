#include <immintrin.h>
#include <cstdint>

bool all_equal(__m512i input) {
    const __m128i lane0  = _mm512_castsi512_si128(input);
    const __m512i populated_0th_byte = _mm512_broadcastb_epi8(lane0);
    const __mmask64 mask = _mm512_cmpeq_epu8_mask(input, populated_0th_byte);
    
    return (mask == 0xfffffffffflu);
}

