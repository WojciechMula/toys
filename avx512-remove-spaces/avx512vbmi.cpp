#include <immintrin.h>
#include <cstdint>
#include <cassert>

char* remove_spaces__avx512vbmi(const char* src, char* dst, size_t n) {
    assert(n % 64 == 0);

    const __m512i NL     = _mm512_set1_epi8('\n');
    const __m512i CR     = _mm512_set1_epi8('\r');
    const __m512i spaces = _mm512_set1_epi8(' ');

    uint64_t index_masks[6] = {
        0xaaaaaaaaaaaaaaaa,
        0xcccccccccccccccc,
        0xf0f0f0f0f0f0f0f0,
        0xff00ff00ff00ff00,
        0xffff0000ffff0000,
        0xffffffff00000000,
    };
    const __m512i index_bits[6] = {
        _mm512_set1_epi8(1),
        _mm512_set1_epi8(2),
        _mm512_set1_epi8(4),
        _mm512_set1_epi8(8),
        _mm512_set1_epi8(16),
        _mm512_set1_epi8(32),
    };

    size_t len;
    for (size_t i=0; i < n; i += 64) {
        const __m512i input  = _mm512_loadu_si512((const __m512i*)(src + i));
        __m512i output;

        uint64_t mask = _mm512_cmpeq_epi8_mask(input, spaces)
                      | _mm512_cmpeq_epi8_mask(input, NL)
                      | _mm512_cmpeq_epi8_mask(input, CR);

        if (mask) {
            len = 64 - __builtin_popcountll(mask);
            mask = ~mask;
            __m512i indices = _mm512_set1_epi8(0);
            for (size_t index = 0; index < 6; index++) {
                uint64_t m = _pext_u64(index_masks[index], mask);
                indices = _mm512_mask_add_epi8(indices, m, indices, index_bits[index]);
            }

            output = _mm512_permutexvar_epi8(indices, input);
        } else {
            output = input;
            len = 64;
        }

        _mm512_storeu_si512((__m512i*)(dst), output);
        dst += len;
    }

    return dst;
}
