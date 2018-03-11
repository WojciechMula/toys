/*

    SSE/AVX: absolute value of difference of two unsigned integers

    Author: Wojciech Muła
    Date: 2018-03-11

*/

#include <stdint.h>
#include <stdio.h>
#include <assert.h>

// --- proof ----------------------------------------------------------------------

int abs(int x) {
    return (x < 0) ? -x : x;
}

int subus(int a, int b) {
    const int d = a - b;

    if (d < 0) {
        return 0;
    } else {
        return d;
    }
}

void proof_uint() {
    for (int a=0; a < 256; a++) {
        for (int b=0; b < 256; b++) {
            const int expected = abs(a - b);
            const int result = subus(a, b) | subus(b, a);
            assert(result == expected);
        }
    }
}

// --- SSE implementation ---------------------------------------------------------

#include <immintrin.h>

__m128i abs_sub_epu8(const __m128i a, const __m128i b) {
    
    const __m128i ab = _mm_subs_epu8(a, b);
    const __m128i ba = _mm_subs_epu8(b, a);
    
    return _mm_or_si128(ab, ba);
}

void test_sse() {
    
    for (int a=0; a < 256; a++) {
        for (int b=0; b < 256; b++) {
            const int expected = abs(a - b);

            const __m128i A = _mm_set1_epi8(a);
            const __m128i B = _mm_set1_epi8(b);
            const __m128i R = abs_sub_epu8(A, B);

            const int result = _mm_extract_epi8(R, 0);
            assert(result == expected);
        }
    }
}

// main

int main() {
    proof_uint();
    puts("proof OK");

    test_sse();
    puts("SSE test passed");
}
