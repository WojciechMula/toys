#include <immintrin.h>
#include <stdint.h>

#define MAX_INT 2147483647

int decimal_digits_avx512(uint32_t val) {
    const __m512i powers = _mm512_setr_epi32(
       /*  0 */ 9,
       /*  1 */ 99,
       /*  2 */ 999,
       /*  3 */ 9999,
       /*  4 */ 99999,
       /*  5 */ 999999,
       /*  6 */ 9999999,
       /*  7 */ 99999999,
       /*  8 */ 999999999,
       /*  9 */ MAX_INT,
       /* 10 */ MAX_INT,
       /* 11 */ MAX_INT,
       /* 12 */ MAX_INT,
       /* 13 */ MAX_INT,
       /* 14 */ MAX_INT,
       /* 15 */ MAX_INT
    );

    const __m512i value = _mm512_set1_epi32(val);

    const uint16_t m = _mm512_cmple_epu32_mask(value, powers);

    return 1 + __builtin_ctz(m);
}
