#include <cstdint>
#include <cassert>

#include <immintrin.h>
#include <x86intrin.h>

namespace base64 {

    namespace avx2 {

        __m256i lookup_base(const __m256i input) {

            // see comment in decode.sse.cpp

#define packed_byte(b) _mm256_set1_epi8(uint8_t(b))

            // shift for range 'A' - 'Z'
            const __m256i ge_A = _mm256_cmpgt_epi8(input, packed_byte('A' - 1));
            const __m256i gt_Z = _mm256_cmpgt_epi8(input, packed_byte('Z'));
            const __m256i range_AZ = _mm256_and_si256(packed_byte(-65), _mm256_andnot_si256(gt_Z, ge_A));

            // shift for range 'a' - 'z'
            const __m256i ge_a = _mm256_cmpgt_epi8(input, packed_byte('a' - 1));
            const __m256i gt_z = _mm256_cmpgt_epi8(input, packed_byte('z'));
            const __m256i range_az = _mm256_and_si256(packed_byte(-71), _mm256_andnot_si256(gt_z, ge_a));

            // shift for range '0' - '9'
            const __m256i ge_0 = _mm256_cmpgt_epi8(input, packed_byte('0' - 1));
            const __m256i gt_9 = _mm256_cmpgt_epi8(input, packed_byte('9'));
            const __m256i range_09 = _mm256_and_si256(packed_byte(4), _mm256_andnot_si256(gt_9, ge_0));

            // shift for character '+'
            const __m256i eq_plus = _mm256_cmpeq_epi8(input, packed_byte('+'));
            const __m256i char_plus = _mm256_and_si256(packed_byte(19), eq_plus);

            // shift for character '/'
            const __m256i eq_slash = _mm256_cmpeq_epi8(input, packed_byte('/'));
            const __m256i char_slash = _mm256_and_si256(packed_byte(16), eq_slash);

            // merge partial results

            const __m256i shift = _mm256_or_si256(range_AZ,
                                  _mm256_or_si256(range_az,
                                  _mm256_or_si256(range_09,
                                  _mm256_or_si256(char_plus, char_slash))));

            // Individual shift values are non-zero, thus if any
            // byte in a shift vector is zero, then the input
            // contains invalid bytes.
            const auto mask = _mm256_movemask_epi8(_mm256_cmpeq_epi8(shift, packed_byte(0)));
            if (mask) {
                // some characters do not match the valid range
                for (unsigned i=0; i < 32; i++) {
                    if (mask & (1 << i)) {
                        throw invalid_input(i, 0);
                    }
                }
            }

            return _mm256_add_epi8(input, shift);
#undef packed_byte
        }


        __m256i lookup_byte_blend(const __m256i input) {

#define packed_byte(b) _mm256_set1_epi8(uint8_t(b))

            __m256i shift;

            // shift for range 'A' - 'Z'
            const __m256i ge_A = _mm256_cmpgt_epi8(input, packed_byte('A' - 1));
            const __m256i gt_Z = _mm256_cmpgt_epi8(input, packed_byte('Z'));
            shift = _mm256_and_si256(packed_byte(-65), _mm256_andnot_si256(gt_Z, ge_A));

            // shift for range 'a' - 'z'
            const __m256i ge_a = _mm256_cmpgt_epi8(input, packed_byte('a' - 1));
            const __m256i gt_z = _mm256_cmpgt_epi8(input, packed_byte('z'));
            shift = _mm256_blendv_epi8(shift, packed_byte(-71), _mm256_andnot_si256(gt_z, ge_a));

            // shift for range '0' - '9'
            const __m256i ge_0 = _mm256_cmpgt_epi8(input, packed_byte('0' - 1));
            const __m256i gt_9 = _mm256_cmpgt_epi8(input, packed_byte('9'));
            shift = _mm256_blendv_epi8(shift, packed_byte(4), _mm256_andnot_si256(gt_9, ge_0));

            // shift for character '+'
            const __m256i eq_plus = _mm256_cmpeq_epi8(input, packed_byte('+'));
            shift = _mm256_blendv_epi8(shift, packed_byte(19), eq_plus);

            // shift for character '/'
            const __m256i eq_slash = _mm256_cmpeq_epi8(input, packed_byte('/'));
            shift = _mm256_blendv_epi8(shift, packed_byte(16), eq_slash);

            // Individual shift values are non-zero, thus if any
            // byte in a shift vector is zero, then the input
            // contains invalid bytes.
            const auto mask = _mm256_movemask_epi8(_mm256_cmpeq_epi8(shift, packed_byte(0)));
            if (mask) {
                // some characters do not match the valid range
                for (unsigned i=0; i < 32; i++) {
                    if (mask & (1 << i)) {
                        throw invalid_input(i, 0);
                    }
                }
            }

            return _mm256_add_epi8(input, shift);
#undef packed_byte
        }


