#include <cstdint>
#include <cstdlib>
#include <immintrin.h>


void bitmask_SSE(const uint32_t* array, size_t n, const uint32_t key, uint8_t* bitvector) {

    const size_t blocks = n / 16;
    const size_t tail   = n % 16;

    const __m128i *input = reinterpret_cast<const __m128i*>(array);
    uint16_t* bitvector16 = reinterpret_cast<uint16_t*>(bitvector);

    const __m128i vkey = _mm_set1_epi32(key);

    for (size_t i=0; i < blocks; i++) {

        // packed dword results
        const __m128i d0 = _mm_cmpeq_epi32(vkey, _mm_loadu_si128(input + 4*i + 0));
        const __m128i d1 = _mm_cmpeq_epi32(vkey, _mm_loadu_si128(input + 4*i + 1));
        const __m128i d2 = _mm_cmpeq_epi32(vkey, _mm_loadu_si128(input + 4*i + 2));
        const __m128i d3 = _mm_cmpeq_epi32(vkey, _mm_loadu_si128(input + 4*i + 3));

        // packed word results
        const __m128i d01 = _mm_packs_epi32(d0, d1);
        const __m128i d23 = _mm_packs_epi32(d2, d3);

        // packed byte result
        const __m128i pck = _mm_packs_epi16(d01, d23);

        // convert byte-mask into bitmask
        bitvector16[i] = _mm_movemask_epi8(pck);
    }

    if (tail > 0) {
        bitmask_better_2(array + blocks*16, tail, key, bitvector + blocks*16);
    }
}

