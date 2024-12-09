#include <cstdio>
#include <vector>

#include "impl.cpp"

#define SIZE 256 * 255

class Application {
    uint8_t a[SIZE];
    uint8_t b[SIZE];
    uint8_t reference[SIZE];
    bool    all_ok;

public:
    Application() : all_ok(false) {
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

        check("SSE", sse_div_u8);
        check("SSE (no rounding)", sse_div_u8_no_rounding);
        check("AVX2", avx2_div_u8);
        check("manual (SSE: ver1)", manual_div_u8);
        check("manual (SSE: ver2)", manual_div_u8_ver2);
        check("manual (AVX: ver2)", manual_div_u8_ver2_avx);

        if (all_ok) {
            puts("All OK");
        }
    }

private:
    template<typename T>
    void check(const char* name, T func) {
        printf("checking %s... ", name);
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
