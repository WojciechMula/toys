#include <immintrin.h>
#include <cstdint>

bool all_equal(__m512i input) {
    const __m128i lane0  = _mm512_castsi512_si128(input);
    const __m128i t0     = _mm_shuffle_epi8(lane0, _mm_setzero_si128());
    const __m512i populated_0th_byte = _mm512_broadcast_i32x4(t0);

    // AVX512F does not support byte-level ops
    const __m512i t1     = _mm512_xor_si512(input, populated_0th_byte);

    // ... thus we expect that all 32-bit words are zero (as x xor x = 0)
    const __mmask16 mask = _mm512_cmpeq_epi32_mask(t1, _mm512_setzero_si512());
    
    return (mask == 0xffff);
}
