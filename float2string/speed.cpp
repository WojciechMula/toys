#include <cstdio>
#include "float2string.h"
#include "cmdline.cpp"
#include "gettime.cpp"


class Tester final {

    const uint32_t min_mantissa = 0;
    const uint32_t max_mantissa = (uint32_t(1) << 23) - 1;

    const uint32_t min_exponent = 1;
    const uint32_t max_exponent = 190;

    const uint32_t mantissa_step = max_mantissa / 100000;

    char buffer[fp::tostring<float>::min_buffer_size + 10];

    fp::traits<float>::proxy p;

public:
    Tester() : p(uint32_t(0)) {}

public:
    void stdlib() {
        for (uint32_t exp = min_exponent; exp < max_exponent; exp++) {
            for (uint32_t mantissa = min_mantissa; mantissa < max_mantissa; mantissa += mantissa_step) {
                p.raw = (exp << fp::traits<float>::mantissa_bits) | mantissa;

                fp::tostring<float> conv(p.value);
                if (conv.can_convert()) {
                    sprintf(buffer, "%f", p.value);
                }
            }
        }
    }

    void converter() {
        for (uint32_t exp = min_exponent; exp < max_exponent; exp++) {
            for (uint32_t mantissa = min_mantissa; mantissa < max_mantissa; mantissa += mantissa_step) {
                p.raw = (exp << fp::traits<float>::mantissa_bits) | mantissa;

                fp::tostring<float> conv(p.value);
                if (conv.can_convert()) {
                    conv(buffer);
                }
            }
        }
    }
};


int main(int argc, char* argv[]) {

    CommandLine cmd(argc, argv);
    Tester test;

    const bool test_stdlib = cmd.empty() || cmd.has("stdlib");
    const bool test_custom = cmd.empty() || cmd.has("custom");

    double sprintf_time;
    double custom_time;

    if (test_stdlib) {

        printf("sprintf... ");
        fflush(stdout);

        const auto t1 = get_time();
        test.stdlib();
        const auto t2 = get_time();

        sprintf_time = (t2 - t1)/1000000.0;
        printf("%0.3fs\n", sprintf_time);
    }

    if (test_custom) {

        printf("custom... ");
        fflush(stdout);

        const auto t1 = get_time();
        test.converter();
        const auto t2 = get_time();

        custom_time = (t2 - t1)/1000000.0;
        printf("%0.3fs", custom_time);
        if (test_stdlib) {
            printf(" speedup: %0.1f", sprintf_time/custom_time);
        }

        putchar('\n');
    }
}
