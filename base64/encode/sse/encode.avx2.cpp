#include <immintrin.h>
#include <x86intrin.h>

#include <cstdint>

// definition copied from http://stackoverflow.com/questions/32630458/setting-m256i-to-the-value-of-two-m256i-values
// thank you Paul! (http://stackoverflow.com/users/253056/paul-r)
#define _mm256_set_m256i(v0, v1)  _mm256_insertf256_si256(_mm256_castsi256_si256(v1), (v0), 1)


namespace base64 {

    namespace avx2 {

#define packed_dword(x) _mm256_set1_epi32(x)

        template <typename LOOKUP_FN>
        void encode(LOOKUP_FN lookup, uint8_t* input, size_t bytes, uint8_t* output) {

            uint8_t* out = output;

            for (size_t i = 0; i < bytes; i += 2*4*3) {
#if 1
                // lo = [xxxx|DDDC|CCBB|BAAA]
                // hi = [xxxx|HHHG|GGFF|FEEE]
                const __m256i lo = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(input + i));
                const __m256i hi = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(input + i + 4*3));

                // bytes from groups A, B and C are needed in separate 32-bit lanes
                // in = [0HHH|0GGG|0FFF|0EEE[0DDD|0CCC|0BBB|0AAA]
                const __m256i shuf = _mm256_setr_epi8(
                    0x00, 0x01, 0x02, char(0xff),
                    0x03, 0x04, 0x05, char(0xff),
                    0x06, 0x07, 0x08, char(0xff),
                    0x09, 0x0a, 0x0b, char(0xff),

                    0x00, 0x01, 0x02, char(0xff),
                    0x03, 0x04, 0x05, char(0xff),
                    0x06, 0x07, 0x08, char(0xff),
                    0x09, 0x0a, 0x0b, char(0xff)
                );

                const __m256i in = _mm256_shuffle_epi8(_mm256_set_m256i(hi, lo), shuf);
#else
                // just one memory load, however it read 4-bytes off on the first iteration

                const __m256i data = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(input + i - 4));
                // data = [????|HHHG|GGFF|FEEE|DDDC|CCBB|BAAA|????]
                              256-bit lane    |   256-bit lane

                // bytes from groups A...G are placed in separate 32-bit lanes
                // in = [0HHH|0GGG|0FFF|0EEE|0DDD|0CCC|0BBB|0AAA]
                const __m256i shuf = _mm256_setr_epi8(
                    4 + 0x00, 4 + 0x01, 4 + 0x02, char(0xff),
                    4 + 0x03, 4 + 0x04, 4 + 0x05, char(0xff),
                    4 + 0x06, 4 + 0x07, 4 + 0x08, char(0xff),
                    4 + 0x09, 4 + 0x0a, 4 + 0x0b, char(0xff),

                        0x00,     0x01,     0x02, char(0xff),
                        0x03,     0x04,     0x05, char(0xff),
                        0x06,     0x07,     0x08, char(0xff),
                        0x09,     0x0a,     0x0b, char(0xff)
                );

                const __m256i in = _mm256_shuffle_epi8(data, shuf);
#endif

                // this is "improved version" well commented in ecnode.sse.cpp
                const __m256i indice_ab = _mm256_and_si256(in, packed_dword(0x00000fff));
                const __m256i indice_cd = _mm256_and_si256(_mm256_slli_epi32(in, 4), packed_dword(0x0fff0000));
                const __m256i in2 = _mm256_or_si256(indice_ab, indice_cd);
                const __m256i indice_ac = _mm256_and_si256(in, packed_dword(0x003f003f));
                const __m256i indice_db = _mm256_and_si256(_mm256_slli_epi32(in, 2), packed_dword(0x3f003f00));
                const __m256i indices = _mm256_or_si256(indice_ac, indice_db);

                const auto result = lookup(indices);

