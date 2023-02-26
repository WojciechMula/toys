result sse_parse_ipv4_v7(const std::string& ipv4) {
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
        dotmask |= 1 << n;
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

#   include "sse_parse_aux_v7.inl"

    // 3. build a hashcode -- see generate_v7/main.go::hash_v3
    const uint16_t hashcode = (dotmask >> 5) ^ (dotmask & 0x03ff);
    if (hashcode > max_hash) {
        res.err = errInvalidInput;
        return res;
    }

    // 3. finally parse ipv4 address according to input length & the dots pattern

    const int8_t id = patterns_id[hashcode];
    const uint8_t* pat = &patterns[id][0];
    const uint16_t expected_code = (uint16_t(pat[14]) << 8) | (uint16_t(pat[13]));
    if (expected_code != dotmask) {
        res.err = errInvalidInput;
        return res;
    }

    const uint8_t max_digits = pat[15];
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
