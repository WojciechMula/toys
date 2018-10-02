#include <cstdio>
#include <cassert>

#include "all.h"

class Unittest {
    
    static const size_t size = 256;
    int32_t array[size];

    class TestFailed {};

public:
    bool run() {
        try {
            test_case1("scalar",        min_index_scalar);
            test_case1("SSE",           min_index_sse);
            test_case1("SSE unrolled",  min_index_sse_unrolled);
#ifdef HAVE_AVX2
            test_case1("AVX2",          min_index_avx2);
#endif
#ifdef HAVE_AVX512
            test_case1("AVX512F",       min_index_avx512f);
#endif

            test_case2("scalar",        min_index_scalar);
            test_case2("SSE",           min_index_sse);
            test_case2("SSE unrolled",  min_index_sse_unrolled);
#ifdef HAVE_AVX2
            test_case2("AVX2",          min_index_avx2);
#endif
#ifdef HAVE_AVX512
            test_case2("AVX512F",       min_index_avx512f);
#endif

            test_case3("scalar",        min_index_scalar);
            test_case3("SSE",           min_index_sse);
            test_case3("SSE unrolled",  min_index_sse_unrolled);
#ifdef HAVE_AVX2
            test_case3("AVX2",          min_index_avx2);
#endif
#ifdef HAVE_AVX512
            test_case3("AVX512F",       min_index_avx512f);
#endif
        } catch (TestFailed&) {
            return false;
        }

        return true;
    }

private:
    template <typename FUN>
    void test_case1(const char* name, FUN f) {

        printf("Testing %15s [case 1]... ", name); fflush(stdout);

        for (size_t i = 0; i < size; i++) {
            prepare(i);
            const size_t result = f(array, size);
            if (result != i) {
                print_ansi("failed\n", ANSI_RED);
                printf("expected %lu, result %lu\n", i, result);
                throw TestFailed();
            }
        }

        print_ansi("OK\n", ANSI_GREEN);
    }

    template <typename FUN>
    void test_case2(const char* name, FUN f) {

        printf("Testing %15s [case 2]... ", name); fflush(stdout);

        for (size_t i = 0; i < size; i++) {
            for (size_t j = i + 1; j < size; j++) {
                prepare(i, j);
                const size_t result = f(array, size);
                if (result != i) {
                    print_ansi("failed\n", ANSI_RED);
                    printf("expected %lu, result %lu\n", i, result);
                    throw TestFailed();
                }
            }
        }

        print_ansi("OK\n", ANSI_GREEN);
    }

    template <typename FUN>
    void test_case3(const char* name, FUN f) {

        printf("Testing %15s [case 3]... ", name); fflush(stdout);

        fill(-1);
        const size_t expected = 0;
        const size_t result = f(array, size);
        if (result != expected) {
            print_ansi("failed\n", ANSI_RED);
            printf("expected %lu, result %lu\n", expected, result);
            throw TestFailed();
        }

        print_ansi("OK\n", ANSI_GREEN);
    }

private:
    static const int ANSI_RED = 31;
    static const int ANSI_GREEN = 32;
    
    void print_ansi(const char* str, int color) {
        printf("\033[%dm%s\033[0m", color, str);
    }


private:
    void prepare(int min_index) {
        fill(1000);
        array[min_index] = -42;
    }

    void prepare(int min_index1, int min_index2) {

        assert(min_index1 != min_index2);

        fill(1000);
        array[min_index1] = -42;
        array[min_index2] = -42;
    }

    void fill(int32_t val) {
        for (size_t i=0; i < size; i++)
            array[i] = val;
    }
};


int main() {
    
    Unittest tests;

    return tests.run() ? EXIT_SUCCESS : EXIT_FAILURE;
}
