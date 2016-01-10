#include <immintrin.h>
#include <x86intrin.h>

#include <cstdint>
#include "pext.cpp"

namespace base64 {

    namespace sse {
    
#define packed_dword(x) _mm_set1_epi32(x)

        template <typename LOOKUP_FN>
        void encode(LOOKUP_FN lookup, uint8_t* input, size_t bytes, uint8_t* output) {
        
            uint8_t* out = output;

            for (size_t i = 0; i < bytes; i += 4*3) {

                // input = [xxxx|DDDC|CCBB|BAAA]
                __m128i in = _mm_loadu_si128(reinterpret_cast<const __m128i*>(input + i));

                __m128i shuf = _mm_setr_epi8(
                    0x00, 0x01, 0x02, char(0xff),
                    0x03, 0x04, 0x05, char(0xff),
                    0x06, 0x07, 0x08, char(0xff),
                    0x09, 0x0a, 0x0b, char(0xff)
                );

                // bytes from groups A, B and C are needed in separate 32-bit lanes
                // in = [0DDD|0CCC|0BBB|0AAA]
                in = _mm_shuffle_epi8(in, shuf);

                // single lane layout; a, b, c and d are bits from 6-bit groups
                // [00000000|ddddddcc|ccccbbbb|bbaaaaaa]
                const __m128i indice_a = _mm_and_si128(in, packed_dword(0x0000003f));
                const __m128i indice_b = _mm_and_si128(_mm_slli_epi32(in, 2), packed_dword(0x00003f00));
                const __m128i indice_c = _mm_and_si128(_mm_slli_epi32(in, 4), packed_dword(0x003f0000));
                const __m128i indice_d = _mm_and_si128(_mm_slli_epi32(in, 6), packed_dword(0x3f000000));

                // indices = [00dddddd|00cccccc|00bbbbbb|00aaaaaa]
                const __m128i indices = _mm_or_si128(_mm_or_si128(_mm_or_si128(indice_a, indice_b), indice_c), indice_d);

                const auto result = lookup(indices);

                _mm_storeu_si128(reinterpret_cast<__m128i*>(out), result);
                out += 16;
            }
        }


#if defined(HAVE_PEXT_INSTRUCTION)
        template <typename LOOKUP_FN>
        void encode_bmi2(LOOKUP_FN lookup, uint8_t* input, size_t bytes, uint8_t* output) {
        
            uint8_t* out = output;

            for (size_t i = 0; i < bytes; i += 4*3) {

                const uint64_t lo = *reinterpret_cast<const uint64_t*>(input);
                const uint64_t hi = *reinterpret_cast<const uint64_t*>(input + 6);

                const uint64_t expanded_lo = pext(lo, 0x3f3f3f3f3f3f3f3flu);
                const uint64_t expanded_hi = pext(hi, 0x3f3f3f3f3f3f3f3flu);

                const __m128i indices = _mm_set_epi64x(expanded_lo, expanded_hi);

                const auto result = lookup(indices);

                _mm_storeu_si128(reinterpret_cast<__m128i*>(out), result);
                out += 16;
            }
        }
#endif

    } // namespace sse

} // namespace base64
