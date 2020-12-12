#include "naive.h"
#include "binary_search.h"
#include "binary_search_inline.h"
#include "avx2.h"

#include "benchmark.h"

#include <cstdio>
#include <cstdlib>
#include <cmath>


class Application {
private:
    float a[8];
    float b[8];
    float x_boundary[8];

public:
    Application() {
        // 1. init of function params
        for (int i=0; i < 8; i++) {
            a[i] = i * 0.5;
            b[i] = 0;// -i * 0.25;
            x_boundary[i] = (i + 1);
        }
    }

    void run() {
        benchmark("linear search", naive);
        benchmark("binary search", binary_search);
        benchmark("binary search inline", binary_search_inline);
        benchmark("AVX2", avx2);
    }

private:
    template <typename FUNCTION>
    void benchmark(const char* name, FUNCTION function) {
        
        auto fn = [this, function]() {
            const float x_from = 0.0;
            const float x_to   = 10.0;

            for (float x = x_from; x < x_to; x += 0.000025) {
                evaluate(function, x);
            }
        };

        constexpr size_t size = 401'835;

        BEST_TIME(/**/, fn(), name, 10, size);
    }

    template <typename FUNCTION>
    float evaluate(FUNCTION function, float x) {
        return function(x, x_boundary, a, b);
    }
};


int main() {
    Application app{};
    app.run();

    return EXIT_SUCCESS;
}
