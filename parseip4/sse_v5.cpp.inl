result sse_parse_ipv4_v5(const std::string& ipv4) {
    result res;
    res.ipv4 = 0;
    res.err = false;

    const size_t n = ipv4.size();
    if (n < minlen_ipv4) {
        res.err = errTooShort;
        return res;
    }
    if (n > maxlen_ipv4) {
        res.err = errTooLong;
        return res;
    }

    uint16_t mask = 0xffff;
    mask <<= n;
    mask = ~mask;

    const __m128i input = _mm_loadu_si128((const __m128i*)ipv4.data());

    // 1. locate dots
    uint16_t dotmask;
    {
        const __m128i dot = _mm_set1_epi8('.');
        const __m128i t0 = _mm_cmpeq_epi8(input, dot);
        dotmask = _mm_movemask_epi8(t0);
        dotmask &= mask;
    }

    // 2. validate chars if they in range '0'..'9'
    {
        const __m128i ascii0 = _mm_set1_epi8(-128 + '0');
        const __m128i rangedigits = _mm_set1_epi8(-128 + ('9' - '0' + 1));

        const __m128i t1 = _mm_sub_epi8(input, ascii0);
        const __m128i t2 = _mm_cmplt_epi8(t1, rangedigits);

        uint16_t less = _mm_movemask_epi8(t2);
        less &= mask;
        less ^= (~dotmask) & mask;

        if (less != 0) {
            res.err = errWrongCharacter;
            return res;
        }
    }

    // k is in range 7..15
    // 137: ((((1 * len) + (31 * ((code >> 9) & 0xff))) + (3 * ((code >> 2) & 0x3f))) - (19 * ((code >> 8) & 0xff)))
    uint32_t w0 = 31 * uint32_t((dotmask >> 9) & 0xff);
    uint32_t w1 =  3 * uint32_t((dotmask >> 2) & 0x3f);
    uint32_t w2 = 19 * uint32_t((dotmask >> 8) & 0xff);
    uint32_t hashcode = n + w0 + w1 - w2;

    // 3. finally parse ipv4 address according to input length & the dots pattern
#   include "sse_parse_aux_v5.inl"

    const int8_t* pat = &patterns[hashcode][0];
    const auto max_digits = pat[15];
    switch (max_digits) {
        case 1: {
            const __m128i pattern = _mm_load_si128((const __m128i*)pat);
            const __m128i ascii0 = _mm_set1_epi8('0');
            const __m128i t0 = _mm_sub_epi8(input, ascii0);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);

            res.ipv4 = _mm_cvtsi128_si32(t1);
            return res;
            }

        case 2: {
            const __m128i pattern = _mm_load_si128((const __m128i*)pat);
            const __m128i ascii0 = _mm_set1_epi8('0');
            const __m128i t0 = _mm_sub_epi8(input, ascii0);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);

            const uint64_t w01 = _mm_cvtsi128_si64(t1);
            const uint32_t w0 = w01;
            const uint32_t w1 = (w01 >> 32);
            res.ipv4 = 10 * w1 + w0;
            return res;
            }
        case 3: {
            const __m128i pattern = _mm_load_si128((const __m128i*)pat);
            const __m128i ascii0 = _mm_set1_epi8('0');
            const __m128i t0 = _mm_sub_epi8(input, ascii0);
            const __m128i t1 = _mm_shuffle_epi8(t0, pattern);

            const uint64_t w01 = _mm_cvtsi128_si64(t1);
            const uint32_t w2 = _mm_extract_epi32(t1, 2);
            const uint32_t w0 = w01;
            const uint32_t w1 = (w01 >> 32);
            res.ipv4 = 10 * (10 * w2 + w1) + w0;
            return res;
            }
    }

    res.err = errInvalidInput;
    return res;
}
