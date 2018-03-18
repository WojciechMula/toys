#include <vector>
#include <string>
#include <cstdint>

template <typename FUN>
uint64_t convchunk_aux(FUN f, const char* s) {
    uint64_t result = f(s + 0);
    result = 10000 * result + f(s + 4);
    result = 10000 * result + f(s + 8);
    result = 10000 * result + f(s + 12);

    return result;
}

#include "common.cpp"
#include "parse.naive.cpp"
#include "parse.swar.cpp"
#include "parse.sse.cpp"
#include "parse.ssse3.cpp"

using convfun = uint64_t (*)(const char* s);

struct Procedure {
    convfun fun;
    std::string name;

    Procedure(convfun fun_, const std::string& name_)
        : fun(fun_)
        , name(name_) {}
};


std::vector<Procedure> get_procedures() {
    std::vector<Procedure> p;

    p.emplace_back(naive, "naive");
    p.emplace_back(parse1, "SWAR (1)");
    p.emplace_back(parse2, "SWAR (2)");
    p.emplace_back(parse3, "SWAR (3)");
    p.emplace_back(parse_sse, "SSE");
    p.emplace_back(parse_ssse3, "SSSE3");

    return p;
}
