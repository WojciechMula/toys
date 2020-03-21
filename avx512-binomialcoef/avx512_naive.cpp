#include "precalc_factors.cpp"
#include <immintrin.h>

uint64_t avx512_binom_aux(uint64_t n, uint64_t p);

uint64_t avx512_binom_scalar(uint64_t n, uint64_t k) {
    assert(n > 1);
    assert(k > 1);
    assert(k < n);

    if (k <= (n - k))
        return avx512_binom_aux(n, k);
    else
        return avx512_binom_aux(n, n - k);
}

uint64_t int_power(uint64_t val, uint8_t power) {
    if (power == 1)
        return val;

    uint64_t x = val;
    uint64_t result = 1;
    while (power > 0) {
        if (power & 0x01)
            result *= x;
        
        x = x * x;
        power >>= 1;
    }

    return result;
}

uint64_t avx512_binom_aux(uint64_t n, uint64_t p) {
    __m512i vnum   = _mm512_setzero_si512();
    __m512i vdenom = _mm512_setzero_si512();
    
    // multiply
    for (uint64_t i=0; i < p; i++) {
        const uint64_t num_coef   = n - p + (i + 1);
        const uint64_t denom_coef = i + 1;

        vnum   = _mm512_add_epi8(vnum,
                                 _mm512_loadu_si512((const __m512i*)(avx512binom::factors[num_coef - 1])));
        vdenom = _mm512_add_epi8(vdenom,
                                 _mm512_loadu_si512((const __m512i*)(avx512binom::factors[denom_coef - 1])));
    }

    // divide num/denom
    const __m512i tmp = _mm512_sub_epi8(vnum, vdenom);
    int8_t coef[64];
    _mm512_store_si512((__m512i*)coef, tmp);

    // get back from the product of factorials into the integer domain
    uint64_t num   = 1;
    uint64_t denom = 1;
    for (int i=0; i < 64; i++) {
        if (coef[i] > 0)
            num *= int_power(avx512binom::primes[i], coef[i]);
        else if (coef[i] < 0)
            denom *= int_power(avx512binom::primes[i], -coef[i]);
    }

    return num / denom;
}
