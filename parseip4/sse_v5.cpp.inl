result sse_parse_ipv4_v5(const std::string& ipv4) {
    result res;
    res.ipv4 = 0;
    res.err = 0;

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

    // 2. validate if the remaining chars are in the range '0'..'9'
    {
        const __m128i ascii0 = _mm_set1_epi8(-128 + '0');
        const __m128i rangedigits = _mm_set1_epi8(-128 + ('9' - '0' + 1));

        const __m128i t1 = _mm_sub_epi8(input, ascii0);
        const __m128i t2 = _mm_cmplt_epi8(t1, rangedigits);

        uint16_t less = _mm_movemask_epi8(t2);
        less &= mask;

        if ((less | dotmask) != mask) {
            res.err = errWrongCharacter;
            return res;
        }
    }

    // n is in range 7..15
    // 137: ((((1 * len) + (31 * ((code >> 9) & 0xff))) + (3 * ((code >> 2) & 0x3f))) - (19 * ((code >> 8) & 0xff)))
    uint16_t w0 = 31 * uint16_t((dotmask >> 9) & 0xff);
    uint16_t w1 =  3 * uint16_t((dotmask >> 2) & 0x3f);
    uint16_t w2 = 19 * uint16_t((dotmask >> 8) & 0xff);
    uint16_t hashcode = n + w0 + w1 - w2;

    // 3. finally parse thr IPv4 address according to the input length & dot mask
    #include "sse_parse_aux_v5.inl"

    if (hashcode > max_hash) {
        res.err = errInvalidInput;
        return res;
    }

    const uint8_t* spec = &patterns[hashcode][0];
    if ((spec[16] != (dotmask & 0xff)) || spec[17] != (dotmask >> 8) || spec[18] != ipv4.size()) {
        res.err = errInvalidInput;
        return res;
    }

    const __m128i ascii0  = _mm_set1_epi8('0');
    const __m128i pattern = _mm_loadu_si128((const __m128i*)spec);
    const __m128i t0      = input;

    const auto max_digits = spec[19];
    switch (max_digits) {
        case 1: {
            SSE_CONVERT_MAX1
            return res;
            }
        case 2: {
            SSE_CONVERT_MAX2
            return res;
            }
        case 3: {
            SSE_CONVERT_MAX3
            return res;
            }
    }

    res.err = errInvalidInput;
    return res;
}
