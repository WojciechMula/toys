#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "all.h"

class UnitTests {

    static const size_t size = 1024 * 32;
    uint8_t array[size];
    uint8_t byte;

    struct Failed {};

public:
    bool run() {

        byte = 42;
     
        try {
            case1();
            case2();
            case3();
            case4();

            puts("All OK");
            return true;
        } catch (Failed&) {
            return false;
        }
    }

private:

    void case1() {
        memset(array, 0, size);
        test();
    }

    void case2() {
        memset(array, -1, size);
        test();
    }

    void case3() {
        memset(array, byte, size);
        test();
    }

    void case4() {
        srand(0);
        memset(array, 0, size);
        for (size_t i=0; i < size; i++) {
            if (rand() % 4 == 0)
                array[i] = byte;
        }

        test();
    }

    void test() {
        const uint64_t reference = scalar_count_bytes((const uint8_t*)array, size, byte);
#ifdef HAVE_SSE
        test("SSE", sse_count_byte, reference);
        test("SSE (popcount)", sse_count_byte_popcount, reference);
#endif
#ifdef HAVE_AVX2
        test("AVX2", avx2_count_byte, reference);
        //test("AVX2 (popcount)", avx2_count_byte_popcount, reference);
#endif
#ifdef HAVE_AVX512BW
        test("AVX512", avx512bw_count_bytes, reference);
        test("AVX512 (unrolled)", avx512bw_count_bytes_unrolled, reference);
        test("AVX512 (version 2)", avx512bw_count_bytes__version2, reference);
        test("AVX512 (version 3)", avx512bw_count_bytes__version3, reference);
        test("AVX512 (version 4)", avx512bw_count_bytes__version4, reference);
        test("AVX512 (version 5)", avx512bw_count_bytes__version5, reference);
#endif
    }

    template <typename FUNCTION>
    void test(const char* name, FUNCTION fun, uint64_t reference) {
        const uint64_t result = fun(array, size, byte);
        if (result != reference) {
            printf("%s failed: reference = %lu result = %lu\n", name, reference, result);
            throw Failed{};
        }
    }

};

int main() {

    UnitTests tests;
    tests.run();
}