        __m256i lookup_pshufb(const __m256i input) {

#define packed_byte(b) _mm256_set1_epi8(uint8_t(b))

            const __m256i higher_nibble = _mm256_srli_epi32(input, 4) & packed_byte(0x0f);
            const char linv = 1;
            const char hinv = 0;

            const __m256i lower_bound_LUT = _mm256_setr_epi8(
                /* 0 */ linv, /* 1 */ linv, /* 2 */ 0x2b, /* 3 */ 0x30,
                /* 4 */ 0x41, /* 5 */ 0x50, /* 6 */ 0x61, /* 7 */ 0x70,
                /* 8 */ linv, /* 9 */ linv, /* a */ linv, /* b */ linv,
                /* c */ linv, /* d */ linv, /* e */ linv, /* f */ linv,

                /* 0 */ linv, /* 1 */ linv, /* 2 */ 0x2b, /* 3 */ 0x30,
                /* 4 */ 0x41, /* 5 */ 0x50, /* 6 */ 0x61, /* 7 */ 0x70,
                /* 8 */ linv, /* 9 */ linv, /* a */ linv, /* b */ linv,
                /* c */ linv, /* d */ linv, /* e */ linv, /* f */ linv
            );

            const __m256i upper_bound_LUT = _mm256_setr_epi8(
                /* 0 */ hinv, /* 1 */ hinv, /* 2 */ 0x2b, /* 3 */ 0x39,
                /* 4 */ 0x4f, /* 5 */ 0x5a, /* 6 */ 0x6f, /* 7 */ 0x7a,
                /* 8 */ hinv, /* 9 */ hinv, /* a */ hinv, /* b */ hinv,
                /* c */ hinv, /* d */ hinv, /* e */ hinv, /* f */ hinv,

                /* 0 */ hinv, /* 1 */ hinv, /* 2 */ 0x2b, /* 3 */ 0x39,
                /* 4 */ 0x4f, /* 5 */ 0x5a, /* 6 */ 0x6f, /* 7 */ 0x7a,
                /* 8 */ hinv, /* 9 */ hinv, /* a */ hinv, /* b */ hinv,
                /* c */ hinv, /* d */ hinv, /* e */ hinv, /* f */ hinv
            );

            const __m256i shift_LUT = _mm256_setr_epi8(
                /* 0 */ 0x00, /* 1 */ 0x00, /* 2 */ 0x3e, /* 3 */ 0x34,
                /* 4 */ 0x00, /* 5 */ 0x0f, /* 6 */ 0x1a, /* 7 */ 0x29,
                /* 8 */ 0x00, /* 9 */ 0x00, /* a */ 0x00, /* b */ 0x00,
                /* c */ 0x00, /* d */ 0x00, /* e */ 0x00, /* f */ 0x00,

                /* 0 */ 0x00, /* 1 */ 0x00, /* 2 */ 0x3e, /* 3 */ 0x34,
                /* 4 */ 0x00, /* 5 */ 0x0f, /* 6 */ 0x1a, /* 7 */ 0x29,
                /* 8 */ 0x00, /* 9 */ 0x00, /* a */ 0x00, /* b */ 0x00,
                /* c */ 0x00, /* d */ 0x00, /* e */ 0x00, /* f */ 0x00
            );

            const __m256i upper_bound = _mm256_shuffle_epi8(upper_bound_LUT, higher_nibble);
            const __m256i lower_bound = _mm256_shuffle_epi8(lower_bound_LUT, higher_nibble);

            const __m256i below = _mm256_cmpgt_epi8(lower_bound, input);
            const __m256i above = _mm256_cmpgt_epi8(input, upper_bound);
            const __m256i eq_2f = _mm256_cmpeq_epi8(input, packed_byte(0x2f));

            const __m256i outside = _mm256_andnot_si256(eq_2f, above | below);

            const auto mask = _mm256_movemask_epi8(outside);
            if (mask) {
                // some characters do not match the valid range
                for (unsigned i=0; i < 32; i++) {
                    if (mask & (1 << i)) {
                        throw invalid_input(i, 0);
                    }
                }
            }

            __m256i shift = _mm256_shuffle_epi8(shift_LUT, higher_nibble);
            __m256i result = _mm256_sub_epi8(input, lower_bound);
            result = _mm256_add_epi8(result, shift);
            result = _mm256_add_epi8(result, _mm256_and_si256(eq_2f, packed_byte(-3)));

            return result;
#undef packed_byte
        }

    } // namespace avx2

} // namespace base64
