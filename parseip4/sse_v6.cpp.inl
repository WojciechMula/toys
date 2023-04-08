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
            const __m128i t0        = _mm_sub_epi8(input, ascii0);
            const __m128i t1        = _mm_shuffle_epi8(t0, pattern);

            res.ipv4 = _mm_cvtsi128_si32(t1);
            return res;
            }

        case 2: {
            const __m128i t1     = _mm_shuffle_epi8(t0, pattern);
            const __m128i t2     = _mm_cmpeq_epi8(t1, ascii0);
            const uint32_t msd   = _mm_cvtsi128_si32(t2);
            if (msd != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const uint64_t ascii = _mm_cvtsi128_si64(t1);
            const uint64_t w01   = ascii & 0x0f0f0f0f0f0f0f0f;
            const uint32_t w0    = w01 >> 32;
            const uint32_t w1    = w01 & 0xfffffffflu;
            res.ipv4 = 10 * w1 + w0;
            return res;
            }
        case 3: {
            const __m128i t1        = _mm_shuffle_epi8(t0, pattern);
            const __m128i eq0       = _mm_cmpeq_epi8(t1, ascii0);
            const uint16_t eqmask   = _mm_movemask_epi8(eq0);
            if ((eqmask & 0xaa00) != 0) {
                res.err = errLeadingZeros;
                return res;
            }
            const __m128i t2        = _mm_subs_epu8(t1, ascii0);
            const __m128i weights   = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);
            const __m128i t3        = _mm_maddubs_epi16(t2, weights);
            const __m128i t4        = _mm_alignr_epi8(t3, t3, 8);
            const __m128i t5        = _mm_add_epi16(t4, t3);
            const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));
            const uint16_t gtmask   = _mm_movemask_epi8(gt);
            if ((gtmask & 0x00ff) != 0) {
                res.err = errTooBig;
                return res;
            }
            const __m128i t6 = _mm_packus_epi16(t5, t5);
            res.ipv4 = _mm_cvtsi128_si32(t6);
            return res;
            }
    }

    res.err = errInvalidInput;
    return res;
}
