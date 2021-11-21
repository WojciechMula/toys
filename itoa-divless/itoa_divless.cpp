#include "itoa_divless.h"

#include "itoa_divless_table.h"

#include <cassert>

void itoa_divless(uint32_t x, char* buffer) {
    union {
        uint64_t qword[2];
        uint8_t bytes[16];
    };

    qword[0] = qword[1] = 0;

    // 1. obtain BCD representation of all bytes
    {
        const uint8_t byte0 = x & 0xff;
        qword[1] += *(uint64_t*)&lookup0[byte0][0];
    }
    {
        const uint8_t byte1 = (x >> 8) & 0xff;
        qword[1] += *(uint64_t*)&lookup1[byte1][0];
    }
    {
        const uint8_t byte2 = (x >> 16) & 0xff;
        qword[0] += *(uint64_t*)&lookup2[byte2][0];
        qword[1] += *(uint64_t*)&lookup2[byte2][8];
    }
    {
        const uint8_t byte3 = (x >> 24) & 0xff;
        qword[0] += *(uint64_t*)&lookup3[byte3][0];
        qword[1] += *(uint64_t*)&lookup3[byte3][8];
    }
    
    // 2. fixup BCD & store result
    uint8_t carry = 0;
    for (int i=15; i >= 0; i--) {
        const uint8_t byte = bytes[i] + carry;
        if (byte >= 30) {
            buffer[i] = byte - 30 + '0';
            carry = 3;
        } else if (byte >= 20) {
            buffer[i] = byte - 20 + '0';
            carry = 2;
        } else if (byte >= 10) {
            buffer[i] = byte - 10 + '0';
            carry = 1;
        } else {
            buffer[i] = byte + '0';
            carry = 0;
        }
    }
}
