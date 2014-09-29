/*
	Convert to octal representation - verify different implementations

	Author  : Wojciech Muła
	Date    : 2014-09-28
	License : BSD
*/


#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "common.c"
#include "conv.swar.c"
#include "conv.pdep.c"
#include "conv.sse2.c"


void verify_correcteness() {
    uint32_t buf_result[2];
    char buf_expected[5];

    buf_result[0] = buf_result[1] = 0;

    for (uint32_t i=0; i <= 0xfff; i++) {
        sprintf(buf_expected, "%04o", i);

        buf_result[0] = to_oct_naive(i);

        if (strcmp((char*)buf_result, buf_expected) != 0) {
            printf("'%s' != '%s'\n", buf_expected, (char*)buf_result);
            assert(0);
        }
    }
}


void verify() {
    for (uint32_t i=0; i <= 0xfff; i++) {
        const uint32_t naive = to_oct_naive(i);
        const uint32_t mul   = to_oct_mul(i);
        const uint32_t pdep  = to_oct_pdep(i);
        const uint64_t sse2  = to_oct_sse2(i | (i << 12));

        const uint32_t sse2_lo = (uint32_t)sse2;
        const uint32_t sse2_hi = (uint32_t)(sse2 >> 32);

        assert(naive == mul);
        assert(naive == pdep);
        assert(naive == sse2_lo);
        assert(naive == sse2_hi);
    }
}


int main() {
    verify_correcteness();
    verify();

    puts("all ok");

    return 0;
}
