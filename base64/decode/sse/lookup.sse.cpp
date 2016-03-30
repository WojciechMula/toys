#include <cstdint>
#include <cassert>

#include <immintrin.h>
#include <x86intrin.h>

namespace base64 {

    namespace sse {

        __m128i lookup_base(const __m128i input) {

            /*
            +--------+-------------------+------------------------+
            | range  | expression        | after constant folding |
            +========+===================+========================+
            | A-Z    | i - ord('A')      | i - 65                 |
            +--------+-------------------+------------------------+
            | a-z    | i - ord('a') + 26 | i - 71                 |
            +--------+-------------------+------------------------+
            | 0-9    | i - ord('0') + 52 | i + 4                  |
            +--------+-------------------+------------------------+
            | +      | i - ord('+') + 62 | i + 19                 |
            +--------+-------------------+------------------------+
            | /      | i - ord('/') + 63 | i + 16                 |
            +--------+-------------------+------------------------+

            number of operations:
            - cmp (le/gt/eq): 9
            - bit-and:        8
            - bit-or:         4
            - add:            1
            - movemask:       1
            - total:        =23
            */

#define packed_byte(b) _mm_set1_epi8(uint8_t(b))

            // shift for range 'A' - 'Z'
            const __m128i ge_A = _mm_cmpgt_epi8(input, packed_byte('A' - 1));
            const __m128i le_Z = _mm_cmplt_epi8(input, packed_byte('Z' + 1));
            const __m128i range_AZ = _mm_and_si128(packed_byte(-65), _mm_and_si128(ge_A, le_Z));

            // shift for range 'a' - 'z'
            const __m128i ge_a = _mm_cmpgt_epi8(input, packed_byte('a' - 1));
            const __m128i le_z = _mm_cmplt_epi8(input, packed_byte('z' + 1));
            const __m128i range_az = _mm_and_si128(packed_byte(-71), _mm_and_si128(ge_a, le_z));

            // shift for range '0' - '9'
            const __m128i ge_0 = _mm_cmpgt_epi8(input, packed_byte('0' - 1));
            const __m128i le_9 = _mm_cmplt_epi8(input, packed_byte('9' + 1));
            const __m128i range_09 = _mm_and_si128(packed_byte(4), _mm_and_si128(ge_0, le_9));

            // shift for character '+'
            const __m128i eq_plus = _mm_cmpeq_epi8(input, packed_byte('+'));
            const __m128i char_plus = _mm_and_si128(packed_byte(19), eq_plus);

            // shift for character '/'
            const __m128i eq_slash = _mm_cmpeq_epi8(input, packed_byte('/'));
            const __m128i char_slash = _mm_and_si128(packed_byte(16), eq_slash);

            // merge partial results

            const __m128i shift = _mm_or_si128(range_AZ,
                                  _mm_or_si128(range_az,
                                  _mm_or_si128(range_09,
                                  _mm_or_si128(char_plus, char_slash))));

            // Individual shift values are non-zero, thus if any
            // byte in a shift vector is zero, then the input
            // contains invalid bytes.
            const auto mask = _mm_movemask_epi8(_mm_cmpeq_epi8(shift, packed_byte(0)));
            if (mask) {
                // some characters do not match the valid range
                for (unsigned i=0; i < 16; i++) {
                    if (mask & (1 << i)) {
                        throw invalid_input(i, 0);
                    }
                }
            }

            return _mm_add_epi8(input, shift);
#undef packed_byte
        }


