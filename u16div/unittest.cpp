#include <cstdio>
#include <vector>

#include "impl.cpp"

#define SIZE 65536

class Application {
    uint16_t dividend[SIZE + 64];
    uint16_t divisor[SIZE + 64];
    uint16_t reference[SIZE + 64];
    bool    all_ok;
    function_names_t names;

public:
    Application()
        : all_ok(false)
        , names(function_names())
    {}

    void run() {
        all_ok = true;

        #ifdef HAVE_AVX2
            check(avx2_div_u16_cvtt);
            check(avx2_div_u16_cvtt_ver2);
            check(avx2_div_u16_rcp);
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

        uint16_t got[SIZE + 64];

        // 1. all values of dividend
        for (size_t i = 0; i < 65536; i++) {
            dividend[i] = i;
        }

        // 2. iterate over all divisor
        int errors = 0;
        for (uint32_t divisor = 1; divisor < 65536; divisor++) {
            for (size_t i=0; i < 65536; i++) {
                this->divisor[i] = divisor;
            }

            memset(got, 0, SIZE);
            scalar_div_u16(this->dividend, this->divisor, reference, SIZE);
            func(this->dividend, this->divisor, got, SIZE);

            for (size_t i=0; i < SIZE; i++) {
                if (got[i] != reference[i]) {
                    if (errors == 0) {
                        putchar('\n');
                    }

                    printf("item #%lu (%d/%d)\n", i, this->dividend[i], this->divisor[i]);
                    printf(" got: %d\n", got[i]);
                    printf("want: %d\n", reference[i]);

                    errors += 1;
                    if (errors == 10) {
                        puts("more than 10 errors, bailing out");
                        divisor = 0x10000; // force the outer loop to exit too
                        break;
                    }
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
