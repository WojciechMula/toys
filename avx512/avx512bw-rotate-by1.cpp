#include <cassert>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <immintrin.h>

__m512i _mm512_rotate_by1_epi8(const __m512i input) {

    // lanes order: 1, 2, 3, 0 => 0b00_11_10_01
    const __m512i permuted = _mm512_shuffle_i32x4(input, input, 0x39);

    return _mm512_alignr_epi8(permuted, input, 1);
}

void dump(uint8_t* data, size_t size) {
    for (size_t i=0; i < size; i++) {
        printf("%02x ", data[i]);
        if (i % 16 == 15)
            putchar('|');
    }

    putchar('\n');
}

void validate() {
    uint8_t input[64];
    uint8_t output[64];

    for (int i=0; i < 64; i++) {
        input[i] = i;
    }

    const __m512i v = _mm512_loadu_si512((__m512i*)(input + 0));
    const __m512i res = _mm512_rotate_by1_epi8(v);

    _mm512_storeu_si512((__m512i*)output, res);
    for (int i=0; i < 64; i++) {
        if (output[i] != input[(i + 1) % 64]) {
            printf("input  = "); dump(input, 64);
            printf("output = "); dump(output, 64);
            printf("mistmach at #%d\n", i);
            exit(1);
        }
    }
}

int main() {
    
    validate();
    puts("All OK");
}
