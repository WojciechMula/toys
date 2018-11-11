#pragma once

#include <cmath>

template <typename Random>
void scalar_normal_distr(Random random, size_t size, float* output) {
    for (size_t i=0; i < size; i += 2) {
        const float r1 = random();
        const float r2 = random();

        const float R     = sqrt(-2 * log(r1));
        const float angle = 2 * M_PI * r2;

        output[i + 0] = R * sin(angle);
        output[i + 1] = R * cos(angle);
    }
}

template <typename Random>
void scalar_normal_distr_sin_cos(Random random, size_t size, float* output) {
    for (size_t i=0; i < size; i += 2) {
        const float r1 = random();
        const float r2 = random();

        const float R     = sqrt(-2 * log(r1));
        const float angle = 2 * M_PI * r2;

        float s;
        float c;
        sincosf(angle, &s, &c);

        output[i + 0] = R * s;
        output[i + 1] = R * c;
    }
}
