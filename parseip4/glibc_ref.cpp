#include "glibc_ref.h"
#include <cstring>

#define NS_INADDRSZ 4

// This procedure comes from glibc; changed `new` into `new_`, to avoid
// use the C++ language keyword. Also changed the output, to be little-endian.
static int inet_pton4 (const char *src, const char *end, unsigned char *dst)
{
  int saw_digit, octets, ch;
  unsigned char tmp[NS_INADDRSZ], *tp;

  saw_digit = 0;
  octets = 0;

  *(tp = tmp) = 0;
  while (src < end)
    {
      ch = *src++;
      if (ch >= '0' && ch <= '9')
        {
          unsigned int new_ = *tp * 10 + (ch - '0');

          if (saw_digit && *tp == 0)
            return 0;
          if (new_ > 255)
            return 0;
          *tp = new_;
          if (! saw_digit)
            {
              if (++octets > 4)
                return 0;
              saw_digit = 1;
            }
        }
      else if (ch == '.' && saw_digit)
        {
          if (octets == 4)
            return 0;
          *++tp = 0;
          saw_digit = 0;
        }
      else
        return 0;
    }
  if (octets < 4)
    return 0;
  memcpy (dst, tmp, NS_INADDRSZ);
  return 1;
}

result glibc_parse_ipv4(const std::string& s) {
    result r;
    const auto res = inet_pton4(
        reinterpret_cast<const char*>(s.data()),
        reinterpret_cast<const char*>(s.data()) + s.size(),
        reinterpret_cast<unsigned char*>(&r.ipv4)
    );
    
    if (res == 0) {
        r.err = errInvalidInput;
    } else {
        r.err = 0;
    }

    return r;
}
