#include <cstdio>
#include <cassert>

#include "common.cpp"
#include "parse.naive.cpp"
#include "parse.swar.cpp"
#include "parse.sse.cpp"


void verify() {
    char buf[32];

    for (unsigned i=0; i <= 9999; i++) {
        std::sprintf(buf, "%04d", i);

        const uint32_t result0 = naive(buf);
        const uint32_t result1 = parse1(buf);
        const uint32_t result2 = parse2(buf);
        const uint32_t result3 = parse3(buf);

        std::sprintf(buf, "%016d", i);

        const uint32_t result_sse = parse_sse(buf);

        assert(result0 == i);
        assert(result1 == i);
        assert(result2 == i);
        assert(result3 == i);
        assert(result_sse == i);
    }
}


void verify_sse() {
    char buf[32];

    for (uint32_t shift=0; shift < 64 - 16; shift++) {
        for (uint64_t i=0; i <= 9999; i++) {
            uint64_t ref = i << shift;

            if (std::sprintf(buf, "%016llu", ref) > 16) {
                return;
            }

            const uint64_t result = parse_sse(buf);

            if (result != ref)
            printf("%s => %llu\n", buf, result);

            assert(result == ref);
        }
    }
}


int main() {

    verify();
    verify_sse();

    std::puts("all ok");
}
