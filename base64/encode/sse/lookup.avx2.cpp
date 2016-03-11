#include <immintrin.h>
#include <x86intrin.h>

#include <cstdint>

namespace base64 {

    namespace avx2 {

    #define packed_byte(x) _mm256_set1_epi8(char(x))

        __m256i lookup_version2(const __m256i input) {

            __m256i result = packed_byte(65);

            const __m256i ge_26 = _mm256_cmpgt_epi8(input, packed_byte(25));
            const __m256i ge_52 = _mm256_cmpgt_epi8(input, packed_byte(51));
            const __m256i eq_62 = _mm256_cmpeq_epi8(input, packed_byte(62));
            const __m256i eq_63 = _mm256_cmpeq_epi8(input, packed_byte(63));

            result = _mm256_add_epi8(result, _mm256_and_si256(ge_26, packed_byte(  6)));
            result = _mm256_sub_epi8(result, _mm256_and_si256(ge_52, packed_byte( 75)));
            result = _mm256_add_epi8(result, _mm256_and_si256(eq_62, packed_byte(241)));
            result = _mm256_sub_epi8(result, _mm256_and_si256(eq_63, packed_byte( 12)));

            result = _mm256_add_epi8(result, input);

            return result;
        }

    #undef packed_byte

    } // namespace sse

} // namespace base64

