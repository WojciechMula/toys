#include <cstdint>
#include <cassert>

#include <immintrin.h>
#include <x86intrin.h>

namespace base64 {

    namespace avx512bw {

        namespace precalc {

            static __m512i lookup_0;
            static __m512i lookup_1;
        }

        void initalize_lookup() {

            uint8_t lookup_0[64];
            uint8_t lookup_1[64];

            // bytes having MSB set will be rejected earlier
            for (int i=0; i < 64; i++) {
                lookup_0[i] = 0x80;
                lookup_1[i] = 0x80; // invalid bytes
            }

            for (int i=0; i < 64; i++) {
                const uint8_t val = static_cast<uint8_t>(base64::lookup[i]);

                const uint8_t bit6   = val & 0x40;
                const uint8_t bits05 = val & 0x3f;

                // Yes, I know that lookup_X could be merged and
                // addressed directly by six lower bits.
                if (bit6) {
                    lookup_1[bits05] = i;
                } else {
                    lookup_0[bits05] = i;
                }
            }

            precalc::lookup_0 = _mm512_loadu_si512(reinterpret_cast<__m512i*>(lookup_0));
            precalc::lookup_1 = _mm512_loadu_si512(reinterpret_cast<__m512i*>(lookup_1));
        }

        __m512i lookup(const __m512i input) {

#define packed_byte(b) _mm512_set1_epi8(uint8_t(b))

            const __m512i lookup_0 = precalc::lookup_0;
            const __m512i lookup_1 = precalc::lookup_1;

            // According to the documentation the MSB is not considered
            // thus no masking is needed.
            const __m512i translated = _mm512_permutex2var_epi8(lookup_0, input, lookup_1);

            // 7th bit is set if translation failed or input already had this bit set
            const uint64_t mask = _mm512_movepi8_mask(translated | input); // convert MSBs to a mask
            if (mask) {
                for (unsigned i=0; i < 64; i++) {
                    if (mask & (uint64_t(1) << i)) {
                        throw invalid_input(i, 0);
                    }
                }
            }

            return translated;
#undef packed_byte
        }

    } // namespace avx512bw

} // namespace base64
