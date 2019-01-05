#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cassert>

#include "all.cpp"
#include "ansi.cpp"

class Test {

    struct TestFailed{};

    static const size_t size = 64;
    char input[size];
    char output[size];
    char output_ref[size];

public:
    bool run() {
        try {
            test_1_gap();
            test_2_gaps();
            test_random();

            puts(ansi::seq("All OK", ansi::GREEN).c_str());

            return true;
        } catch (TestFailed&) {
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


    uint64_t random(int cardinality) {
        uint64_t v = 0;
        while (__builtin_popcountll(v) != cardinality) {
            v |= uint64_t(1) << (rand() % 64);
        }

        return v;
    }


    void compare() {

        const char* ret_ref = remove_spaces__scalar    (input, output_ref, size);
        const char* ret     = remove_spaces__avx512vbmi(input, output,     size);

        const size_t len_ref = (ret_ref - output_ref);
        const size_t len     = (ret - output);

        if (len != len_ref || !output_prefixes_equal(len_ref)) {
            printf("%s; len_ref=%lu, len=%lu\n", ansi::seq("FAILED", ansi::RED).c_str(), len_ref, len);
            printf(" input: "); dump(input, size);
            printf("   ref: "); dump(output_ref, len_ref);
            printf("result: "); dump(output, len);

            throw TestFailed{};
        }
    }

    void init_input() {
        int i=0;
        for (int j='a'; j <= 'z'; j++)
            input[i++] = j;

        for (int j='A'; j <= 'Z'; j++)
            input[i++] = j;

        for (int j='0'; j <= '9'; j++)
            input[i++] = j;

        input[i++] = '#';
        input[i++] = '@';

        assert(i == size);
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

    Test test;

    test.run();
}
