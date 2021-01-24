#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <immintrin.h>

#define MAX_INT 2147483647

int decimal_digits_sse(int32_t x) {
	assert(x >= 0);

    const __m128i powers_a = _mm_setr_epi32(9, 99, 999, 9999);
    const __m128i powers_b = _mm_setr_epi32(99999, 999999, 9999999, 99999999);
    const __m128i powers_c = _mm_setr_epi32(999999999, MAX_INT, MAX_INT, MAX_INT);

    const __m128i value = _mm_set1_epi32(x);

    // gt0 = [x > 10^1 - 1, x > 10^2 - 1, x > 10^3 - 1, x > 10^4 - 1]
    const __m128i gt0 = _mm_cmpgt_epi32(value, powers_a);

    // gt1 = [x > 10^5 - 1, x > 10^6 - 1, x > 10^7 - 1, x > 10^8 - 1]
    const __m128i gt1 = _mm_cmpgt_epi32(value, powers_b);

    // xmm2 = [x > 10^9 - 1, 0           , 0           , 0           ]
    const __m128i gt2 = _mm_cmpgt_epi32(value, powers_c);

    // convert 3 x int32_t[4] into 2 x int16_t[8]
    const __m128i t0 = _mm_packs_epi32(gt0, gt1);
    const __m128i t1 = _mm_packs_epi32(gt2, _mm_setzero_si128());

    // convert 2 x int16_t[8] into 1 x int8_t[0]
    const __m128i t2 = _mm_packs_epi16(t0, t1);

    // convert int a negated bit mask
    const uint16_t m = ~_mm_movemask_epi8(t2);

    return __builtin_ctz(m) + 1;
}
