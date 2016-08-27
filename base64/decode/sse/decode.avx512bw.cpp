#include <cstdint>
#include <cassert>

#include <immintrin.h>
#include <x86intrin.h>

namespace base64 {

    namespace avx512bw {

        namespace precalc {

            static __m512i pack_bytes;
        }

        void initalize_decode() {

            uint8_t lookup[64];

            for (int i=0; i < 64; i++) {
                lookup[i] = 0;
            }

            uint8_t output = 0;
            for (int i=0; i < 16; i++) {
                lookup[i*3 + 0] = output + 0;
                lookup[i*3 + 1] = output + 1;
                lookup[i*3 + 2] = output + 2;
                output += 4;
            }

            precalc::pack_bytes = _mm512_loadu_si512(reinterpret_cast<__m128i*>(lookup));
        }

        template <typename FN_LOOKUP, typename FN_PACK>
        void decode(FN_LOOKUP lookup, FN_PACK pack, const uint8_t* input, size_t size, uint8_t* output) {

            assert(size % 64 == 0);

            uint8_t* out = output;

            for (size_t i=0; i < size; i += 64) {

                __m512i in = _mm512_loadu_si512(reinterpret_cast<const __m512i*>(input + i));
                __m512i values;

                try {
                    values = lookup(in);
                } catch (invalid_input& e) {

                    const auto shift = e.offset;
                    throw invalid_input(i + shift, input[i + shift]);
                }

                // input:  packed_dword([00dddddd|00cccccc|00bbbbbb|00aaaaaa] x 4)
                // merged: packed_dword([00000000|ddddddcc|ccccbbbb|bbaaaaaa] x 4)

                const __m512i merged = pack(values);

                // merged = packed_byte([0XXX|0YYY|0ZZZ|0WWW])

                const __m512i pack = precalc::pack_bytes;
                const __m512i shuffled = _mm512_permutexvar_epi8(pack, merged);

                _mm512_storeu_si512(reinterpret_cast<__m512*>(out), shuffled);

                out += 48;
            }
        }

    } // namespace avx512bw

} // namespace base64
