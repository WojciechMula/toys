#include <cstdio>
#include "float2string.h"
#include "gettime.cpp"


class Tester final {

    const uint32_t min_mantissa = 0;
    const uint32_t max_mantissa = (uint32_t(1) << 23) - 1;

    const uint32_t min_exponent = 1;
    const uint32_t max_exponent = 190;

    const uint32_t mantissa_step = max_mantissa / 10000;

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


int main() {

    bool t = 1;
    bool c = 1;

    double sprintf_time;
    double custom_time;

    Tester test;

    if (t) {
        const auto t1 = get_time();
        test.stdlib();
        const auto t2 = get_time();

        sprintf_time = (t2 - t1)/1000000.0;
        printf("sprintf time = %0.3fs\n", sprintf_time);
    }

    if (c) {
        const auto t1 = get_time();
        test.converter();
        const auto t2 = get_time();

        custom_time = (t2 - t1)/1000000.0;
        printf("custom time = %0.3fs\n", custom_time);
        if (t) {
            printf("speedup = %0.1f\n", sprintf_time/custom_time);
        }
    }
}
