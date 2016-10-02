#include <cstdlib>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <cassert>
#include <immintrin.h>

#include "avx512f-strlen.cpp"

bool test_strlen() {
    const size_t N = 512;
    char buffer[N];

    for (size_t length=0; length < N; length++) {
        memset(buffer, '?', N);
        buffer[length] = 0;

        const size_t res = avx512f_strlen(buffer);
        if (res != length) {
            printf("failed: result=%u, expected=%u\n", res, length);
            return false;
        }
    }

    return true;
}


bool test_strlen2() {
    const size_t N = 512;
    char buffer[N];

    for (size_t length=0; length < N; length++) {
        for (size_t i=length + 1; i < N; i++) {
            memset(buffer, '?', N);
            buffer[length] = buffer[i] = 0;

            const size_t res = avx512f_strlen(buffer);
            if (res != length) {
                printf("failed: result=%u, expected=%u\n", res, length);
                return false;
            }
        }
    }

    return true;
}


template <typename TESTFN>
void test(const char* name, TESTFN test) {
    printf("%s... ", name); fflush(stdout);
    if (test()) {
        puts("OK");
    } else {
        puts("FAILED");
        exit(1);
    }
}


int main() {
    test("strlen (case 1)", test_strlen);
    test("strlen (case 2)", test_strlen2);

    puts("All OK");
}
