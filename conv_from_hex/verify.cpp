#include <cstdio>

#include "parse_hex_string.c"

void verify() {
    char buf[5];

    for (uint32_t i=0; i <= 0xffff; i++) {

        sprintf(buf, "%04x", i);
        assert(parse(buf) == i);

        sprintf(buf, "%04X", i);
        assert(parse(buf) == i);
    }
}


int main() {
    verify();

    puts("all ok");
}