        __m128i lookup_byte_blend(const __m128i input) {

            /*
            improvment of lookup_base

            number of operations:
            - cmp (le/gt/eq): 9
            - bit-and:        4
            - byte-blend:     4
            - add:            1
            - movemask:       1
            - total:        =19
            */

#define packed_byte(b) _mm_set1_epi8(uint8_t(b))

            __m128i shift;

            // shift for range 'A' - 'Z'
            const __m128i ge_A = _mm_cmpgt_epi8(input, packed_byte('A' - 1));
            const __m128i le_Z = _mm_cmplt_epi8(input, packed_byte('Z' + 1));
            shift = _mm_and_si128(packed_byte(-65), _mm_and_si128(ge_A, le_Z));

            // shift for range 'a' - 'z'
            const __m128i ge_a = _mm_cmpgt_epi8(input, packed_byte('a' - 1));
            const __m128i le_z = _mm_cmplt_epi8(input, packed_byte('z' + 1));
            shift = _mm_blendv_epi8(shift, packed_byte(-71), _mm_and_si128(ge_a, le_z));

            // shift for range '0' - '9'
            const __m128i ge_0 = _mm_cmpgt_epi8(input, packed_byte('0' - 1));
            const __m128i le_9 = _mm_cmplt_epi8(input, packed_byte('9' + 1));
            shift = _mm_blendv_epi8(shift, packed_byte(4), _mm_and_si128(ge_0, le_9));

            // shift for character '+'
            const __m128i eq_plus = _mm_cmpeq_epi8(input, packed_byte('+'));
            shift = _mm_blendv_epi8(shift, packed_byte(19), eq_plus);

            // shift for character '/'
            const __m128i eq_slash = _mm_cmpeq_epi8(input, packed_byte('/'));
            shift = _mm_blendv_epi8(shift, packed_byte(16), eq_slash);

            // Individual shift values are non-zero, thus if any
            // byte in a shift vector is zero, then the input
            // contains invalid bytes.
            const auto mask = _mm_movemask_epi8(_mm_cmpeq_epi8(shift, packed_byte(0)));
            if (mask) {
                // some characters do not match the valid range
                for (unsigned i=0; i < 16; i++) {
                    if (mask & (1 << i)) {
                        throw invalid_input(i, 0);
                    }
                }
            }

            return _mm_add_epi8(input, shift);
#undef packed_byte
        }


        __m128i lookup_incremental(const __m128i input) {
            /*
            +-------+------------+-----------+--------+
            | index | byte range | comment   | shift  |
            +=======+============+===========+========+
            |  0    |  00 ..  42 | invalid   |      0 |
            +-------+------------+-----------+--------+
            |  1    |         43 | '+'       |  19    |
            +-------+------------+-----------+--------+
            |  2    |  44 ..  46 | invalid   |      0 |
            +-------+------------+-----------+--------+
            |  3    |         47 | '/'       |  16    |
            +-------+------------+-----------+--------+
            |  4    |  48 ..  57 | '0' - '9' |   4    |
            +-------+------------+-----------+--------+
            |  5    |  58 ..  64 | invalid   |      0 |
            +-------+------------+-----------+--------+
            |  6    |  65 ..  90 | 'A' - 'Z' | -65    |
            +-------+------------+-----------+--------+
            |  7    |  91 ..  96 | invalid   |      0 |
            +-------+------------+-----------+--------+
            |  8    |  97 .. 122 | 'a' - 'z' | -71    |
            +-------+------------+-----------+--------+
            |  9    | 122 .. ... | invalid   |      0 |
            +-------+------------+-----------+--------+

            number of operations:
            - cmp (le/gt/eq): 9
            - add:           10
            - movemask:       1
            - pshufb          1
            - total:        =21
            */

#define packed_byte(b) _mm_set1_epi8(uint8_t(b))

            // value from the first column
            __m128i index = packed_byte(0);

            index = _mm_sub_epi8(index, _mm_cmpgt_epi8(input, packed_byte(42)));
            index = _mm_sub_epi8(index, _mm_cmpgt_epi8(input, packed_byte(43)));
            index = _mm_sub_epi8(index, _mm_cmpgt_epi8(input, packed_byte(46)));
            index = _mm_sub_epi8(index, _mm_cmpgt_epi8(input, packed_byte(47)));
            index = _mm_sub_epi8(index, _mm_cmpgt_epi8(input, packed_byte(57)));
            index = _mm_sub_epi8(index, _mm_cmpgt_epi8(input, packed_byte(64)));
            index = _mm_sub_epi8(index, _mm_cmpgt_epi8(input, packed_byte(90)));
            index = _mm_sub_epi8(index, _mm_cmpgt_epi8(input, packed_byte(96)));
            index = _mm_sub_epi8(index, _mm_cmpgt_epi8(input, packed_byte(122)));

            const char invalid = 0;
            const __m128i LUT = _mm_setr_epi8(
             /* 0 */ invalid,
             /* 1 */ char(19),
             /* 2 */ invalid,
             /* 3 */ char(16),
             /* 4 */ char(4),
             /* 5 */ invalid,
             /* 6 */ char(-65),
             /* 7 */ invalid,
             /* 8 */ char(-71),
             /* 9 */ invalid,
             // the rest is also invalid
             invalid, invalid, invalid, invalid, invalid, invalid
            );

            const __m128i shift = _mm_shuffle_epi8(LUT, index);

            const auto mask = _mm_movemask_epi8(_mm_cmpeq_epi8(shift, packed_byte(0)));
            if (mask) {
                // some characters do not match the valid range
                for (unsigned i=0; i < 16; i++) {
                    if (mask & (1 << i)) {
                        throw invalid_input(i, 0);
                    }
                }
            }

            return _mm_add_epi8(input, shift);
#undef packed_byte
        }


