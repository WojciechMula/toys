#include <stdint.h>

uint32_t movmask_unsafe(const uint32_t input) {

    assert((input & 0x7f7f7f7f) == 0);

	const uint32_t mult = 0x02040810;

	const uint64_t result = (uint64_t)input * mult;

	return (result >> 32) & 0xff;
}


uint32_t movmask(const uint32_t input) {

    return movmask_unsafe(input & 0x80808080);
}
