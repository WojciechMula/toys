#include <immintrin.h>
#include <x86intrin.h>

namespace base64 {

    namespace sse {

    #define packed_byte(x) _mm_set1_epi8(char(x))

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


        __m128i lookup_version2(const __m128i input) {

            __m128i result = packed_byte(65);

            const __m128i ge_26 = _mm_cmpgt_epi8(input, packed_byte(25));
            const __m128i ge_52 = _mm_cmpgt_epi8(input, packed_byte(51));
            const __m128i eq_62 = _mm_cmpeq_epi8(input, packed_byte(62));
            const __m128i eq_63 = _mm_cmpeq_epi8(input, packed_byte(63));

            result = _mm_add_epi8(result, _mm_and_si128(ge_26, packed_byte(  6)));
            result = _mm_sub_epi8(result, _mm_and_si128(ge_52, packed_byte( 75)));
            result = _mm_add_epi8(result, _mm_and_si128(eq_62, packed_byte(241)));
            result = _mm_sub_epi8(result, _mm_and_si128(eq_63, packed_byte( 12)));

            result = _mm_add_epi8(result, input);

            return result;
        }


        __m128i lookup_pshufb(const __m128i input) {

            const __m128i row_LUT = _mm_setr_epi8(
                /*  0 ..  9 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                /* 10 .. 12 */ 4*1, 4*1, 4*1,
                /* 13 .. 14 */ 4*2, 4*2,
                /*       15 */ 4*3
            );

            // input (byte): [00abcdef]

            //     bits_1_4: [000bcde0]
            //   bit_0_and5: [00a0000f]
            const __m128i bits_1_4    = input & packed_byte(0x1e);
            const __m128i bit_0_and_5 = input ^ bits_1_4;

            //       index1: [0000bcde]
            const __m128i index1 = _mm_srli_epi16(bits_1_4, 1);

            // note: row_number is already shifted left
            const __m128i row_number = _mm_shuffle_epi8(row_LUT, index1);

            //       index2: [000000af]
            const __m128i index2 = bit_0_and_5 | (_mm_srli_epi16(bit_0_and_5, 4));

            //       index2: [0000XYaf] -- bits X, Y come from row_LUT
            const __m128i shift_index = row_number | index2;

            const __m128i shift_LUT = _mm_setr_epi8(
                /* 0 */ 65, 65,  71,  71,
                /* 1 */ 65, 65,  -4,  -4,
                /* 2 */ 71, 71,  -4,  -4,
                /* 3 */ 71, 71, -19, -16
            );

            const __m128i shift = _mm_shuffle_epi8(shift_LUT, shift_index);

            return _mm_add_epi8(input, shift);
        }


        __m128i lookup_pshufb_improved(const __m128i input) {

            __m128i result = _mm_subs_epu8(input, packed_byte(51));

            const __m128i less = _mm_cmpgt_epi8(packed_byte(26), input);

            result = _mm_or_si128(result, _mm_and_si128(less, packed_byte(13)));

            const __m128i shift_LUT = _mm_setr_epi8(
                'a' - 26, '0' - 52, '0' - 52, '0' - 52, '0' - 52, '0' - 52,
                '0' - 52, '0' - 52, '0' - 52, '0' - 52, '0' - 52, '+' - 62,
                '/' - 63, 'A', 0, 0
            );

            result = _mm_shuffle_epi8(shift_LUT, result);

            return _mm_add_epi8(result, input);
        }

    #undef packed_byte

    } // namespace sse

} // namespace base64

