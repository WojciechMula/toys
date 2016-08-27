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


        void encode_with_SWAR(uint8_t* input, size_t bytes, uint8_t* output) {

            uint8_t* out = output;

            static const uint32_t input_offsets[16] = {
                 0*3,  1*3,  2*3,  3*3,
                 4*3,  5*3,  6*3,  7*3,
                 8*3,  9*3, 10*3, 11*3,
                12*3, 13*3, 14*3, 15*3
            };

            const __m512i input_gather = _mm512_loadu_si512(reinterpret_cast<const __m512i*>(input_offsets));

#define packed_dword(x) _mm512_set1_epi32(x)
#define packed_byte(x) packed_dword((x) | ((x) << 8) | ((x) << 16) | ((x) << 24))

            for (size_t i = 0; i < bytes; i += 4 * 12) {
                // load bytes
                const __m512i in = _mm512_i32gather_epi32(input_gather, (const int*)(input + i), 1);

                // split bytes into separate vectors
                const __m512i indice_ab = _mm512_and_si512(in, packed_dword(0x00000fff));
                const __m512i indice_cd = _mm512_and_si512(_mm512_slli_epi32(in, 4), packed_dword(0x0fff0000));
                const __m512i tmp = _mm512_or_si512(indice_ab, indice_cd);
                const __m512i indice_ac = _mm512_and_si512(tmp, packed_dword(0x003f003f));
                const __m512i indice_db = _mm512_and_si512(_mm512_slli_epi32(tmp, 2), packed_dword(0x3f003f00));
                const __m512i indices = _mm512_or_si512(indice_ac, indice_db);

                // 
                __m512i shift = packed_byte('A');
                __m512i c;
                const __m512i MSB = packed_byte(0x80);
                
                // shift += cmp(i >= 26) & 6;
                c = _mm512_and_si512(_mm512_add_epi32(indices, packed_byte(0x80 - 26)), MSB);
                c = _mm512_sub_epi32(c, _mm512_srli_epi32(c, 7));
                c = _mm512_and_si512(c, packed_byte(6));

                shift = _mm512_add_epi32(shift, c);

                // shift -= cmp(i >= 52) & 75;
                c = _mm512_and_si512(_mm512_add_epi32(indices, packed_byte(0x80 - 52)), MSB);
                c = _mm512_sub_epi32(c, _mm512_srli_epi32(c, 7));
                c = _mm512_and_si512(c, packed_byte(75));

                shift = _mm512_sub_epi32(shift, c);

                // shift -= cmp(i >= 62) & 15;
                c = _mm512_and_si512(_mm512_add_epi32(indices, packed_byte(0x80 - 62)), MSB);
                c = _mm512_sub_epi32(c, _mm512_srli_epi32(c, 7));
                c = _mm512_and_si512(c, packed_byte(15));

                shift = _mm512_sub_epi32(shift, c);

                // shift -= cmp(i >= 63) & 12;
                c = _mm512_and_si512(_mm512_add_epi32(indices, packed_byte(0x80 - 63)), MSB);
                c = _mm512_sub_epi32(c, _mm512_srli_epi32(c, 7));
                c = _mm512_and_si512(c, packed_byte(3));

                shift = _mm512_add_epi32(shift, c);

                // produce the result
                const __m512i result = _mm512_add_epi32(indices, shift);

                _mm512_storeu_si512(reinterpret_cast<__m512i*>(out), result);

#undef packed_dword
                out += 64;
            }
        }


    #undef packed_dword

    } // namespace avx512

} // namespace base64
