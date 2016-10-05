#include <cstdlib>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <cassert>
#include <immintrin.h>

#include "gettime.cpp"
#include "avx512f-strchr.cpp"
#include "scalar-strchr.cpp"


class TestCase {

private:
    char* buffer;
    size_t size;
    volatile size_t count;

public:
    TestCase(size_t s)
        : size(s) {

        buffer = new char[s + 64];
        memset(buffer, '?', s + 64);
        buffer[s - 1] = 0;
    }

    ~TestCase() {
        delete[] buffer;
    }

public:
    template <typename STRCHR>
    void run(STRCHR strchr_function) {
        for (size_t i=0; i < size; i++) {
            buffer[i] = 'X';
            count += int(strchr_function(buffer, 'X') != NULL);
            buffer[i] = '?';
        }
    }


    void run_std_function() {
        for (size_t i=0; i < size; i++) {
            buffer[i] = 'X';
            count += int(strchr(buffer, 'X') != NULL);
            buffer[i] = '?';
        }
    }
};


class Test {

    size_t size;
    size_t iterations;

public:
    Test(size_t size, size_t iterations)
        : size(size)
        , iterations(iterations) {}


    template <typename STRCHR>
    void measure(const char* name, STRCHR strchr_function) {

        printf("%-20s [", name); fflush(stdout);

        TestCase test(size);

        const uint32_t t1 = get_time();
        for (size_t i=0; i < iterations; i++) {
            putchar('.'); fflush(stdout);
            test.run(strchr_function);
        }
        const uint32_t t2 = get_time();

        printf("] %0.4f s\n", (t2 - t1)/1000000.0);
    }


    void measure(const char* name) {

        printf("%-20s [", name); fflush(stdout);

        TestCase test(size);

        const uint32_t t1 = get_time();
        for (size_t i=0; i < iterations; i++) {
            putchar('.'); fflush(stdout);
            test.run_std_function();
        }
        const uint32_t t2 = get_time();

        printf("] %0.4f s\n", (t2 - t1)/1000000.0);
    }
};


int main() {

    Test test(100*1024, 5);

    test.measure("strchr"); // for a mysterious reason GCC is not able to match std::strchr
    test.measure("scalar strchr",    scalar_strchr);
    test.measure("AVX512F",          avx512f_strchr);
}
