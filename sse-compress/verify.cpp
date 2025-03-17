#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <immintrin.h>

#include "scalar.cpp"
#include "simdutf.cpp"
#include "simdutf_ver2.cpp"

template <typename Compress>
bool check_aux(Compress compress) {
    const char in[16] = {char(0x11), char(0x22), char(0x33), char(0x44),
                         char(0x55), char(0x66), char(0x77), char(0x88),
                         char(0x99), char(0xaa), char(0xbb), char(0xcc),
                         char(0xdd), char(0xee), char(0xff), char(0xf1)};
    char want[16];
    char get[16];

    for (uint32_t mask=1; mask <= 0xffff; mask++) {
        mask = 0x7;
        const auto n = __builtin_popcount(uint16_t(~mask));

        memset(get, 0xca, sizeof(want));
        scalar_compress(mask, in, want);

        memset(get, 0xca, sizeof(get));
        compress(mask, in, get);

        if (memcmp(want, get, n) != 0) {
            printf("failed for mask = 0x%04x, popcount=%d\n", mask, n);

            printf("want:");
            for (int i=0; i < 16; i++) {
                printf(" %02x", uint8_t(want[i]));
            }

            putchar('\n');

            printf("got: ");
            for (int i=0; i < 16; i++) {
                printf(" %02x", uint8_t(get[i]));
            }

            putchar('\n');
        }

        break;
    }

    return true;
}

template <typename Compress>
void check(const char* name, Compress compress) {
    printf("%s... ", name);
    fflush(stdout);

    if (check_aux(compress)) {
        puts("OK");
    }
}

int main() {
    check("simdutf", simdutf_compress);
    check("simdutf - variant 2", simdutf_compress2);
}
