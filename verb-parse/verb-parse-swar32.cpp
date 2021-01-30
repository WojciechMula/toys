#include "http_verb.h"

#include <cstring>

namespace swar32 {

    using ::boost::beast::http::verb;

    std::string_view
    operator"" _sv(char const* p, std::size_t n)
    {
        return std::string_view{p, n};
    }

    #define STRING_CONST(s0, s1, s2, s3) \
       ((uint64_t(uint8_t((s0))) << 0*8) | \
        (uint64_t(uint8_t((s1))) << 1*8) | \
        (uint64_t(uint8_t((s2))) << 2*8) | \
        (uint64_t(uint8_t((s3))) << 3*8))

    verb
    string_to_verb(std::string_view v)
    {
        if (v.size() < 3 or v.size() > 13)
            return verb::unknown;

        union {
            char buf[13];
            uint32_t word[2];
            uint32_t value;
        };

        value = 0;
        memcpy(buf, v.data(), v.size());

        switch (value) {
            case STRING_CONST('A', 'C', 'L', 0):
                return verb::acl;
            case STRING_CONST('B', 'I', 'N', 'D'):
                return verb::bind;
            case STRING_CONST('C', 'H', 'E', 'C'):
                if (word[1] == STRING_CONST('K', 'O', 'U', 'T'))
                    return verb::checkout;
                break;
            case STRING_CONST('C', 'O', 'N', 'N'):
                if (word[1] == STRING_CONST('E', 'C', 'T', 0))
                    return verb::connect;
                break;
            case STRING_CONST('C', 'O', 'P', 'Y'):
                return verb::copy;
            case STRING_CONST('D', 'E', 'L', 'E'):
                if (word[1] == STRING_CONST('T', 'E', 0, 0))
                    return verb::delete_;
                break;
            case STRING_CONST('G', 'E', 'T', 0):
                return verb::get;
            case STRING_CONST('H', 'E', 'A', 'D'):
                return verb::head;
            case STRING_CONST('L', 'I', 'N', 'K'):
                return verb::link;
            case STRING_CONST('L', 'O', 'C', 'K'):
                return verb::lock;
            case STRING_CONST('M', '-', 'S', 'E'):
                if (word[1] == STRING_CONST('A', 'R', 'C', 'H'))
                    return verb::msearch;
                break;
            case STRING_CONST('M', 'E', 'R', 'G'):
                if (word[1] == STRING_CONST('E', 0, 0, 0))
                    return verb::merge;
                break;
            case STRING_CONST('M', 'K', 'A', 'C'):
                if (v.substr(4) == /*MKAC*/"TIVITY"_sv)
                    return verb::mkactivity;
                break;
            case STRING_CONST('M', 'K', 'C', 'A'):
                if (v.substr(4) == /*MKCA*/"LENDAR"_sv)
                    return verb::mkcalendar;
                break;
            case STRING_CONST('M', 'K', 'C', 'O'):
                if (word[1] == STRING_CONST('L', 0, 0, 0))
                    return verb::mkcol;
                break;
            case STRING_CONST('M', 'O', 'V', 'E'):
                return verb::move;
            case STRING_CONST('N', 'O', 'T', 'I'):
                if (word[1] == STRING_CONST('F', 'Y', 0, 0))
                    return verb::notify;
                break;
            case STRING_CONST('O', 'P', 'T', 'I'):
                if (word[1] == STRING_CONST('O', 'N', 'S', 0))
                    return verb::options;
                break;
            case STRING_CONST('P', 'A', 'T', 'C'):
                if (v[4] == 'H')
                    return verb::patch;
                break;
            case STRING_CONST('P', 'O', 'S', 'T'):
                return verb::post;
            case STRING_CONST('P', 'R', 'O', 'P'):
                if (v.substr(4) == /*PROP*/"FIND"_sv)
                    return verb::propfind;
                else if (v.substr(4) == /*PROP*/"PATCH"_sv)
                    return verb::proppatch;
                break;
            case STRING_CONST('P', 'U', 'R', 'G'):
                if (v[4] == 'E')
                    return verb::purge;
                break;
            case STRING_CONST('P', 'U', 'T', 0):
                return verb::put;
            case STRING_CONST('R', 'E', 'B', 'I'):
                if (word[1] == STRING_CONST('N', 'D', 0, 0))
                    return verb::rebind;
                break;
            case STRING_CONST('R', 'E', 'P', 'O'):
                if (word[1] == STRING_CONST('R', 'T', 0, 0))
                    return verb::report;
                break;
            case STRING_CONST('S', 'E', 'A', 'R'):
                if (word[1] == STRING_CONST('C', 'H', 0, 0))
                    return verb::search;
                break;
            case STRING_CONST('S', 'U', 'B', 'S'):
                if (v.substr(4) == /*SUBS*/"CRIBE"_sv)
                    return verb::subscribe;
                break;
            case STRING_CONST('T', 'R', 'A', 'C'):
                if (v[4] == 'E')
                    return verb::trace;
                break;
            case STRING_CONST('U', 'N', 'B', 'I'):
                if (word[1] == STRING_CONST('N', 'D', 0, 0))
                    return verb::unbind;
                break;
            case STRING_CONST('U', 'N', 'L', 'I'):
                if (word[1] == STRING_CONST('N', 'K', 0, 0))
                    return verb::unlink;
                break;
            case STRING_CONST('U', 'N', 'L', 'O'):
                if (word[1] == STRING_CONST('C', 'K', 0, 0))
                    return verb::unlock;
                break;
            case STRING_CONST('U', 'N', 'S', 'U'):
                if (v.substr(4) == /*UNSU*/"BSCRIBE"_sv)
                    return verb::unsubscribe;
                break;
        }

        return verb::unknown;
    }

    #undef STRING_CONST
}
