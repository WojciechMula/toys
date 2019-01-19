#include "sse.h"

#include "scalar.h"
#include <immintrin.h>

uint64_t sse_count_byte(const uint8_t* data, size_t size, uint8_t byte) {

    const __m128i v = _mm_set1_epi8(byte);

    const uint8_t* end = data + size;
    const uint8_t* ptr = data;

    __m128i global_sum = _mm_setzero_si128();
    __m128i local_sum;

    // 1. blocks of 255 registers
    while (ptr + 255*16 < end) {
        local_sum = _mm_setzero_si128();

        // update 16 x 8-bit counter
        for (int i=0; i < 255; i++, ptr += 16) {
            const __m128i in = _mm_loadu_si128((const __m128i*)ptr);
            const __m128i eq = _mm_cmpeq_epi8(in, v); // 0 or -1

            local_sum = _mm_sub_epi8(local_sum, eq);
        }

        // update the global accumulator 2 x 64-bit
        const __m128i tmp = _mm_sad_epu8(local_sum, _mm_setzero_si128());
        global_sum = _mm_add_epi64(global_sum, tmp);
    }


    // 2. tail of < 255 registers
    local_sum = _mm_setzero_si128();
    while (ptr + 16 < end) {
        const __m128i in = _mm_loadu_si128((const __m128i*)ptr);
        const __m128i eq = _mm_cmpeq_epi8(in, v);

        local_sum = _mm_sub_epi8(local_sum, eq);

        ptr += 16;
    }

    const __m128i tmp = _mm_sad_epu8(local_sum, _mm_setzero_si128());
    global_sum = _mm_add_epi64(global_sum, tmp);


    // 3. process tail < 16 bytes
    uint64_t result = _mm_extract_epi64(global_sum, 0)
                    + _mm_extract_epi64(global_sum, 1);

    return result + scalar_count_bytes(ptr, end - ptr, byte);
}


uint64_t sse_count_byte_popcount(const uint8_t* data, size_t size, uint8_t byte) {

    const __m128i v = _mm_set1_epi8(byte);

    const uint8_t* end = data + size;
    const uint8_t* ptr = data;

    uint64_t result = 0;

    // 1. blocks of 8 registers
    while (ptr + 8*16 < end) {
        const __m128i eq0 = _mm_cmpeq_epi8(v, _mm_loadu_si128((const __m128i*)(ptr + 0*16)));
        const __m128i eq1 = _mm_cmpeq_epi8(v, _mm_loadu_si128((const __m128i*)(ptr + 1*16)));
        const __m128i eq2 = _mm_cmpeq_epi8(v, _mm_loadu_si128((const __m128i*)(ptr + 2*16)));
        const __m128i eq3 = _mm_cmpeq_epi8(v, _mm_loadu_si128((const __m128i*)(ptr + 3*16)));
        const __m128i eq4 = _mm_cmpeq_epi8(v, _mm_loadu_si128((const __m128i*)(ptr + 4*16)));
        const __m128i eq5 = _mm_cmpeq_epi8(v, _mm_loadu_si128((const __m128i*)(ptr + 5*16)));
        const __m128i eq6 = _mm_cmpeq_epi8(v, _mm_loadu_si128((const __m128i*)(ptr + 6*16)));
        const __m128i eq7 = _mm_cmpeq_epi8(v, _mm_loadu_si128((const __m128i*)(ptr + 7*16)));

        const __m128i eq0bit = _mm_and_si128(eq0, _mm_set1_epi8(0x01));
        const __m128i eq1bit = _mm_and_si128(eq1, _mm_set1_epi8(0x02));
        const __m128i eq2bit = _mm_and_si128(eq2, _mm_set1_epi8(0x04));
        const __m128i eq3bit = _mm_and_si128(eq3, _mm_set1_epi8(0x08));
        const __m128i eq4bit = _mm_and_si128(eq4, _mm_set1_epi8(0x10));
        const __m128i eq5bit = _mm_and_si128(eq5, _mm_set1_epi8(0x20));
        const __m128i eq6bit = _mm_and_si128(eq6, _mm_set1_epi8(0x40));
        const __m128i eq7bit = _mm_and_si128(eq7, _mm_set1_epi8(int8_t(0x80)));

        const __m128i m01    = _mm_or_si128(eq0bit, eq1bit);
        const __m128i m23    = _mm_or_si128(eq2bit, eq3bit);
        const __m128i m45    = _mm_or_si128(eq4bit, eq5bit);
        const __m128i m67    = _mm_or_si128(eq6bit, eq7bit);

        const __m128i m0123  = _mm_or_si128(m01, m23);
        const __m128i m4567  = _mm_or_si128(m45, m67);

        const __m128i merged = _mm_or_si128(m0123, m4567);

        result += __builtin_popcountll(_mm_extract_epi64(merged, 0));
        result += __builtin_popcountll(_mm_extract_epi64(merged, 1));

        ptr += 8 * 16;
    }

    return result + scalar_count_bytes(ptr, end - ptr, byte);
}

