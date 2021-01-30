// Extracted from https://github.com/boostorg/beast/blob/855fc23885307aeb6ad1318001a4bbdd4345d47c/include/boost/beast/http/impl/verb.ipp

#pragma once

#include <string_view>

namespace boost::beast::http {

    enum class verb {
        delete_,
        get,
        head,
        post,
        put,
        connect,
        options,
        trace,
        copy,
        lock,
        mkcol,
        move,
        propfind,
        proppatch,
        search,
        unlock,
        bind,
        rebind,
        unbind,
        acl,
        report,
        mkactivity,
        checkout,
        merge,
        msearch,
        notify,
        subscribe,
        unsubscribe,
        patch,
        purge,
        mkcalendar,
        link,
        unlink,
        unknown
    };

    constexpr unsigned int verb_count = 33;

    const std::string_view as_string(verb v);
}
