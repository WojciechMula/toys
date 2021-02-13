#include "avx512bw.h"

#include "scalar.h"
#include <immintrin.h>

uint64_t avx512bw_count_bytes(const uint8_t* data, size_t size, uint8_t byte) {

    const uint8_t* end = data + size;
    const uint8_t* ptr = data;

    uint64_t sum = 0;

    const __m512i v = _mm512_set1_epi8(byte);

    while (ptr + 64 < end) {
        const __m512i in = _mm512_loadu_si512((const __m512i*)ptr);
        sum += __builtin_popcountll(_mm512_cmpeq_epi8_mask(in, v));

        ptr += 64;
    }

    return sum + scalar_count_bytes(ptr, end - ptr, byte);
}

uint64_t avx512bw_count_bytes_unrolled(const uint8_t* data, size_t size, uint8_t byte) {

    const uint8_t* end = data + size;
    const uint8_t* ptr = data;

    uint64_t sum = 0;

    const __m512i v = _mm512_set1_epi8(byte);

    while (ptr + 4*64 < end) {
        const __m512i in0 = _mm512_loadu_si512((const __m512i*)(ptr + 0*64));
        const __m512i in1 = _mm512_loadu_si512((const __m512i*)(ptr + 1*64));
        const __m512i in2 = _mm512_loadu_si512((const __m512i*)(ptr + 2*64));
        const __m512i in3 = _mm512_loadu_si512((const __m512i*)(ptr + 3*64));
        sum += __builtin_popcountll(_mm512_cmpeq_epi8_mask(in0, v));
        sum += __builtin_popcountll(_mm512_cmpeq_epi8_mask(in1, v));
        sum += __builtin_popcountll(_mm512_cmpeq_epi8_mask(in2, v));
        sum += __builtin_popcountll(_mm512_cmpeq_epi8_mask(in3, v));

        ptr += 4*64;
    }

    while (ptr + 64 < end) {
        const __m512i in = _mm512_loadu_si512((const __m512i*)ptr);
        sum += __builtin_popcountll(_mm512_cmpeq_epi8_mask(in, v));

        ptr += 64;
    }

    return sum + scalar_count_bytes(ptr, end - ptr, byte);
}

uint64_t avx512bw_count_bytes__version2(const uint8_t* data, size_t size, uint8_t byte) {

    const uint8_t* end = data + size;
    const uint8_t* ptr = data;

    uint64_t sum = 0;

    const __m512i v    = _mm512_set1_epi8(byte);
    const __m512i v_0f = _mm512_set1_epi8(0x0f);

    // lookup for lane-wide shuffle: [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    const __m512i lookup_initial = _mm512_setr_epi64(1, 0, 1, 0, 1, 0, 1, 0);

    while (ptr + 64*8 < end) {
        __m512i lookup = lookup_initial;

#define OP(n)                                                                       \
        const __m512i in##n = _mm512_loadu_si512((const __m512i*)(ptr + n*64));     \
        const __m512i a##n  = _mm512_xor_si512(in##n, v);                           \
        const __m512i b##n  = _mm512_srli_epi32(a##n, 4);                           \
        /* 0xa8 => (a##n or b##n) & 0x0f */                                         \
        const __m512i c##n  = _mm512_ternarylogic_epi32(a##n, b##n, v_0f, 0xa8);    \
        const __m512i d##n  = _mm512_shuffle_epi8(lookup, c##n);                    \
        lookup = _mm512_add_epi32(lookup, lookup);

        OP(0)
        OP(1)
        OP(2)
        OP(3)
        OP(4)
        OP(5)
        OP(6)
        OP(7)

#undef OP
        const int OR_ALL = 0xfe;
        const __m512i t0 = _mm512_ternarylogic_epi32(d0, d1, d2, OR_ALL);
        const __m512i t1 = _mm512_ternarylogic_epi32(d3, d4, d5, OR_ALL);
        const __m512i t2 = _mm512_ternarylogic_epi32(d6, d7, t0, OR_ALL);
        const __m512i t3 = _mm512_or_si512(t1, t2);

        const __m256i lo = _mm512_extracti64x4_epi64(t3, 0);
        const __m256i hi = _mm512_extracti64x4_epi64(t3, 1);

        sum += __builtin_popcountll(_mm256_extract_epi64(lo, 0));
        sum += __builtin_popcountll(_mm256_extract_epi64(lo, 1));
        sum += __builtin_popcountll(_mm256_extract_epi64(lo, 2));
        sum += __builtin_popcountll(_mm256_extract_epi64(lo, 3));

        sum += __builtin_popcountll(_mm256_extract_epi64(hi, 0));
        sum += __builtin_popcountll(_mm256_extract_epi64(hi, 1));
        sum += __builtin_popcountll(_mm256_extract_epi64(hi, 2));
        sum += __builtin_popcountll(_mm256_extract_epi64(hi, 3));

        ptr += 64*8;
    }

    return sum + scalar_count_bytes(ptr, end - ptr, byte);
}

