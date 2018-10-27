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
            in[i] = zigzag_reference[i];
        }
    }

public:
    void run() {
        try {
            test("scalar",      jpeg_zigzag_scalar);
            test("SSE",         jpeg_zigzag_sse);
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

