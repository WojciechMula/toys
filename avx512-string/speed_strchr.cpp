#include <cstdlib>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <cassert>
#include <immintrin.h>

#include "gettime.cpp"
#include "avx512f-strchr.cpp"


class Test {

private:
    char* buffer;
    size_t size;

public:
    Test(size_t s)
        : size(s) {

        buffer = new char[s + 64];
        memset(buffer, '?', s + 64);
        buffer[s - 1] = 0;
    }

    ~Test() {
        delete[] buffer;
    }

public:
    template <typename STRCHR>
    void run(STRCHR strchr_function) {
        for (size_t i=0; i < size; i++) {
            buffer[i] = 'X';
            strchr_function(buffer, int('X'));
            buffer[i] = '?';
        }
    }


    void run_std_function() {
        for (size_t i=0; i < size; i++) {
            buffer[i] = 'X';
            strchr(buffer, int('X'));
            buffer[i] = '?';
        }
    }
};


template <typename STRCHR>
void measure(const char* name, STRCHR strchr_function) {

    printf("%-10s [", name); fflush(stdout);

    Test test(1*1024);

    const uint32_t t1 = get_time();
    for (int i=0; i < 10; i++) {
        putchar('.'); fflush(stdout);
        test.run(strchr_function);
    }
    const uint32_t t2 = get_time();

    printf("] %0.4f s\n", (t2 - t1)/1000000.0);
}


void measure(const char* name) {

    printf("%-10s [", name); fflush(stdout);

    Test test(100*1024);

    const uint32_t t1 = get_time();
    for (int i=0; i < 10; i++) {
        putchar('.'); fflush(stdout);
        test.run_std_function();
    }
    const uint32_t t2 = get_time();

    printf("] %0.4f s\n", (t2 - t1)/1000000.0);
}


int main() {

    measure("strchr"); // for a mysterious reason GCC is not able to match std::strchr
    measure("AVX512F", avx512f_strchr);
}
