#include "bom.h"


BOM detect(std::string_view s) {
    if (s.substr(0, 4) == std::string_view("\x00\x00\xfe\xff", 4))
        return BOM::UTF32BE;

    if (s.substr(0, 4) == std::string_view("\xff\xfe\x00\x00", 4))
        return BOM::UTF32LE;

    if (s.substr(0, 3) == std::string_view("\xef\xbb\xbf", 3))
        return BOM::UTF8;

    if (s.substr(0, 2) == std::string_view("\xff\xfe", 2))
        return BOM::UTF16LE;

    if (s.substr(0, 2) == std::string_view("\xfe\xff", 2))
        return BOM::UTF16BE;

    return BOM::None;
}

size_t bom_size(BOM b) {
    switch (b) {
        case BOM::UTF32LE:
        case BOM::UTF32BE:
            return 4;

        case BOM::UTF16LE:
        case BOM::UTF16BE:
            return 2;

        case BOM::UTF8:
            return 1;

        default:
            return 0;
    }
}

const char* to_string(BOM b) {
    switch (b) {
        case BOM::UTF32LE: return "UTF-32LE";
        case BOM::UTF32BE: return "UTF-32BE";
        case BOM::UTF16LE: return "UTF-16LE";
        case BOM::UTF16BE: return "UTF-16BE";
        case BOM::UTF8: return "UTF-8";
        default: return "<None>";
    }
}
