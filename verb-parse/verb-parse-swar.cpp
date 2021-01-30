#include "http_verb.h"

#include <cstring>

namespace swar {

    using ::boost::beast::http::verb;

    std::string_view
    operator"" _sv(char const* p, std::size_t n)
    {
        return std::string_view{p, n};
    }

    #define STRING_CONST(s0, s1, s2, s3, s4, s5, s6, s7) \
       ((uint64_t(uint8_t((s0))) << 0*8) | \
        (uint64_t(uint8_t((s1))) << 1*8) | \
        (uint64_t(uint8_t((s2))) << 2*8) | \
        (uint64_t(uint8_t((s3))) << 3*8) | \
        (uint64_t(uint8_t((s4))) << 4*8) | \
        (uint64_t(uint8_t((s5))) << 5*8) | \
        (uint64_t(uint8_t((s6))) << 6*8) | \
        (uint64_t(uint8_t((s7))) << 7*8))

    verb
    string_to_verb(std::string_view v)
    {
        if (v.size() < 3 or v.size() > 13)
            return verb::unknown;

        union {
            char buf[13];
            uint64_t value;
        };

        value = 0;
        memcpy(buf, v.data(), v.size());

        switch (value) {
            case STRING_CONST('A', 'C', 'L', 0, 0, 0, 0, 0):
                return verb::acl;
            case STRING_CONST('B', 'I', 'N', 'D', 0, 0, 0, 0):
                return verb::bind;
            case STRING_CONST('C', 'H', 'E', 'C', 'K', 'O', 'U', 'T'):
                return verb::checkout;
            case STRING_CONST('C', 'O', 'N', 'N', 'E', 'C', 'T', 0):
                return verb::connect;
            case STRING_CONST('C', 'O', 'P', 'Y', 0, 0, 0, 0):
                return verb::copy;
            case STRING_CONST('D', 'E', 'L', 'E', 'T', 'E', 0, 0):
                return verb::delete_;
            case STRING_CONST('G', 'E', 'T', 0, 0, 0, 0, 0):
                return verb::get;
            case STRING_CONST('H', 'E', 'A', 'D', 0, 0, 0, 0):
                return verb::head;
            case STRING_CONST('L', 'I', 'N', 'K', 0, 0, 0, 0):
                return verb::link;
            case STRING_CONST('L', 'O', 'C', 'K', 0, 0, 0, 0):
                return verb::lock;
            case STRING_CONST('M', '-', 'S', 'E', 'A', 'R', 'C', 'H'):
                return verb::msearch;
            case STRING_CONST('M', 'E', 'R', 'G', 'E', 0, 0, 0):
                return verb::merge;
            case STRING_CONST('M', 'K', 'A', 'C', 'T', 'I', 'V', 'I'):
                if (v.size() == 10 and v.substr(8) == "TY"_sv)
                    return verb::mkactivity;
                break;
            case STRING_CONST('M', 'K', 'C', 'A', 'L', 'E', 'N', 'D'):
                if (v.size() == 10 and v.substr(8) == "AR"_sv)
                    return verb::mkactivity;
                break;
            case STRING_CONST('M', 'K', 'C', 'O', 'L', 0, 0, 0):
                return verb::mkcol;
            case STRING_CONST('M', 'O', 'V', 'E', 0, 0, 0, 0):
                return verb::move;
            case STRING_CONST('N', 'O', 'T', 'I', 'F', 'Y', 0, 0):
                return verb::notify;
            case STRING_CONST('O', 'P', 'T', 'I', 'O', 'N', 'S', 0):
                return verb::options;
            case STRING_CONST('P', 'A', 'T', 'C', 'H', 0, 0, 0):
                return verb::patch;
            case STRING_CONST('P', 'O', 'S', 'T', 0, 0, 0, 0):
                return verb::post;
            case STRING_CONST('P', 'R', 'O', 'P', 'F', 'I', 'N', 'D'):
                return verb::propfind;
            case STRING_CONST('P', 'R', 'O', 'P', 'P', 'A', 'T', 'C'):
                if (v.size() == 9 and v[9] == 'H')
                    return verb::proppatch;
                break;
            case STRING_CONST('P', 'U', 'R', 'G', 'E', 0, 0, 0):
                return verb::purge;
            case STRING_CONST('P', 'U', 'T', 0, 0, 0, 0, 0):
                return verb::put;
            case STRING_CONST('R', 'E', 'B', 'I', 'N', 'D', 0, 0):
                return verb::rebind;
            case STRING_CONST('R', 'E', 'P', 'O', 'R', 'T', 0, 0):
                return verb::report;
            case STRING_CONST('S', 'E', 'A', 'R', 'C', 'H', 0, 0):
                return verb::search;
            case STRING_CONST('S', 'U', 'B', 'S', 'C', 'R', 'I', 'B'):
                if (v.size() == 9 and v[9] == 'E')
                    return verb::subscribe;
                break;
            case STRING_CONST('T', 'R', 'A', 'C', 'E', 0, 0, 0):
                return verb::trace;
            case STRING_CONST('U', 'N', 'B', 'I', 'N', 'D', 0, 0):
                return verb::unbind;
            case STRING_CONST('U', 'N', 'L', 'I', 'N', 'K', 0, 0):
                return verb::unlink;
            case STRING_CONST('U', 'N', 'L', 'O', 'C', 'K', 0, 0):
                return verb::unlock;
            case STRING_CONST('U', 'N', 'S', 'U', 'B', 'S', 'C', 'R'):
                if (v.size() == 11 and v.substr(9) == "IBE"_sv)
                    return verb::unsubscribe;
                break;
        }

        return verb::unknown;
    }

    #undef STRING_CONST
}