uint64_t avx512bw_count_bytes__version3(const uint8_t* data, size_t size, uint8_t byte) {

    const uint8_t* end = data + size;
    const uint8_t* ptr = data;

    const __m512i v    = _mm512_set1_epi8(byte);
    const __m512i v_0f = _mm512_set1_epi8(0x0f);

    // lookup for lane-wide shuffle: [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    const __m512i lookup_initial  = _mm512_setr_epi64(1, 0, 1, 0, 1, 0, 1, 0);
    // lookup for 4-bit popcount
    const __m512i lookup_popcount = _mm512_setr_epi64(
            0x0302020102010100llu, 0x0403030203020201llu,
            0x0302020102010100llu, 0x0403030203020201llu,
            0x0302020102010100llu, 0x0403030203020201llu,
            0x0302020102010100llu, 0x0403030203020201llu);

    __m512i vector_acc = _mm512_setzero_si512();
    while (ptr + 64*4 < end) {
        __m512i lookup = lookup_initial;

#define OP(n)                                                                       \
        const __m512i in##n = _mm512_loadu_si512((const __m512i*)(ptr + n*64));     \
        const __m512i a##n  = _mm512_xor_si512(in##n, v);                           \
        const __m512i b##n  = _mm512_srli_epi32(a##n, 4);                           \
        /* 0xa8 => (a##n or b##n) & 0x0f */                                         \
        const __m512i c##n  = _mm512_ternarylogic_epi32(a##n, b##n, v_0f, 0xa8);    \
        const __m512i d##n  = _mm512_shuffle_epi8(lookup, c##n);                    \
        lookup = _mm512_add_epi32(lookup, lookup);

        OP(0)
        OP(1)
        OP(2)
        OP(3)

#undef OP
        const int OR_ALL = 0xfe;
        const __m512i t0 = _mm512_ternarylogic_epi32(d0, d1, d2, OR_ALL);
        const __m512i t1 = _mm512_or_si512(d3, t0);

        // t1 has got 4-bit values in bytes
        const __m512i popcnt = _mm512_shuffle_epi8(lookup_popcount, t1);
        const __m512i vector_sum = _mm512_sad_epu8(popcnt, _mm512_setzero_si512());
        vector_acc = _mm512_add_epi64(vector_acc, vector_sum);

        ptr += 64*4;
    }

    uint64_t sum = 0;

    const __m256i lo = _mm512_extracti64x4_epi64(vector_acc, 0);
    const __m256i hi = _mm512_extracti64x4_epi64(vector_acc, 1);
    const __m256i t0 = _mm256_add_epi64(lo, hi);

    sum += _mm256_extract_epi64(t0, 0);
    sum += _mm256_extract_epi64(t0, 1);
    sum += _mm256_extract_epi64(t0, 2);
    sum += _mm256_extract_epi64(t0, 3);

    return sum + scalar_count_bytes(ptr, end - ptr, byte);
}

