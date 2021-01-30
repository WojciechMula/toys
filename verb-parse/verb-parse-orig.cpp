// Extracted from https://github.com/boostorg/beast/blob/855fc23885307aeb6ad1318001a4bbdd4345d47c/include/boost/beast/http/impl/verb.ipp

#include "http_verb.h"

namespace boost::beast::http {

    std::string_view
    operator"" _sv(char const* p, std::size_t n)
    {
        return std::string_view{p, n};
    }

    verb
    string_to_verb(std::string_view v)
    {
    /*
        ACL
        BIND
        CHECKOUT
        CONNECT
        COPY
        DELETE
        GET
        HEAD
        LINK
        LOCK
        M-SEARCH
        MERGE
        MKACTIVITY
        MKCALENDAR
        MKCOL
        MOVE
        NOTIFY
        OPTIONS
        PATCH
        POST
        PROPFIND
        PROPPATCH
        PURGE
        PUT
        REBIND
        REPORT
        SEARCH
        SUBSCRIBE
        TRACE
        UNBIND
        UNLINK
        UNLOCK
        UNSUBSCRIBE
    */
        if(v.size() < 3)
            return verb::unknown;
        auto c = v[0];
        v.remove_prefix(1);
        switch(c)
        {
        case 'A':
            if(v == "CL"_sv)
                return verb::acl;
            break;

        case 'B':
            if(v == "IND"_sv)
                return verb::bind;
            break;

        case 'C':
            c = v[0];
            v.remove_prefix(1);
            switch(c)
            {
            case 'H':
                if(v == "ECKOUT"_sv)
                    return verb::checkout;
                break;

            case 'O':
                if(v == "NNECT"_sv)
                    return verb::connect;
                if(v == "PY"_sv)
                    return verb::copy;
                ;

            default:
                break;
            }
            break;

        case 'D':
            if(v == "ELETE"_sv)
                return verb::delete_;
            break;

        case 'G':
            if(v == "ET"_sv)
                return verb::get;
            break;

        case 'H':
            if(v == "EAD"_sv)
                return verb::head;
            break;

        case 'L':
            if(v == "INK"_sv)
                return verb::link;
            if(v == "OCK"_sv)
                return verb::lock;
            break;

        case 'M':
            c = v[0];
            v.remove_prefix(1);
            switch(c)
            {
            case '-':
                if(v == "SEARCH"_sv)
                    return verb::msearch;
                break;

            case 'E':
                if(v == "RGE"_sv)
                    return verb::merge;
                break;

            case 'K':
                if(v == "ACTIVITY"_sv)
                    return verb::mkactivity;
                if(v[0] == 'C')
                {
                    v.remove_prefix(1);
                    if(v == "ALENDAR"_sv)
                        return verb::mkcalendar;
                    if(v == "OL"_sv)
                        return verb::mkcol;
                    break;
                }
                break;

            case 'O':
                if(v == "VE"_sv)
                    return verb::move;
                ;

            default:
                break;
            }
            break;

        case 'N':
            if(v == "OTIFY"_sv)
                return verb::notify;
            break;

        case 'O':
            if(v == "PTIONS"_sv)
                return verb::options;
            break;

        case 'P':
            c = v[0];
            v.remove_prefix(1);
            switch(c)
            {
            case 'A':
                if(v == "TCH"_sv)
                    return verb::patch;
                break;

            case 'O':
                if(v == "ST"_sv)
                    return verb::post;
                break;

            case 'R':
                if(v == "OPFIND"_sv)
                    return verb::propfind;
                if(v == "OPPATCH"_sv)
                    return verb::proppatch;
                break;

            case 'U':
                if(v == "RGE"_sv)
                    return verb::purge;
                if(v == "T"_sv)
                    return verb::put;
                ;

            default:
                break;
            }
            break;

        case 'R':
            if(v[0] != 'E')
                break;
            v.remove_prefix(1);
            if(v == "BIND"_sv)
                return verb::rebind;
            if(v == "PORT"_sv)
                return verb::report;
            break;

        case 'S':
            if(v == "EARCH"_sv)
                return verb::search;
            if(v == "UBSCRIBE"_sv)
                return verb::subscribe;
            break;

        case 'T':
            if(v == "RACE"_sv)
                return verb::trace;
            break;

        case 'U':
            if(v[0] != 'N')
                break;
            v.remove_prefix(1);
            if(v == "BIND"_sv)
                return verb::unbind;
            if(v == "LINK"_sv)
                return verb::unlink;
            if(v == "LOCK"_sv)
                return verb::unlock;
            if(v == "SUBSCRIBE"_sv)
                return verb::unsubscribe;
            break;

        default:
            break;
        }

        return verb::unknown;
    }
}
