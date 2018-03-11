/*
    Is power of two - use instruction BSLR from BMI2

	Author  : Wojciech Muła
	Date    : 2018-11-03
	License : public domain
*/

#include <stdio.h>
#include <stdint.h>
#include <assert.h>


// ------------------------------------------------------------------------

int is_power_of_two(uint32_t x) {
    int32_t result = x;   
    __asm__ volatile (
        "blsr %%eax, %%eax\n      \n" // ZF set when popcount(x) == 1, CF set when x == 0

        // result = (ZF == 1) and (CF == 0)
        "setz %%al              \n"
        "sbb  $0, %%al          \n"
        "movzx %%al, %%eax      \n"
        : "+a" (result)
    );

    return result;
}


// ------------------------------------------------------------------------

int is_power_of_two_naive(uint32_t x) {
    return __builtin_popcount(x) == 1;
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
