#pragma once

#include <cstdint>
#include <string>

enum errors {
    errTooShort         = 1,
    errTooLong          = 2,
    errTooManyDigits    = 3,
    errEmptyField       = 4,
    errTooBig           = 5,
    errWrongCharacter   = 6,
    errTooManyFields    = 7,
    errTooFewFields     = 8,
    errLeadingZeros     = 9
};

struct result {
    uint32_t    ipv4;
    int         err;
};

const uint32_t minlen_ipv4 = 7;      // "0.0.0.0"
const uint32_t maxlen_ipv4 = 15;     // "123.123.123.123"
