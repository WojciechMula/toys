#include <cstdlib>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <memory>

#include "input_data.cpp"
#include "gettime.cpp"
#include "quicksort-all.cpp"


class PerformanceTest final {

    int         iterations;
    InputData&  input;
    uint32_t*   tmp;

public:
    PerformanceTest(int n, InputData& input)
        : iterations(n)
        , input(input) {
        
        assert(iterations > 0);
        tmp = new uint32_t[input.count()];
    }

    ~PerformanceTest() {
        delete[] tmp;
    }

public:
    template <typename SORT_FUNCTION>
    uint32_t run(SORT_FUNCTION sort) {

        uint32_t time = 0;

        int k = iterations;
        while (k--) {
            memcpy(tmp, input.pointer(), input.size());

            const uint32_t t1 = get_time();
            sort(input.pointer(), 0, input.count() - 1);
            const uint32_t t2 = get_time();

            const uint32_t dt = t2 - t1;

            if (time == 0) {
                time = dt;
            } else if (dt < time) {
                time = dt;
            }
        }

        return time;
    }
};


enum class InputType {
    randomfew,
    random,
    ascending,
    descending,
};


const char* as_string(InputType type) {
    switch (type) {
        case InputType::randomfew:
            return "randomfew";

        case InputType::random:
            return "random";

        case InputType::ascending:
            return "ascending";

        case InputType::descending:
            return "descending";

        default:
            return "<unknown>";
    }
}

void std_qsort_wrapper(uint32_t* array, int left, int right) {
    
    std::qsort(array + left, right - left + 1, sizeof(uint32_t),  [](const void* a, const void* b)
    {
        uint32_t a1 = *static_cast<const uint32_t*>(a);
        uint32_t a2 = *static_cast<const uint32_t*>(b);
 
        if(a1 < a2) return -1;
        if(a1 > a2) return 1;
        return 0;
    });
}


void std_stable_sort_wrapper(uint32_t* array, int left, int right) {
    
    std::stable_sort(array + left, array + right + 1);
}


void std_sort_wrapper(uint32_t* array, int left, int right) {
    
    std::sort(array + left, array + right + 1);
}


class Test {

    std::unique_ptr<InputData> data;
    InputType   type;
    size_t      count;
    int         iterations;

public:
    Test(InputType type, size_t count, int iterations)
        : type(type)
        , count(count)
        , iterations(iterations) {

        switch (type) {
            case InputType::randomfew:
                data.reset(new InputRandomFew(count));
                break;

            case InputType::random:
                data.reset(new InputRandom(count));
                break;

            case InputType::ascending:
                data.reset(new InputAscending(count));
                break;

            case InputType::descending:
                data.reset(new InputDescending(count));
                break;
        }
    }

    void run() {

        printf("items count: %lu (%lu bytes), input %s\n", data->count(), data->size(), as_string(type));

        uint32_t ref = 0;
        ref = measure("std::sort",              std_sort_wrapper,             ref);
        measure("std::qsort",                   std_qsort_wrapper,            ref);
        measure("std::stable_sort",             std_stable_sort_wrapper,      ref);
        measure("quick sort",                   quicksort,                    ref);
#ifdef HAVE_AVX2_INSTRUCTIONS
        measure("AVX2 quick sort",              qs::avx2::quicksort,          ref);
#endif
#ifdef HAVE_AVX512F_INSTRUCTIONS
        measure("AVX512 quick sort",            qs::avx512::quicksort,        ref);
        measure("AVX512 + popcnt quick sort",   qs::avx512::popcnt_quicksort, ref);
        measure("AVX512 + BMI2 quick sort",     qs::avx512::bmi2_quicksort,   ref);
#endif
    }

private:
    template <typename SORT_FUNCTION>
    uint32_t measure(const char* name, SORT_FUNCTION sort, uint32_t ref) {

        PerformanceTest test(iterations, *data);

        printf("%30s ... ", name); fflush(stdout);
        uint32_t time = test.run(sort);
        if (ref > 0) {
            printf("%0.4f s (%0.2f)\n", time/1000000.0, ref/double(time));
        } else {
            printf("%0.4f s\n", time/1000000.0);
        }

        return time;
    }
};


// ------------------------------------------------------------


void usage() {
    puts("usage:");
    puts("speed SIZE ITERATIONS INPUT");
    puts("");
    puts("where");
    puts("* SIZE       - number of 32-bit elements");
    puts("* ITERATIONS - number of iterations");
    puts("* INPUT      - one of:");
    puts("                 ascending (or asc)");
    puts("                 descending (or dsc, desc)");
    puts("                 random (or rnd, rand)");
    puts("                 randomfew");
}


int main(int argc, char* argv[]) {

    if (argc < 4) {
        usage();
        return EXIT_FAILURE;
    }

    int count      = atoi(argv[1]);
    int iterations = atoi(argv[2]);
    InputType type;

#define is_keyword(key) (strcmp(argv[3], key) == 0)
    if (is_keyword("descending") || is_keyword("desc") || is_keyword("dsc")) {
        type = InputType::descending;
    } else if (is_keyword("ascending") || is_keyword("asc")) {
        type = InputType::ascending;
    } else if (is_keyword("random") || is_keyword("rnd") || is_keyword("rand")) {
        type = InputType::random;
    } else if (is_keyword("randomfew")) {
        type = InputType::randomfew;
    } else {
        usage();
        return EXIT_FAILURE;
    }
#undef is_keyword

    Test test(type, count, iterations);
    test.run();

    return EXIT_SUCCESS;
}
