#pragma once

#include <string_view>

enum class BOM {
    None,
    UTF32BE,
    UTF32LE,
    UTF8,
    UTF16BE,
    UTF16LE
};

BOM detect(std::string_view s);
size_t bom_size(BOM b);
const char* to_string(BOM b);