        __m128i lookup_pshufb(const __m128i input) {

            /*
            number of operations:
            - cmp (le/gt/eq):  3
            - shift:           1
            - add/sub:         3
            - and/or/andnot:   4
            - movemask:        1
            - pshufb           3
            - total:         =15
            */

#define packed_byte(b) _mm_set1_epi8(uint8_t(b))

            const __m128i higher_nibble = _mm_srli_epi32(input, 4) & packed_byte(0x0f);
            const char linv = 1;
            const char hinv = 0;

            const __m128i lower_bound_LUT = _mm_setr_epi8(
                /* 0 */ linv, /* 1 */ linv, /* 2 */ 0x2b, /* 3 */ 0x30,
                /* 4 */ 0x41, /* 5 */ 0x50, /* 6 */ 0x61, /* 7 */ 0x70,
                /* 8 */ linv, /* 9 */ linv, /* a */ linv, /* b */ linv,
                /* c */ linv, /* d */ linv, /* e */ linv, /* f */ linv
            );

            const __m128i upper_bound_LUT = _mm_setr_epi8(
                /* 0 */ hinv, /* 1 */ hinv, /* 2 */ 0x2b, /* 3 */ 0x39,
                /* 4 */ 0x4f, /* 5 */ 0x5a, /* 6 */ 0x6f, /* 7 */ 0x7a,
                /* 8 */ hinv, /* 9 */ hinv, /* a */ hinv, /* b */ hinv,
                /* c */ hinv, /* d */ hinv, /* e */ hinv, /* f */ hinv
            );

            const __m128i shift_LUT = _mm_setr_epi8(
                /* 0 */ 0x00, /* 1 */ 0x00, /* 2 */ 0x3e, /* 3 */ 0x34,
                /* 4 */ 0x00, /* 5 */ 0x0f, /* 6 */ 0x1a, /* 7 */ 0x29,
                /* 8 */ 0x00, /* 9 */ 0x00, /* a */ 0x00, /* b */ 0x00,
                /* c */ 0x00, /* d */ 0x00, /* e */ 0x00, /* f */ 0x00
            );

            const __m128i upper_bound = _mm_shuffle_epi8(upper_bound_LUT, higher_nibble);
            const __m128i lower_bound = _mm_shuffle_epi8(lower_bound_LUT, higher_nibble);

            const __m128i below = _mm_cmplt_epi8(input, lower_bound);
            const __m128i above = _mm_cmpgt_epi8(input, upper_bound);
            const __m128i eq_2f = _mm_cmpeq_epi8(input, packed_byte(0x2f));

            // in_range = not (below or above) or eq_2f
            // outside  = not in_range = below or above and not eq_2f (from de Morgan law)
            const __m128i outside = _mm_andnot_si128(eq_2f, above | below);

            const auto mask = _mm_movemask_epi8(outside);
            if (mask) {
                // some characters do not match the valid range
                for (unsigned i=0; i < 16; i++) {
                    if (mask & (1 << i)) {
                        throw invalid_input(i, 0);
                    }
                }
            }

            __m128i shift  = _mm_shuffle_epi8(shift_LUT, higher_nibble);
            __m128i result = _mm_sub_epi8(input, lower_bound);
            result = _mm_add_epi8(result, shift);
            result = _mm_add_epi8(result, _mm_and_si128(eq_2f, packed_byte(-3)));

            return result;
#undef packed_byte
        }

    } // namespace sse

} // namespace base64

