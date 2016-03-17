#include <immintrin.h>
#include <x86intrin.h>

#include <cstdint>
#include "../../bmi2.cpp"

namespace base64 {

    namespace sse {

#define packed_dword(x) _mm_set1_epi32(x)
#define packed_byte(x) _mm_set1_epi8(char(x))

        template <typename LOOKUP_FN>
        void encode(LOOKUP_FN lookup, uint8_t* input, size_t bytes, uint8_t* output) {

            uint8_t* out = output;

            const __m128i shuf = _mm_setr_epi8(
                0x00, 0x01, 0x02, char(0xff),
                0x03, 0x04, 0x05, char(0xff),
                0x06, 0x07, 0x08, char(0xff),
                0x09, 0x0a, 0x0b, char(0xff)
            );

            for (size_t i = 0; i < bytes; i += 4*3) {
                // input = [xxxx|DDDC|CCBB|BAAA]
                __m128i in = _mm_loadu_si128(reinterpret_cast<const __m128i*>(input + i));

                // bytes from groups A, B and C are needed in separate 32-bit lanes
                // in = [0DDD|0CCC|0BBB|0AAA]
                in = _mm_shuffle_epi8(in, shuf);


#if 0           // reference implementation

                // single lane layout; a, b, c and d are bits from 6-bit groups
                // [00000000|ddddddcc|ccccbbbb|bbaaaaaa]
                const __m128i indices_a = _mm_and_si128(in, packed_dword(0x0000003f));
                const __m128i indices_b = _mm_and_si128(_mm_slli_epi32(in, 2), packed_dword(0x00003f00));
                const __m128i indices_c = _mm_and_si128(_mm_slli_epi32(in, 4), packed_dword(0x003f0000));
                const __m128i indices_d = _mm_and_si128(_mm_slli_epi32(in, 6), packed_dword(0x3f000000));

                // indices = [00dddddd|00cccccc|00bbbbbb|00aaaaaa]
                const __m128i indices = _mm_or_si128(_mm_or_si128(_mm_or_si128(indices_a, indices_b), indices_c), indices_d);
#else
                // improved version

                // in        = [00000000|ddddddcc|ccccbbbb|bbaaaaaa]

                // indices_ab = [00000000|00000000|0000bbbb|bbaaaaaa]
                // indices_cd = [0000dddd|ddcccccc|00000000|00000000]
                const __m128i indices_ab = _mm_and_si128(in, packed_dword(0x00000fff));
                const __m128i indices_cd = _mm_and_si128(_mm_slli_epi32(in, 4), packed_dword(0x0fff0000));

                // in'       = [0000dddd|ddcccccc|0000bbbb|bbaaaaaa]
                in = _mm_or_si128(indices_ab, indices_cd);
                const __m128i indices_ac = _mm_and_si128(in, packed_dword(0x003f003f));
                const __m128i indices_db = _mm_and_si128(_mm_slli_epi32(in, 2), packed_dword(0x3f003f00));

                const __m128i indices = _mm_or_si128(indices_ac, indices_db);
#endif
                const auto result = lookup(indices);

                _mm_storeu_si128(reinterpret_cast<__m128i*>(out), result);
                out += 16;
            }
        }