uint64_t avx512bw_count_bytes__version4(const uint8_t* data, size_t size, uint8_t byte) {

    const uint8_t* end = data + size;
    const uint8_t* ptr = data;

    const __m512i v    = _mm512_set1_epi8(byte);
    const __m512i v_01 = _mm512_set1_epi8(0x01);

    // lookup for NEGATED 4-bit popcount
    const __m512i lookup_popcount = _mm512_setr_epi64(
            0x0102020302030304llu, 0x0001010201020203llu,
            0x0102020302030304llu, 0x0001010201020203llu,
            0x0102020302030304llu, 0x0001010201020203llu,
            0x0102020302030304llu, 0x0001010201020203llu);

    __m512i vector_acc = _mm512_setzero_si512();
    while (ptr + 64*4 < end) {
        __m512i tmp = _mm512_setzero_si512();

#define OP(n)                                                                       \
        const __m512i in##n = _mm512_loadu_si512((const __m512i*)(ptr + n*64));     \
        const __m512i a##n  = _mm512_xor_si512(in##n, v);                           \
        const __m512i b##n  = _mm512_min_epu8(a##n, v_01);                          \
        tmp = _mm512_add_epi64(tmp, tmp);                                           \
        tmp = _mm512_add_epi64(tmp, b##n);

        OP(0)
        OP(1)
        OP(2)
        OP(3)

#undef OP
        // tmp has got NEGATED 4-bit values in bytes
        const __m512i popcnt = _mm512_shuffle_epi8(lookup_popcount, tmp);
        const __m512i vector_sum = _mm512_sad_epu8(popcnt, _mm512_setzero_si512());
        vector_acc = _mm512_add_epi64(vector_acc, vector_sum);

        ptr += 64*4;
    }

    uint64_t sum = 0;

    const __m256i lo = _mm512_extracti64x4_epi64(vector_acc, 0);
    const __m256i hi = _mm512_extracti64x4_epi64(vector_acc, 1);
    const __m256i t0 = _mm256_add_epi64(lo, hi);

    sum += _mm256_extract_epi64(t0, 0);
    sum += _mm256_extract_epi64(t0, 1);
    sum += _mm256_extract_epi64(t0, 2);
    sum += _mm256_extract_epi64(t0, 3);

    return sum + scalar_count_bytes(ptr, end - ptr, byte);
}

uint64_t avx512bw_count_bytes__version5(const uint8_t* data, size_t size, uint8_t byte) {

    const uint8_t* end = data + size;
    const uint8_t* ptr = data;

    const __m512i v    = _mm512_set1_epi8(byte);
    const __m512i v_01 = _mm512_set1_epi8(0x01);

    __m512i vector_acc = _mm512_setzero_si512();
    while (ptr + 64*255 < end) {
        __m512i local_sum = _mm512_set1_epi8(-1); // 255

        // update 64 x 8-bit counter
        for (int i=0; i < 255; i++, ptr += 64) {
            const __m512i in = _mm512_loadu_si512((const __m512i*)ptr);
            const __m512i t0 = _mm512_xor_si512(in, v);
            const __m512i t1 = _mm512_min_epu8(t0, v_01); // 0 if equal, 1 otherwise

            local_sum = _mm512_sub_epi8(local_sum, t1);
        }

        // update the global accumulator 8 x 64-bit
        const __m512i tmp = _mm512_sad_epu8(local_sum, _mm512_setzero_si512());
        vector_acc = _mm512_add_epi64(vector_acc, tmp);
    }

    uint64_t sum = 0;

    const __m256i lo = _mm512_extracti64x4_epi64(vector_acc, 0);
    const __m256i hi = _mm512_extracti64x4_epi64(vector_acc, 1);
    const __m256i t0 = _mm256_add_epi64(lo, hi);

    sum += _mm256_extract_epi64(t0, 0);
    sum += _mm256_extract_epi64(t0, 1);
    sum += _mm256_extract_epi64(t0, 2);
    sum += _mm256_extract_epi64(t0, 3);

    return sum + scalar_count_bytes(ptr, end - ptr, byte);
}
