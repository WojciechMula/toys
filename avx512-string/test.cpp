#include <cstdlib>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <cassert>
#include <immintrin.h>

#include "common.h"
#include "avx512f-strlen.cpp"
#include "avx512f-strchr.cpp"
#include "avx512f-strrchr.cpp"
#include "avx512f-strcmp.cpp"


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


bool test_strrchr() {
    const size_t N = 512;
    char buffer[N];

    for (size_t length=0; length < N; length++) {
        for (size_t i=0; i < N; i++) {
            memset(buffer, '?', N);
            buffer[i]      = 'X';
            buffer[length] = 0;

            const char* result   = avx512f_strrchr(buffer, 'X');
            const char* expected = strrchr(buffer, 'X');
            if (result != expected) {
                for (size_t i=0; i < N; i++) {
                    if (buffer[i] != 0)
                        putchar(buffer[i]);
                    else
                        putchar('@');
                }
                        putchar('\n');

                printf("failed: result=%p, expected=%p\n", result, expected);
                return false;
            }
        }
    }

    return true;
}


bool test_strcmp1() {
    const size_t N = 512;
    char buffer1[N];
    char buffer2[N];

    memset(buffer1, '?', N);
    memset(buffer2, '?', N);

    for (size_t l1=0; l1 < N; l1++) {
        for (size_t l2=0; l2 < N; l2++) {
            buffer1[l1] = 0;
            buffer2[l2] = 0;

            const int result   = avx512f_strcmp(buffer1, buffer2);
            const int expected = strcmp(buffer1, buffer2);
            if (result != expected) {
                printf("failed: result=%d, expected=%d\n", result, expected);
                return false;
            }

            buffer1[l1] = '?';
            buffer2[l2] = '?';
        }
    }

    return true;
}


bool test_strcmp2() {
    const size_t N = 128;
    char buffer1[N];
    char buffer2[N];

    memset(buffer1, '?', N);
    memset(buffer2, '?', N);

    for (size_t l1=0; l1 < N; l1++) {
        for (size_t l2=0; l2 < N; l2++) {
            for (size_t x=0; x < N; x++) {
                buffer1[x]  = 'X';
                buffer1[l1] = 0;
                buffer2[l2] = 0;

                const int result   = avx512f_strcmp(buffer1, buffer2);
                const int expected = strcmp(buffer1, buffer2);
                if (result != expected) {
                    printf("failed: result=%d, expected=%d\n", result, expected);
                    return false;
                }

                buffer1[x]  = '?';
                buffer1[l1] = '?';
                buffer2[l2] = '?';
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
    test("strcmp (case 1)", test_strcmp1);
    test("strcmp (case 2)", test_strcmp2);
    test("strrchr", test_strrchr);
    test("strlen (case 1)", test_strlen);
    test("strlen (case 2)", test_strlen2);
    test("strchr", test_strchr);

    puts("All OK");
}
