result sse_parse_ipv4_v2(const std::string& ipv4) {
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

    const uint16_t msb = uint16_t(1) << n;
    const uint16_t mask = msb - 1;

    const __m128i input = _mm_loadu_si128((const __m128i*)ipv4.data());

    // 1. locate dots
    uint16_t dotmask;
    {
        const __m128i dot = _mm_set1_epi8('.');
        const __m128i t0 = _mm_cmpeq_epi8(input, dot);
        dotmask = _mm_movemask_epi8(t0);
        dotmask &= mask;
    }

    // ... there has to be exactly 3 dots
    const auto k = __builtin_popcount(dotmask);
    if (k != 3) {
        if (k > 3) {
            res.err = errTooManyFields;
        } else {
            res.err = errTooFewFields;
        }
        return res;
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

    // 3. add the dot after the last character (max length is 15 chars, so it's safe)
    dotmask |= msb;

    // 4. build pattern mask (rejecting wrong patterns upfront)
    const uint8_t* data = (const uint8_t*)ipv4.data();
    uint8_t code = 0;
    for (int i=0; i < 4; i++) {
        const uint8_t n = __builtin_ctz(dotmask);
        if (n == 0) {
            res.err = errEmptyField;
            return res;
        }
        if (n > 3) {
            res.err = errTooManyDigits;
            return res;
        }

        code = (code << 2) | n;
        dotmask >>= n + 1;
    }

    // 5. finally parse the IPv4 address according to the pattern
    #include "sse_parse_aux_v2.inl"

    return res;
}
