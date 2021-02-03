#include <immintrin.h>
#include <cstdint>

bool all_equal(__m128i input) {
    const __m128i rotated = _mm_alignr_epi8(input, input, 1);
    const __m128i eq = _mm_cmpeq_epi8(input, rotated);
    
    return ((uint16_t)_mm_movemask_epi8(eq) == 0xffff);
}

