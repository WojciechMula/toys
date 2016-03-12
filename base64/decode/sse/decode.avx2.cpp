#include <cstdint>
#include <cassert>

#include <immintrin.h>
#include <x86intrin.h>

namespace base64 {

    namespace avx2_templates {

        template <typename FN>
        void decode(FN lookup, const uint8_t* input, size_t size, uint8_t* output) {

            assert(size % 32 == 0);

            uint8_t* out = output;

            for (size_t i=0; i < size; i += 32) {

                __m256i in = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(input + i));
                __m256i values;

                try {
                    values = lookup(in);
                } catch (invalid_input& e) {
                    
                    const auto shift = e.offset;
                    throw invalid_input(i + shift, input[i + shift]);
                }

                // input:  packed_dword([00dddddd|00cccccc|00bbbbbb|00aaaaaa] x 4)
                // merged: packed_dword([00000000|ddddddcc|ccccbbbb|bbaaaaaa] x 4)

#define packed_dword(x) _mm256_set1_epi32(x)
                const __m256i bits_a = _mm256_and_si256(values, packed_dword(0x0000003f));
                const __m256i bits_b = _mm256_srli_epi32(_mm256_and_si256(values, packed_dword(0x00003f00)), 2);
                const __m256i bits_c = _mm256_srli_epi32(_mm256_and_si256(values, packed_dword(0x003f0000)), 4);
                const __m256i bits_d = _mm256_srli_epi32(_mm256_and_si256(values, packed_dword(0x3f000000)), 6);
#undef packed_dword
                const __m256i merged = _mm256_or_si256(bits_a,
                                       _mm256_or_si256(bits_b,
                                       _mm256_or_si256(bits_c, bits_d)));

                // merged = packed_byte([0XXX|0YYY|0ZZZ|0WWW])

                const __m256i shuf = _mm256_setr_epi8(
                       0,  1,  2,
                       4,  5,  6,
                       8,  9, 10,
                      12, 13, 14,
                      char(0xff), char(0xff), char(0xff), char(0xff),
                       0,  1,  2,
                       4,  5,  6,
                       8,  9, 10,
                      12, 13, 14,
                      char(0xff), char(0xff), char(0xff), char(0xff)
                );

                const __m256i shuffled = _mm256_shuffle_epi8(merged, shuf);

                _mm_storeu_si128(reinterpret_cast<__m128i*>(out), _mm256_extracti128_si256(shuffled, 0));
                _mm_storeu_si128(reinterpret_cast<__m128i*>(out + 12), _mm256_extracti128_si256(shuffled, 1));

                out += 24;
            }
        }


#if defined(HAVE_BMI2_INSTRUCTIONS)
        template <typename FN>
        void decode_bmi2(FN lookup, const uint8_t* input, size_t size, uint8_t* output) {

            assert(size % 32 == 0);

            uint8_t* out = output;

            for (size_t i=0; i < size; i += 32) {

                __m256i in = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(input + i));
                __m256i values;

                try {
                    values = lookup(in);
                } catch (invalid_input& e) {
                    
                    const auto shift = e.offset;
                    throw invalid_input(i + shift, input[i + shift]);
                }

                // input:  packed_dword([00dddddd|00cccccc|00bbbbbb|00aaaaaa] x 4)
                // merged: packed_dword([00000000|ddddddcc|ccccbbbb|bbaaaaaa] x 4)

                const __m128i lane0 = _mm256_extracti128_si256(values, 0);
                const __m128i lane1 = _mm256_extracti128_si256(values, 1);

                const uint64_t t0 = pext(_mm_extract_epi64(lane0, 0), 0x3f3f3f3f3f3f3f3f);
                const uint64_t t1 = pext(_mm_extract_epi64(lane0, 1), 0x3f3f3f3f3f3f3f3f);
                const uint64_t t2 = pext(_mm_extract_epi64(lane1, 0), 0x3f3f3f3f3f3f3f3f);
                const uint64_t t3 = pext(_mm_extract_epi64(lane1, 1), 0x3f3f3f3f3f3f3f3f);

#if 0 // naive store
                *reinterpret_cast<uint64_t*>(out + 0*0) = t0;
                *reinterpret_cast<uint64_t*>(out + 1*6) = t1;
                *reinterpret_cast<uint64_t*>(out + 2*6) = t2;
                *reinterpret_cast<uint64_t*>(out + 3*6) = t3;
#else
                *reinterpret_cast<uint64_t*>(out + 0*8) = (t1 << (6*8)) | t0;
                *reinterpret_cast<uint64_t*>(out + 1*8) = (t2 << (4*8)) | (t1 >> (2*8));
                *reinterpret_cast<uint64_t*>(out + 2*8) = (t3 << (2*8)) | (t2 >> (4*8));
#endif
                out += 24;
            }
        }
#endif // defined(HAVE_BMI2_INSTRUCTIONS)

    } // namespace avx2_templates

} // namespace base64
