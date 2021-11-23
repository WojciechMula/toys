#include "itoa_divless_sse_v2.h"

#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>

int main() {
    char result[17];
    memset(result, 0, sizeof(result));

    char expected[17];
    memset(expected, 0, sizeof(expected));

    const std::vector<uint32_t> quick_test{
        uint32_t(0),
        uint32_t(1),
        uint32_t(0xff),
        uint32_t(0xff) + 1,
        uint32_t(0xffff),
        uint32_t(0xffff) + 1,
        uint32_t(0xffffff),
        uint32_t(0xffffff) + 1,
        uint32_t(0xffffffff)};

    for (const uint32_t x: quick_test) {

        itoa_divless_sse_v2(x, result);
        sprintf(expected, "%016u", x);
        if (memcmp(result, expected, 16) != 0) {
            printf("FAILED for %u\n", x);
            printf("expected = '%s'\n", expected);
            printf("result   = '%s'\n", result);
            return EXIT_FAILURE;
        }
    }

    const int interval = 1000000;
    int k = interval;
    for (uint64_t i=0; i <= 0xffffffff; i++) {
        const uint32_t x = i;

        itoa_divless_sse_v2(x, result);
        sprintf(expected, "%016u", x);
        if (memcmp(result, expected, 16) != 0) {
            printf("FAILED for %u\n", x);
            printf("expected = '%s'\n", expected);
            printf("result   = '%s'\n", result);
            return EXIT_FAILURE;
        }

        k -= 1;
        if (k == 0) {
            const double prog = double(x) * 100 / double(0xffffffff);
            printf("%6.2f%%\r", prog);
            fflush(stdout);
            k = interval;
        }
    }

    puts("");
    puts("All OK");
    return EXIT_SUCCESS;
}
