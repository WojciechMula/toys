#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <immintrin.h>

uint8_t sse_div_u8_rcp(uint32_t a, uint32_t b, float a_coef) {
    const __m128i a_u32 = _mm_cvtsi32_si128(a);
    const __m128  a_f32 = _mm_cvtepi32_ps(a_u32);

    const __m128i b_u8  = _mm_cvtsi32_si128(b);
    const __m128i b_u32 = _mm_cvtepu8_epi32(b_u8);
    const __m128  b_f32 = _mm_cvtepi32_ps(b_u32);

    const __m128  b_inv_f32 = _mm_rcp_ps(b_f32);
    const __m128  c_f32 = _mm_mul_ps(_mm_mul_ps(a_f32, _mm_set1_ps(a_coef * 256)), b_inv_f32);
    const __m128i c_i32 = _mm_cvtps_epi32(c_f32);

    const uint32_t buf = _mm_cvtsi128_si32(c_i32);

    return buf >> 8;
}

uint8_t ref[256];


bool check_coef(uint32_t b, float coef) {
    for (uint32_t a=0; a < 256; a++) {
        const uint32_t got = sse_div_u8_rcp(a, b, coef);
        if (got != ref[a]) {
            return false;
        }
    }

    return true;
}


int main() {
    for (uint32_t b=1; b < 256; b++) {
        for (uint32_t a=0; a < 256; a++) {
            ref[a] = a / b;
        }

        bool ok = false;
        float a_shift = 0.0;
        for (a_shift=1.0; a_shift < 2.0; a_shift += 0.00001) {
            if (check_coef(b, a_shift)) {
                ok = true;
                break;
            }
        }

        if (ok) {
            printf("b=%d, a_shift=%0.7f\n", b, a_shift);
        } else {
            printf("b=%d, no solutions found\n", b);
            return EXIT_FAILURE;
        }
    }
}
