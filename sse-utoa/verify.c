#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

#include "procedures.c"

void progress(float x) {
    printf("veryfing %5.2f\r", x * 100);
    fflush(stdout);
}

void verify32() {
    char expected[32];
    char* result;
    for (uint32_t x=0; x <= 99999999; x++) {
        sprintf(expected, "%u", x);

        if (x % 10000 == 0) {
            progress(x/99999999.0);
        }

        result = utoa32_sse(x);
        if (strcmp(expected, result) != 0) {
            printf("utoa32_sse failed, expected = '%s', result = '%s'\n", expected, result);
            exit(1);
        }

        result = utoa32_sse_2(x);
        if (strcmp(expected, result) != 0) {
            printf("utoa32_sse_2 failed, expected = '%s', result = '%s'\n", expected, result);
            exit(1);
        }

        result = utoa64_sse(x);
        if (strcmp(expected, result) != 0) {
            printf("utoa64_sse failed, expected = '%s', result = '%s'\n", expected, result);
            exit(1);
        }
    }

    progress(1.0);
    putchar('\n');
}

int main() {
    verify32();
    puts("All OK");
    return 0;
}
