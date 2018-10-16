#include "all.h"

#include <cstdio>

class UnitTest {

    static const size_t size = 256;
    uint8_t array[size];
    uint32_t expected;
    bool failed;

public:
    UnitTest() {
        for (size_t i=0; i < size; i++) {
            array[i] = i & 0xff;
        }
        
        expected = scalar_sumbytes(array, size);
        failed = false;
    }

    bool run() {
        test("SSE",              sse_sumbytes);
        test("SSE (sadbw)",      sse_sadbw_sumbytes);
        test("SSE (16bit accu)", sse_16bit_sumbytes);

        return failed;
    }

private:
    template <typename Function>
    void test(const char* name, Function fun) {

        printf("%s... ", name);
        const uint32_t result = fun(array, size);
        if (result == expected) {
            print_ansi("OK", ANSI_GREEN);
        } else {
            failed = true;
            print_ansi("FAILED", ANSI_RED);
            printf(" (expected=%u, result=%u)", expected, result);
        }

        putchar('\n');
    }

private:
    static const int ANSI_RED = 31;
    static const int ANSI_GREEN = 32;

    void print_ansi(const char* str, int color) {
        printf("\033[%dm%s\033[0m", color, str);
    }
};

int main() {

    UnitTest test;

    return test.run() ? EXIT_SUCCESS : EXIT_FAILURE;
}
