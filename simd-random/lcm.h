#pragma once

#include <cstdint>

namespace rnd {

    // https://en.wikipedia.org/wiki/Linear_congruential_generator
    template <uint32_t MULTIPLIER, uint32_t INCREMENT>
    uint32_t lcm(uint32_t x) {
        return x * MULTIPLIER + INCREMENT;
    }
    
    inline uint32_t scalar(uint32_t x) {
        return lcm<48271, 0>(x);
    }
}
