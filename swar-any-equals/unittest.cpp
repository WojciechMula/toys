#include <cstdio>
#include <cstdint>
#include <cstdlib>

#include "reference.h"
#include "better.h"

char chars[] = "@/?\\abcdefgh\xff\x81";

uint8_t randchar() {
    return chars[rand() % sizeof(chars)];
}

int main() {
    const int count = 10000000;
    uint64_t word = 0;

    unsigned int seed = 42;
    srand(seed);
    bool ok = true;
    for (int i=0; i < count; i++) {
        const auto want = find_authority_delimiter_special_reference(word);
        const auto got  = find_authority_delimiter_special_better(word);

        if (want != got) {
            printf("case %d, value %016lx\n", i, word);
            printf("got : %d\n", got);
            printf("want: %d\n", want);
            ok = false;
        }

        word = 0;
        for (int j=0; j < 8; j++) {
            uint64_t x = randchar();
            word = (word << 8) | x;
        }
    }

    if (ok) {
        puts("All OK");
    }
}
