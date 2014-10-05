#include <stdio.h>
#include <assert.h>

#include "common.c"
#include "pext.c"

#define packed32(byte) ((uint8_t)(byte) * 0x01010101u)

/*
    input: 4 ASCII chars
    output: 0 .. 15 if 4 chars form a binary string
            -1 otherwise
*/
int nibble_from_string(char* string) {
    // assert(strlen(string) >= 4);

    const uint32_t chars = *((uint32_t*)string);

    // ord('0') = 0x30, ord('1') = 0x31

    if ((chars & packed32(~0x31)) != 0) {
        return -1;
    }

    return pext(bswap(chars), 0x01010101);
}


// ------------------------------------------------------------------------


void to_bin_naive(uint32_t x, char* c) {
    for (int i=3; i >= 0; i--, c++) {
        const uint32_t bit = (1 << i);

        *c = (x & bit) ? '1' : '0';
    }

    *c = 0;
}


void verify() {

    char buf[5];
    for (int x=0; x < 16; x++) {

        to_bin_naive(x, buf);

        const int parsed = nibble_from_string(buf);

        printf("%d => '%s' => %d\n", x, buf, parsed);

        assert(x == parsed);
    }

    buf[0] = '?';
    assert(nibble_from_string(buf) < 0);
}

int main() {
    verify();
}
