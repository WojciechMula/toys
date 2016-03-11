#include <immintrin.h>
#include <x86intrin.h>

#include <cstdint>

// definition copied from http://stackoverflow.com/questions/32630458/setting-m256i-to-the-value-of-two-m128i-values
// thank you Paul! (http://stackoverflow.com/users/253056/paul-r)
#define _mm256_set_m128i(v0, v1)  _mm256_insertf128_si256(_mm256_castsi128_si256(v1), (v0), 1)


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
                const __m128i lo = _mm_loadu_si128(reinterpret_cast<const __m128i*>(input + i));
                const __m128i hi = _mm_loadu_si128(reinterpret_cast<const __m128i*>(input + i + 4*3));

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

                const __m256i in = _mm256_shuffle_epi8(_mm256_set_m128i(hi, lo), shuf);
#else
                // just one memory load, however it read 4-bytes off on the first iteration

                const __m256i data = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(input + i - 4));
                // data = [????|HHHG|GGFF|FEEE|DDDC|CCBB|BAAA|????]
                              128-bit lane    |   128-bit lane

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

                // single lane layout; a, b, c and d are bits from 6-bit groups
                // [00000000|ddddddcc|ccccbbbb|bbaaaaaa]
                const __m256i indice_a = _mm256_and_si256(in, packed_dword(0x0000003f));
                const __m256i indice_b = _mm256_and_si256(_mm256_slli_epi32(in, 2), packed_dword(0x00003f00));
                const __m256i indice_c = _mm256_and_si256(_mm256_slli_epi32(in, 4), packed_dword(0x003f0000));
                const __m256i indice_d = _mm256_and_si256(_mm256_slli_epi32(in, 6), packed_dword(0x3f000000));

                // indices = [00dddddd|00cccccc|00bbbbbb|00aaaaaa]
                const __m256i indices = _mm256_or_si256(indice_a,
                                        _mm256_or_si256(indice_b,
                                        _mm256_or_si256(indice_c, indice_d)));

                const auto result = lookup(indices);

                _mm256_storeu_si256(reinterpret_cast<__m256i*>(out), result);
                out += 32;
            }
        }

    #undef packed_dword

    } // namespace sse

} // namespace base64
