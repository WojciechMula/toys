#include <cstdint>

namespace reference {

    uint8_t cmp(bool val) {
        return val ? 0xff : 0x00;
    }

    uint8_t andnot(uint8_t a, uint8_t b) {
        return ~a & b;
    }

    /*
        Number of operations:
        - comparison    : 5
        - and           : 5
        - adnnot        : 2
        - or            : 4
        - add           : 1
        - total         = 17
    */
    char lookup_naive(uint8_t i) {

        const uint8_t less_26 = cmp(i < 26);
        const uint8_t less_52 = cmp(i < 52);
        const uint8_t less_62 = cmp(i < 62);
        const uint8_t equal_62 = cmp(i == 62);
        const uint8_t equal_63 = cmp(i == 63);

        const uint8_t range_AZ = 'A' & less_26;
        const uint8_t range_az = ('a' - 26) & andnot(less_26, less_52);
        const uint8_t range_09 = ('0' - 52) & andnot(less_52, less_62);
        const uint8_t char_plus  = ('+' - 62) & equal_62;
        const uint8_t char_slash = ('/' - 63) & equal_63;

        const uint8_t shift = range_AZ | range_az | range_09 | char_plus | char_slash;

        return shift + i;
    }

    /*
        Number of operations:
        - comparison    : 4
        - and           : 4
        - adnnot        : 1
        - or            : 1
        - add           : 4
        - total         = 10
    */
    char lookup_version1(uint8_t i) {

        uint8_t range;

        // 1. resolve ranges A-Z, a-z and 0-9
        const uint8_t shift_AZ = 'A';
        const uint8_t shift_az = 'a' - 26;

        range = shift_AZ;
        range += cmp(i >= 26) & (shift_az - shift_AZ);
        range -= cmp(i >= 52) & 75;
        range += i;

        const uint8_t le_61 = cmp(i <= 61);
        range &= le_61;

        // 2. resolve chars '+' and '/'
        uint8_t ord_62_or_63 = '+';
        ord_62_or_63 += cmp(i == 63) & 4;
        ord_62_or_63 &= ~le_61;

        // 3. merge ranges
        return range | ord_62_or_63;
    }


    char lookup_version1_base(uint8_t i) {

        uint8_t range;

        // 1. resolve ranges A-Z, a-z and 0-9
        const uint8_t shift_AZ = 'A';
        const uint8_t shift_az = 'a' - 26;
        //const uint8_t shift_09 = '0' - 52;

        range = shift_AZ;
        range += cmp(i >= 26) & (shift_az - shift_AZ);
        // ('0' - 52) - ('a' - 26) = -75
        // range += cmp(i >= 52) & (shift_09 - shift_az);
        range -= cmp(i >= 52) & 75;
        range += i;

        const uint8_t le_61 = cmp(i <= 61);
        range &= le_61;

        // 2. resolve chars '+' and '/'
        const uint8_t ord_62 = cmp(i == 62) & '+';
        const uint8_t ord_63 = cmp(i == 63) & '/';

        // 3. merge ranges
        return range | ord_62 | ord_63;
    }
}
