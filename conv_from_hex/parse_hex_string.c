#include <assert.h>
#include <cstdint>
#include <cstring>

#include "common.c"
#include "pext.c"


#define packed32(b) (uint8_t(b) * 0x01010101)

/*
    Convert 4 hex digits [0-9a-fA-F] to number
*/
uint32_t parse(char* str) {

    assert(strlen(str) >= 4);

    const uint32_t input = bswap(*reinterpret_cast<uint32_t*>(str));

    const uint32_t tmp1  = input & packed32(0x40);
    const uint32_t nine  = tmp1 >> 3 | tmp1 >> 6; // 9 if char ~ [a-fA-F], 0 otherwise

    const uint32_t res   = input + nine;


    return pext(res, 0x0f0f0f0f);
}
