#include <cstdio>
#include <cstring>
#include "all.cpp"

class Test {
    uint16_t in[64];
    uint16_t out[64];

    class TestFailed {};

public:
    Test() {
        for (int i=0; i < 64; i++) {
            in[i] = index_to_value(zigzag_reference[i]);
        }
    }

public:
    void run() {
        try {
            test("scalar",              jpeg_zigzag_scalar);
            test("SSE",                 jpeg_zigzag_sse);
            test("SSE (copy single)",   jpeg_zigzag_sse_copy_single);
#ifdef HAVE_AVX512F
            test("AVX512F",             jpeg_zigzag_avx512f);
#endif
#ifdef HAVE_AVX512BW
            test("AVX512BW",            jpeg_zigzag_avx512bw);
#endif
        } catch (TestFailed&) {
            return;
        }
    }

private:
    template <typename FUN>
    void test(const char* name, FUN jpeg_zigzag_fun) {
        printf("%20s... ", name);
        fflush(stdout);

        memset(out, 0, sizeof(out));
        jpeg_zigzag_fun(in, out);
        for (int i=0; i < 64; i++) {
            if (index_to_value(i) != out[i]) {
                printf("failed at %d\n", i);
                throw TestFailed();
            }
        }

        puts("OK");
    }

    
    uint16_t index_to_value(uint16_t v) const {
        // Since we work at words level, but might shuffle bytes, it's
        // worth to set also the higher byte of input words.

        return v | ~(v << 8);
    }
};

int main() {
    
    Test test;
    test.run();

    return 0;
}

