#include <cstdint>
#include <cassert>

#include <immintrin.h>
#include <x86intrin.h>

#define packed_dword(x) _mm512_set1_epi32(x)
#define packed_byte(x) packed_dword((x) | ((x) << 8) | ((x) << 16) | ((x) << 24))

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

        void dump(__m512i v) {
            static uint8_t buf[64];

            _mm512_storeu_si512(reinterpret_cast<__m512i*>(buf), v);
        
            for (int i=0; i < 64; i++) {
                printf("%02x ", buf[i]);
            }

            putchar('\n');
        }


        void report_exception(const __m512i erroneous_input) {

            // an error occurs just once, peformance is not cruical

            uint8_t tmp[64];
            _mm512_storeu_si512(reinterpret_cast<__m512*>(tmp), erroneous_input);

            for (unsigned i=0; i < 64; i++) {
                if (!precalc::valid[tmp[i]]) {
                    throw invalid_input(i, tmp[i]);
                }
            }
        }


        __m512i lookup_gather(const __m512i input) {

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

            const uint16_t mask = _mm512_cmplt_epi32_mask(translated, _mm512_set1_epi32(0));
            if (mask) {
                report_exception(input);
            }

            return translated;
        }


        // returns packed (a[i] >= lo and a[i] <= hi) ? 0xff : 0x00;
        // assertion a[i] < 0x80

        __m512i _mm512_range_mask(const __m512i a, const __m512i lo, const __m512i hi) {

            const __m512i L = _mm512_add_epi32(a, lo);
            const __m512i H = _mm512_add_epi32(a, hi);

            const __m512i MSB = _mm512_and_epi32(_mm512_andnot_epi32(H, L), packed_byte(0x80));

            // MSB | (MSB - (MSB >> 7))
            return _mm512_or_si512(MSB, _mm512_sub_epi32(MSB, _mm512_srli_epi32(MSB, 7)));
        }


        __m512i lookup_comparisons(const __m512i input) {

            // we operate on lower 7 bits, as all values with 8th bit set are invalid
            const __m512i in = _mm512_and_si512(input, packed_byte(0x7f));

#define GET_RANGE_SHIFT(shift, lo, hi) \
            _mm512_and_si512(packed_byte(uint8_t(shift)), \
                             _mm512_range_mask(in, packed_byte(0x80 - (lo)), packed_byte(0x80 - (hi))))

            // shift for range 'A' - 'Z'
            const __m512i range_AZ = GET_RANGE_SHIFT(-65, 'A', 'Z' + 1);

            // shift for range 'a' - 'z'
            const __m512i range_az = GET_RANGE_SHIFT(-71, 'a', 'z' + 1);

            // shift for range '0' - '9'
            const __m512i range_09 = GET_RANGE_SHIFT(4, '0', '9' + 1);

            // shift for character '+'
            const __m512i char_plus = GET_RANGE_SHIFT(19, '+', '+' + 1);

            // shift for character '/'
            const __m512i char_slash = GET_RANGE_SHIFT(16, '/', '/' + 1);

            // merge partial results

            const __m512i shift = _mm512_or_si512(range_AZ,
                                  _mm512_or_si512(range_az,
                                  _mm512_or_si512(range_09,
                                  _mm512_or_si512(char_plus, char_slash))));

            // a paddb equivalent
            const __m512i shift06 = _mm512_and_si512(shift, packed_byte(0x7f));
            const __m512i shift7  = _mm512_and_si512(shift, packed_byte(0x80));
            const __m512i result  = _mm512_xor_si512(_mm512_add_epi32(in, shift06), shift7);

            // validation
            const __m512i non_zero_7lower = _mm512_add_epi32(shift06, packed_byte(0x7f));
#if 1
            /*  7 lower bits of shift are non-zero
                | 7th bit of shift is non-zero
                | | 7th bit of inoput is non-zero (extended ASCII)
                | | |
                a b c r
                0 0 0 1
                0 0 1 1
                0 1 0 0
                0 1 1 1
                1 0 0 0
                1 0 1 1
                1 1 0 0
                1 1 1 1

                expression = ~(a | b) | c

            */
            // we're use 7th bit of each byte
            const __m512i valid = _mm512_ternarylogic_epi32(in, shift, non_zero_7lower, 0xab);
            
#else       // a reference implementation
            // non-zero byte in shift -- 7th bit is set
            const __m512i non_zero = _mm512_or_si512(shift, non_zero_7lower);

            // 7th bit marks error - either shift is zero or byte outside standard ASCII
            const __m512i valid = _mm512_or_si512(input, _mm512_xor_si512(non_zero, packed_byte(0x80)));
#endif
            const __mmask16 mask = _mm512_test_epi32_mask(valid, packed_byte(0x80));
            if (mask) {
                report_exception(input);
            }

            return result;
        }

    } // namespace avx512bw

} // namespace base64


#undef packed_dword
