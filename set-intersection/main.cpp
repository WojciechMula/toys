#include <algorithm>
#include <numeric>

#include <cstdio>

#include "vector_utils.h"
#include "time_utils.h"

#include "vector_utils.cpp"
#include "time_utils.cpp"

#include "sse_set_intersection.cpp"
#include "binarysearch_set_intersection.cpp"

constexpr int STD = 0;
constexpr int SSE = 1;
constexpr int BINARY = 2;

template <int version>
void test(const char* info, const vec& a, const vec& b, int k) {

    vec result;
    volatile int32_t ref = 0;

    printf("%s [a.size = %lu, b.size = %lu, %d iterations] ", info, a.size(), b.size(), k);
    fflush(stdout);

    Clock::rep best_time = 0;
    int tmp = k;
    while (tmp-- > 0) {
        result.clear();
        const auto t1 = Clock::now();
        if constexpr (version == STD) {
            std::set_intersection(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(result));
        } else if constexpr (version == SSE) {
            sse_set_intersection(a, b, std::back_inserter(result));
        } else if constexpr (version == BINARY) {
            binsearch_set_intersection(a, b, std::back_inserter(result));
        }
        const auto t2 = Clock::now();
        best_time += elapsed(t1, t2);

        ref += std::accumulate(result.begin(), result.end(), int32_t(0));
    }

    printf("%lu us (%d)\n", best_time, ref);
}

void test_all(const vec& larger, size_t size, int iterations) {

    auto smaller = sample_sorted(larger, size);

    test<STD>("std",          smaller, larger, iterations);
    test<SSE>("SSE",          smaller, larger, iterations);
    test<BINARY>("binsearch", smaller, larger, iterations);
}

int main() {

    vec input_vec;
    measure_time("create input table: ", [&input_vec]{
        input_vec = create_sorted(1024*1024);
    });

    for (size_t base_size: {128, 1024}) {
        for (size_t factor: {1,2,3,4,5,6,7,8,9,10}) {
            const size_t size = base_size * factor;
            test_all(input_vec, size, 1000);
        }
    }
}

