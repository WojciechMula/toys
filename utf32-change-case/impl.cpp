#include <map>
#include <string>
#include <immintrin.h>

#include "scalar.cpp"
#include "avx2.cpp"
#include "cpp_lookup.cpp.inl"

using signature_t = size_t(*)(const uint32_t*, size_t, uint32_t*);
using function_names_t = std::map<signature_t, std::string>;

function_names_t function_names() {
    function_names_t names;

    names[utf32_uppercase_plain] = "scalar uppercase [plain]";
    names[utf32_uppercase_compressed] = "scalar uppercase [compressed]";
    names[utf32_lowercase_plain] = "scalar lowercase [plain]";
    names[utf32_lowercase_compressed] = "scalar lowercase [compressed]";

    names[avx2_utf32_uppercase_plain] = "AVX2 uppercase [plain]";
    names[avx2_utf32_uppercase_compressed] = "AVX2 uppercase [compressed]";

    names[cpp_utf32_uppercase] = "c++ uppercase";
    names[cpp_utf32_lowercase] = "c++ lowercase";

    return names;
}

size_t longest_function_label(const function_names_t& names) {
    size_t max = 0;
    for (const auto& item: names) {
        const size_t len = item.second.size();
        if (len > max) {
            max = len;
        }
    }

    return max;
}
