#include <immintrin.h>
#include <x86intrin.h>

#include <cstdint>

namespace base64 {

    namespace avx512 {

        static const char* lookup = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
        static uint32_t lookup_0[64];
        static uint32_t lookup_1[64];
        static uint32_t lookup_2[64];
        static uint32_t lookup_3[64];

        void initialize() {
            for (int i=0; i < 64; i++) {
                const uint32_t val = lookup[i];

                lookup_0[i] = val;
                lookup_1[i] = val << 8;
                lookup_2[i] = val << 16;
                lookup_3[i] = val << 24;
            }
        }

        void dump(__m512i v) {
            static uint8_t buf[64];

            _mm512_storeu_si512(reinterpret_cast<__m512i*>(buf), v);
        
            for (int i=0; i < 64; i++) {
                printf("%02x ", buf[i]);
            }

            putchar('\n');
        }

        void encode_with_gathers(uint8_t* input, size_t bytes, uint8_t* output) {

            uint8_t* out = output;

            static const uint32_t input_offsets[16] = {
                 0*3,  1*3,  2*3,  3*3,
                 4*3,  5*3,  6*3,  7*3,
                 8*3,  9*3, 10*3, 11*3,
                12*3, 13*3, 14*3, 15*3
            };

            const __m512i input_gather = _mm512_loadu_si512(reinterpret_cast<const __m512i*>(input_offsets));

#define packed_dword(x) _mm512_set1_epi32(x)

            for (size_t i = 0; i < bytes; i += 4 * 12) {
                // load bytes
                const __m512i in = _mm512_i32gather_epi32(input_gather, (const int*)(input + i), 1);

                // split bytes into separate vectors
                const __m512i b0 = _mm512_and_si512(in, packed_dword(0x0000003f));
                const __m512i b1 = _mm512_and_si512(_mm512_srli_epi32(in, 1*6), packed_dword(0x0000003f));
                const __m512i b2 = _mm512_and_si512(_mm512_srli_epi32(in, 2*6), packed_dword(0x0000003f));
                const __m512i b3 = _mm512_and_si512(_mm512_srli_epi32(in, 3*6), packed_dword(0x0000003f));

                // do lookup
                const __m512i r0 = _mm512_i32gather_epi32(b0, (const int*)lookup_0, 4);
                const __m512i r1 = _mm512_i32gather_epi32(b1, (const int*)lookup_1, 4);
                const __m512i r2 = _mm512_i32gather_epi32(b2, (const int*)lookup_2, 4);
                const __m512i r3 = _mm512_i32gather_epi32(b3, (const int*)lookup_3, 4);
                const __m512i result = _mm512_or_si512(r0,
                                       _mm512_or_si512(r1,
                                       _mm512_or_si512(r2, r3)));

                _mm512_storeu_si512(reinterpret_cast<__m512i*>(out), result);

#undef packed_dword
                out += 64;
            }
        }


    #undef packed_dword

    } // namespace avx512

} // namespace base64
