#include <immintrin.h>
#include <x86intrin.h>

#include <cstdint>

namespace base64 {

    namespace avx512 {


        template <typename LOOKUP_FN>
        void encode_gather(LOOKUP_FN lookup, uint8_t* input, size_t bytes, uint8_t* output) {

            uint8_t* out = output;

            static const uint32_t input_offsets[16] = {
                 0*3,  1*3,  2*3,  3*3,
                 4*3,  5*3,  6*3,  7*3,
                 8*3,  9*3, 10*3, 11*3,
                12*3, 13*3, 14*3, 15*3
            };

            const __m512i input_gather = _mm512_loadu_si512(reinterpret_cast<const __m512i*>(input_offsets));

            for (size_t i = 0; i < bytes; i += 4 * 12) {
                // load bytes
                const __m512i in = _mm512_i32gather_epi32(input_gather, (const int*)(input + i), 1);

                // do lookup
                const __m512i result = lookup(in);

                _mm512_storeu_si512(reinterpret_cast<__m512i*>(out), result);

                out += 64;
            }
        }

#define packed_dword(x) _mm512_set1_epi32(x)

        template <typename LOOKUP_FN>
        void encode(LOOKUP_FN lookup, uint8_t* input, size_t bytes, uint8_t* output) {

            uint8_t* out = output;

            static const uint32_t input_offsets[16] = {
                 0*3,  1*3,  2*3,  3*3,
                 4*3,  5*3,  6*3,  7*3,
                 8*3,  9*3, 10*3, 11*3,
                12*3, 13*3, 14*3, 15*3
            };

            const __m512i input_gather = _mm512_loadu_si512(reinterpret_cast<const __m512i*>(input_offsets));

            for (size_t i = 0; i < bytes; i += 4 * 12) {
                // load bytes
                const __m512i in = _mm512_i32gather_epi32(input_gather, (const int*)(input + i), 1);

                // scatter 6-bit value into separate bytes
                const __m512i indice_ab = _mm512_and_si512(in, packed_dword(0x00000fff));
                const __m512i indice_cd = _mm512_and_si512(_mm512_slli_epi32(in, 4), packed_dword(0x0fff0000));
                const __m512i tmp = _mm512_or_si512(indice_ab, indice_cd);
                const __m512i indice_ac = _mm512_and_si512(tmp, packed_dword(0x003f003f));
                const __m512i indice_db = _mm512_and_si512(_mm512_slli_epi32(tmp, 2), packed_dword(0x3f003f00));
                const __m512i indices = _mm512_or_si512(indice_ac, indice_db);

                // do lookup
                const __m512i result = lookup(indices);

                _mm512_storeu_si512(reinterpret_cast<__m512i*>(out), result);

                out += 64;
            }
        }

#undef packed_dword

    } // namespace avx512

} // namespace base64
