#include <cstdlib>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <cassert>
#include <immintrin.h>

#include "gettime.cpp"
#include "avx512f-strlen.cpp"
#include "scalar-strlen.cpp"


class TestCase {

private:
    char* buffer;
    size_t size;

public:
    TestCase(size_t s)
        : size(s) {

        buffer = new char[s + 64];
        memset(buffer, '?', s + 64);
    }

    ~TestCase() {
        delete[] buffer;
    }

public:
    template <typename STRLEN>
    void run(STRLEN strlen_function) {
        for (size_t i=0; i < size; i++) {
            buffer[i] = 0;
            strlen_function(buffer);
            buffer[i] = '?';
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


    template <typename STRLEN>
    void measure(const char* name, STRLEN strlen_function) {

        printf("%-15s [", name); fflush(stdout);

        TestCase test(size);

        const uint32_t t1 = get_time();
        for (size_t i=0; i < iterations; i++) {
            putchar('.'); fflush(stdout);
            test.run(strlen_function);
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

    test.measure("std::strlen",      strlen);
    test.measure("scalar strlen",    scalar_strlen);
    test.measure("AVX512F",          avx512f_strlen);
}
