#include <cstdlib>
#include <cstdio>
#include <cstdint>
#include <cstring>

#include <algorithm>
#include "avx512-sort.cpp"

void print(const char* s) {
    printf("%s... ", s);
    fflush(stdout);
}



class Failed {};

class Test {

    uint32_t in[16];
    uint32_t out[16];
    uint32_t ref[16];

    const size_t iterations = 10000000;

public:
    using FunctionPtr = __m512i (*)(const __m512i v);

private:
    FunctionPtr function;

public:
    Test(FunctionPtr fn)
        : function(fn) {}

    void run() {

        print("test 1");
        input_test_1();
        check();
        puts("OK");

        print("test ascending");
        input_ascending();
        check();
        puts("OK");

        print("test descending");
        input_descending();
        check();
        puts("OK");

        print("test all same");
        input_all_same();
        check();
        puts("OK");

        print("test random");
        for (int i=0; i < 1000; i++) {
            input_random();
            check();
        }
    }

private:
    void check() {

        // run AVX512 procedure
        const __m512i input  = _mm512_loadu_si512(in);
        const __m512i sorted = function(input);
        _mm512_storeu_si512(out, sorted);

        // run reference
        memcpy(ref, in, sizeof(in));
        std::sort(ref, ref + 16);

        // compare
        for (int i=1; i < 16; i++) {
            if (ref[i] != out[i]) {
                printf("mismatch at %d", i);
                dump("in ", in);
                dump("out", out);
                throw Failed();
            }
        }
    }


    void input_ascending() {
        for (int i=0; i < 16; i++) {
            in[i] = i;
        }
    }

    void input_descending() {
        for (int i=0; i < 16; i++) {
            in[i] = 15-i;
        }
    }

    void input_all_same() {
        for (int i=0; i < 16; i++) {
            in[i] = 42;
        }
    }

    void input_random() {
        for (int i=0; i < 16; i++) {
            in[i] = rand();
        }
    }

    void input_test_1() {
        in[0]  = 1000;
        in[1]  = 500;
        in[2]  = 1000;
        in[3]  = 1001;
        in[4]  = 1;
        in[5]  = 400;
        in[6]  = 10000;
        in[7]  = 9400;
        in[8]  = 1400;
        in[9]  = 5400;
        in[10] = 400;
        in[11] = 400;
        in[12] = 400;
        in[13] = 400;
        in[14] = 400;
        in[15] = 400;
    }


    void dump(const char* name, const uint32_t* data) {

        printf("%s = [", name);
        for (int i=0; i < 16; i++) {
            if (i > 0) printf(", ");
            printf("%5d", data[i]);
        }
        printf("]\n");
    }
};


int main() {

    {
        puts("");
        puts("avx512_sort_epi32");
        Test test(avx512_sort_epi32);

        try {
            test.run();
            puts("OK");
        } catch (Failed&) {
            puts("ERROR");
        }
    }

    {
        puts("");
        puts("avx512_sort_epi32_unrolled");
        Test test(avx512_sort_epi32_unrolled);

        try {
            test.run();
            puts("OK");
        } catch (Failed&) {
            puts("ERROR");
        }
    }

    {
        puts("");
        puts("avx512_sort_loop_epi32");
        Test test(avx512_sort_loop_epi32);

        try {
            test.run();
            puts("OK");
        } catch (Failed&) {
            puts("ERROR");
        }
    }

    {
        puts("");
        puts("avx512_sort_while_epi32");
        Test test(avx512_sort_while_epi32);

        try {
            test.run();
            puts("OK");
        } catch (Failed&) {
            puts("ERROR");
        }
    }
}
