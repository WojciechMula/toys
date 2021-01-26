#include "sse_variant2.h"

#include "lcm.h"

namespace rnd {

    void sse_variant2(__m128i& sse_seed, uint32_t& seed) {
        seed = rnd::scalar(seed);
        sse_seed = _mm_mullo_epi32(sse_seed, _mm_set1_epi32(48271));
    }
}
