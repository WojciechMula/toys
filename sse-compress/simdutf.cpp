// This file comes from https://github.com/simdutf/simdutf

#include "simdutf_tables.h"

static inline void compress(__m128i data, uint16_t mask, char *output) {
  if (mask == 0) {
    _mm_storeu_si128(reinterpret_cast<__m128i *>(output), data);
    return;
  }

  // this particular implementation was inspired by work done by @animetosho
  // we do it in two steps, first 8 bytes and then second 8 bytes
  uint8_t mask1 = uint8_t(mask);      // least significant 8 bits
  uint8_t mask2 = uint8_t(mask >> 8); // most significant 8 bits
  // next line just loads the 64-bit values thintable_epi8[mask1] and
  // thintable_epi8[mask2] into a 128-bit register, using only
  // two instructions on most compilers.

  __m128i shufmask = _mm_set_epi64x(thintable_epi8[mask2],
                                    thintable_epi8[mask1]);
  // we increment by 0x08 the second half of the mask
  shufmask =
      _mm_add_epi8(shufmask, _mm_set_epi32(0x08080808, 0x08080808, 0, 0));
  // this is the version "nearly pruned"
  __m128i pruned = _mm_shuffle_epi8(data, shufmask);
  // we still need to put the two halves together.
  // we compute the popcount of the first half:
  int pop1 = BitsSetTable256mul2[mask1];
  // then load the corresponding mask, what it does is to write
  // only the first pop1 bytes from the first 8 bytes, and then
  // it fills in with the bytes from the second 8 bytes + some filling
  // at the end.
  __m128i compactmask = _mm_loadu_si128(reinterpret_cast<const __m128i *>(
      pshufb_combine_table + pop1 * 8));
  __m128i answer = _mm_shuffle_epi8(pruned, compactmask);
  _mm_storeu_si128(reinterpret_cast<__m128i *>(output), answer);
}

void simdutf_compress(uint16_t mask, const char* in, char* out) {
    compress(
        _mm_loadu_si128((__m128i*)in),
        mask,
        out
    );
}
