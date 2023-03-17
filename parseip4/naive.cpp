#include "naive.h"


result naive_parse_ipv4(const std::string& ipv4) {
    result res;
    res.err = 0;
    res.ipv4 = 0;

    if (ipv4.size() < minlen_ipv4) {
        res.err = errTooShort;
        return res;
    }
    if (ipv4.size() > maxlen_ipv4) {
        res.err = errTooLong;
        return res;
    }

    uint32_t word = 0;
    int consumed = 0;
    int components = 0;
    for (char c: ipv4) {
        if (c == '.') {
            if (consumed > 3) {
                res.err = errTooManyDigits;
                return res;
            }

            if (consumed == 0) {
                res.err = errEmptyField;
                return res;
            }

            if (word > 0xff) {
                res.err = errTooBig;
                return res;
            }

            res.ipv4 <<= 8;
            res.ipv4 |= word;
            word = 0;
            consumed = 0;
            components++;
            continue;
        }

        if (c < '0' || c > '9') {
            res.err = errWrongCharacter;
            return res;
        }

        word = 10*word + uint32_t(c - '0');
        consumed++;
    }

    if (components > 3) {
        res.err = errTooManyFields;
        return res;
    }

    if (components < 3) {
        res.err = errTooFewFields;
        return res;
    }

    if (consumed > 3) {
        res.err = errTooManyDigits;
        return res;
    }

    if (consumed == 0) {
        res.err = errEmptyField;
        return res;
    }

    if (word > 0xff) {
        res.err = errTooBig;
        return res;
    }

    res.ipv4 <<= 8;
    res.ipv4 |= word;
    res.ipv4 = __builtin_bswap32(res.ipv4);

    return res;
}

result naive_parse_ipv4_no_validation(const std::string& ipv4) {
    result res;
    res.err = 0;
    res.ipv4 = 0;

    uint32_t word = 0;
    for (char c: ipv4) {
        if (c == '.') {
            res.ipv4 <<= 8;
            res.ipv4 |= word;
            word = 0;
            continue;
        }

        word = 10*word + uint32_t(c - '0');
    }

    res.ipv4 <<= 8;
    res.ipv4 |= word;
    res.ipv4 = __builtin_bswap32(res.ipv4);

    return res;
}
