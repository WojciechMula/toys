#include "sse-dump.h"

#include <time.h>
#include <errno.h>
#include <immintrin.h>
#include <cstddef> // for offsetof

#define USE_PMOVMASKB
#ifdef USE_PMOVMASKB
#   define TEST_ALL_ZEROS(vector) (_mm_movemask_epi8(vector) == 0)
#   define TEST_ALL_ONES(vector)  (_mm_movemask_epi8(vector) == uint16_t(-1))
#else
#   define TEST_ALL_ZEROS(vector) (_mm_test_all_zeros(vector, vector))
#   define TEST_ALL_ONES(vector)  (_mm_test_all_ones(vector))
#endif

int parse_rfc_date(const char* in, tm* fields) {

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

    const __m128i valid = _mm_and_si128(lo_check, hi_check);
    if (!TEST_ALL_ONES(valid)) {
        return -EINVAL;
    }

    // 2. decode Weekday: "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
    const __m128i weekday_letters01 = _mm_setr_epi8('S', 'u', 'M', 'o', 'T', 'u', 'W', 'e', 'T', 'h', 'F', 'r', 'S', 'a', -1, -1);
    const __m128i weekday_letters22 = _mm_setr_epi8('n', 'n', 'n', 'n', 'e', 'e', 'd', 'd', 'u', 'u', 'i', 'i', 't', 't', -1, -1);

    const __m128i w01 = _mm_shuffle_epi8(lo, _mm_setr_epi8(0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, -1, -1));
    const __m128i w22 = _mm_shuffle_epi8(lo, _mm_set1_epi8(2));

    const __m128i weekday_bytemask =
        _mm_and_si128(_mm_cmpeq_epi16(w01, weekday_letters01), _mm_cmpeq_epi16(w22, weekday_letters22));

    const uint16_t weekday_mask = _mm_movemask_epi8(weekday_bytemask);
    if (weekday_mask == 0) {
        return -EINVAL;
    }

    fields->tm_wday = __builtin_ctz(weekday_mask)/2;

    // 3. decode month: "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
#define METHOD 2
#if METHOD == 1
    const __m128i month_letter0 = _mm_setr_epi8('J', 'F', 'M', 'A', 'M', 'J', 'J', 'A', 'S', 'O', 'N', 'D', 'D', 'D', 'D', 'D');
    const __m128i month_letter1 = _mm_setr_epi8('a', 'e', 'a', 'p', 'a', 'u', 'u', 'u', 'e', 'c', 'o', 'e', 'e', 'e', 'e', 'e');
    const __m128i month_letter2 = _mm_setr_epi8('n', 'b', 'r', 'r', 'y', 'n', 'l', 'g', 'p', 't', 'v', 'c', 'c', 'c', 'c', 'c');

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

    fields->tm_mon = __builtin_ctz(month_mask);
#elif METHOD == 2
    const __m128i month0 = _mm_setr_epi8('J', 'a', 'n', 0,
                                         'F', 'e', 'b', 0,
                                         'M', 'a', 'r', 0,
                                         'A', 'p', 'r', 0);
    const __m128i month1 = _mm_setr_epi8('M', 'a', 'y', 0,
                                         'J', 'u', 'n', 0,
                                         'J', 'u', 'l', 0,
                                         'A', 'u', 'g', 0);
    const __m128i month2 = _mm_setr_epi8('S', 'e', 'p', 0,
                                         'O', 'c', 't', 0,
                                         'N', 'o', 'v', 0,
                                         'D', 'e', 'c', 0);
    const __m128i month = _mm_shuffle_epi8(lo, _mm_setr_epi8(8, 9, 10, -1, 8, 9, 10, -1, 8, 9, 10, -1, 8, 9, 10, -1));

    const __m128i eq0 = _mm_cmpeq_epi32(month, month0);
    const __m128i eq1 = _mm_cmpeq_epi32(month, month1);
    const __m128i eq2 = _mm_cmpeq_epi32(month, month2);

    const __m128i p01 = _mm_packs_epi32(eq0, eq1);
    const __m128i p22 = _mm_packs_epi32(eq2, eq2);
    const __m128i p   = _mm_packs_epi16(p01, p22);

    const uint16_t month_mask = _mm_movemask_epi8(p);
    if (month_mask == 0) {
        return -EINVAL;
    }

    fields->tm_mon = __builtin_ctz(month_mask);
#else
#   error "Wrong METHOD"
#endif

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
    const __m128i less_ascii0    = _mm_cmplt_epi8(digits, _mm_set1_epi8(0)); // char < '0' <=> char - '0' < 0
    const __m128i greater_ascii9 = _mm_cmplt_epi8(_mm_set1_epi8(9), digits); // char > '9'
    const __m128i wrong_digits   = _mm_or_si128(less_ascii0, greater_ascii9);
    if (!TEST_ALL_ZEROS(wrong_digits)) {
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
    const __m128i numbers_lo_bound = _mm_setr_epi16(0, 0, 19,  0,  1,  1,  0,  0);
    const __m128i numbers_hi_bound = _mm_setr_epi16(0, 0, 29, 99, 31, 24, 59, 59);

    const __m128i outside_bounds = _mm_or_si128(
                                    _mm_cmplt_epi16(numbers, numbers_lo_bound),
                                    _mm_cmpgt_epi16(numbers, numbers_hi_bound));

    if (!TEST_ALL_ZEROS(outside_bounds)) {
        return -EINVAL;
    }

    constexpr bool known_layout = (offsetof(tm, tm_sec)  ==  0)
                               && (offsetof(tm, tm_min)  ==  4)
                               && (offsetof(tm, tm_hour) ==  8)
                               && (offsetof(tm, tm_mday) == 12);

    if (known_layout) {
        //   index =    0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15
        // numbers  = [00|00|00|00|C0|C1|Y0|Y1|D0|D1|H0|H1|M0|M1|S0|S1]
        // shuffled = [S0|S1|00|00|M0|M1|00|00|H0|H1|00|00|D0|D1|00|00]
        const __m128i shuffled = _mm_shuffle_epi8(numbers,
                                 _mm_setr_epi8(14, 15, -1, -1,
                                               12, 13, -1, -1,
                                               10, 11, -1, -1,
                                                8,  9, -1, -1));

        _mm_storeu_si128((__m128i*)(fields), shuffled);
    } else {
        // 2. copy numbers to struct
        fields->tm_mday = _mm_extract_epi16(numbers, 4);
        fields->tm_hour = _mm_extract_epi16(numbers, 5);
        fields->tm_min  = _mm_extract_epi16(numbers, 6);
        fields->tm_sec  = _mm_extract_epi16(numbers, 7);
    }


    int tmp = _mm_extract_epi16(numbers, 2) * 100 + _mm_extract_epi16(numbers, 3);
    tmp -= 1900;
    if (tmp < 0 || tmp > 1000) {
        return -EINVAL;
    }

    fields->tm_year = tmp;

    return 0;
}

