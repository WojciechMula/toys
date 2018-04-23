// This file contains the translation of an excellent scalar procedure
// by Leandro A. F. Pereira (@lpereira)
// https://github.com/lpereira/lwan/blob/master/src/lib/lwan-time.c
//
// His code is under GPL, so I had to rewrite it.

#include <cstdint>

#define CONST(b0, b1, b2, b3) (         \
      (uint32_t(uint8_t(b0)) << 0*8)    \
    | (uint32_t(uint8_t(b1)) << 1*8)    \
    | (uint32_t(uint8_t(b2)) << 2*8)    \
    | (uint32_t(uint8_t(b3)) << 3*8)    \
)

namespace {

    enum {
        WEEKDAY0    = 0,
        WEEKDAY1    = 1,
        WEEKDAY2    = 2,

        COMMA       = 3,
        SPACE0      = 4,

        DAY0        = 5,
        DAY1        = 6,

        SPACE1      = 7,

        MONTH0      = 8,
        MONTH1      = 9,
        MONTH2      = 10,

        SPACE2      = 11,

        YEAR0       = 12,
        YEAR1       = 13,
        YEAR2       = 14,
        YEAR3       = 15,

        SPACE3      = 16,

        HOUR0       = 17,
        HOUR1       = 18,

        COLON0      = 19,

        MINUTE0     = 20,
        MINUTE1     = 21,

        COLON1      = 22,

        SECOND0     = 23,
        SECOND1     = 24,

        SPACE4      = 25,

        LETTER_G    = 26,
        LETTER_M    = 27,
        LETTER_T    = 28,
    };

    int parse_2digits(const char* in) {

        uint8_t digit0 = uint8_t(in[0]) - '0';
        if (digit0 > 9) {
            return -1;
        }

        uint8_t digit1 = uint8_t(in[1]) - '0';
        if (digit1 > 9) {
            return -1;
        }

        return digit0 * 10 + digit1;
    }


    int parse_4digits(const char* in) {

        unsigned digit0 = uint8_t(in[0]) - '0';
        if (digit0 > 9) {
            return -1;
        }

        unsigned digit1 = uint8_t(in[1]) - '0';
        if (digit1 > 9) {
            return -1;
        }

        unsigned digit2 = uint8_t(in[2]) - '0';
        if (digit2 > 9) {
            return -1;
        }

        unsigned digit3 = uint8_t(in[3]) - '0';
        if (digit3 > 9) {
            return -1;
        }

        return digit0 * 1000 + digit1 * 100 + digit2 * 10 + digit3;
    }

} // namespace

#ifdef UNITTESTS
#   define ERROR(value) (-(value))
#else
#   define ERROR(_)     (-EINVAL)
#endif

int parse_rfc_date_reference(const char* in, tm* fields) {

    switch (CONST(in[WEEKDAY0], in[WEEKDAY1], in[WEEKDAY2], in[COMMA])) {
        case CONST('S', 'u', 'n', ','): fields->tm_wday = 0; break;
        case CONST('M', 'o', 'n', ','): fields->tm_wday = 1; break;
        case CONST('T', 'u', 'e', ','): fields->tm_wday = 2; break;
        case CONST('W', 'e', 'd', ','): fields->tm_wday = 3; break;
        case CONST('T', 'h', 'u', ','): fields->tm_wday = 4; break;
        case CONST('F', 'r', 'i', ','): fields->tm_wday = 5; break;
        case CONST('S', 'a', 't', ','): fields->tm_wday = 6; break;
        default:
            return ERROR(1);
    }

    if (in[SPACE0] != ' ') {
        return ERROR(2);
    }

    fields->tm_mday = parse_2digits(in + DAY0);
    if (fields->tm_mday < 1 || fields->tm_mday > 31) {
        return ERROR(3);
    }

    if (in[SPACE1] != ' ') {
        return ERROR(4);
    }

    switch (CONST(in[MONTH0], in[MONTH1], in[MONTH2], in[SPACE2])) {
        case CONST('J', 'a', 'n', ' '): fields->tm_mon = 0; break;
        case CONST('F', 'e', 'b', ' '): fields->tm_mon = 1; break;
        case CONST('M', 'a', 'r', ' '): fields->tm_mon = 2; break;
        case CONST('A', 'p', 'r', ' '): fields->tm_mon = 3; break;
        case CONST('M', 'a', 'y', ' '): fields->tm_mon = 4; break;
        case CONST('J', 'u', 'n', ' '): fields->tm_mon = 5; break;
        case CONST('J', 'u', 'l', ' '): fields->tm_mon = 6; break;
        case CONST('A', 'u', 'g', ' '): fields->tm_mon = 7; break;
        case CONST('S', 'e', 'p', ' '): fields->tm_mon = 8; break;
        case CONST('O', 'c', 't', ' '): fields->tm_mon = 9; break;
        case CONST('N', 'o', 'v', ' '): fields->tm_mon = 10; break;
        case CONST('D', 'e', 'c', ' '): fields->tm_mon = 11; break;
        default:
            return ERROR(5);
    }

    fields->tm_year = parse_4digits(in + YEAR0);
    fields->tm_year -= 1900;
    if (fields->tm_year < 0 || fields->tm_year > 1000) {
        return ERROR(6);
    }

    if (in[SPACE3] != ' ') {
        return ERROR(7);
    }

    fields->tm_hour = parse_2digits(in + HOUR0);
    if (fields->tm_hour < 1 || fields->tm_hour > 24) {
        return ERROR(8);
    }

    if (in[COLON0] != ':') {
        return ERROR(9);
    }

    fields->tm_min = parse_2digits(in + MINUTE0);
    if (fields->tm_min < 0 || fields->tm_min > 59) {
        return ERROR(10);
    }

    if (in[COLON1] != ':') {
        return ERROR(11);
    }

    fields->tm_sec = parse_2digits(in + SECOND0);
    if (fields->tm_sec < 0 || fields->tm_sec > 59) {
        return ERROR(12);
    }

    if (in[SPACE4] != ' ') {
        return ERROR(13);
    }

    if (in[LETTER_G] != 'G' || in[LETTER_M] != 'M' || in[LETTER_T] != 'T') {
        return ERROR(14);
    }

    return 0;
}

#undef CONST
