#include "naive.h"
#include "binary_search.h"
#include "binary_search_inline.h"
#include "avx2.h"

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>


class Application {
private:
    float a[8];
    float b[8];
    float x_boundary[8];
    std::vector<float> test_values;

public:
    Application() {
        // 1. init of function params
        for (int i=0; i < 8; i++) {
            a[i] = i * 0.5;
            b[i] = 0;// -i * 0.25;
            x_boundary[i] = (i + 1);
        }

        // 2. init of test values
        for (int i=0; i < 8; i++) {
            test_values.push_back(x_boundary[i]);
            test_values.push_back(x_boundary[i] - 0.5);
            test_values.push_back(x_boundary[i] + 0.25);
        }

        test_values.push_back(test_values.back() + 10.0);
    }

    bool run() {
        bool ok = true;

        ok = validate("binary search", binary_search) && ok;
        ok = validate("binary search inline", binary_search_inline) && ok;
        ok = validate("AVX2", avx2) && ok;

        return ok;
    }

private:
    template <typename FUNCTION>
    bool validate(const char* name, FUNCTION function) {
        printf("testing '%s' ", name); fflush(stdout);

        bool ok = true;
        for (const float x: test_values) {
            const float expected = evaluate(naive, x);
            const float result = evaluate(function, x);
            if (fabs(expected - result) > 1e-6f) {
                printf("failed for x=%f: result = %0.11f, expected = %0.11f\n", x, result, expected);
                ok = false;
            }
        }

        if (ok)
            puts("OK");

        return ok;
    }

    template <typename FUNCTION>
    float evaluate(FUNCTION function, float x) {
        return function(x, x_boundary, a, b);
    }
};


int main() {
    Application app{};
    return app.run() ? EXIT_SUCCESS : EXIT_FAILURE;
}
