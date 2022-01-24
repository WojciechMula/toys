#include "byte_buffer.h"

#include <cstring>

void append_4bytes(std::string& target, uint32_t v) {
    target.push_back((v >> (0*8)) & 0xff);
    target.push_back((v >> (1*8)) & 0xff);
    target.push_back((v >> (2*8)) & 0xff);
    target.push_back((v >> (3*8)) & 0xff);
}

void append_3bytes(std::string& target, uint32_t v) {
    target.push_back((v >> (0*8)) & 0xff);
    target.push_back((v >> (1*8)) & 0xff);
    target.push_back((v >> (2*8)) & 0xff);
}

void append_2bytes(std::string& target, uint32_t v) {
    target.push_back((v >> (0*8)) & 0xff);
    target.push_back((v >> (1*8)) & 0xff);
}

void append_byte(std::string& target, uint32_t v) {
    target.push_back(v & 0xff);
}

uint32_t unsafe_read_4bytes(const std::string& buf, size_t index) {
    uint32_t val;
    memcpy(&val, &buf[index], 4);

    return val;
}

uint32_t unsafe_read_3bytes(const std::string& buf, size_t index) {
    const uint32_t b0 = uint32_t(uint8_t(buf[index + 0])) << (0*8);
    const uint32_t b1 = uint32_t(uint8_t(buf[index + 1])) << (1*8);
    const uint32_t b2 = uint32_t(uint8_t(buf[index + 2])) << (2*8);

    return b0 | b1 | b2;
}

uint32_t unsafe_read_2bytes(const std::string& buf, size_t index) {
    const uint32_t b0 = uint32_t(uint8_t(buf[index + 0])) << (0*8);
    const uint32_t b1 = uint32_t(uint8_t(buf[index + 1])) << (1*8);

    return b0 | b1;
}

uint32_t unsafe_read_byte(const std::string& buf, size_t index) {
    return uint32_t(uint8_t(buf[index]));
}
