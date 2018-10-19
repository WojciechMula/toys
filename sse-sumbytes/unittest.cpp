#include "all.h"

#include <cstdio>

class UnitTest {

    static const size_t size = 256;//1024 * 8;
    uint8_t array[size];
    uint32_t expected;
    bool failed;

public:
    UnitTest() : failed(false) {}
    
    bool run() {

        puts("Fill array with 0x00");
        init(0x00);
        run_all();

        puts("Fill array with 0xff");
        init(0xff);
        run_all();

        puts("Fill array with pseudo-random values");
        init_pseudorandom();
        run_all();

        return failed;
    }

private:
    void run_all() {
        expected = scalar_sumbytes(array, size);
        test("scalar (C++)",             scalar_cpp_sumbytes);
        test("SSE",                      sse_sumbytes);
        test("SSE (v2)",                 sse_sumbytes_variant2);
        test("SSE (sadbw)",              sse_sadbw_sumbytes);
        test("SSE (sadbw 4 x unrolled)", sse_sadbw_unrolled4_sumbytes);
        test("SSE (16bit accu)",         sse_16bit_sumbytes);
        test("SSE (16bit accu, v2)",     sse_16bit_sumbytes_variant2);
        test("SSE (8bit accu)",          sse_8bit_sumbytes);
    }

    void init(uint8_t v) {
        for (size_t i=0; i < size; i++) {
            array[i] = v;
        }
    }

    void init_pseudorandom() {
        for (size_t i=0; i < size; i++) {
            array[i] = (i * 33 + i) & 0xff;
        }
    }

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
