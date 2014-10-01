/*
    Specification:

    if x = 0 then
        return 0x00000000
    else if x is power of 2 then
        return 0xffffffff
    else
        -- unspecified
    fi

	Author  : Wojciech Muła
	Date    : 2014-10-01
	License : public domain
*/

#include <stdio.h>
#include <stdint.h>
#include <assert.h>


int is_power_of_two_non_zero(uint32_t x) {
    return (x & -x) == x;
}


// ------------------------------------------------------------------------

uint32_t fill_word_naive(uint32_t x) {
    assert(x == 0 || is_power_of_two_non_zero(x));

    return x ? 0xffffffff : 0;
}


uint32_t fill_word_branchless(uint32_t x) {
    assert(x == 0 || is_power_of_two_non_zero(x));
    
    const uint32_t y = -x;

    return ((int32_t)(y) >> 31);
}


// ------------------------------------------------------------------------


void verify() {
    assert(fill_word_branchless(0) == fill_word_naive(0));

    uint32_t bit = 1;
    for (int i=0; i < 32; i++, bit <<= 1) {
        
        assert(fill_word_branchless(bit) == fill_word_naive(bit));
    }
}


int main() {
    verify();
}
