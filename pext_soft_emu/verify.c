#include <assert.h>
#include <stdio.h>

#include "pext.c"

char get_bit(uint32_t v, int bit) {
    const uint32_t mask = ((uint32_t)(1) << bit);

    return (v & mask) != 0;
}


uint32_t assign_bit(uint32_t v, int bit, int value) {
    const uint32_t mask = ((uint32_t)(1) << bit);
    
    if (value) {
        return v | mask;
    } else {
        return v & ~mask;
    }
}


uint32_t pext_naive(uint32_t src, uint32_t mask) {

    uint32_t result = 0;

    int k = 0;
    for (int i=0; i < 32; i++) {
        const char bit = get_bit(mask, i);
        if (bit) {
            result = assign_bit(result, k, get_bit(src, i));
            k += 1;
        }
    }

    return result;
}


void verify() {
    uint32_t src  = 0;
    uint32_t mask = 0;

    for (int i=0; i < 100000000; i++) {
        if (i % 0xffff == 0)
            printf("%d\n", i);

        assert(pext_naive(src, mask) == pext(src, mask));

        src  += 11;
        mask += 33;
    }
}


int main() {
    
    verify();
}
