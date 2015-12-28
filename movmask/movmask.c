#include <stdint.h>
#include <stdint.h>

uint32_t movmask_unsafe(const uint32_t input) {

    assert((input & 0x7f7f7f7f) == 0);

	const uint32_t mult = 0x02040810;

	const uint64_t result = (uint64_t)input * mult;

	return (result >> 32) & 0x0f;
}


uint32_t movmask(const uint32_t input) {

    return movmask_unsafe(input & 0x80808080);
}


uint64_t movmask64_unsafe(const uint64_t input) {

    assert((input & 0x7f7f7f7f7f7f7f7flu) == 0);

    const uint64_t mult = (1lu << (1*8 - 0))
                        | (1lu << (2*8 - 1))
                        | (1lu << (3*8 - 2))
                        | (1lu << (4*8 - 3))
                        | (1lu << (5*8 - 4))
                        | (1lu << (6*8 - 5))
                        | (1lu << (7*8 - 6))
                        | (1lu << (8*8 - 7))
                        ;

    const unsigned __int128 result = (unsigned __int128)mult * (unsigned __int128)input;

    return (result >> 64) & 0xff;
}


uint64_t movmask64(const uint64_t input) {

    return movmask64_unsafe(input & 0x8080808080808080lu);
}
