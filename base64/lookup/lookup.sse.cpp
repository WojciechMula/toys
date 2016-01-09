#include <immintrin.h>
#include <x86intrin.h>

#include <cstdint>

namespace base64 {

    namespace sse {

    #define packed_byte(x) _mm_set1_epi8(x)

        __m128i lookup_naive(const __m128i input) {

            const __m128i less_26  = _mm_cmplt_epi8(input, packed_byte(26));
            const __m128i less_52  = _mm_cmplt_epi8(input, packed_byte(52));
            const __m128i less_62  = _mm_cmplt_epi8(input, packed_byte(62));
            const __m128i equal_62 = _mm_cmpeq_epi8(input, packed_byte(62));
            const __m128i equal_63 = _mm_cmpeq_epi8(input, packed_byte(63));

            const __m128i range_AZ = _mm_and_si128(packed_byte('A'), less_26);
            const __m128i range_az = _mm_and_si128(packed_byte('a' - 26), _mm_andnot_si128(less_26, less_52));
            const __m128i range_09 = _mm_and_si128(packed_byte('0' - 52), _mm_andnot_si128(less_52, less_62));
            const __m128i char_plus  = _mm_and_si128(packed_byte('+' - 62), equal_62);
            const __m128i char_slash = _mm_and_si128(packed_byte('/' - 63), equal_63);

            __m128i shift;
            shift = _mm_or_si128(range_AZ, range_az);
            shift = _mm_or_si128(shift, range_09);
            shift = _mm_or_si128(shift, char_plus);
            shift = _mm_or_si128(shift, char_slash);

            return _mm_add_epi8(shift, input);
        }


        __m128i lookup_version1(const __m128i input) {

            const uint8_t shift_AZ = 'A';
            const uint8_t shift_az = 'a' - 26;

            __m128i result = packed_byte(65);

            const __m128i ge_26 = _mm_cmpgt_epi8(input, packed_byte(25));
            result = _mm_add_epi8(result, _mm_and_si128(ge_26, packed_byte(shift_az - shift_AZ)));

            const __m128i ge_52 = _mm_cmpgt_epi8(input, packed_byte(51));
            result = _mm_sub_epi8(result, _mm_and_si128(ge_52, packed_byte(75)));

            result = _mm_add_epi8(result, input);
            const __m128i le_61 = _mm_cmplt_epi8(input, packed_byte(62));
            result = _mm_and_si128(result, le_61);

            __m128i ord_62_or_63 = packed_byte('+');
            const __m128i eq_63  = _mm_cmpeq_epi8(input, packed_byte(63));
            ord_62_or_63 = _mm_add_epi8(ord_62_or_63, _mm_and_si128(eq_63, packed_byte(4)));
            ord_62_or_63 = _mm_andnot_si128(le_61, ord_62_or_63);

            result = _mm_or_si128(result, ord_62_or_63);

            return result;
        }

    } // namespace sse

} // namespace base64

