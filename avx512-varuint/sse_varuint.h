#pragma once

#include <string>
#include <cstdint>
#include <cstddef>

class PackedVarUintBuilder {
public:
    void add(uint32_t);
    std::string capture();

private:
    std::string buffer;
    int         count{0};
    uint32_t    incoming[4];

    void flush();
};

// unsafe_unpack unpacks `count` int32 into `output` buffer.
// It does not validate the input `buf`.
void unsafe_unpack(const std::string& buf, size_t count, uint32_t* output);

// sse_unsafe_unpack unpacks `count` int32 into `output` buffer.
// It does not validate the input `buf`.
void sse_unsafe_unpack(const std::string& buf, size_t count, uint32_t* output);
