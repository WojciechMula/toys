#include "all.h"

#include <cstdio>

class UnitTest {

    static const size_t size = 1024 * 8;
    uint16_t array[size];
    uint32_t expected;
    bool failed;

public:
    UnitTest() : failed(false) {}

    bool run() {

        puts("Fill array with 0x0000");
        init(0x0000);
        run_all();

        puts("Fill array with 0xffff");
        init(0xffff);
        run_all();

        puts("Fill array with pseudo-random values");
        init_pseudorandom();
        run_all();

        return failed;
    }

private:
    void run_all() {
        expected = scalar_sumwords(array, size);
        test("scalar (C++)",           scalar_cpp_sumwords);
        test("SSE",                    sse_sumwords);
        test("SSE (v2)",               sse_sumwords_variant2);
        test("SSE (sadbw)",            sse_sadbw_sumwords);
        test("SSE (sadbw-v2)",         sse_sadbw_sumwords_variant2);
        test("SSE (sadbw, unrolled)",  sse_sadbw_unrolled4_sumwords);
#ifdef HAVE_AVX2
        test("AVX2",                   avx2_sumwords);
        test("AVX2 (v2)",              avx2_sumwords_variant2);
        test("AVX2 (sadbw)",           avx2_sadbw_sumwords);
        test("AVX2 (sadbw-v2)",        avx2_sadbw_sumwords_variant2);
        test("AVX2 (sadbw, unrolled)", avx2_sadbw_unrolled4_sumwords);
        test("AVX2 (madd)",            avx2_madd_sumwords);
#endif
    }

    void init(uint16_t v) {
        for (size_t i=0; i < size; i++) {
            array[i] = v;
        }
    }

    void init_pseudorandom() {
        for (size_t i=0; i < size; i++) {
            array[i] = (i * 33 + i) & 0xffff;
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
