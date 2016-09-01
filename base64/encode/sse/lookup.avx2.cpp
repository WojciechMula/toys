#include <immintrin.h>
#include <x86intrin.h>

#include <cstdint>

namespace base64 {

    namespace avx2 {

    #define packed_byte(x) _mm256_set1_epi8(char(x))

        __m256i lookup_version2(const __m256i input) {

            __m256i result = packed_byte(65);

            const __m256i ge_26 = _mm256_cmpgt_epi8(input, packed_byte(25));
            const __m256i ge_52 = _mm256_cmpgt_epi8(input, packed_byte(51));
            const __m256i eq_62 = _mm256_cmpeq_epi8(input, packed_byte(62));
            const __m256i eq_63 = _mm256_cmpeq_epi8(input, packed_byte(63));

            result = _mm256_add_epi8(result, _mm256_and_si256(ge_26, packed_byte(  6)));
            result = _mm256_sub_epi8(result, _mm256_and_si256(ge_52, packed_byte( 75)));
            result = _mm256_add_epi8(result, _mm256_and_si256(eq_62, packed_byte(241)));
            result = _mm256_sub_epi8(result, _mm256_and_si256(eq_63, packed_byte( 12)));

            result = _mm256_add_epi8(result, input);

            return result;
        }


        __m256i lookup_pshufb(const __m256i input) {

            const __m256i row_LUT = _mm256_setr_epi8(
                /*  0 ..  9 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                /* 10 .. 12 */ 4*1, 4*1, 4*1,
                /* 13 .. 14 */ 4*2, 4*2,
                /*       15 */ 4*3,
                /*  0 ..  9 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                /* 10 .. 12 */ 4*1, 4*1, 4*1,
                /* 13 .. 14 */ 4*2, 4*2,
                /*       15 */ 4*3
            );

            const __m256i bits_1_4    = input & packed_byte(0x1e);
            const __m256i bit_0_and_5 = input ^ bits_1_4;
            const __m256i index1 = _mm256_srli_epi16(bits_1_4, 1);
            const __m256i row_number = _mm256_shuffle_epi8(row_LUT, index1);
            const __m256i index2 = bit_0_and_5 | (_mm256_srli_epi16(bit_0_and_5, 4));
            const __m256i shift_index = row_number | index2;

            const __m256i shift_LUT = _mm256_setr_epi8(
                /* 0 */ 65, 65,  71,  71,
                /* 1 */ 65, 65,  -4,  -4,
                /* 2 */ 71, 71,  -4,  -4,
                /* 3 */ 71, 71, -19, -16,
                /* 0 */ 65, 65,  71,  71,
                /* 1 */ 65, 65,  -4,  -4,
                /* 2 */ 71, 71,  -4,  -4,
                /* 3 */ 71, 71, -19, -16
            );

            const __m256i shift = _mm256_shuffle_epi8(shift_LUT, shift_index);

            return _mm256_add_epi8(input, shift);
        }


        __m256i lookup_pshufb_improved(const __m256i input) {

            __m256i result = _mm256_subs_epu8(input, packed_byte(51));

            const __m256i less = _mm256_cmpgt_epi8(packed_byte(26), input);

            result = _mm256_or_si256(result, _mm256_and_si256(less, packed_byte(13)));

            const __m256i shift_LUT = _mm256_setr_epi8(
                'a' - 26, '0' - 52, '0' - 52, '0' - 52, '0' - 52, '0' - 52,
                '0' - 52, '0' - 52, '0' - 52, '0' - 52, '0' - 52, '+' - 62,
                '/' - 63, 'A', 0, 0,

                'a' - 26, '0' - 52, '0' - 52, '0' - 52, '0' - 52, '0' - 52,
                '0' - 52, '0' - 52, '0' - 52, '0' - 52, '0' - 52, '+' - 62,
                '/' - 63, 'A', 0, 0
            );

            result = _mm256_shuffle_epi8(shift_LUT, result);

            return _mm256_add_epi8(result, input);
        }



    #undef packed_byte

    } // namespace avx2

} // namespace base64

