#include <cstdint>
#include <cassert>

#include <immintrin.h>
#include <x86intrin.h>


namespace base64 {

    namespace sse_templates {

        template <typename FN>
        void decode(FN lookup, const uint8_t* input, size_t size, uint8_t* output) {

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

                // lower 12 bytes contains the result
                const __m128i shuffled = _mm_shuffle_epi8(merged, shuf);

#if 0
                // Note: on Core i5 maskmove is slower than bare write
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


#if defined(HAVE_BMI2_INSTRUCTIONS)
        template <typename FN>
        void decode_bmi2(FN lookup, const uint8_t* input, size_t size, uint8_t* output) {

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

                const uint64_t lo = _mm_extract_epi64(values, 0);
                const uint64_t hi = _mm_extract_epi64(values, 1);

                const uint64_t t0 = pext(lo, 0x3f3f3f3f3f3f3f3f);
                const uint64_t t1 = pext(hi, 0x3f3f3f3f3f3f3f3f);

                *reinterpret_cast<uint64_t*>(out + 0) = t0;
                *reinterpret_cast<uint64_t*>(out + 6) = t1;
                out += 12;
            }
        }
#endif // defined(HAVE_BMI2_INSTRUCTIONS)

    } // namespace sse_templates

} // namespace base64

