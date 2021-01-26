#pragma once

#include <cstdint>
#include <immintrin.h>

namespace rnd {

    void sse_variant2(__m128i& sse_seed, uint32_t& seed);
}
