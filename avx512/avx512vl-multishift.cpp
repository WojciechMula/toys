/*
    This is just a software implementation of instruction
    VPMULTISHIFTQB (Select Packed Unaligned Bytes from Quadword Sources)
*/

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <immintrin.h>

namespace internal {

    uint8_t getbyte(uint64_t x, uint8_t index) {
        index = index & 0x7f; // index = 0..63

        if (index < 64 - 8) {
            return (x >> index) & 0xff;
        } else {
            return ((x >> index) | (x << (64 - index))) & 0xff;
        }
    }

    uint64_t mshift_lane(uint64_t x, uint8_t* indices) {
        
        // assert: len(indices) = 8

        union {
            uint64_t result;
            uint8_t  bytes[8];
        };

        for (int i=0; i < 8; i++) {
            bytes[i] = getbyte(x, indices[i]);
        }

        return result;
    }

}


__m512i vpmultishiftqb_emu(__m512i in) {

    union {
        uint64_t qword[8];
        uint8_t  bytes[64];
    };

    _mm512_storeu_si512((__m512i*)qword, in);
    for (int i=0; i < 8; i++) {
        qword[i] = internal::mshift_lane(qword[i], bytes + i*8);
    }

    return _mm512_loadu_si512((__m512i*)qword);
}


void test_internal() {
    for (int shift=57; shift < 64; shift++) {
        for (uint64_t i=0; i < 256; i++) {
            uint64_t x = i << shift;
            if (shift > 64 - 8) {
                x = x | (i >> (8 - shift % 8));
            }

            const uint8_t expected = i;
            const uint8_t result   = internal::getbyte(x, shift);

            if (expected != result) {
                printf("failed for shift=%d, value=%016llx\n", shift, x);
                printf("expected result is %x, function returned %x\n", expected, result);
                assert(false);
            }
        }
    }
}


int main() {
    test_internal();
}
