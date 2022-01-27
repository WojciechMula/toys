#include <cstdio>
#include <cstdlib>
#include <vector>

#include "algorithm1.h"
#include "algorithm2.h"
#include "geoff_algorithm.h"


char nibble2hex(uint64_t val) {
    switch (val) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            return val + '0';

        case 10:
            return 'a';
        case 11:
            return 'B';
        case 12:
            return 'c';
        case 13:
            return 'D';
        case 14:
            return 'e';
        case 15:
            return 'F';
    }

    abort();
    return 0;
}


template <typename FN>
bool validate(const char* name, FN function) {
    char ascii[17];

    printf("%-10s: ", name);
    fflush(stdout);

    const std::vector<uint64_t> testcases = {
        0x1023456789abcdeflu, 0xa23121bcef, 0x11112222ffff, 0, 1
    };
    for (const uint64_t expected: testcases) {
        snprintf(ascii, 17, "%016lx", expected);
        bool ok = false;
        const uint64_t result = function(ascii, ok);
        if (not ok) {
            puts("input is valid, procedure detected error");
            return false;
        }

        if (expected != result) {
            puts("");
            printf("expected = %016lx\n", expected);
            printf("got      = %016lx\n", result);
            puts("wrongly parsed number");
            return false;
        }
    }


    for (int position=0; position < 16; position++) {
        for (int i=0; i < 16; i++) {
            ascii[i] = '0';
        }

        for (uint64_t nibble=0; nibble < 16; nibble++) {
            ascii[position] = nibble2hex(nibble);

            const uint64_t expected = nibble << (4*(15 - position));

            bool ok = false;
            const uint64_t result = function(ascii, ok);
            if (not ok) {
                puts("input is valid, procedure detected error");
                return false;
            }

            if (expected != result) {
                puts("");
                printf("expected = %016lx\n", expected);
                printf("got      = %016lx\n", result);
                puts("wrongly parsed number");
                return false;
            }
        }
    }

    puts("OK");
    return true;
}

bool run() {
    bool ret = true;

    ret = validate("Algorithm #1", hex_to_u64_sse_v1) and ret;
    ret = validate("Algorithm #2", hex_to_u64_sse_v2) and ret;
    ret = validate("Geoff's algorithm", hex_to_u64_sse_geoff) and ret;

    return ret;
}

int main() {
    if (not run()) {
        return EXIT_FAILURE;
    }

    puts("All OK");
    return EXIT_SUCCESS;
}
