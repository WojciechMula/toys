#include <cstdlib>
#include <cstdio>
#include <cstdint>
#include <cstring>


#include "gettime.cpp"
#include "avx512-sort.cpp"
#include "insertion-sort.cpp"


template <unsigned N>
class Test {

    static_assert(N == 16 || N == 32, "N has got invalid value");

    uint32_t in[N];
    uint32_t out[N];

    const size_t iterations = 10000000;

public:
    template <typename FUNCTION>
    void run(FUNCTION fun) {

        for (int i=0; i < N; i++) {
            in[i] = rand();
        }

        memcpy(out, in, sizeof(in));
        for (size_t i=0; i < iterations; i++) {
            fun(in, in + N);
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


void avx512_sort_for_loop(uint32_t* start, uint32_t* /*unused*/) {

    const __m512i input  = _mm512_loadu_si512(start);
    const __m512i sorted = avx512_sort_loop_epi32(input);
    _mm512_storeu_si512(start, sorted);
}


void avx512_sort_while_loop(uint32_t* start, uint32_t* /*unused*/) {

    const __m512i input  = _mm512_loadu_si512(start);
    const __m512i sorted = avx512_sort_while_epi32(input);
    _mm512_storeu_si512(start, sorted);
}


void test_std_sort(uint32_t* start, uint32_t* end) {
    std::sort(start, end);
}


void test_insertion(uint32_t* start, uint32_t* end) {
    insertion_sort(start, end);
}


void avx512_sort2regs(uint32_t* start, uint32_t* /*unused*/) {

    const __m512i in1 = _mm512_loadu_si512(start);
    const __m512i in2 = _mm512_loadu_si512(start + 16);

    __m512i sorted1, sorted2;
    avx512_sort2xreg_epi32(in1, in2, sorted1, sorted2);
    _mm512_storeu_si512(start, sorted1);
    _mm512_storeu_si512(start + 16, sorted2);
}


template <unsigned N, typename FUNCTION>
void measure(const char* name, FUNCTION fun) {

    printf("%s... ", name); fflush(stdout);
    Test<N> test;
    const auto t1 = get_time();
    test.run(fun);
    const auto t2 = get_time();

    const double t = (t2 - t1)/1000000.0;

    printf("%0.2f\n", t);
}


int main() {

    puts("sorting a single AVX512 register");
    measure<16>("std::sort",                    test_std_sort);
    measure<16>("insertion sort",               test_insertion);
    measure<16>("AVX512F sort",                 avx512_sort);
    measure<16>("AVX512F sort (for loop)",      avx512_sort_for_loop);
    measure<16>("AVX512F sort (while loop)",    avx512_sort_while_loop);

    puts("sorting two AVX512 registers");
    measure<32>("std::sort",                    test_std_sort);
    measure<32>("insertion sort",               test_insertion);
    measure<32>("AVX512F sort",                 avx512_sort2regs);
}
