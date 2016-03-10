#include <cstdint>
#include <cassert>

#include <immintrin.h>
#include <x86intrin.h>

namespace base64 {

    namespace avx2 {

        __m256i lookup(const __m256i input) {

            // see comment in decode.sse.cpp

#define packed_byte(b) _mm256_set1_epi8(uint8_t(b))

            // shift for range 'A' - 'Z'
            const __m256i ge_A = _mm256_cmpgt_epi8(input, packed_byte('A' - 1));
            const __m256i gt_Z = _mm256_cmpgt_epi8(input, packed_byte('Z'));
            const __m256i range_AZ = _mm256_and_si256(packed_byte(-65), _mm256_andnot_si256(gt_Z, ge_A));

            // shift for range 'a' - 'z'
            const __m256i ge_a = _mm256_cmpgt_epi8(input, packed_byte('a' - 1));
            const __m256i gt_z = _mm256_cmpgt_epi8(input, packed_byte('z'));
            const __m256i range_az = _mm256_and_si256(packed_byte(-71), _mm256_andnot_si256(gt_z, ge_a));

            // shift for range '0' - '9'
            const __m256i ge_0 = _mm256_cmpgt_epi8(input, packed_byte('0' - 1));
            const __m256i gt_9 = _mm256_cmpgt_epi8(input, packed_byte('9'));
            const __m256i range_09 = _mm256_and_si256(packed_byte(4), _mm256_andnot_si256(gt_9, ge_0));

            // shift for character '+'
            const __m256i eq_plus = _mm256_cmpeq_epi8(input, packed_byte('+'));
            const __m256i char_plus = _mm256_and_si256(packed_byte(19), eq_plus);

            // shift for character '/'
            const __m256i eq_slash = _mm256_cmpeq_epi8(input, packed_byte('/'));
            const __m256i char_slash = _mm256_and_si256(packed_byte(16), eq_slash);

            // merge partial results

            const __m256i shift = _mm256_or_si256(range_AZ,
                                  _mm256_or_si256(range_az,
                                  _mm256_or_si256(range_09,
                                  _mm256_or_si256(char_plus, char_slash))));

            // Individual shift values are non-zero, thus if any
            // byte in a shift vector is zero, then the input
            // contains invalid bytes.
            const auto mask = _mm256_movemask_epi8(_mm256_cmpeq_epi8(shift, packed_byte(0)));
            if (mask) {
                // some characters do not match the valid range
                for (unsigned i=0; i < 32; i++) {
                    if (mask & (1 << i)) {
                        throw invalid_input(i, 0);
                    }
                }
            }

            return _mm256_add_epi8(input, shift);
#undef packed_byte
        }

        void decode(const uint8_t* input, size_t size, uint8_t* output) {

            assert(size % 32 == 0);

            uint8_t* out = output;

            for (size_t i=0; i < size; i += 32) {

                __m256i in = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(input + i));
                __m256i values;

                try {
                    values = lookup(in);
                } catch (invalid_input& e) {
                    
                    const auto shift = e.offset;
                    throw invalid_input(i + shift, input[i + shift]);
                }

                // input:  packed_dword([00dddddd|00cccccc|00bbbbbb|00aaaaaa] x 4)
                // merged: packed_dword([00000000|ddddddcc|ccccbbbb|bbaaaaaa] x 4)

#define packed_dword(x) _mm256_set1_epi32(x)
                const __m256i bits_a = _mm256_and_si256(values, packed_dword(0x0000003f));
                const __m256i bits_b = _mm256_srli_epi32(_mm256_and_si256(values, packed_dword(0x00003f00)), 2);
                const __m256i bits_c = _mm256_srli_epi32(_mm256_and_si256(values, packed_dword(0x003f0000)), 4);
                const __m256i bits_d = _mm256_srli_epi32(_mm256_and_si256(values, packed_dword(0x3f000000)), 6);
#undef packed_dword
                const __m256i merged = _mm256_or_si256(bits_a,
                                       _mm256_or_si256(bits_b,
                                       _mm256_or_si256(bits_c, bits_d)));

                // merged = packed_byte([0XXX|0YYY|0ZZZ|0WWW])

                const __m256i shuf = _mm256_setr_epi8(
                       0,  1,  2,
                       4,  5,  6,
                       8,  9, 10,
                      12, 13, 14,
                      char(0xff), char(0xff), char(0xff), char(0xff),
                       0,  1,  2,
                       4,  5,  6,
                       8,  9, 10,
                      12, 13, 14,
                      char(0xff), char(0xff), char(0xff), char(0xff)
                );

                const __m256i shuffled = _mm256_shuffle_epi8(merged, shuf);

                _mm_storeu_si128(reinterpret_cast<__m128i*>(out), _mm256_extracti128_si256(shuffled, 0));
                _mm_storeu_si128(reinterpret_cast<__m128i*>(out + 12), _mm256_extracti128_si256(shuffled, 1));

                out += 24;
            }
        }


#if defined(HAVE_BMI2_INSTRUCTIONS)
        void decode_bmi2(const uint8_t* input, size_t size, uint8_t* output) {

            assert(size % 32 == 0);

            uint8_t* out = output;

            for (size_t i=0; i < size; i += 32) {

                __m256i in = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(input + i));
                __m256i values;

                try {
                    values = lookup(in);
                } catch (invalid_input& e) {
                    
                    const auto shift = e.offset;
                    throw invalid_input(i + shift, input[i + shift]);
                }

                // input:  packed_dword([00dddddd|00cccccc|00bbbbbb|00aaaaaa] x 4)
                // merged: packed_dword([00000000|ddddddcc|ccccbbbb|bbaaaaaa] x 4)

                const __m128i lane0 = _mm256_extracti128_si256(values, 0);
                const __m128i lane1 = _mm256_extracti128_si256(values, 1);

                const uint64_t t0 = pext(_mm_extract_epi64(lane0, 0), 0x3f3f3f3f3f3f3f3f);
                const uint64_t t1 = pext(_mm_extract_epi64(lane0, 1), 0x3f3f3f3f3f3f3f3f);
                const uint64_t t2 = pext(_mm_extract_epi64(lane1, 0), 0x3f3f3f3f3f3f3f3f);
                const uint64_t t3 = pext(_mm_extract_epi64(lane1, 1), 0x3f3f3f3f3f3f3f3f);

#if 0 // naive store
                *reinterpret_cast<uint64_t*>(out + 0*0) = t0;
                *reinterpret_cast<uint64_t*>(out + 1*6) = t1;
                *reinterpret_cast<uint64_t*>(out + 2*6) = t2;
                *reinterpret_cast<uint64_t*>(out + 3*6) = t3;
#else
                *reinterpret_cast<uint64_t*>(out + 0*8) = (t1 << (6*8)) | t0;
                *reinterpret_cast<uint64_t*>(out + 1*8) = (t2 << (4*8)) | (t1 >> (2*8));
                *reinterpret_cast<uint64_t*>(out + 2*8) = (t3 << (2*8)) | (t2 >> (4*8));
#endif
                out += 24;
            }
        }
#endif // defined(HAVE_BMI2_INSTRUCTIONS)

    } // namespace sse

} // namespace base64
