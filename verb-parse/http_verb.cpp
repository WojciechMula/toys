#include "http_verb.h"

#include <array>

namespace {
    constexpr std::array<std::string_view, boost::beast::http::verb_count> verb2string = {
        "ACL",
        "BIND",
        "CHECKOUT",
        "CONNECT",
        "COPY",
        "DELETE",
        "GET",
        "HEAD",
        "LINK",
        "LOCK",
        "M-SEARCH",
        "MERGE",
        "MKACTIVITY",
        "MKCALENDAR",
        "MKCOL",
        "MOVE",
        "NOTIFY",
        "OPTIONS",
        "PATCH",
        "POST",
        "PROPFIND",
        "PROPPATCH",
        "PURGE",
        "PUT",
        "REBIND",
        "REPORT",
        "SEARCH",
        "SUBSCRIBE",
        "TRACE",
        "UNBIND",
        "UNLINK",
        "UNLOCK",
        "UNSUBSCRIBE"
    };
}

namespace boost::beast::http {

    const std::string_view as_string(verb v) {
        return verb2string.at(std::underlying_type<verb>::type(v));
    }

}
