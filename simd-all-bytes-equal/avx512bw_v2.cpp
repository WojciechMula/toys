#include <immintrin.h>
#include <cstdint>

bool all_equal(__m512i input) {
    const __m128i lane0  = _mm512_castsi512_si128(input);
    const __m512i populated_0th_byte = _mm512_broadcastb_epi8(lane0);
    const __mmask16 mask = _mm512_cmpeq_epi32_mask(input, populated_0th_byte);

    return _mm512_kortestc(mask, mask);
}
