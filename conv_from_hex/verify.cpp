#include <cstdio>

#include "common.c"
#include "parse.naive.c"
#include "parse.pext.c"
#include "parse.sse2.c"

void verify_naive() {
    char buf[5];

    for (uint32_t i=0; i <= 0xffff; i++) {
        sprintf(buf, "%04x", i);
        assert(parse_naive(buf) == i);

        sprintf(buf, "%04X", i);
        assert(parse_naive(buf) == i);
    }
}


void verify_pext() {
    char buf[5];

    for (uint32_t i=0; i <= 0xffff; i++) {
        sprintf(buf, "%04x", i);
        assert(parse_pext(buf) == i);

        sprintf(buf, "%04X", i);
        assert(parse_pext(buf) == i);
    }
}


void verify_sse_16chars() {
    char buf[17];
    uint64_t result;

    for (int shift=0; shift < (64 - 16); shift++) {
        putchar('.'); fflush(stdout);
        for (uint64_t i=0; i <= 0xffff; i++) {

            const uint64_t input = i << shift;

            sprintf(buf, "%016llx", input);
            result = parse_sse_16chars(buf);
            assert(result == input);
        }
    }
}


void verify_sse_32chars() {
    char buf[17];
    uint128_t result;

    for (int shift=0; shift < (64 - 16); shift++) {
        putchar('.'); fflush(stdout);
        for (uint64_t i=0; i <= 0xffff; i++) {

            const uint64_t input = i << shift;

            sprintf(buf, "%016llx%016llx", input * 33, input);
            result = parse_sse_32chars(buf);
            assert(result.qword[0] == input);
            assert(result.qword[1] == input * 33);
        }
    }
}


void verify() {

    printf("naive..."); fflush(stdout);
        verify_pext();
    puts(" ok");

    printf("PEXT..."); fflush(stdout);
        verify_pext();
    puts(" ok");

    printf("SSE (16 chars)..."); fflush(stdout);
        verify_sse_16chars();
    puts(" ok");

    printf("SSE (32 chars)..."); fflush(stdout);
        verify_sse_32chars();
    puts(" ok");
}


int main() {
    puts("checking...");
    verify();

    puts("all ok");
}
