#include <cstdio>
#include <random>
#include <limits>
#include "benchmark.h"

#define SIZE 1024*1024*2
uint32_t data[SIZE];
uint32_t mask[SIZE];
uint32_t out[SIZE + 64];

#define BENCH(func) \
    BEST_TIME(/**/, func(data, mask, out, SIZE), names[func].c_str(), repeat, SIZE);

uint32_t rand(std::mt19937& re, int bits) {
    std::uniform_int_distribution<int> bit_pos(0, 31);

    uint32_t mask = 0;
    for (int i=0; i < bits; i++) {
        mask |= 1 << bit_pos(re);
    }

    return mask;
}

uint32_t rand_non_zero(std::mt19937& re, std::uniform_int_distribution<uint32_t> &uid) {
    while (true) {
        const uint32_t mask = uid(re);
        if (mask) {
            return mask;
        }
    }
}