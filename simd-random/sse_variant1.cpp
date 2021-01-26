#include "sse_variant1.h"

namespace rnd {

    __m128i sse_variant1(__m128i seed) {
        return _mm_mullo_epi32(seed, _mm_set1_epi32(48271));
    }
}
