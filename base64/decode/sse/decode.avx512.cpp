#include <cstdint>
#include <cassert>

#include <immintrin.h>
#include <x86intrin.h>

namespace base64 {

    namespace avx512 {

        namespace precalc {

            static __m512i scatter_offsets;
        }

        void initalize_decode() {

            uint32_t lookup[16];

            for (int i=0; i < 16; i++) {
                lookup[i] = i * 3;
            }

            precalc::scatter_offsets = _mm512_loadu_si512(reinterpret_cast<__m512i*>(lookup));
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

                const __m512i packed = pack(values);

                _mm512_i32scatter_epi32(reinterpret_cast<int*>(out), precalc::scatter_offsets, packed, 1);

                out += 48;
            }
        }

    } // namespace avx512bw

} // namespace base64
