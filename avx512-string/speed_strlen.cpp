#include <cstdlib>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <cassert>
#include <immintrin.h>

#include "gettime.cpp"
#include "avx512f-strlen.cpp"


class Test {

private:
    char* buffer;
    size_t size;

public:
    Test(size_t s)
        : size(s) {

        buffer = new char[s + 64];
        memset(buffer, '?', s + 64);
    }

    ~Test() {
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


template <typename STRLEN>
void measure(const char* name, STRLEN strlen_function) {

    printf("%s", name); fflush(stdout);

    Test test(1024*1024);

    const uint32_t t1 = get_time();
    for (int i=0; i < 10; i++) {
        putchar('.'); fflush(stdout);
        test.run(strlen_function);
    }
    const uint32_t t2 = get_time();

    printf(" %0.4f s\n", (t2 - t1)/1000000.0);
}


int main() {

    measure("strlen", std::strlen);
    measure("AVX512", avx512f_strlen);
}
