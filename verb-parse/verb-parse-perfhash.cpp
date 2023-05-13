/* C++ code produced by gperf version 3.1 */
/* Command-line: gperf --language=C++ --enum --readonly-tables --compare-strncmp --class-name=perfect_hash_aux --lookup-function-name=string_to_verb --struct-type --output-file=verb-parse-perfhash.cpp http_verbs.gperf  */
/* Computed positions: -k'1,3-4' */

#if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35) \
      && ('%' == 37) && ('&' == 38) && ('\'' == 39) && ('(' == 40) \
      && (')' == 41) && ('*' == 42) && ('+' == 43) && (',' == 44) \
      && ('-' == 45) && ('.' == 46) && ('/' == 47) && ('0' == 48) \
      && ('1' == 49) && ('2' == 50) && ('3' == 51) && ('4' == 52) \
      && ('5' == 53) && ('6' == 54) && ('7' == 55) && ('8' == 56) \
      && ('9' == 57) && (':' == 58) && (';' == 59) && ('<' == 60) \
      && ('=' == 61) && ('>' == 62) && ('?' == 63) && ('A' == 65) \
      && ('B' == 66) && ('C' == 67) && ('D' == 68) && ('E' == 69) \
      && ('F' == 70) && ('G' == 71) && ('H' == 72) && ('I' == 73) \
      && ('J' == 74) && ('K' == 75) && ('L' == 76) && ('M' == 77) \
      && ('N' == 78) && ('O' == 79) && ('P' == 80) && ('Q' == 81) \
      && ('R' == 82) && ('S' == 83) && ('T' == 84) && ('U' == 85) \
      && ('V' == 86) && ('W' == 87) && ('X' == 88) && ('Y' == 89) \
      && ('Z' == 90) && ('[' == 91) && ('\\' == 92) && (']' == 93) \
      && ('^' == 94) && ('_' == 95) && ('a' == 97) && ('b' == 98) \
      && ('c' == 99) && ('d' == 100) && ('e' == 101) && ('f' == 102) \
      && ('g' == 103) && ('h' == 104) && ('i' == 105) && ('j' == 106) \
      && ('k' == 107) && ('l' == 108) && ('m' == 109) && ('n' == 110) \
      && ('o' == 111) && ('p' == 112) && ('q' == 113) && ('r' == 114) \
      && ('s' == 115) && ('t' == 116) && ('u' == 117) && ('v' == 118) \
      && ('w' == 119) && ('x' == 120) && ('y' == 121) && ('z' == 122) \
      && ('{' == 123) && ('|' == 124) && ('}' == 125) && ('~' == 126))
/* The character set is not based on ISO-646.  */
#error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gperf@gnu.org>."
#endif



#include "http_verb.h"

using ::boost::beast::http::verb;

struct httpverb {
    const char* name;
    verb v;
};
/* maximum key range = 67, duplicates = 0 */

class perfect_hash_aux
{
private:
  static inline unsigned int hash (const char *str, size_t len);
public:
  static const struct httpverb *string_to_verb (const char *str, size_t len);
};

inline unsigned int
perfect_hash_aux::hash (const char *str, size_t len)
{
  static const unsigned char asso_values[] =
    {
      70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 10,  5, 15,  0,  5,
      25,  0, 10, 70, 15, 70,  0,  0, 20,  0,
       5, 25, 20,  0,  0,  0, 40, 70, 70, 70,
      20, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 70, 70
    };
  unsigned int hval = len;

  switch (hval)
    {
      default:
        hval += asso_values[static_cast<unsigned char>(str[3]+1)];
      /*FALLTHROUGH*/
      case 3:
        hval += asso_values[static_cast<unsigned char>(str[2])];
      /*FALLTHROUGH*/
      case 2:
      case 1:
        hval += asso_values[static_cast<unsigned char>(str[0])];
        break;
    }
  return hval;
}

const struct httpverb *
perfect_hash_aux::string_to_verb (const char *str, size_t len)
{
  enum
    {
      TOTAL_KEYWORDS = 33,
      MIN_WORD_LENGTH = 3,
      MAX_WORD_LENGTH = 11,
      MIN_HASH_VALUE = 3,
      MAX_HASH_VALUE = 69
    };

  static const struct httpverb wordlist[] =
    {
      {""}, {""}, {""},

      {"GET", verb::get},
      {""}, {""}, {""}, {""},

      {"PUT", verb::put},

      {"POST", verb::post},

      {"PATCH", verb::patch},

      {"UNLOCK", verb::unlock},
      {""},

      {"ACL", verb::acl},

      {"SUBSCRIBE", verb::subscribe},

      {"TRACE", verb::trace},

      {"SEARCH", verb::search},
      {""}, {""},

      {"LOCK", verb::lock},

      {"MKACTIVITY", verb::mkactivity},

      {"UNLINK", verb::unlink},

      {"OPTIONS", verb::options},
      {""},

      {"LINK", verb::link},

      {"MKCOL", verb::mkcol},

      {"UNBIND", verb::unbind},
      {""},

      {"CHECKOUT", verb::checkout},

      {"HEAD", verb::head},

      {"MKCALENDAR", verb::mkcalendar},

      {"DELETE", verb::delete_},
      {""},

      {"M-SEARCH", verb::msearch},

      {"BIND", verb::bind},

      {"MERGE", verb::merge},

      {"REPORT", verb::report},
      {""},

      {"PROPFIND", verb::propfind},

      {"PROPPATCH", verb::proppatch},

      {"PURGE", verb::purge},

      {"NOTIFY", verb::notify},

      {"CONNECT", verb::connect},
      {""},

      {"COPY", verb::copy},
      {""},

      {"REBIND", verb::rebind},
      {""}, {""}, {""}, {""},

      {"UNSUBSCRIBE", verb::unsubscribe},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},

      {"MOVE", verb::move}
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      unsigned int key = hash (str, len);

      if (key <= MAX_HASH_VALUE)
        {
          const char *s = wordlist[key].name;

          if (*str == *s && !strncmp (str + 1, s + 1, len - 1) && s[len] == '\0')
            return &wordlist[key];
        }
    }
  return 0;
}


class perfect_hash
{
  using verb = boost::beast::http::verb;
private:
  static inline unsigned int hash(std::string_view str);
public:
  static verb string_to_verb(std::string_view str) {
    const httpverb* ret = perfect_hash_aux::string_to_verb(str.data(), str.size());
    if (ret != nullptr) {
        return ret->v;
    }

    return boost::beast::http::verb::unknown;
  }
};
