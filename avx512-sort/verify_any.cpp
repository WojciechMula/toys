#include <cstdlib>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <cassert>

#include <algorithm>
#include "avx512-sort-any.cpp"


class Failed {};


class Test {

protected:

    size_t N;

    uint32_t buf[64];
    uint32_t ref[64];

public:

    Test(size_t n)
        : N(n) {

        assert(N > 0);
        assert(N <= 64);
    }

    void run() {

        input_ascending();
        check("test ascending");

        input_descending();
        check("test descending");

        input_all_same();
        check("test all same");

        for (int i=0; i < 1000; i++) {
            input_random();
            check("test random");
        }
    }

private:

    void input_ascending() {
        for (size_t i=0; i < N; i++) {
            buf[i] = i;
        }
    }

    void input_descending() {
        for (size_t i=0; i < N; i++) {
            buf[i] = N-i;
        }
    }

    void input_all_same() {
        for (size_t i=0; i < N; i++) {
            buf[i] = 42;
        }
    }

    void input_random() {
        for (size_t i=0; i < N; i++) {
            buf[i] = rand();
        }
    }

    void check(const char* name) {

        // run reference
        memcpy(ref, buf, sizeof(buf));
        std::sort(ref, ref + N);

        // run an AVX512 procedure
        avx512sort::sort_inplace(buf, N);

        // compare
        for (size_t i=1; i < N; i++) {
            if (ref[i] != buf[i]) {
                printf("test %s -- mismatch at %lu\n", name, i);
                dump("ref", ref);
                dump("buf", buf);
                throw Failed();
            }
        }
    }

    void dump(const char* name, const uint32_t* data) {

        printf("%s = [", name);
        for (size_t i=0; i < N; i++) {
            if (i > 0) printf(", ");
            printf("%5d", data[i]);
        }
        printf("]\n");
    }
};


int main() {

    for (int i=2; i <= 64; i++) {
        Test test(i);

        printf("AVX512 sort(%d)... ", i); fflush(stdout);
        try {
            test.run();
            puts("OK");
        } catch (Failed&) {
            puts("ERROR");
            return EXIT_FAILURE;
        }
    }

    puts("All OK");
    return EXIT_SUCCESS;
}
