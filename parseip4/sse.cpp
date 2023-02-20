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
