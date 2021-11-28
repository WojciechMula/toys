#include "utf8.h"

int utf8_bytes(uint32_t value, uint8_t* byte) {
    if (value <= 0x7f) {
        byte[0] = value;
        return 1;
    }

    if (value <= 0x7ff) {
        byte[0] = (value >> 6) | 0xc0;
        byte[1] = (value & 0x3f) | 0x80;
        return 2;
    }

    if (value <= 0xffff) {
        byte[0] = (value >> 12) | 0xe0;
        byte[1] = ((value >> 6) & 0x3f) | 0x80;
        byte[2] = (value & 0x3f) | 0x80;
        return 3;
    }

    // assert value <= 0x10ffff
    byte[0] = (value >> 18) | 0xf0;
    byte[1] = ((value >> 12) & 0x3f) | 0x80;
    byte[2] = ((value >> 6) & 0x3f) | 0x80;
    byte[3] = (value & 0x3f) | 0x80;
    return 4;
}

uint32_t utf8_bytes(uint32_t value) {
    union {
        uint32_t word;
        uint8_t byte[4];
    };

    word = 0xcccccccc;

    utf8_bytes(value, byte);
    return word;
}
