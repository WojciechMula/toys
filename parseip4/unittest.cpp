#include <cassert>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <vector>

#include "common.h"
#include "naive.cpp"
#include "sse.cpp"

struct testcase {
    std::string ipv4;
    int err;
    std::string name;
};

template <typename T>
bool test_wrong_input(T procedure) {
    std::vector<testcase> testcases = {
        {"ip", errTooShort, "string too short"},
        {"123.123.123.124    ", errTooLong, "string too long"},
        {"a.0.0.0", errWrongCharacter, "not a digit (1)"},
        {"0.z.0.0", errWrongCharacter, "not a digit (2)"},
        {"0.0.?.0", errWrongCharacter, "not a digit (3)"},
        {"0.0.0.%", errWrongCharacter, "not a digit (4)"},
        {"1.2.3.4.5", errTooManyFields, "too many dots"},
        {"192.168.10", errTooFewFields, "too few dots"},
        {"1.2.3.400", errTooBig, "too big number"},
        {"192.2..4", errEmptyField, "too few chars"},
        {"1.2.11111.4", errTooManyDigits, "too many chars"},
    };

    for (const auto& tc: testcases) {
        const auto res = procedure(tc.ipv4);
        if (res.err != tc.err) {
            printf("got : %d\n", res.err);
            printf("want: %d\n", tc.err);
            printf("%s: wrong result\n", tc.name.c_str());
            assert(false);
        }
    }

    return true;
}

std::string ipv4str(uint32_t x) {
    char tmp[16];
    sprintf(tmp, "%d.%d.%d.%d", (x >> 24), (x >> 16) & 0xff, (x >> 8) & 0xff, x & 0xff);

    return tmp;
}


template <typename T>
bool test_valid_inputs(T procedure) {
    int i = 0;
    for (uint64_t tmp = 0; tmp <= 0xffffffff; tmp += 1031) {
        uint32_t ipv4 = tmp;
        const std::string img = ipv4str(ipv4);

        const auto res = procedure(img);
        if (res.err != 0) {
            printf("IPv4: %s\n", img.c_str());
            printf("hex : %04x\n", ipv4);
            printf("classified as invalid: err code=%d\n", res.err);
            return false;
        }

        if (res.ipv4 != uint32_t(ipv4)) {
            printf("IPv4: %s\n", img.c_str());
            printf("got : %08x\n", res.ipv4);
            printf("want: %08x\n", ipv4);
            printf("wrongly parsed\n");
            return false;
        }

        i++;
    }

    return true;
}

int main() {
    srand(0);

    bool ok = true;
    ok = test_wrong_input(naive_parse_ipv4) && ok;
    ok = test_valid_inputs(naive_parse_ipv4) && ok;
    ok = test_wrong_input(sse_parse_ipv4) && ok;
    ok = test_valid_inputs(sse_parse_ipv4) && ok;
    ok = test_wrong_input(sse_parse_ipv4_v2) && ok;
    ok = test_valid_inputs(sse_parse_ipv4_v2) && ok;

    if (ok) {
        puts("All OK");
    }
}
