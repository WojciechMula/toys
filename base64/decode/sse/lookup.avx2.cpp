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

    } // namespace avx2

} // namespace base64
