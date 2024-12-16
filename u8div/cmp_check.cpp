#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <immintrin.h>

uint32_t sse_lt(uint32_t a, uint32_t b, uint32_t shift) {
    const __m128i shift_u32 = _mm_cvtsi32_si128(shift);
    const __m128i a_u32 = _mm_xor_si128(_mm_cvtsi32_si128(a), shift_u32);
    const __m128i b_u32 = _mm_xor_si128(_mm_cvtsi32_si128(b), shift_u32);

    const __m128i lt = _mm_cmplt_epi8(a_u32, b_u32);

    return _mm_cvtsi128_si32(lt);
}

bool check(uint32_t shift) {
    for (uint32_t a=0; a < 256; a++) {
        for (uint32_t b=0; b < 256; b++) {
            uint32_t got = sse_lt(a, b, shift);
            uint32_t expected = (a < b) ? 0xff : 0;
            if (got != expected) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    for (uint32_t shift=0; shift < 256; shift++)
        if (check(shift)) {
            printf("OK, shift=%d\n", shift);
            break;
        }

}
