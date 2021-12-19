#pragma once

#include <cstddef>
#include <cstdint>

struct UTF8seq {
    bool valid;
    uint8_t bytes[5];
};

constexpr size_t utf8_sequences_size = 262144;
extern UTF8seq utf8_sequences[utf8_sequences_size];
