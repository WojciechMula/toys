#include <cstdlib>
#include <cstdio>
#include <cstdint>
#include <cstring>


#include "gettime.cpp"
#include "avx512-sort.cpp"
#include "insertion-sort.cpp"


class Test {

    uint32_t in[16];
    uint32_t out[16];

    const size_t iterations = 10000000;

public:
    template <typename FUNCTION>
    void run(FUNCTION fun) {
        in[0]  = 1000;
        in[1]  = 500;
        in[2]  = 1000;
        in[3]  = 1001;
        in[4]  = 1;
        in[5]  = 400;
        in[6]  = 10000;
        in[7]  = 9400;
        in[8]  = 1400;
        in[9]  = 5400;
        in[10] = 400;
        in[11] = 400;
        in[12] = 400;
        in[13] = 400;
        in[14] = 400;
        in[15] = 400;

        memcpy(out, in, sizeof(in));
        for (size_t i=0; i < iterations; i++) {
            fun(in, in + 16);
        }
    }
};


void avx512_sort(uint32_t* start, uint32_t* /*unused*/) {

    const __m512i input  = _mm512_loadu_si512(start);
    const __m512i sorted = avx512_sort_epi32(input);
    _mm512_storeu_si512(start, sorted);
}


void avx512_sort_unrolled(uint32_t* start, uint32_t* /*unused*/) {

    const __m512i input  = _mm512_loadu_si512(start);
    const __m512i sorted = avx512_sort_epi32_unrolled(input);
    _mm512_storeu_si512(start, sorted);
}


void test_std_sort(uint32_t* start, uint32_t* end) {
    std::sort(start, end);
}


void test_insertion(uint32_t* start, uint32_t* end) {
    insertion_sort(start, end);
}


template <typename FUNCTION>
void measure(const char* name, FUNCTION fun) {

    printf("%s... ", name); fflush(stdout);
    Test test;
    const auto t1 = get_time();
    test.run(fun);
    const auto t2 = get_time();

    const double t = (t2 - t1)/1000000.0;

    printf("%0.2f\n", t);
}


int main() {

    measure("std::sort",                test_std_sort);
    measure("insertion sort",           test_insertion);
    measure("AVX512F sort",             avx512_sort);
    measure("AVX512F sort unrolled",    avx512_sort_unrolled);
}
