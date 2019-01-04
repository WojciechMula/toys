#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cassert>

#include "all.cpp"

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
            test_random(100000);

            puts("All OK");

            return true;
        } catch (TestFailed&) {
            return false;
        }
    }

private:
    void test_1_gap() {

        const size_t output_len = size - 1;
 
        puts("test 1 gap");
        for (size_t i=0; i < size; i++) {
            init_input();
            input[i] = ' ';
            compare(output_len);
        }
    }

    void test_2_gaps() {

        const size_t output_len = size - 2;
    
        puts("test 2 gaps");
        for (size_t i=0; i < size; i++) {
            for (size_t j=i + 5; j < size; j++) {
                init_input();
                input[i] = ' ';
                input[j] = ' ';
                compare(output_len);
            }
        }
    }

    void test_random(int tries) {
        printf("random gaps [%d tests]\n", tries);
        while (tries) {
            test_random();
            tries -= 1;
        }
    }

    void test_random() {
        init_input();
        uint64_t v = random64();
        const size_t output_len = 64 - __builtin_popcountll(v);
        while (v) {
            const int k = __builtin_ctzll(v);
            input[k] = ' ';

            v ^= (v & -v);
        }

        compare(output_len);
    }

    uint64_t random64() {
        union {
            uint64_t word;
            uint8_t bytes[8];
        } value;

        for (int i=0; i < 8; i++) {
            value.bytes[i] = rand() % 256;
        }

        return value.word;
    }

    void compare(size_t output_len) {

        remove_spaces__scalar(input, output_ref, size);
        remove_spaces__avx512vbmi(input, output, size);
        if (!output_prefixes_equal(output_len)) {
            puts("FAILED");
            dump(input, size);
            dump(output_ref, output_len);
            dump(output, output_len);

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
