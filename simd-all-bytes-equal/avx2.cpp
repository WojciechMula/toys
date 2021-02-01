#include <immintrin.h>
#include <cstdint>

bool all_equal(__m256i input) {
    const __m128i lane0 = _mm256_castsi256_si128(input); // no cost, 0th lane is mapped to an XMM reg
    const __m128i tmp   = _mm_shuffle_epi8(lane0, _mm_setzero_si128());
    const __m256i populated_0th_byte = _mm256_set_m128i(tmp, tmp);
    const __m256i eq = _mm256_cmpeq_epi8(input, populated_0th_byte);
    
    return ((uint32_t)_mm256_movemask_epi8(eq) == 0xffffffff);
}

