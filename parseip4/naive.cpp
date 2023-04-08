#include "naive.h"

result naive_parse_ipv4(const std::string& ipv4) {
    result res;
    res.ipv4 = 0;
    res.err = 0;

    if (ipv4.size() < minlen_ipv4) {
        res.err = errTooShort;
        return res;
    }
    if (ipv4.size() > maxlen_ipv4) {
        res.err = errTooLong;
        return res;
    }

    uint32_t word = 0;
    unsigned consumed = 0;
    unsigned component = 0;

    for (char c: ipv4) {
        if (c == '.') {
            if (component > 3) {
                res.err = errTooManyFields;
                return res;
            }

            switch (consumed) {
                case 0:
                    res.err = errEmptyField;
                    return res;

                case 1:
                    res.byte[component] = word;
                    break;

                case 2:
                    if (word < 10) {
                        res.err = errLeadingZeros;
                        return res;
                    }
                    res.byte[component] = word;
                    break;

                case 3:
                    if (word < 100) {
                        res.err = errLeadingZeros;
                        return res;
                    } else if (word > 255) {
                        res.err = errTooBig;
                        return res;
                    }

                    res.byte[component] = word;
                    break;

                default:
                    res.err = errTooManyDigits;
                    return res;
            }

            word = 0;
            consumed = 0;
            component++;
            continue;
        }

        if (c < '0' || c > '9') {
            res.err = errWrongCharacter;
            return res;
        }

        word = 10*word + uint32_t(c - '0');
        consumed++;
    }

    if (component != 3) {
        if (component > 3) {
            res.err = errTooManyFields;
            return res;
        } else {
            res.err = errTooFewFields;
            return res;
        }
    }

    switch (consumed) {
        case 0:
            res.err = errEmptyField;
            return res;

        case 1:
            res.byte[component] = word;
            break;

        case 2:
            if (word < 10) {
                res.err = errLeadingZeros;
                return res;
            }
            res.byte[component] = word;
            break;

        case 3:
            if (word < 100) {
                res.err = errLeadingZeros;
                return res;
            } else if (word > 255) {
                res.err = errTooBig;
                return res;
            }

            res.byte[component] = word;
            break;

        default:
            res.err = errTooManyDigits;
            return res;
    }

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
