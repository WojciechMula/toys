#include <cstdio>
#include <vector>
#include "float2string.h"
#include "cmdline.cpp"


void test_wide_range() {

    char buffer[fp::tostring<float>::min_buffer_size + 10];

    const uint32_t min_mantissa = 0;
    const uint32_t max_mantissa = (uint32_t(1) << 23) - 1;

    const uint32_t min_exponent = 1;
    const uint32_t max_exponent = 254;

    fp::traits<float>::proxy p(uint32_t(0));

    for (uint32_t exp = min_exponent; exp < max_exponent; exp++) {
        for (uint32_t mantissa = min_mantissa; mantissa < max_mantissa; mantissa += max_mantissa/5) {
            p.raw = (exp << fp::traits<float>::mantissa_bits) | mantissa;

            fp::tostring<float> conv(p.value);
            if (conv.can_convert()) {
                printf("%3d: %40.8f %30s\n", exp, p.value, (conv(buffer), buffer));
            }
        }
    }
}


void test_predefined() {

    std::vector<float> values = {
        0.0,
        0.001235,
        0.125,
        0.0125,
        0.001234,
        0.5,
        1.0,
        1.5,
        1000.0,
        432.00009,
        123243243.091,
    };

    char buffer[fp::tostring<float>::min_buffer_size + 10];

    for (float x: values) {
        printf("%30.8f\t\t", x);

        fp::tostring<float> z(x);

        z(buffer);

        puts(buffer);
    }
}


int main(int argc, char* argv[]) {

    CommandLine cmd(argc, argv);

    if (cmd.empty()) {
        puts("usage: program all|selected");
        return 1;
    }

    if (cmd.has("all")) {
        test_wide_range();
    }
    
    if (cmd.has("selected")) {
        test_predefined();
    }

    return 0;
}
