#include <cstdlib>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <cassert>
#include <immintrin.h>

#include "avx512f-strlen.cpp"
#include "avx512f-strchr.cpp"
#include "avx512f-strfind.cpp"


bool test_strlen() {
    const size_t N = 512;
    char buffer[N];

    for (size_t length=0; length < N; length++) {
        memset(buffer, '?', N);
        buffer[length] = 0;

        const size_t res = avx512f_strlen(buffer);
        if (res != length) {
            printf("failed: result=%lu, expected=%lu\n", res, length);
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
                printf("failed: result=%lu, expected=%lu\n", res, length);
                return false;
            }
        }
    }

    return true;
}


bool test_strchr() {
    const size_t N = 512;
    char buffer[N];

    for (size_t length=0; length < N; length++) {
        for (size_t i=length + 1; i < N; i++) {
            memset(buffer, '?', N);
            buffer[length] =  0;
            buffer[i] =  'X';

            const char* result   = avx512f_strchr(buffer, 'X');
            const char* expected = strchr(buffer, 'X');
            if (result != expected) {
                printf("failed: result=%p, expected=%p\n", result, expected);
                return false;
            }
        }
    }

    return true;
}


bool test_strfind() {
    const size_t N = 512;
    char buffer[N];

    const char*  needle = "kitten";
    const size_t n      = strlen(needle);

    for (size_t pos=0; pos < N - n; pos++) {
        memset(buffer, '?', N);

        for (size_t i=0; i < n; i++) {
            buffer[pos + i] = needle[i];
        }

        const size_t result   = avx512f_strfind_gt4(buffer, N/64, needle, n);
        const size_t expected = pos;
        if (result != expected) {
            printf("failed: result=%lu, expected=%lu\n", result, expected);
            return false;
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
    test("strfind", test_strfind);
    test("strlen (case 1)", test_strlen);
    test("strlen (case 2)", test_strlen2);
    test("strchr", test_strchr);

    puts("All OK");
}
