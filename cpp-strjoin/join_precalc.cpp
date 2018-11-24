#include "join_precalc.h"

std::string join_precalc(const std::string& sep, const std::vector<std::string>& items) {

    const size_t n = items.size();

    if (n == 0) {
        return "";
    }

    size_t len = (n - 1) * sep.size();

    for (size_t i=1; i < n; i++) {
        len += items[i].size();
    }

    std::string res;
    res.reserve(len);

    res.append(items[0]);
    for (size_t i=1; i < n; i++) {
        res.append(sep);
        res.append(items[i]);
    }

    return res;
}
