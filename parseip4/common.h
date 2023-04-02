#pragma once

#include <cstdint>
#include <string>

enum errors {
    errInvalidInput     = 0xffff,   // generic error
    errTooShort         = 0x0001,
    errTooLong          = 0x0002,
    errTooManyDigits    = 0x0004,
    errEmptyField       = 0x0008,
    errTooBig           = 0x0010,
    errWrongCharacter   = 0x0020,
    errTooManyFields    = 0x0040,
    errTooFewFields     = 0x0080,
    errLeadingZeros     = 0x0100
};

std::string describeErr(int err);

struct result {
    union {
        uint32_t    ipv4;
        uint8_t     byte[4];
    };
    int         err;
};

const uint32_t minlen_ipv4 = 7;      // "0.0.0.0"
const uint32_t maxlen_ipv4 = 15;     // "123.123.123.123"

// https://graphics.stanford.edu/~seander/bithacks.html#ZeroInWord
#define haszero32(v) (((v) - 0x01010101ul) & ~(v) & 0x80808080ul)
#define haszero64(v) (((v) - 0x0101010101010101ull) & ~(v) & 0x8080808080808080ull)
