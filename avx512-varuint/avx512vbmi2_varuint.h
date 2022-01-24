#pragma once

#include <string>
#include <cstdint>
#include <cstddef>

class Packed16VarUintBuilder {
public:
    void add(uint32_t);
    std::string capture();

private:
    std::string buffer;
    int         count{0};
    uint32_t    incoming[16];

    void flush();
};

// unsafe_unpack unpacks `count` int32 into `output` buffer.
// It does not validate the input `buf`.
void unsafe_unpack16(const std::string& buf, size_t count, uint32_t* output);

#ifdef __AVX512VBMI2__
// sse_unsafe_unpack unpacks `count` int32 into `output` buffer.
// It does not validate the input `buf`.
void avx512vbmi2_unsafe_unpack16(const std::string& buf, size_t count, uint32_t* output);
#endif
