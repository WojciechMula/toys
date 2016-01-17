#include <cstdint>
#include <cassert>

#include <immintrin.h>
#include <x86intrin.h>

namespace base64 {

    namespace sse {

        __m128i lookup(const __m128i input) {

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

        void decode(const uint8_t* input, size_t size, uint8_t* output) {

            assert(size % 16 == 0);

            uint8_t* out = output;

            for (size_t i=0; i < size; i += 16) {

                __m128i in = _mm_loadu_si128(reinterpret_cast<const __m128i*>(input + i));
                __m128i values;

                try {
                    values = lookup(in);
                } catch (invalid_input& e) {
                    
                    const auto shift = e.offset;
                    throw invalid_input(i + shift, input[i + shift]);
                }

                // input:  packed_dword([00dddddd|00cccccc|00bbbbbb|00aaaaaa] x 4)
                // merged: packed_dword([00000000|ddddddcc|ccccbbbb|bbaaaaaa] x 4)

#define packed_dword(x) _mm_set1_epi32(x)
                const __m128i bits_a = _mm_and_si128(values, packed_dword(0x0000003f));
                const __m128i bits_b = _mm_srli_epi32(_mm_and_si128(values, packed_dword(0x00003f00)), 2);
                const __m128i bits_c = _mm_srli_epi32(_mm_and_si128(values, packed_dword(0x003f0000)), 4);
                const __m128i bits_d = _mm_srli_epi32(_mm_and_si128(values, packed_dword(0x3f000000)), 6);
#undef packed_dword
                const __m128i merged = _mm_or_si128(bits_a,
                                       _mm_or_si128(bits_b,
                                       _mm_or_si128(bits_c, bits_d)));

                // merged = packed_byte([0XXX|0YYY|0ZZZ|0WWW])

                const __m128i shuf = _mm_setr_epi8(
                       0,  1,  2,
                       4,  5,  6,
                       8,  9, 10,
                      12, 13, 14,
                      char(0xff), char(0xff), char(0xff), char(0xff)
                );

                // lower 12 bytes contains
                const __m128i shuffled = _mm_shuffle_epi8(merged, shuf);

#if 0
                // Note: maskmove is slower on Core i5 than bare write
                const __m128i mask = _mm_setr_epi8(
                      char(0xff), char(0xff), char(0xff), char(0xff),
                      char(0xff), char(0xff), char(0xff), char(0xff),
                      char(0xff), char(0xff), char(0xff), char(0xff),
                      char(0x00), char(0x00), char(0x00), char(0x00)
                );
                _mm_maskmoveu_si128(shuffled, mask, reinterpret_cast<char*>(out));
#else
                _mm_storeu_si128(reinterpret_cast<__m128i*>(out), shuffled);
#endif
                out += 12;
            }
        }

    } // namespace sse

} // namespace base64

