#include <immintrin.h>
#include <x86intrin.h>

#include <cstdint>

namespace base64 {

    namespace avx512 {

#define packed_dword(x) _mm512_set1_epi32(x)

        __m512i unpack_identity(const __m512i in) {
            return in;
        }


        __m512i unpack_default(const __m512i in) {
            // scatter 6-bit value into separate bytes
            const __m512i indice_ab = _mm512_and_si512(in, packed_dword(0x00000fff));
            const __m512i indice_cd = _mm512_and_si512(_mm512_slli_epi32(in, 4), packed_dword(0x0fff0000));
            const __m512i tmp = _mm512_or_si512(indice_ab, indice_cd);
            const __m512i indice_ac = _mm512_and_si512(tmp, packed_dword(0x003f003f));
            const __m512i indice_db = _mm512_and_si512(_mm512_slli_epi32(tmp, 2), packed_dword(0x3f003f00));

            return _mm512_or_si512(indice_ac, indice_db);
        }

        /*  c b a | c ? b : a
            0 0 0 |   0
            0 0 1 |   0
            0 1 0 |   1
            0 1 1 |   1
            1 0 0 |   0
            1 0 1 |   1
            1 1 0 |   0
            1 1 1 |   1
        */
        const uint8_t MERGE_BITS = 0xac;


        __m512i unpack_improved(const __m512i in) {
            // scatter 6-bit value into separate bytes

            // a1 = 00000000|aaaaaabb|bbbbcccc|ccdddddd
            // b1 = 0000AAAA|AABBBBBB|CCCCCCDD|DDDD0000
            // m1 = 0000AAAA|AABBBBBB|????cccc|ccdddddd

            const __m512i a1 = in;
            const __m512i b1 = _mm512_slli_epi32(in, 4);
            const __m512i m1 = _mm512_ternarylogic_epi32(packed_dword(0x0fff0000), a1, b1, MERGE_BITS);
            
            // a2 = 0000aaaa|aabbbbbb|????cccc|ccdddddd
            // b2 = 00AAAAAA|BBBBBB??|??CCCCCC|DDDDDD00
            // m2 = 00AAAAAA|??bbbbbb|??CCCCCC|??dddddd

            const __m512i a2 = m1;
            const __m512i b2 = _mm512_slli_epi32(m1, 2);
            const __m512i m2 = _mm512_ternarylogic_epi32(packed_dword(0x3f003f00), a2, b2, MERGE_BITS);

            return _mm512_and_si512(m2, packed_dword(0x3f3f3f3f));
        }

#undef packed_dword

    } // namespace avx512

} // namespace base64
