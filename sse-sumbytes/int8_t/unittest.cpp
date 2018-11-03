#include "all.h"

#include <cstdio>

class UnitTest {

    static const size_t size = 1024 * 8;
    int8_t array[size];
    int32_t expected;
    bool failed;

public:
    UnitTest() : failed(false) {}
    
    bool run() {

        puts("Fill array with 0x00");
        init(0x00);
        run_all();

        puts("Fill array with -127");
        init(-127);
        run_all();

        puts("Fill array with pseudo-random values");
        init_pseudorandom();
        run_all();

        return failed;
    }

private:
    void run_all() {
        expected = scalar_sumsignedbytes(array, size);
        test("scalar (C++)",             scalar_cpp_sumsignedbytes);
        test("SSE",                      sse_sumsignedbytes);
        test("SSE (v2)",                 sse_sumsignedbytes_variant2);
        test("SSE (sadbw)",              sse_sadbw_sumsignedbytes);
        test("SSE (sadbw, unrolled)",    sse_sadbw_unrolled4_sumsignedbytes);
#ifdef HAVE_AVX2
        test("AVX2",                     avx2_sumsignedbytes);
        test("AVX2 (v2)",                avx2_sumsignedbytes_variant2);
#endif
    }

    void init(int8_t v) {
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
        const int32_t result = fun(array, size);
        if (result == expected) {
            print_ansi("OK", ANSI_GREEN);
        } else {
            failed = true;
            print_ansi("FAILED", ANSI_RED);
            printf(" (expected=%d, result=%d)", expected, result);
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
