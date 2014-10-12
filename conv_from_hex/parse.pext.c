#include <assert.h>
#include <cstdint>
#include <cstring>

#include "common.c"
#include "pext.c"


#define packed32(b) (uint8_t(b) * 0x01010101)

/*
    Convert 4 hex digits [0-9a-fA-F] to number
*/
uint32_t parse_pext(char* str) {

    assert(strlen(str) >= 4);

    const uint32_t input  = bswap(*reinterpret_cast<uint32_t*>(str));

    const uint32_t letter = input & packed32(0x40);
    const uint32_t shift  = letter >> 3 | letter >> 6; // 9 if char ~ [a-fA-F], 0 otherwise

    const uint32_t adjusted   = input + shift;

    // gather lower nibbles of each byte
    return pext(adjusted, 0x0f0f0f0f);
}
