#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cassert>

#include "all.cpp"
#include "ansi.cpp"
#include "application_base.cpp"

class UnitTests: public ApplicationBase {

    struct UnitTestsFailed{};

    char output_ref[size];

public:
    bool run() {
        try {
            test_1_gap();
            test_2_gaps();
            test_random();

            puts(ansi::seq("All OK", ansi::GREEN).c_str());

            return true;
        } catch (UnitTestsFailed&) {
            return false;
        }
    }

private:
    void test_1_gap() {
        puts("test 1 gap");
        for (size_t i=0; i < size; i++) {
            init_input();
            input[i] = ' ';
            compare();
        }
    }

    void test_2_gaps() {
        puts("test 2 gaps");
        for (size_t i=0; i < size; i++) {
            for (size_t j=i + 5; j < size; j++) {
                init_input();
                input[i] = ' ';
                input[j] = ' ';
                compare();
            }
        }
    }

    void test_random() {
        const int runs = 10;

        puts("test random number of gaps (from 1 to 64)");
        for (int cardinality=1; cardinality <= 64; cardinality++) {
            for (int k=0; k < runs; k++) {
                test_random(random(cardinality));
            }
         }
    }

    void test_random(uint64_t v) {
        init_input();
        while (v) {
            const int k = __builtin_ctzll(v);
            v ^= (v & -v);

            input[k] = ' ';
        }

        compare();
    }


    void compare() {
        compare("AVX512VBMI",          remove_spaces__avx512vbmi);
        compare("AVX512VBMI (Travis)", remove_spaces__avx512vbmi__travis);
        compare("AVX512VBMI (Zach)",   remove_spaces__avx512vbmi__zach);
    }


    template <typename FUNCTION>
    void compare(const char* name, FUNCTION vectorized_remove_spaces) {

        const char* ret_ref = remove_spaces__scalar   (input, output_ref, size);
        const char* ret     = vectorized_remove_spaces(input, output,     size);

        const size_t len_ref = (ret_ref - output_ref);
        const size_t len     = (ret - output);

        if (len != len_ref || !output_prefixes_equal(len_ref)) {
            printf("%s %s; len_ref=%lu, len=%lu\n", name, ansi::seq("FAILED", ansi::RED).c_str(), len_ref, len);
            printf(" input: "); dump(input, size);
            printf("   ref: "); dump(output_ref, len_ref);
            printf("result: "); dump(output, len);

            throw UnitTestsFailed{};
        }
    }

    bool output_prefixes_equal(size_t k) {
        assert(k <= size);

        for (size_t i=0; i < k; i++) {
            if (output[i] != output_ref[i])
                return false;
        }

        return true;
    }

    void dump(const char* buf, size_t size) {
        printf("[");
        for (size_t i=0; i < size; i++) {
            printf("%c", buf[i]);
        }
        printf("]\n");
    }
};


int main() {

    srand(0);

    UnitTests test;
    return test.run() ? EXIT_SUCCESS : EXIT_FAILURE;
}
