#pragma once

#include <cstddef>

enum class Error {
    no_error,
    wrong_first_byte,
    not_continuation_1,
    not_continuation_2,
    not_continuation_3,
    unexpected_continuation,
    overlong,
    surrogate,
    too_large,
};

Error scalar_validate_utf8(const char* bytes, size_t size);

bool scalar_validate_utf8_simple(const char* bytes, size_t size);
