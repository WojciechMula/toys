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

int main() {
	for (unsigned mask=0; mask < 16; mask++) {

		const uint32_t input  = generate(mask);
		assert((input & 0x7f7f7f7f) == 0);

		const uint32_t result = movmask(input);

		printf("%08x => %x (expected %x)\n", input, result, mask);

		assert(result == mask);
	}
}
