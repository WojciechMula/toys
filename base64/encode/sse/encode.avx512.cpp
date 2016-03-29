#include <immintrin.h>
#include <x86intrin.h>

#include <cstdint>

namespace base64 {

    namespace avx512 {

        void encode_faster_spliting(uint8_t* input, size_t bytes, uint8_t* output) {

            uint8_t* out = output;

            static const char* lookup_tbl = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
            uint8_t shuffle_input_tbl[64];
            {
                // 32-bit input: [00000000|ddddddcc|ccccbbbb|bbaaaaaa]
                //                            2         1        0
                // output order  [2, 1, 1, 0], i.e.:
                //               [ddddddcc|ccccbbbb|ccccbbbb|bbaaaaaa]
                unsigned src_index = 0;
                for (int i=0; i < 64; i += 4) { 
                    shuffle_input_tbl[i + 0] = src_index + 0;
                    shuffle_input_tbl[i + 1] = src_index + 1;
                    shuffle_input_tbl[i + 2] = src_index + 1;
                    shuffle_input_tbl[i + 3] = src_index + 2;
                    src_index += 3;
                }
            }

            const __m512i shuffle_input = _mm512_loadu_si512(reinterpret_cast<__m512i*>(shuffle_input_tbl));
            const __m512i lookup = _mm512_loadu_si512(reinterpret_cast<const __m512i*>(lookup_tbl));

#define packed_dword(x) _mm512_set1_epi32(x)

            for (size_t i = 0; i < bytes; i += 4 * 12) {
                const __m512i v = _mm512_loadu_si512(reinterpret_cast<const __m512i*>(input + i));

                // 32-bit lane: [ddddddcc|ccccXXXX|XXXXbbbb|bbaaaaaa]
                const __m512i in = _mm512_permutexvar_epi8(shuffle_input, v);


                //              [0000dddd|ddcccccc|XXXXbbbb|bbaaaaaa]
                const __m512i shifted_dc = _mm512_srlv_epi16(in, packed_dword(0x00040000));

                //              [00dddddd|00000000|00bbbbbb|00000000]
                const __m512i indices_db = _mm512_and_si512(_mm512_slli_epi32(shifted_dc, 2), packed_dword(0x3f00ff00));

                //              [00000000|00cccccc|00000000|00aaaaaa]
                const __m512i indices_ca = _mm512_and_si512(shifted_dc, packed_dword(0x003f003f));

                const __m512i indices = indices_ca | indices_db;

                const __m512i result = _mm512_permutexvar_epi8(indices, lookup);

                _mm512_storeu_si512(reinterpret_cast<__m512i*>(out), result);

#undef packed_dword
                out += 64;
            }
        }


        void encode_improved_splitting(uint8_t* input, size_t bytes, uint8_t* output) {

            uint8_t* out = output;

            static const char* lookup_tbl = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
            uint8_t shuffle_input_tbl[64];
            {
                unsigned src_index = 0;
                for (int i=0; i < 64; i += 4) { 
                    shuffle_input_tbl[i + 0] = src_index + 0;
                    shuffle_input_tbl[i + 1] = src_index + 1;
                    shuffle_input_tbl[i + 2] = src_index + 2;
                    shuffle_input_tbl[i + 3] = src_index + 0; // could be anything
                    src_index += 3;
                }
            }

            const __m512i shuffle_input = _mm512_loadu_si512(reinterpret_cast<__m512i*>(shuffle_input_tbl));
            const __m512i lookup = _mm512_loadu_si512(reinterpret_cast<const __m512i*>(lookup_tbl));

#define packed_dword(x) _mm512_set1_epi32(x)

            for (size_t i = 0; i < bytes; i += 4 * 12) {
                const __m512i v = _mm512_loadu_si512(reinterpret_cast<const __m512i*>(input + i));

                const __m512i in = _mm512_permutexvar_epi8(shuffle_input, v);

                const __m512i indices_ab = _mm512_and_si512(in, packed_dword(0x00000fff));
                const __m512i indices_cd = _mm512_and_si512(_mm512_slli_epi32(in, 4), packed_dword(0x0fff0000));

                const __m512i merged = _mm512_or_si512(indices_ab, indices_cd);
                const __m512i indices_ac = _mm512_and_si512(merged, packed_dword(0x003f003f));
                const __m512i indices_db = _mm512_and_si512(_mm512_slli_epi32(merged, 2), packed_dword(0x3f003f00));
                const __m512i indices = _mm512_or_si512(indices_ac, indices_db);

                const __m512i result = _mm512_permutexvar_epi8(indices, lookup);

                _mm512_storeu_si512(reinterpret_cast<__m512i*>(out), result);

#undef packed_dword
                out += 64;
            }
        }


    #undef packed_dword

    } // namespace avx512

} // namespace base64
