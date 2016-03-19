#include <immintrin.h>
#include <x86intrin.h>

/*
    Pack algorithm is responsible for converting from
    four 6-bit indices saved in separate bytes of 32-bit word
    into 24-bit word
*/

namespace base64 {

    namespace sse {

#define packed_dword(x) _mm_set1_epi32(x)

        __m128i pack_naive(const __m128i values) {

            const __m128i bits_a = _mm_and_si128(values, packed_dword(0x0000003f));
            const __m128i bits_b = _mm_srli_epi32(_mm_and_si128(values, packed_dword(0x00003f00)), 2);
            const __m128i bits_c = _mm_srli_epi32(_mm_and_si128(values, packed_dword(0x003f0000)), 4);
            const __m128i bits_d = _mm_srli_epi32(_mm_and_si128(values, packed_dword(0x3f000000)), 6);

            return _mm_or_si128(bits_a,
                   _mm_or_si128(bits_b,
                   _mm_or_si128(bits_c, bits_d)));
        }


        __m128i pack_improved(const __m128i values) {

            // bits_ac: packed_dword([00000000|00cccccc|00000000|00aaaaaa] x 4)
            // bits_bd: packed_dword([00dddddd|00000000|00bbbbbb|00000000] x 4)
            const __m128i bits_ac = _mm_and_si128(values, packed_dword(0x003f003f));
            const __m128i bits_bd = _mm_and_si128(values, packed_dword(0x3f003f00));

            // tmp:     packed_dword([0000dddd|ddcccccc|0000bbbb|bbaaaaaa] x 4)
            const __m128i tmp     = _mm_or_si128(bits_ac, _mm_srli_epi32(bits_bd, 2));

            // bits_cd: packed_dword([0000dddd|ddcccccc|00000000|00000000] x 4)
            // bits_ab: packed_dword([00000000|00000000|0000bbbb|bbaaaaaa] x 4)
            const __m128i bits_cd = _mm_and_si128(tmp, packed_dword(0x0fff0000));
            const __m128i bits_ab = _mm_and_si128(tmp, packed_dword(0x00000fff));

            // merged:  packed_dword([00000000|ddddddcc|ccccbbbb|bbaaaaaa] x 4)
            return _mm_or_si128(bits_ab, _mm_srli_epi32(bits_cd, 4));
        }


        __m128i pack_madd_improved(const __m128i values) {

            //          packed_dword([0000dddd|ddcccccc|0000bbbb|bbaaaaaa] x 4)
            const __m128i merge_ab_and_bc = _mm_maddubs_epi16(values, packed_dword(0x40014001));

            // bits_cd: packed_dword([0000dddd|ddcccccc|00000000|00000000] x 4)
            // bits_ab: packed_dword([00000000|00000000|0000bbbb|bbaaaaaa] x 4)
            const __m128i bits_cd = _mm_and_si128(merge_ab_and_bc, packed_dword(0x0fff0000));
            const __m128i bits_ab = _mm_and_si128(merge_ab_and_bc, packed_dword(0x00000fff));

            // merged:  packed_dword([00000000|ddddddcc|ccccbbbb|bbaaaaaa] x 4)
            return _mm_or_si128(bits_ab, _mm_srli_epi32(bits_cd, 4));
        }


        __m128i pack_madd(const __m128i values) {

            const __m128i merge_ab_and_bc = _mm_maddubs_epi16(values, packed_dword(0x40014001));

            return _mm_madd_epi16(merge_ab_and_bc, packed_dword(0x10000001));
        }

#undef packed_dword

    } // namespace sse

} // namespace base64
