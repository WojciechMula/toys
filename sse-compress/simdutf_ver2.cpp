// a slightly improved(?) simdutf procedure

static inline void compress2(__m128i data, uint16_t mask, char *output) {
  // this particular implementation was inspired by work done by @animetosho
  // we do it in two steps, first 8 bytes and then second 8 bytes
  const uint8_t mask1 = uint8_t(mask);      // least significant 8 bits
  const uint8_t mask2 = uint8_t(mask >> 8); // most significant 8 bits
  // next line just loads the 64-bit values thintable_epi8[mask1] and
  // thintable_epi8[mask2] into a 128-bit register, using only
  // two instructions on most compilers.

  const __m128i shufmask = _mm_set_epi64x(thintable_epi8[mask2] + 0x0808080808080808,
                                    thintable_epi8[mask1]);
  // we increment by 0x08 the second half of the mask
  // this is the version "nearly pruned"
  const __m128i pruned = _mm_shuffle_epi8(data, shufmask);
  // we still need to put the two halves together.
  // we compute the popcount of the first half:
  const int pop1 = __builtin_popcount(mask1);
  // then load the corresponding mask, what it does is to write
  // only the first pop1 bytes from the first 8 bytes, and then
  // it fills in with the bytes from the second 8 bytes + some filling
  // at the end.
  const __m128i compactmask = _mm_loadu_si128(reinterpret_cast<const __m128i *>(
      pshufb_combine_table + pop1 * 16));
  const __m128i answer = _mm_shuffle_epi8(pruned, compactmask);
  _mm_storeu_si128(reinterpret_cast<__m128i *>(output), answer);
}

void simdutf_compress2(uint16_t mask, const char* in, char* out) {
    compress2(
        _mm_loadu_si128((__m128i*)in),
        mask,
        out
    );
}
