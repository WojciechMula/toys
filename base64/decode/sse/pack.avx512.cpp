#include <immintrin.h>
#include <x86intrin.h>

namespace base64 {

    namespace avx512 {

#define packed_dword(x) _mm512_set1_epi32(x)

        // please refere to pack.avx2.cpp for comments
        __m512i pack_improved(const __m512i values) {

            const __m512i bits_ac = _mm512_and_si512(values, packed_dword(0x003f003f));
            const __m512i bits_bd = _mm512_and_si512(values, packed_dword(0x3f003f00));
            const __m512i tmp     = _mm512_or_si512(bits_ac, _mm512_srli_epi32(bits_bd, 2));
            const __m512i bits_cd = _mm512_and_si512(tmp, packed_dword(0x0fff0000));
            const __m512i bits_ab = _mm512_and_si512(tmp, packed_dword(0x00000fff));

            return _mm512_or_si512(bits_ab, _mm512_srli_epi32(bits_cd, 4));
        }


        // please refere to pack.avx2.cpp for comments
        __m512i pack_identity(const __m512i values) {
            
            return values;
        }

#undef packed_dword

    } // namespace avx512

} // namespace base64
