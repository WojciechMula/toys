/*
    Is power of two - another approach.

	Author  : Wojciech Muła
	Date    : 2014-10-01
	License : public domain
*/

#include <stdio.h>
#include <stdint.h>
#include <assert.h>


// ------------------------------------------------------------------------


uint32_t isolate_lowest_set(uint32_t x) {
    return x & -x;
}

int is_power_of_two_non_zero(uint32_t x) {
    return isolate_lowest_set(x) == x;
}

int is_power_of_two(uint32_t x) {
    return x != 0 && is_power_of_two_non_zero(x);
}


// ------------------------------------------------------------------------

int is_power_of_two_naive(uint32_t x) {
    uint32_t bit = 1;
    for (int i=0; i < 32; i++, bit <<= 1) {
        if (x == bit) {
            return 1;
        }
    }

    return 0;
}

void verify() {
    uint32_t x = 0;
    while (1) {
        if ((x & 0xfffff) == 0) {
            printf("%x\n", x);
        }

        assert(is_power_of_two(x) == is_power_of_two_naive(x));

        x += 1;
        if (x == 0) break;
    }
}


int main() {
    verify();
}
