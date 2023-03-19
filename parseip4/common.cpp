#include "common.h"

struct errorName {
    unsigned    mask;
    std::string name;
}

const errorName[8] = {
    {errTooShort,       "input too short"},
    {errTooLong,        "input too long"},
    {errEmptyField,     "field has no digits"},
    {errTooBig,         "field value greater than 255"},
    {errWrongCharacter, "not allowed character"},
    {errTooManyFields,  "too many fields"},
    {errTooFewFields,   "too few fields"},
    {errLeadingZeros,   "number cannot start with 0"},
};

std::string describeErr(int err) {
    switch (err) {
        case 0:
            return "no error";

        case errInvalidInput:
            return "invalid input";
    }

    std::string res;
    for (const auto& item: errorName) {
        if ((err & item.mask) != 0) {
            if (!res.empty()) {
                res += "/";
            }

            res += item.name;
        }
    }

    return res;
}
