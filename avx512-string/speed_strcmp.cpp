#include <cstdlib>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <cassert>
#include <immintrin.h>

#include "gettime.cpp"
#include "common.h"
#include "avx512f-strcmp.cpp"


class TestCase {

private:
    char* buffer1;
    char* buffer2;
    size_t size;
    volatile size_t count;

public:
    TestCase(size_t s)
        : size(s) {

        buffer1 = new char[s + 64];
        buffer2 = new char[s + 64];
        memset(buffer1, '?', s + 64);
        memset(buffer2, '?', s + 64);
        buffer1[s - 1] = 0;
        buffer2[s - 1] = 0;
    }

    ~TestCase() {
        delete[] buffer1;
        delete[] buffer2;
    }

public:
    template <typename STRCMP>
    void run(STRCMP strcmp_function) {
        for (size_t i=0; i < size; i++) {
            buffer1[i] = 'X';
            count += strcmp_function(buffer1, buffer2);
            buffer1[i] = '?';
        }
    }
};


class Test {

    size_t size;
    size_t iterations;
    uint32_t ref_time;

public:
    Test(size_t size, size_t iterations)
        : size(size)
        , iterations(iterations)
        , ref_time(0) {}

    template <typename STRCHR>
    void measure(const char* name, STRCHR strcmp_function) {

        printf("%-20s [", name); fflush(stdout);

        TestCase test(size);

        const uint32_t t1 = get_time();
        for (size_t i=0; i < iterations; i++) {
            putchar('.'); fflush(stdout);
            test.run(strcmp_function);
        }
        const uint32_t t2 = get_time();
        const uint32_t time = t2 - t1;

        printf("] %0.4f s", time/1000000.0);

        if (ref_time == 0) {
            ref_time = time;
        } else {
            printf(" (%0.2f)", ref_time/double(time));
        }

        putchar('\n');
    }
};


int main() {

    Test test(10*1024, 5);

    test.measure("strcmp", strcmp);
    test.measure("AVX512F", avx512f_strcmp);
}
