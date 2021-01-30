/* C++ code produced by gperf version 3.1 */
/* Command-line: gperf --language=C++ --enum --readonly-tables --class-name=perfect_hash --lookup-function-name=string_to_verb --output-file=verb-parse-perfhash.in.cpp http_verbs.txt  */
/* Computed positions: -k'1,3-4' */

#include "http_verb.h"

class perfect_hash
{
  using verb = boost::beast::http::verb;
private:
  static inline unsigned int hash(std::string_view str);
public:
  static verb string_to_verb(std::string_view str);
};

inline unsigned int
perfect_hash::hash(std::string_view str)
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
  auto hval = str.size();

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


perfect_hash::verb
perfect_hash::string_to_verb(std::string_view str)
{
  enum
    {
      TOTAL_KEYWORDS = 33,
      MIN_WORD_LENGTH = 3,
      MAX_WORD_LENGTH = 11,
      MIN_HASH_VALUE = 3,
      MAX_HASH_VALUE = 69
    };

  static std::string_view wordlist[] =
    {
      "", "", "",
      "GET",
      "", "", "", "",
      "PUT",
      "POST",
      "PATCH",
      "UNLOCK",
      "",
      "ACL",
      "SUBSCRIBE",
      "TRACE",
      "SEARCH",
      "", "",
      "LOCK",
      "MKACTIVITY",
      "UNLINK",
      "OPTIONS",
      "",
      "LINK",
      "MKCOL",
      "UNBIND",
      "",
      "CHECKOUT",
      "HEAD",
      "MKCALENDAR",
      "DELETE",
      "",
      "M-SEARCH",
      "BIND",
      "MERGE",
      "REPORT",
      "",
      "PROPFIND",
      "PROPPATCH",
      "PURGE",
      "NOTIFY",
      "CONNECT",
      "",
      "COPY",
      "",
      "REBIND",
      "", "", "", "",
      "UNSUBSCRIBE",
      "", "", "", "", "", "", "", "", "",
      "", "", "", "", "", "", "", "",
      "MOVE"
    };

  static verb values[] =
    {
      verb::unknown,
      verb::unknown,
      verb::unknown,
      verb::get,
      verb::unknown,
      verb::unknown,
      verb::unknown,
      verb::unknown,
      verb::put,
      verb::post,
      verb::patch,
      verb::unlock,
      verb::unknown,
      verb::acl,
      verb::subscribe,
      verb::trace,
      verb::search,
      verb::unknown,
      verb::unknown,
      verb::lock,
      verb::mkactivity,
      verb::unlink,
      verb::options,
      verb::unknown,
      verb::link,
      verb::mkcol,
      verb::unbind,
      verb::unknown,
      verb::checkout,
      verb::head,
      verb::mkcalendar,
      verb::delete_,
      verb::unknown,
      verb::msearch,
      verb::bind,
      verb::merge,
      verb::report,
      verb::unknown,
      verb::propfind,
      verb::proppatch,
      verb::purge,
      verb::notify,
      verb::connect,
      verb::unknown,
      verb::copy,
      verb::unknown,
      verb::rebind,
      verb::unknown,
      verb::unknown,
      verb::unknown,
      verb::unknown,
      verb::unsubscribe,
      verb::unknown,
      verb::unknown,
      verb::unknown,
      verb::unknown,
      verb::unknown,
      verb::unknown,
      verb::unknown,
      verb::unknown,
      verb::unknown,
      verb::unknown,
      verb::unknown,
      verb::unknown,
      verb::unknown,
      verb::unknown,
      verb::unknown,
      verb::unknown,
      verb::unknown,
      verb::move
    };

  if (str.size() <= MAX_WORD_LENGTH && str.size() >= MIN_WORD_LENGTH)
    {
      const unsigned int key = hash(str);

      if (key <= MAX_HASH_VALUE) {
          if (wordlist[key] == str)
            return values[key];
      }
    }
  return verb::unknown;
}