                _mm256_storeu_si256(reinterpret_cast<__m256i*>(out), result);
                out += 32;
            }
        }


        template <typename LOOKUP_FN>
        void encode_lookup(LOOKUP_FN lookup, uint8_t* input, size_t bytes, uint8_t* output) {

            uint8_t* out = output;

            for (size_t i = 0; i < bytes; i += 2*4*3 * 4) {

                const __m256i lo0 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(input + i + 4*3*0));
                const __m256i hi0 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(input + i + 4*3*1));
                const __m256i lo1 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(input + i + 4*3*2));
                const __m256i hi1 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(input + i + 4*3*3));
                const __m256i lo2 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(input + i + 4*3*4));
                const __m256i hi2 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(input + i + 4*3*5));
                const __m256i lo3 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(input + i + 4*3*6));
                const __m256i hi3 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(input + i + 4*3*7));

                // bytes from groups A, B and C are needed in separate 32-bit lanes
                // in = [0HHH|0GGG|0FFF|0EEE[0DDD|0CCC|0BBB|0AAA]
                const __m256i shuf = _mm256_setr_epi8(
                    0x00, 0x01, 0x02, char(0xff),
                    0x03, 0x04, 0x05, char(0xff),
                    0x06, 0x07, 0x08, char(0xff),
                    0x09, 0x0a, 0x0b, char(0xff),

                    0x00, 0x01, 0x02, char(0xff),
                    0x03, 0x04, 0x05, char(0xff),
                    0x06, 0x07, 0x08, char(0xff),
                    0x09, 0x0a, 0x0b, char(0xff)
                );

                const __m256i indice_ab0 = _mm256_and_si256(in0, packed_dword(0x00000fff));
                const __m256i indice_ab1 = _mm256_and_si256(in1, packed_dword(0x00000fff));
                const __m256i indice_ab2 = _mm256_and_si256(in2, packed_dword(0x00000fff));
                const __m256i indice_ab3 = _mm256_and_si256(in3, packed_dword(0x00000fff));

                const __m256i indice_cd0 = _mm256_and_si256(_mm256_slli_epi32(in0, 4), packed_dword(0x0fff0000));
                const __m256i indice_cd1 = _mm256_and_si256(_mm256_slli_epi32(in1, 4), packed_dword(0x0fff0000));
                const __m256i indice_cd2 = _mm256_and_si256(_mm256_slli_epi32(in2, 4), packed_dword(0x0fff0000));
                const __m256i indice_cd3 = _mm256_and_si256(_mm256_slli_epi32(in3, 4), packed_dword(0x0fff0000));

                in0 = _mm256_or_si256(indice_ab0, indice_cd0);
                in1 = _mm256_or_si256(indice_ab1, indice_cd1);
                in2 = _mm256_or_si256(indice_ab2, indice_cd2);
                in3 = _mm256_or_si256(indice_ab3, indice_cd3);

                const __m256i indice_ac0 = _mm256_and_si256(in0, packed_dword(0x003f003f));
                const __m256i indice_ac1 = _mm256_and_si256(in1, packed_dword(0x003f003f));
                const __m256i indice_ac2 = _mm256_and_si256(in2, packed_dword(0x003f003f));
                const __m256i indice_ac3 = _mm256_and_si256(in3, packed_dword(0x003f003f));

                const __m256i indice_db0 = _mm256_and_si256(_mm256_slli_epi32(in0, 2), packed_dword(0x3f003f00));
                const __m256i indice_db1 = _mm256_and_si256(_mm256_slli_epi32(in1, 2), packed_dword(0x3f003f00));
                const __m256i indice_db2 = _mm256_and_si256(_mm256_slli_epi32(in2, 2), packed_dword(0x3f003f00));
                const __m256i indice_db3 = _mm256_and_si256(_mm256_slli_epi32(in3, 2), packed_dword(0x3f003f00));

                const __m256i input0 = _mm256_or_si256(indice_ac0, indice_db0);
                const __m256i input1 = _mm256_or_si256(indice_ac1, indice_db1);
                const __m256i input2 = _mm256_or_si256(indice_ac2, indice_db2);
                const __m256i input3 = _mm256_or_si256(indice_ac3, indice_db3);

                {
                    const auto result = lookup(input0);

                    _mm256_storeu_si256(reinterpret_cast<__m256i*>(out), result);
                    out += 32;
                }
                {
                    const auto result = lookup(input1);

                    _mm256_storeu_si256(reinterpret_cast<__m256i*>(out), result);
                    out += 32;
                }
                {
                    const auto result = lookup(input2);

                    _mm256_storeu_si256(reinterpret_cast<__m256i*>(out), result);
                    out += 32;
                }
                {
                    const auto result = lookup(input3);

                    _mm256_storeu_si256(reinterpret_cast<__m256i*>(out), result);
                    out += 32;
                }
            }
        }

    #undef packed_dword

    } // namespace sse

} // namespace base64
