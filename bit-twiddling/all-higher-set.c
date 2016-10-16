/*
    Check whether a bit mask contains a sequence of zeros
    followed by a sequence ones.
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

int is_pattern(uint16_t x) {
    const uint16_t n = -x;
    return (x > 0) && n == (n & x);
}


int is_pattern_naive(uint16_t x) {
    if (x == 0) {
        return 0;
    }

    while (x > 0) {
        if ((x & 0x8000) == 0) {
            return 0;
        }

        x <<= 1;
    }

    return 1;
}


void verify() {
    for (int i=0; i < 65536; i++) {
        int expected = is_pattern_naive(i);
        int result   = is_pattern(i);
        if (expected != result) {
            printf("failed for %04x: result %d, expected %d\n", i, result, expected);
            exit(1);
        }

        if (result) {
            printf("pattern: %04x\n", i);
        }
    }
}


int main() {
    verify();
    puts("All OK");
}
