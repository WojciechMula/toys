#include <cstdint>
#include <cassert>

#include <immintrin.h>
#include <x86intrin.h>

namespace base64 {

    namespace avx512 {

        namespace precalc {

            static uint8_t valid[256];
            static uint32_t lookup_0[256];
            static uint32_t lookup_1[256];
            static uint32_t lookup_2[256];
            static uint32_t lookup_3[256];
        }

        void initalize_lookup() {

            using namespace precalc;

            for (int i=0; i < 256; i++) {
                lookup_0[i] = 0x80000000;
                lookup_1[i] = 0x80000000;
                lookup_2[i] = 0x80000000;
                lookup_3[i] = 0x80000000;
                valid[i] = 0;
            }

            for (int i=0; i < 64; i++) {
                const uint32_t val = static_cast<uint8_t>(base64::lookup[i]);

                valid[val] = 1;
                lookup_0[val] = i;
                lookup_1[val] = i << 1*6;
                lookup_2[val] = i << 2*6;
                lookup_3[val] = i << 3*6;
            }
        }

        __m512i lookup(const __m512i input) {

#define packed_dword(x) _mm512_set1_epi32(x)

            const __m512i b0 = _mm512_and_si512(input, packed_dword(0x000000ff));
            const __m512i b1 = _mm512_and_si512(_mm512_srli_epi32(input, 1*8), packed_dword(0x000000ff));
            const __m512i b2 = _mm512_and_si512(_mm512_srli_epi32(input, 2*8), packed_dword(0x000000ff));
            const __m512i b3 = _mm512_and_si512(_mm512_srli_epi32(input, 3*8), packed_dword(0x000000ff));

            // do lookup
            const __m512i r0 = _mm512_i32gather_epi32(b0, (const int*)precalc::lookup_0, 4);
            const __m512i r1 = _mm512_i32gather_epi32(b1, (const int*)precalc::lookup_1, 4);
            const __m512i r2 = _mm512_i32gather_epi32(b2, (const int*)precalc::lookup_2, 4);
            const __m512i r3 = _mm512_i32gather_epi32(b3, (const int*)precalc::lookup_3, 4);
            const __m512i translated = _mm512_or_si512(r0,
                                       _mm512_or_si512(r1,
                                       _mm512_or_si512(r2, r3)));

            const uint16_t mask = _mm512_cmple_epi32_mask(translated, _mm512_set1_epi32(0));
            if (mask) {
                static uint8_t tmp[64];
                _mm512_storeu_si512(reinterpret_cast<__m512*>(tmp), translated);
                for (unsigned i=0; i < 64; i++) {
                    if (!precalc::valid[tmp[i]]) {
                        throw invalid_input(i, 0);
                    }
                }
            }

            return translated;
#undef packed_dword
        }

    } // namespace avx512bw

} // namespace base64
