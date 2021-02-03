#pragma once

#include <cstdint>
#include <cstddef>

class Visitor
{
public:
    virtual void ansi(size_t, uint8_t) = 0;
    virtual void seq2_head(size_t, uint8_t) = 0;
    virtual void seq3_head(size_t, uint8_t) = 0;
    virtual void seq4_head(size_t, uint8_t) = 0;
    virtual void tail(size_t, uint8_t) = 0;
    virtual void invalid(size_t, uint8_t) = 0;
    virtual void eos() = 0;
};

void utf8_visit(Visitor& visitor, const uint8_t* bytes, size_t size);
