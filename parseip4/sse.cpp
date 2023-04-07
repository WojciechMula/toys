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

        if ((less | dotmask) != mask) {
            res.err = errWrongCharacter;
            return res;
        }
    }

    // 2. add the dot after the last character (max length is 15 chars)
    dotmask |= uint16_t(1) << ipv4.size();

    // 4. process four components
    const uint8_t* data = (const uint8_t*)ipv4.data();
    for (int i=0; i < 4; i++) {
        const int n = __builtin_ctz(dotmask);

        switch (n) {
            case 1:
                res.byte[i] = (data[0] - '0');

                data += 2;
                dotmask >>= 2;
                break;

            case 2:
                {
                    const uint32_t tmp = 10 * (data[0] - '0') + (data[1] - '0');
                    if (tmp < 10) {
                        res.err = errLeadingZeros;
                        return res;
                    }
                    res.byte[i] = tmp;
                }
                data += 3;
                dotmask >>= 3;
                break;

            case 3:
                {
                    const uint32_t tmp = 100 * (data[0] - '0') + 10 * (data[1] - '0') + (data[2] - '0');
                    if (tmp > 0xff) {
                        res.err = errTooBig;
                        return res;
                    }
                    if (tmp < 100) {
                        res.err = errLeadingZeros;
                        return res;
                    }

                    res.byte[i] = tmp;
                }

                data += 4;
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


#include "sse_v2.cpp.inl"
#include "sse_v3.cpp.inl"
#include "sse_v4.cpp.inl"
#include "sse_v5.cpp.inl"
#include "sse_v6.cpp.inl"
#include "sse_v7.cpp.inl"
#include "sse_v8.cpp.inl"
