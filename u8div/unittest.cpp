#include <cstdio>
#include <vector>

#include "impl.cpp"

#define SIZE 256 * 255

class Application {
    uint8_t a[SIZE];
    uint8_t b[SIZE];
    uint8_t reference[SIZE];
    bool    all_ok;
    function_names_t names;

public:
    Application()
        : all_ok(false)
        , names(function_names())
    {
        printf("preparing reference data... ");
        fflush(stdout);

        for (unsigned i=0; i < 256; i++) {
            for (unsigned j=0; j < 255; j++) {
                a[i + j*256] = i;
                b[i + j*256] = j + 1;
            }
        }

        scalar_div_u8(a, b, reference, SIZE);
        puts("done");
    }

    void run() {
        all_ok = true;

        check(scalar_long_div_u8);

        #ifdef HAVE_SSE
            check(sse_div_u8);
            check(sse_div_u8_no_rounding);
            check(sse_div_u8_cvtt);
            check(sse_div_u8_rcp);
            check(sse_long_div_u8);
        #endif

        #ifdef HAVE_AVX2
            check(avx2_div_u8);
            check(avx2_div_u8_cvtt);
            check(avx2_div_u8_rcp);
            check(avx2_div_u8_rcp_4x);
            check(avx2_long_div_u8);
        #endif

        #ifdef HAVE_AVX512
            check(avx512_div_u8_cvtt);
            check(avx512_div_u8_rcp);
            check(avx512_div_u8_rcp_4x);
            check(avx512_long_div_u8);
        #endif

        if (all_ok) {
            puts("All OK");
        }
    }

private:
    template<typename T>
    void check(T func) {
        printf("checking %s... ", names[func].c_str());
        fflush(stdout);

        uint8_t got[SIZE + 64];
        memset(got, 0, SIZE);
        func(a, b, got, SIZE);

        int errors = 0;
        for (size_t i=0; i < SIZE; i++) {
            if (got[i] != reference[i]) {
                if (errors == 0) {
                    putchar('\n');
                }

                printf("item #%lu (%d/%d)\n", i, a[i], b[i]);
                printf(" got: %d\n", got[i]);
                printf("want: %d\n", reference[i]);

                errors += 1;
                if (errors == 10) {
                    puts("more than 10 errors, bailing out");
                    break;
                }
            }
        }

        if (errors == 0) {
            puts("OK");
        } else {
            all_ok = false;
        }
    }
};

int main() {
    Application app;

    app.run();

}
