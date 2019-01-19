#include "avx512bw.h"

#include "scalar.h"
#include <immintrin.h>

uint64_t avx512bw_count_bytes(const uint8_t* data, size_t size, uint8_t byte) {

    const uint8_t* end = data + size;
    const uint8_t* ptr = data;

    uint64_t sum = 0;

    const __m512i v = _mm512_set1_epi8(byte);

    while (ptr + 64 < end) {
        const __m512i in = _mm512_loadu_si512((const __m512i*)ptr);
        sum += __builtin_popcountll(_mm512_cmpeq_epi8_mask(in, v));

        ptr += 64;
    }

    return sum + scalar_count_bytes(ptr, end - ptr, byte);
    
}
