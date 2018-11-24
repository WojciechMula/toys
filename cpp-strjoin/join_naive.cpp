#include "join_naive.h"

std::string join_naive(const std::string& sep, const std::vector<std::string>& items) {

    const size_t n = items.size();

    if (n == 0) {
        return "";
    }

    std::string res = items[0];
    for (size_t i=1; i < n; i++) {
        res.append(sep);
        res.append(items[i]);
    }

    return res;
}
