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

class Application final {

    vec input_vec;
    static constexpr size_t input_size = 1024*1024;
    static constexpr size_t iterations = 1000;

    FILE* csv = nullptr;

public:
    void run() {

        csv = fopen("out.csv", "wt");
        assert((csv != nullptr) && "can't open file");

        measure_time("create input table: ", [this]{
            input_vec = create_sorted(input_size);
        });

        for (size_t base_size: {128, 1024}) {
            for (size_t factor: {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 50}) {
                const size_t size = base_size * factor;
                test_all(size);
            }
        }

        fclose(csv);
    }

private:
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

        fprintf(csv, "%s,%lu,%lu,%lu\n", info, a.size(), b.size(), best_time);
    }

    void test_all(size_t size) {

        auto sampled = sample_sorted(input_vec, size);

        test<STD>("std",          sampled, input_vec, iterations);
        test<SSE>("SSE",          sampled, input_vec, iterations);
        test<BINARY>("binsearch", sampled, input_vec, iterations);
    }

};

int main() {

    Application app;
    app.run();
}

