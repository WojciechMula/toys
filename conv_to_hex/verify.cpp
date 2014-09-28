#include <stdio.h>
#include <string.h>

#include "common.c"
#include "conv_to_hex.c"
#include "expand_nibble.c"


void verify_correctness() {
    union {
        uint32_t dword;
        char     string[9];
    } conv;

    memset(conv.string, 0, sizeof(conv.string));

    char sprintf_result[9];

    for (uint32_t x = 0; x <= 0xffff; x++) {
        const uint32_t nibbles = nibble_expand_naive(x);
        conv.dword = nibbles_to_hex_naive(nibbles);

        sprintf(sprintf_result, "%04x", x);

        assert(strcmp(sprintf_result, conv.string) == 0);
	}
}


void verify_conv_to_hex() {
    for (uint32_t x = 0; x <= 0xffff; x++) {
        const uint32_t nibbles = nibble_expand_naive(x);

        const uint32_t naive = nibbles_to_hex_naive(nibbles);
        const uint32_t swar  = nibbles_to_hex_naive(nibbles);
        const uint32_t simd  = nibbles_to_hex_naive(nibbles);

        assert(naive == swar);
        assert(naive == simd);
	}
}


void verify_expand() {
    for (uint32_t x = 0; x <= 0xffff; x++) {
        const uint32_t naive        = nibble_expand_naive(x);
        const uint32_t handcrafted  = nibble_expand_naive_handcrafted(x);
        const uint32_t mul          = nibble_expand_mul(x);
        const uint32_t simd         = nibble_expand_simd(x);
        const uint32_t pdep         = nibble_expand_pdep(x);

        assert((naive & 0xf0f0f0f0) == 0);

        assert(naive == mul);
        assert(naive == handcrafted);
        assert(naive == simd);
        assert(naive == pdep);
    }
}


int main() {
    puts("preconditions...");
    verify_correctness();

    puts("nibble expand...");
    verify_expand();

    puts("conversion to hex...");
    verify_conv_to_hex();

    puts("all ok!");

    return 0;
}
