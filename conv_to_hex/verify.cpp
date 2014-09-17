#include <stdio.h>

#include "conv_to_hex.c"
#include "expand_nibble.c"


void verify_conv_to_hex() {
	union {
		uint32_t dword;
		uint8_t  byte[4];
	} input;

	for (int a=0; a < 16; a++) {

		input.byte[0] = a;
		for (int b=0; b < 16; b++) {

			input.byte[1] = b;
			for (int c=0; c < 16; c++) {

				input.byte[2] = c;
				for (int d=0; d < 16; d++) {

					input.byte[3] = d;

					assert(nibbles_to_hex_naive(input.dword) == nibbles_to_hex_swar(input.dword));
					assert(nibbles_to_hex_naive(input.dword) == nibbles_to_hex_simd(input.dword));
				}
			}
		}
	}
}


void verify_expand() {
    for (uint32_t x = 0; x <= 0xffff; x++) {
        assert(nibble_expand_naive(x) == nibble_expand_mul(x));
        assert(nibble_expand_naive(x) == nibble_expand_simd(x));
    }
}


int main() {
    puts("conversion to hex...");
    verify_conv_to_hex();

    puts("nibble expand...");
    verify_expand();

    puts("all ok!");

    return 0;
}
