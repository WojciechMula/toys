#include <stdint.h>

uint32_t movmask(const uint32_t input) {
	const uint32_t mult = 0x02040810;

	const uint64_t result = (uint64_t)input * mult;

	return (result >> 32) & 0xff;
}
