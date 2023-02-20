#include "sse.h"

#include <immintrin.h>

result sse_parse_ipv4(const std::string& ipv4) {
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

    // there has to be exactly 3 dots
    const auto k = __builtin_popcount(dotmask);
    if (k != 3) {
        if (k > 3) {
            res.err = errTooManyFields;
        } else {
            res.err = errTooFewFields;
        }
        return res;
    }

    // 3. validate chars if they in range '0'..'9'
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

    // 2. add the dot after the last character (max length is 15 chars)
    dotmask |= uint16_t(1) << ipv4.size();

    // 4. process four components
    const uint8_t* byte = (const uint8_t*)ipv4.data();
    for (int i=0; i < 4; i++) {
        const int n = __builtin_ctz(dotmask);

        switch (n) {
            case 1:
                res.ipv4 <<= 8;
                res.ipv4 |= (byte[0] - '0');

                byte += 2;
                dotmask >>= 2;
                break;

            case 2:
                {
                    const uint32_t tmp = 10 * (byte[0] - '0') + (byte[1] - '0');
                    if (tmp < 10) {
                        res.err = errLeadingZeros;
                        return res;
                    }
                    res.ipv4 <<= 8;
                    res.ipv4 |= tmp;
                }
                byte += 3;
                dotmask >>= 3;
                break;

            case 3:
                {
                    const uint32_t tmp = 100 * (byte[0] - '0') + 10 * (byte[1] - '0') + (byte[2] - '0');
                    if (tmp > 0xff) {
                        res.err = errTooBig;
                        return res;
                    }
                    if (tmp < 100) {
                        res.err = errLeadingZeros;
                        return res;
                    }

                    res.ipv4 <<= 8;
                    res.ipv4 |= tmp;
                }

                byte += 4;
                dotmask >>= 4;
                break;

            default:
                if (n > 0) {
                    res.err = errTooManyDigits;
                } else {
                    res.err = errEmptyField;
                }
                return res;
        }
    }

    return res;
}

result sse_parse_ipv4_v2(const std::string& ipv4) {
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

    // 3. add the dot after the last character (max length is 15 chars, so it's safe)
    dotmask |= uint16_t(1) << ipv4.size();

    // 4. build pattern mask (rejecting wrong patterns upfront)
    const uint8_t* byte = (const uint8_t*)ipv4.data();
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

    // 5. finally parse ipv4 address according to pattern
#   include "sse_parse_aux_v2.inl"

    return res;
}


result sse_parse_ipv4_v3(const std::string& ipv4) {
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

    const uint8_t* byte = (const uint8_t*)ipv4.data();

    // 3. finally parse ipv4 address according to input length & the dots pattern
#   include "sse_parse_aux_v3.inl"

    return res;
}

result sse_parse_ipv4_v4(const std::string& ipv4) {
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

    // 3. finally parse ipv4 address according to input length & the dots pattern
#   include "sse_parse_aux_v4.inl"

    return res;
}

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
    uint32_t w0 = 23 * uint32_t((dotmask >> 0) & 0xf);
    uint32_t w1 =  5 * uint32_t((dotmask >> 4) & 0xf);
    uint32_t w2 = 13 * uint32_t((dotmask >> 8) & 0xf);
    uint32_t hashcode = n ^ w0 ^ (w1 + w2);

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

result sse_parse_ipv4_v6(const std::string& ipv4) {
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

    // 3. finally parse ipv4 address according to input length & the dots pattern
#   include "sse_parse_aux_v6.inl"

    const uint8_t* pat = &patterns[hashcode][0];
    const uint16_t code = (uint16_t(pat[14]) << 8) | (uint16_t(pat[13]));
    if (code != dotmask) {
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
