
#include <x86intrin.h>
#include <errno.h>
#include <stdio.h>
#include <time.h>

int parse_rfc_date(const char *in, struct tm *fields) {

  // magic=7596 1DAC
  // 4-byte day names, eg "Sun,"
  const uint32_t days[8] = {0x2C756854, 0x2C657554, 0x2C6E7553, 0x2C6E6F4D, 0x0, 0x2C697246, 0x2C646557, 0x2C746153 };
  // day numbers by hash value
  const uint16_t days_inv[8] = {4, 2, 0, 1, 0, 5, 3, 6 };

  // 4-byte vals for verification against original
  const uint32_t months[16] = { 0x20766F4E, // Nov 
      0x20706553, // Sep 
      0x206E614A, // Jan 
      0x2074634F, // Oct 
      0x2072614D, // Mar 
      0x0, // 
      0x2079614D, // May 
      0x0, // 
      0x20677541, // Aug 
      0x0, // 
      0x206C754A, // Jul 
      0x206E754A, // Jun 
      0x20626546, // Feb 
      0x20636544, // Dec
      0x20727041, // Apr 
      0x0, // 
      };

  // month numbers by hash value
  const uint16_t months_inv[16] = { 10, 8, 0, 9, 2, 0, 4, 0, 7, 0, 6, 5, 1, 11, 3, 0, };

  // "Fri, 17 Apr 2015 16:14:11 GMT"
  __m128i lo = _mm_loadu_si128((const __m128i*)(in));
  __m128i hi = _mm_loadu_si128((const __m128i*)(in + 13));

  const __m128i lo_digits = _mm_shuffle_epi8(lo,
					     _mm_setr_epi8(9,10, -1,-1,12,13, -1,-1,0,1, -1,-1,14,15, 5,6)); 

  const __m128i hi_digits = _mm_shuffle_epi8(hi,
					     _mm_setr_epi8(-1,-1,10,11,-1,-1, 7,8,-1,-1,  4,5,-1,-1, -1,-1));

  // "pr112014Fr161517" interleaved for thunking
  const __m128i ASCII_digits = _mm_or_si128(lo_digits, hi_digits);

  const __m128i digits = _mm_sub_epi8(ASCII_digits, 
				      _mm_setr_epi8(0,0,'0','0','0','0','0','0',0,0,'0','0','0','0','0','0'));

  const __m128i converters = _mm_setr_epi8( 0xA2, 0x59, 10, 1, 10, 1, 10, 1, 0xAC, 0x1D, 10, 1, 10, 1, 10, 1);
  
  const __m128i numbers = _mm_maddubs_epi16(digits, converters);

  // sec, min, hour, mday,  32-bit aligned
  _mm_storeu_si128( (__m128i*) &fields->tm_sec, _mm_srli_epi32(numbers, 16));

  // mon, century, wday, year
  __m128i others = _mm_and_si128(numbers, _mm_setr_epi16(0x0F00, 0, 0xFFFF, 0, 0x0700, 0, 0xFFFF, 0));

  char ctmp[16];
  _mm_storeu_si128((__m128i*)ctmp, others);
  const uint32_t *atmp = (uint32_t *) ctmp;
  int year = 100 * atmp[1] + atmp[3] - 1900;

  fields->tm_mon = months_inv[ctmp[1]];
  fields->tm_wday = days_inv[ctmp[9]];
  fields->tm_year = year;

  //  if (atmp[1] < 19 || atmp[1] > 29)
  //   return -EINVAL;
  
  return 0;
}
