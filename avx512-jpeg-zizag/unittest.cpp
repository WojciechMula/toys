#include <cstdio>
#include "all.cpp"

class Test {
    uint8_t in[64];
    uint8_t out[64];

    class TestFailed {};

public:
    Test() {
        for (int i=0; i < 64; i++) {
            in[i] = zigzag_reference[i];
        }
    }

public:
    void run() {
        try {
            test("scalar",      jpeg_zigzag_scalar);
            test("SSE",         jpeg_zigzag_sse);
#ifdef HAVE_AVX512VBMI
            test("AVX512VBMI",  jpeg_zigzag_avx512vbmi);
#endif
        } catch (TestFailed&) {
            return;
        }
    }

private:
    template <typename FUN>
    void test(const char* name, FUN jpeg_zigzag_fun) {
        printf("%15s... ", name);
        fflush(stdout);

        jpeg_zigzag_fun(in, out);
        for (int i=0; i < 64; i++) {
            if (i != out[i]) {
                printf("failed at %d\n", i);
                throw TestFailed();
            }
        }

        puts("OK");
    }

};

int main() {
    
    Test test;
    test.run();

    return 0;
}

