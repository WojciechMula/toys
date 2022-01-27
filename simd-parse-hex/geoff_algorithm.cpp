/*
Author: Geoff Langdale, https://branchfree.org/

The algorithm was described in the following tweets:

- https://twitter.com/geofflangdale/status/1484460241240539137
- https://twitter.com/geofflangdale/status/1484460243778097159
- https://twitter.com/geofflangdale/status/1484460245560684550
- https://twitter.com/geofflangdale/status/1484460247368355842
*/
#include "geoff_algorithm.h"

#include <immintrin.h>

uint64_t hex_to_u64_sse_geoff(const char* string, bool& ok) {
    __m128i v = _mm_loadu_si128((const __m128i*)string);
    
    const __m128i t1 = _mm_add_epi8(v, _mm_set1_epi8(char(0xff - '9'))); // puts 0-9 at top of unsigned integer range
    const __m128i t2 = _mm_subs_epu8(t1, _mm_set1_epi8(6)); // now, put 6 blank spots above 0-9
    const __m128i t3 = _mm_sub_epi8(t2, _mm_set1_epi8(char(0xf0)));
    const __m128i t4 = _mm_and_si128(v, _mm_set1_epi8(char(0xdf))); // squash case
    const __m128i t5 = _mm_sub_epi8(t4, _mm_set1_epi8('A')); // put the 'A-F' at 0..5
    const __m128i t6 = _mm_adds_epu8(t5, _mm_set1_epi8(10)); // now put A-F at 10..15, with a guarantee that nothing is smaller

    const __m128i t7 = _mm_min_epu8(t3, t6); // t7 is normalized hex nibbles
    const __m128i t8 = _mm_adds_epu8(t7, _mm_set1_epi8(127-15)); // t8 has high_bit == 1 iff what we had wasn't valid hex

    if (_mm_movemask_epi8(t8)) {
        ok = false;
        return 0;
    }

    // now each byte of result have value 0 .. 15, we're going to merge nibbles:
    {
        const __m128i t0 = _mm_maddubs_epi16(t7, _mm_set1_epi16(0x0110));
        const __m128i t1 = _mm_setr_epi8(
            14, 12, 10, 8, 6, 4, 2, 0,
            -1, -1, -1, -1, -1, -1, -1, -1);
        const __m128i t3 = _mm_shuffle_epi8(t0, t1);

        ok = true;
        return _mm_cvtsi128_si64x(t3);
    }
}
