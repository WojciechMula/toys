#include <immintrin.h>
#include <cstdint>

enum class Colour: uint32_t {
    RED     = 0x00ff0000,
    GREEN   = 0x0000ff00,
    BLUE    = 0x000000ff,
    WHITE   = 0x00ffffff,
    GRAY0   = 0x00333333,
    GRAY1   = 0x00aaaaaa,
    GRAY2   = 0x00dddddd,
    BLACK   = 0x00000000
};

int palette_avx2(Colour col) {

    const __m256i vec = _mm256_set1_epi32((uint32_t)col);
    const __m256i lookup = _mm256_setr_epi32(
        0x00ff0000, 0x0000ff00, 0x000000ff, 0x00ffffff,
        0x00333333, 0x00aaaaaa, 0x00dddddd, 0x00000000
    );

    const __m256i mask = _mm256_cmpeq_epi32(vec, lookup);
    
    uint32_t bitmask = _mm256_movemask_ps((__m256)mask);
    if (bitmask) {
        return __builtin_ctz(bitmask);
    } else {
        // default value
        return -1;
    }
}

