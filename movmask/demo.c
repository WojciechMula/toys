#include <stdio.h>
#include <stdint.h>
#include <assert.h>

#include "movmask.c"

uint32_t generate(int x) {
	assert(x >= 0);
	assert(x < 16);

	uint32_t result = 0;

	for (int i=0; i < 4; i++) {
		if (x & (1 << i))
			result |= 1 << (8*i + 7);
	}

	return result;
}


int test32() {
	for (unsigned mask=0; mask < 16; mask++) {

		const uint32_t input  = generate(mask);
		assert((input & 0x7f7f7f7f) == 0);

		const uint32_t result = movmask(input);

        if (result != mask) {
		    printf("%08x => %x (expected %x)\n", input, result, mask);
            return 0;
        }
	}

    return 1;
}


uint64_t generate64(int x) {
	assert(x >= 0);
	assert(x < 256);

	uint64_t result = 0;

	for (int i=0; i < 8; i++) {
		if (x & (1 << i))
			result |= 1lu << (8*i + 7);
	}

	return result;
}


int test64() {
	for (unsigned mask=0; mask < 256; mask++) {

		const uint64_t input  = generate64(mask);
		assert((input & 0x7f7f7f7f7f7f7f7flu) == 0);

		const uint64_t result = movmask64(input);

        if (result != mask) {
            printf("%016lx => %lx (expected %x)\n", input, result, mask);
            return 0;
        }
	}

    return 1;
}


int main() {
    int result = 0;
    puts("testing 32-bit code...");
    result = test32() || result;

    puts("testing 64-bit code...");
    result = test64() || result;
 
    puts(result ? "OK" : "FAILED");
}
