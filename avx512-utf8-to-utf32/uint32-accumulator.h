#pragma once

#include <immintrin.h>
#include <cstdint>

__m512i uint32_rotate_left(__m512i v, unsigned amount);

// RegisterAccumulator accumulates the unpacked UTF-8 words until
// an AVX512 is full and only then calls the conversion routine.
class RegisterAccumulator {
    struct {
        __m512i vector;
        int     count; // active items 0..active     
    } current;

public:
    RegisterAccumulator() {
        current.vector = _mm512_setzero_si512();
        current.count  = 0;
    }

    // input:
    // - value    - 16 x 32-bit values
    // - mask     - which items are active
    // - callback - fun(__m512 utf32, int count) called when at least 16 values got accumulated
    template <typename CALLBACK>
    void add(__m512i utf8, uint16_t valid, CALLBACK callback) {
        const auto     count    = __builtin_popcount(valid);
        const uint32_t new_mask = (uint32_t(1 << count) - 1) << current.count;

        __m512i tmp;

        tmp = _mm512_mask_compress_epi32(_mm512_setzero_si512(), valid, utf8);
        tmp = uint32_rotate_left(tmp, current.count);
        current.vector = _mm512_mask_mov_epi32(current.vector, (new_mask & 0xffff), tmp);

        if (count + current.count < 16) {
            // there are less than 16 items in register, nothing to do
            current.count += count;
            return;
        }

        // the whole vector is full
        callback(current.vector, 16);

        // keep the remining items from `utf8`
        const auto tail = 16 - current.count;
        current.vector = tmp;
        current.count  = count - tail;
    }

    template <typename CALLBACK>
    void flush(CALLBACK callback) {
        if (current.count)
            callback(current.vector, current.count);

        current.count = 0;
    }
};