        template <typename LOOKUP_FN>
        void encode_unrolled(LOOKUP_FN lookup, uint8_t* input, size_t bytes, uint8_t* output) {

            uint8_t* out = output;

            const __m128i shuf = _mm_setr_epi8(
                0x00, 0x01, 0x02, char(0xff),
                0x03, 0x04, 0x05, char(0xff),
                0x06, 0x07, 0x08, char(0xff),
                0x09, 0x0a, 0x0b, char(0xff)
            );

            for (size_t i = 0; i < bytes; i += 4*3 * 4) {

                // unrolled improved version

                __m128i in0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(input + i + 4*3 * 0));
                __m128i in1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(input + i + 4*3 * 1));
                __m128i in2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(input + i + 4*3 * 2));
                __m128i in3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(input + i + 4*3 * 3));

                in0 = _mm_shuffle_epi8(in0, shuf);
                in1 = _mm_shuffle_epi8(in1, shuf);
                in2 = _mm_shuffle_epi8(in2, shuf);
                in3 = _mm_shuffle_epi8(in3, shuf);

                const __m128i indices_ab0 = _mm_and_si128(in0, packed_dword(0x00000fff));
                const __m128i indices_ab1 = _mm_and_si128(in1, packed_dword(0x00000fff));
                const __m128i indices_ab2 = _mm_and_si128(in2, packed_dword(0x00000fff));
                const __m128i indices_ab3 = _mm_and_si128(in3, packed_dword(0x00000fff));

                const __m128i indices_cd0 = _mm_and_si128(_mm_slli_epi32(in0, 4), packed_dword(0x0fff0000));
                const __m128i indices_cd1 = _mm_and_si128(_mm_slli_epi32(in1, 4), packed_dword(0x0fff0000));
                const __m128i indices_cd2 = _mm_and_si128(_mm_slli_epi32(in2, 4), packed_dword(0x0fff0000));
                const __m128i indices_cd3 = _mm_and_si128(_mm_slli_epi32(in3, 4), packed_dword(0x0fff0000));

                in0 = _mm_or_si128(indices_ab0, indices_cd0);
                in1 = _mm_or_si128(indices_ab1, indices_cd1);
                in2 = _mm_or_si128(indices_ab2, indices_cd2);
                in3 = _mm_or_si128(indices_ab3, indices_cd3);

                const __m128i indices_ac0 = _mm_and_si128(in0, packed_dword(0x003f003f));
                const __m128i indices_ac1 = _mm_and_si128(in1, packed_dword(0x003f003f));
                const __m128i indices_ac2 = _mm_and_si128(in2, packed_dword(0x003f003f));
                const __m128i indices_ac3 = _mm_and_si128(in3, packed_dword(0x003f003f));

                const __m128i indices_db0 = _mm_and_si128(_mm_slli_epi32(in0, 2), packed_dword(0x3f003f00));
                const __m128i indices_db1 = _mm_and_si128(_mm_slli_epi32(in1, 2), packed_dword(0x3f003f00));
                const __m128i indices_db2 = _mm_and_si128(_mm_slli_epi32(in2, 2), packed_dword(0x3f003f00));
                const __m128i indices_db3 = _mm_and_si128(_mm_slli_epi32(in3, 2), packed_dword(0x3f003f00));

                const __m128i input0 = _mm_or_si128(indices_ac0, indices_db0);
                const __m128i input1 = _mm_or_si128(indices_ac1, indices_db1);
                const __m128i input2 = _mm_or_si128(indices_ac2, indices_db2);
                const __m128i input3 = _mm_or_si128(indices_ac3, indices_db3);

                {
                    const auto result = lookup(input0);

                    _mm_storeu_si128(reinterpret_cast<__m128i*>(out), result);
                    out += 16;
                }

                {
                    const auto result = lookup(input1);

                    _mm_storeu_si128(reinterpret_cast<__m128i*>(out), result);
                    out += 16;
                }

                {
                    const auto result = lookup(input2);

                    _mm_storeu_si128(reinterpret_cast<__m128i*>(out), result);
                    out += 16;
                }

                {
                    const auto result = lookup(input3);

                    _mm_storeu_si128(reinterpret_cast<__m128i*>(out), result);
                    out += 16;
                }
            }
        }


        void encode_full_unrolled(uint8_t* input, size_t bytes, uint8_t* output) {

            uint8_t* out = output;

            const __m128i shuf = _mm_setr_epi8(
                0x00, 0x01, 0x02, char(0xff),
                0x03, 0x04, 0x05, char(0xff),
                0x06, 0x07, 0x08, char(0xff),
                0x09, 0x0a, 0x0b, char(0xff)
            );

            for (size_t i = 0; i < bytes; i += 4*3 * 4) {
                
                // the same code as in encode_unrolled (no, no macros!)
                __m128i in0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(input + i + 4*3 * 0));
                __m128i in1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(input + i + 4*3 * 1));
                __m128i in2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(input + i + 4*3 * 2));
                __m128i in3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(input + i + 4*3 * 3));

                in0 = _mm_shuffle_epi8(in0, shuf);
                in1 = _mm_shuffle_epi8(in1, shuf);
                in2 = _mm_shuffle_epi8(in2, shuf);
                in3 = _mm_shuffle_epi8(in3, shuf);

                const __m128i indices_ab0 = _mm_and_si128(in0, packed_dword(0x00000fff));
                const __m128i indices_ab1 = _mm_and_si128(in1, packed_dword(0x00000fff));
                const __m128i indices_ab2 = _mm_and_si128(in2, packed_dword(0x00000fff));
                const __m128i indices_ab3 = _mm_and_si128(in3, packed_dword(0x00000fff));

                const __m128i indices_cd0 = _mm_and_si128(_mm_slli_epi32(in0, 4), packed_dword(0x0fff0000));
                const __m128i indices_cd1 = _mm_and_si128(_mm_slli_epi32(in1, 4), packed_dword(0x0fff0000));
                const __m128i indices_cd2 = _mm_and_si128(_mm_slli_epi32(in2, 4), packed_dword(0x0fff0000));
                const __m128i indices_cd3 = _mm_and_si128(_mm_slli_epi32(in3, 4), packed_dword(0x0fff0000));

                in0 = _mm_or_si128(indices_ab0, indices_cd0);
                in1 = _mm_or_si128(indices_ab1, indices_cd1);
                in2 = _mm_or_si128(indices_ab2, indices_cd2);
                in3 = _mm_or_si128(indices_ab3, indices_cd3);

                const __m128i indices_ac0 = _mm_and_si128(in0, packed_dword(0x003f003f));
                const __m128i indices_ac1 = _mm_and_si128(in1, packed_dword(0x003f003f));
                const __m128i indices_ac2 = _mm_and_si128(in2, packed_dword(0x003f003f));
                const __m128i indices_ac3 = _mm_and_si128(in3, packed_dword(0x003f003f));

                const __m128i indices_db0 = _mm_and_si128(_mm_slli_epi32(in0, 2), packed_dword(0x3f003f00));
                const __m128i indices_db1 = _mm_and_si128(_mm_slli_epi32(in1, 2), packed_dword(0x3f003f00));
                const __m128i indices_db2 = _mm_and_si128(_mm_slli_epi32(in2, 2), packed_dword(0x3f003f00));
                const __m128i indices_db3 = _mm_and_si128(_mm_slli_epi32(in3, 2), packed_dword(0x3f003f00));

                const __m128i input0 = _mm_or_si128(indices_ac0, indices_db0);
                const __m128i input1 = _mm_or_si128(indices_ac1, indices_db1);
                const __m128i input2 = _mm_or_si128(indices_ac2, indices_db2);
                const __m128i input3 = _mm_or_si128(indices_ac3, indices_db3);

                // unrolled lookup_version2 from lookup.sse.cpp
                __m128i result_0 = packed_byte(65);
                __m128i result_1 = packed_byte(65);
                __m128i result_2 = packed_byte(65);
                __m128i result_3 = packed_byte(65);

                const __m128i ge_26_0 = _mm_cmpgt_epi8(input0, packed_byte(25));
                result_0 = _mm_add_epi8(result_0, _mm_and_si128(ge_26_0, packed_byte(  6)));
                const __m128i ge_26_1 = _mm_cmpgt_epi8(input1, packed_byte(25));
                result_1 = _mm_add_epi8(result_1, _mm_and_si128(ge_26_1, packed_byte(  6)));
                const __m128i ge_26_2 = _mm_cmpgt_epi8(input2, packed_byte(25));
                result_2 = _mm_add_epi8(result_2, _mm_and_si128(ge_26_2, packed_byte(  6)));
                const __m128i ge_26_3 = _mm_cmpgt_epi8(input3, packed_byte(25));
                result_3 = _mm_add_epi8(result_3, _mm_and_si128(ge_26_3, packed_byte(  6)));

                const __m128i ge_52_0 = _mm_cmpgt_epi8(input0, packed_byte(51));
                result_0 = _mm_sub_epi8(result_0, _mm_and_si128(ge_52_0, packed_byte( 75)));
                const __m128i ge_52_1 = _mm_cmpgt_epi8(input1, packed_byte(51));
                result_1 = _mm_sub_epi8(result_1, _mm_and_si128(ge_52_1, packed_byte( 75)));
                const __m128i ge_52_2 = _mm_cmpgt_epi8(input2, packed_byte(51));
                result_2 = _mm_sub_epi8(result_2, _mm_and_si128(ge_52_2, packed_byte( 75)));
                const __m128i ge_52_3 = _mm_cmpgt_epi8(input3, packed_byte(51));
                result_3 = _mm_sub_epi8(result_3, _mm_and_si128(ge_52_3, packed_byte( 75)));

                const __m128i eq_62_0 = _mm_cmpeq_epi8(input0, packed_byte(62));
                result_0 = _mm_add_epi8(result_0, _mm_and_si128(eq_62_0, packed_byte(241)));
                const __m128i eq_62_1 = _mm_cmpeq_epi8(input1, packed_byte(62));
                result_1 = _mm_add_epi8(result_1, _mm_and_si128(eq_62_1, packed_byte(241)));
                const __m128i eq_62_2 = _mm_cmpeq_epi8(input2, packed_byte(62));
                result_2 = _mm_add_epi8(result_2, _mm_and_si128(eq_62_2, packed_byte(241)));
                const __m128i eq_62_3 = _mm_cmpeq_epi8(input3, packed_byte(62));
                result_3 = _mm_add_epi8(result_3, _mm_and_si128(eq_62_3, packed_byte(241)));

                const __m128i eq_63_0 = _mm_cmpeq_epi8(input0, packed_byte(63));
                result_0 = _mm_sub_epi8(result_0, _mm_and_si128(eq_63_0, packed_byte( 12)));
                const __m128i eq_63_1 = _mm_cmpeq_epi8(input1, packed_byte(63));
                result_1 = _mm_sub_epi8(result_1, _mm_and_si128(eq_63_1, packed_byte( 12)));
                const __m128i eq_63_2 = _mm_cmpeq_epi8(input2, packed_byte(63));
                result_2 = _mm_sub_epi8(result_2, _mm_and_si128(eq_63_2, packed_byte( 12)));
                const __m128i eq_63_3 = _mm_cmpeq_epi8(input3, packed_byte(63));
                result_3 = _mm_sub_epi8(result_3, _mm_and_si128(eq_63_3, packed_byte( 12)));

                result_0 = _mm_add_epi8(result_0, input0);
                result_1 = _mm_add_epi8(result_1, input1);
                result_2 = _mm_add_epi8(result_2, input2);
                result_3 = _mm_add_epi8(result_3, input3);

                _mm_storeu_si128(reinterpret_cast<__m128i*>(out), result_0);
                out += 16;
                _mm_storeu_si128(reinterpret_cast<__m128i*>(out), result_1);
                out += 16;
                _mm_storeu_si128(reinterpret_cast<__m128i*>(out), result_2);
                out += 16;
                _mm_storeu_si128(reinterpret_cast<__m128i*>(out), result_3);
                out += 16;
            }
        }


#if defined(HAVE_BMI2_INSTRUCTIONS)
        template <typename LOOKUP_FN>
        void encode_bmi2(LOOKUP_FN lookup, uint8_t* input, size_t bytes, uint8_t* output) {

            uint8_t* out = output;

            for (size_t i = 0; i < bytes; i += 2*6) {

                const uint64_t lo = *reinterpret_cast<const uint64_t*>(input + i);
                const uint64_t hi = *reinterpret_cast<const uint64_t*>(input + i + 6);

                const uint64_t expanded_lo = pdep(lo, 0x3f3f3f3f3f3f3f3flu);
                const uint64_t expanded_hi = pdep(hi, 0x3f3f3f3f3f3f3f3flu);
#if 1
                __m128i indices;

                indices = _mm_insert_epi64(indices, expanded_lo, 0);
                indices = _mm_insert_epi64(indices, expanded_hi, 1);
#else
                const __m128i indices = _mm_set_epi64x(expanded_hi, expanded_lo);
#endif

                const auto result = lookup(indices);

                _mm_storeu_si128(reinterpret_cast<__m128i*>(out), result);
                out += 16;
            }
        }
#endif


    #undef packed_dword
    #undef packed_byte

    } // namespace sse

} // namespace base64
