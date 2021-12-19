#include "avx512-validate-utf8.h"

namespace {
    const __m512i v_0f = _mm512_set1_epi8(0x0f);
    const __m512i v_10 = _mm512_set1_epi8(0x10);
    const __m512i v_40 = _mm512_set1_epi8(0x40);
    const __m512i v_80 = _mm512_set1_epi8(char(0x80));
    const __m512i v_1f = _mm512_set1_epi8(0x1f);
    const __m512i v_3f = _mm512_set1_epi8(0x3f);
    const __m512i v_c0 = _mm512_set1_epi8(char(0xc0));
    const __m512i v_c2 = _mm512_set1_epi8(char(0xc2));
    const __m512i v_e0 = _mm512_set1_epi8(char(0xe0));
    const __m512i v_f0 = _mm512_set1_epi8(char(0xf0));
    const __m512i v_f8 = _mm512_set1_epi8(char(0xf8));
}

#include <cstdint>
#include <cstdio>

#include "avx512-validate-structure.cpp"
#include "avx512-validate-leading-bytes.cpp"

namespace {
    bool is_continuation(uint8_t b) {
        return (b & 0xc0) == 0x80;
    }
}

bool avx512_validate_utf8__version1(const char* utf8, size_t size) {
    const char* ptr = utf8;
    const char* end = utf8 + size;
    if (size > 0 and is_continuation(utf8[0])) {
        // The vectorized algorithm is not able to detect errors when
        // the input starts with continuation bytes followed by
        // valid sequence of bytes. This single check handles that case.
        return false;
    }

    while (ptr + 64 < end) {
        const __m512i input = _mm512_loadu_si512((const __m512i*)(ptr));
        if (not avx512_validate_utf8_structure(input)) {
            return false;
        }

        const __m512i continuation1 = _mm512_loadu_si512((const __m512i*)(ptr + 1));
        if (not avx512_validate_leading_bytes(input, continuation1, 0x0ffffffffffffffflu)) {
            return false;
        }

        ptr += 60;
    }

    // TODO: process tail
    return true;
}
