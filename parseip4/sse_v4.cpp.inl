result sse_parse_ipv4_v4(const std::string& ipv4) {
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

    const __m128i ascii0  = _mm_set1_epi8('0');
    const __m128i t0      = input;

    // 3. finally parse ipv4 address according to input length & the dots pattern
#   include "sse_parse_aux_v4.inl"

    return res;
}
