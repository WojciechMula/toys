#include <cstdio>
#include <cassert>

#include "common.cpp"
#include "parse.naive.cpp"
#include "parse.swar.cpp"


void verify() {
    char buf[5];

    for (unsigned i=0; i <= 9999; i++) {
        std::sprintf(buf, "%04d", i);

        const uint32_t result0 = naive(buf);
        const uint32_t result1 = parse1(buf);
        const uint32_t result2 = parse2(buf);
        const uint32_t result3 = parse3(buf);

        assert(result0 == i);
        assert(result1 == i);
        assert(result2 == i);
        assert(result3 == i);
    }
}


int main() {

    verify();

    std::puts("all ok");
}
