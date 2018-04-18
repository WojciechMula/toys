#include <cstdio>
#include <cstdlib>
#include <cassert>

#include <vector>

#include "all-procedures.cpp"

class Test {

    std::vector<int32_t> input;
    size_t max_size;
    bool ok;

public:
    Test(size_t size_)
        : max_size(size_)
        , ok(true) {

        fill_ascending();
    }


    bool all_ok() const {
        return ok;
    }

    template <typename FUNCTION>
    void test(const char* name, FUNCTION fun);

private:
    template <typename FUNCTION>
    bool run(FUNCTION fun);

    void fill_ascending() {
        input.clear();
        input.reserve(max_size);
        for (size_t i=0; i < max_size; i++) {
            input[i] = i;
        }
    }
};


template <typename FUNCTION>
bool Test::run(FUNCTION fun) {
    for (size_t i=0; i < max_size; i++) {
        break;
        const bool expected = true;
        const bool ret = fun(&input[0], i);
        if (ret != expected) {
            printf("case 1, size = %lu failed\n", i);
            return false;
        }
    }

    for (size_t size=3; size < max_size; size++) {
        for (size_t i=0; i < size; i++) {
            const int32_t prev = input[i];
            input[i] = (i == 0) ? prev + 2 : -1;
            const bool expected = false;
            const bool ret = fun(&input[0], size);
            if (ret != expected) {
                printf("case 2, size = %lu, position = %lu failed\n", size, i);
                for (size_t j=0; j < size; j++) {
                    printf(" %d", input[j]);
                }
                putchar('\n');
                return false;
            }
            input[i] = prev;
        }
    }

    return true;
}

template <typename FUNCTION>
void Test::test(const char* name, FUNCTION fun) {
    printf("testing %s", name); fflush(stdout);

    if (run(fun)) {
        puts(" OK");
    } else {
        ok = false;
    }
}


int main() {
    Test test(1024);

    test.test("scalar",
              is_sorted);
    test.test("SSE (generic)",
              is_sorted_sse_generic);
    test.test("SSE (generic, unrolled 4 times)",
              is_sorted_sse_generic_unrolled4);
    test.test("SSE",
              is_sorted_sse);
#ifdef HAVE_AVX2
    test.test("AVX2 (generic)", is_sorted_avx2_generic);
    test.test("AVX2",           is_sorted_avx2);
#endif // HAVE_AVX2

    if (test.all_ok()) {
        puts("All OK");
        return EXIT_SUCCESS;
    } else {
        return EXIT_FAILURE;
    }
}
