#include "sse-dump.h"

#include <time.h>
#include <errno.h>
#include <immintrin.h>

// Fri, 17 Apr 2015 16:14:11 GMT
int parse_rfc_date(const char* in) {
    
    // lo = "Fri, 17 Apr 2015"
    //       0123456789abcdef
    __m128i lo = _mm_loadu_si128((const __m128i*)(in));

    // hi = "015 16:14:11 GMT"
    //       0123456789abcdef
    __m128i hi = _mm_loadu_si128((const __m128i*)(in + 13));

    // 1. validate constant characters
    // lo       = "Fri, 17 Apr 2015"
    // lo_valid = "???, ?? ??? ????"
    const __m128i lo_valid      = _mm_setr_epi8(0, 0, 0, ',', ' ', 0, 0, ' ', 0, 0, 0, ' ', 0, 0, 0, 0);
    const __m128i lo_valid_mask = _mm_setr_epi8(0, 0, 0,  -1,  -1, 0, 0,  -1, 0, 0, 0,  -1, 0, 0, 0, 0);
    // hi       = "015 16:14:11 GMT"
    // hi_valid = "??? ??:??:?? GMT"
    const __m128i hi_valid      = _mm_setr_epi8(0, 0, 0, ' ', 0, 0, ':', 0, 0, ':', 0, 0, ' ', 'G', 'M', 'T');
    const __m128i hi_valid_mask = _mm_setr_epi8(0, 0, 0,  -1, 0, 0,  -1, 0, 0,  -1, 0, 0,  -1,  -1,  -1,  -1);

    __m128i lo_check;
    lo_check = _mm_cmpeq_epi8(lo, lo_valid);
    lo_check = _mm_and_si128 (lo_check, lo_valid_mask);
    lo_check = _mm_cmpeq_epi8(lo_check, lo_valid_mask);

    __m128i hi_check;
    hi_check = _mm_cmpeq_epi8(hi, hi_valid);
    hi_check = _mm_and_si128 (hi_check, hi_valid_mask);
    hi_check = _mm_cmpeq_epi8(hi_check, hi_valid_mask);

    const __m128i valid = _mm_or_si128(lo_check, hi_check);
    if (_mm_movemask_epi8(valid) != (uint16_t)(-1)) {
        return -EINVAL;
    }

    // 2. decode Weekday: "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
    const __m128i weekday_letter0 = _mm_setr_epi8('S', 'M', 'T', 'W', 'T', 'F', 'S', 0, 0, 0, 0, 0, 0, 0, 0, 0);
    const __m128i weekday_letter1 = _mm_setr_epi8('u', 'o', 'u', 'e', 'h', 'r', 'a', 0, 0, 0, 0, 0, 0, 0, 0, 0);
    const __m128i weekday_letter2 = _mm_setr_epi8('n', 'n', 'e', 'd', 'u', 'i', 't', 0, 0, 0, 0, 0, 0, 0, 0, 0);

    const __m128i w0 = _mm_shuffle_epi8(lo, _mm_set1_epi8(0));
    const __m128i w1 = _mm_shuffle_epi8(lo, _mm_set1_epi8(1));
    const __m128i w2 = _mm_shuffle_epi8(lo, _mm_set1_epi8(2));

    const __m128i weekday_bytemask =
        _mm_and_si128(_mm_cmpeq_epi8(w0, weekday_letter0),
        _mm_and_si128(_mm_cmpeq_epi8(w1, weekday_letter1), _mm_cmpeq_epi8(w2, weekday_letter2)));
    
    const uint16_t weekday_mask = _mm_movemask_epi8(weekday_bytemask);
    if (weekday_mask == 0) {
        return -EINVAL;
    }

    struct tm fields;
    fields.tm_wday = __builtin_ctz(weekday_mask);

    // 3. decode month: "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    const __m128i month_letter0 = _mm_setr_epi8('J', 'F', 'M', 'A', 'M', 'J', 'J', 'A', 'S', 'O', 'N', 'D', 0, 0, 0, 0);
    const __m128i month_letter1 = _mm_setr_epi8('a', 'e', 'a', 'p', 'a', 'u', 'u', 'u', 'e', 'c', 'o', 'e', 0, 0, 0, 0);
    const __m128i month_letter2 = _mm_setr_epi8('n', 'b', 'r', 'r', 'y', 'n', 'l', 'g', 'p', 't', 'v', 'c', 0, 0, 0, 0);

    const __m128i m0 = _mm_shuffle_epi8(lo, _mm_set1_epi8(8));
    const __m128i m1 = _mm_shuffle_epi8(lo, _mm_set1_epi8(9));
    const __m128i m2 = _mm_shuffle_epi8(lo, _mm_set1_epi8(10));

    const __m128i month_bytemask =
        _mm_and_si128(_mm_cmpeq_epi8(m0, month_letter0),
        _mm_and_si128(_mm_cmpeq_epi8(m1, month_letter1), _mm_cmpeq_epi8(m2, month_letter2)));
    
    const uint16_t month_mask = _mm_movemask_epi8(month_bytemask);
    if (month_mask == 0) {
        return -EINVAL;
    }
    fields.tm_mon = __builtin_ctz(month_mask);

    // 4. convert [almost] all numeric values at once
    //
    // group all digits in one register
    // lo        = "Fri, 17 Apr 2015"
    // lo_digits = "2222201517......"
    //              ^^^^
    //              not used in conversion, but make digit validation easier
    const __m128i lo_digits = _mm_shuffle_epi8(lo,
                              _mm_setr_epi8(12, 12, 12, 12, 12, 13, 14, 15,  5,  6, -1, -1, -1, -1, -1, -1));
    // hi        = "015 16:14:11 GMT"
    // hi_digits = "..........161411"
    const __m128i hi_digits = _mm_shuffle_epi8(hi,
                              _mm_setr_epi8(-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  4,  5,  7,  8, 10, 11));

    // digits    = "2222201517161411"
    const __m128i ASCII_digits = _mm_or_si128(lo_digits, hi_digits);

    // validate digits
    const __m128i digits = _mm_sub_epi8(ASCII_digits, _mm_set1_epi8('0'));
    const __m128i less_ascii0    = _mm_cmplt_epi8(digits, _mm_set1_epi8(0));   // char < '0' <=> char - '0' < 0
    const __m128i greater_ascii9 = _mm_cmplt_epi8(_mm_set1_epi8('9'), digits); // char > '9'
    const __m128i wrong_digits   = _mm_or_si128(less_ascii0, greater_ascii9);
    if (_mm_movemask_epi8(wrong_digits) != 0) {
        return -EINVAL;
    }

    // convert numbers, the vector contains following 2-digit numbers:
    // [0, 0, century, year, day, hour, min, sec]
    const __m128i numbers = _mm_maddubs_epi16(digits,
                            _mm_set_epi8(1, 10, 1, 10, 1, 10, 1, 10, 1, 10, 1, 10, 0, 0, 0, 0));

    // 5. validate numeric ranges
    // century: 19 .. 20
    // year   :  0 .. 99 -- always valid if letters were digits
    // day    :  1 .. 31
    // hour   :  1 .. 24
    // min    :  1 .. 59
    // sec    :  1 .. 59
    const __m128i numbers_lo_bound = _mm_setr_epi16(0, 0, 19,  0,  1,  1,  1,  1);
    const __m128i numbers_hi_bound = _mm_setr_epi16(0, 0, 20, 99, 31, 24, 59, 29);

    const __m128i outside_bounds = _mm_or_si128(
                                    _mm_cmplt_epi16(numbers, numbers_lo_bound),
                                    _mm_cmpgt_epi16(numbers, numbers_hi_bound));

    if (_mm_movemask_epi8(outside_bounds) != 0) {
        return -EINVAL;
    }

    // 2. copy numbers to strucut
    fields.tm_mday = _mm_extract_epi16(numbers, 4);
    fields.tm_hour = _mm_extract_epi16(numbers, 5);
    fields.tm_min  = _mm_extract_epi16(numbers, 6);
    fields.tm_sec  = _mm_extract_epi16(numbers, 7);

    fields.tm_year = (_mm_extract_epi16(numbers, 2) - 19) * 100 + _mm_extract_epi16(numbers, 3);

    mktime(&fields);
    printf("%s\n", asctime(&fields));

    return 0;
}

int main() {
    const char* input = "Fri, 17 Apr 2015 16:14:11 GMT";
    puts(input);
    parse_rfc_date(input);
}
