// macro-definitions for SSE conversion procedures

#define SSE_CONVERT_MAX1                                    \
    const __m128i t1 = _mm_sub_epi8(t0, ascii0);            \
    const __m128i t2 = _mm_shuffle_epi8(t1, pattern);       \
    res.ipv4 = _mm_cvtsi128_si32(t2);

#define SSE_CONVERT_MAX2                                    \
    const __m128i t1     = _mm_shuffle_epi8(t0, pattern);   \
    const __m128i t2     = _mm_cmpeq_epi8(t1, ascii0);      \
    const uint32_t msd   = _mm_cvtsi128_si32(t2);           \
    if (msd != 0) {                                         \
        res.err = errLeadingZeros;                          \
        return res;                                         \
    }                                                       \
    const uint64_t ascii = _mm_cvtsi128_si64(t1);           \
    const uint64_t w01   = ascii & 0x0f0f0f0f0f0f0f0f;      \
    const uint32_t w0    = w01 >> 32;                       \
    const uint32_t w1    = w01 & 0xfffffffflu;              \
    res.ipv4 = 10 * w1 + w0;

#define SSE_CONVERT_MAX3                                        \
    const __m128i t1        = _mm_shuffle_epi8(t0, pattern);    \
    const __m128i eq0       = _mm_cmpeq_epi8(t1, ascii0);       \
    const uint16_t eqmask   = _mm_movemask_epi8(eq0);           \
    if ((eqmask & 0xaa00) != 0) {                               \
        res.err = errLeadingZeros;                              \
        return res;                                             \
    }                                                           \
    const __m128i t2        = _mm_subs_epu8(t1, ascii0);        \
    const __m128i weights   = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0); \
    const __m128i t3        = _mm_maddubs_epi16(t2, weights);   \
    const __m128i t4        = _mm_alignr_epi8(t3, t3, 8);       \
    const __m128i t5        = _mm_add_epi16(t4, t3);            \
    const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255)); \
    const uint16_t gtmask   = _mm_movemask_epi8(gt);            \
    if ((gtmask & 0x00ff) != 0) {                               \
        res.err = errTooBig;                                    \
        return res;                                             \
    }                                                           \
    const __m128i t6 = _mm_packus_epi16(t5, t5);                \
    res.ipv4 = _mm_cvtsi128_si32(t6);
