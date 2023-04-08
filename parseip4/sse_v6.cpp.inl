result sse_parse_ipv4_v6(const std::string& ipv4) {
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

    // 2. validate chars if they in range '0'..'9'
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

    dotmask |= msb;

    // 3. build a hashcode -- the valid dotmask is expected
    //    1) to have exactly four bits set, 2) and distances
    //    between ones are 1, 2 or 3.
                                                // ip = 127.3.12.4

                                                //                 127 3 12 4
    uint16_t word0 = dotmask;                   // word0 = 0b0000010001010010
    uint16_t word1 = dotmask;                   // word1 = 0b0000010001010010
    uint16_t word2 = dotmask;                   // word2 = 0b0000010001010010
    uint16_t word3 = dotmask;                   // word3 = 0b0000010001010010

    const int pos0  = __builtin_ctz(word0);     // pos0 = 1

    word1 = word1 & (word1 - 1);                // word1 = 0b0000010001010000
    word2 = word2 & (word2 - 1);                // word2 = 0b0000010001010000
    word3 = word3 & (word3 - 1);                // word3 = 0b0000010001010000

    const int pos1  = __builtin_ctz(word1);     // pos1 = 4

    word2 = word2 & (word2 - 1);                // word2 = 0b0000010001000000
    word3 = word3 & (word3 - 1);                // word3 = 0b0000010001000000

    const int pos2  = __builtin_ctz(word2);     // pos2 = 6

    word3 = word3 & (word3 - 1);                // word3 = 0b0000010000000000

    const int pos3  = __builtin_ctz(word3);     // pos2 = 10

    // 4. Caculate field lengths (from 1 to 3)

    const uint16_t len0 = pos0;                 // len0 = 1
    const uint16_t len1 = pos1 - pos0 - 1;      // len1 = 2
    const uint16_t len2 = pos2 - pos1 - 1;      // len2 = 1
    const uint16_t len3 = pos3 - pos2 - 1;      // len3 = 3

    // 5. Calculate hash:
    //      h = (len0-1) * pow(3,0) + (len1-1) * pow(3,1) + (len2-1) * pow(3,2) + (len3-1) * pow(3,3)
    //      h = (len0-1) + (len2-1) * 3 + (len1-1) * 9 + (len3-1) * 27
    //
    //    h is in range 0..80
    const uint16_t hashcode = (len0-1) + (len1-1) * 3 + (len2-1) * 9 + (len3-1) * 27;

    if (hashcode > 80) {
        res.err = errInvalidInput;
        return res;
    }

    // 3. finally, parse the IPv4 address according to the input length & dots pattern
#   include "sse_parse_aux_v6.inl"

    const uint8_t* spec = &patterns[hashcode][0];
    const uint16_t code = uint16_t(spec[16]) | (uint16_t(spec[17]) << 8);
    if (code != dotmask) {
        res.err = errInvalidInput;
        return res;
    }

    const __m128i ascii0  = _mm_set1_epi8('0');
    const __m128i pattern = _mm_loadu_si128((const __m128i*)spec);
    const __m128i t0      = input;

    const uint8_t max_digits = spec[18];
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
