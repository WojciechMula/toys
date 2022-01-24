#pragma once

#include <cstdint>
#include <string>

void append_4bytes(std::string& target, uint32_t v);
void append_3bytes(std::string& target, uint32_t v);
void append_2bytes(std::string& target, uint32_t v);
void append_byte(std::string& target, uint32_t v);
uint32_t unsafe_read_4bytes(const std::string& buf, size_t index);
uint32_t unsafe_read_3bytes(const std::string& buf, size_t index);
uint32_t unsafe_read_2bytes(const std::string& buf, size_t index);
uint32_t unsafe_read_byte(const std::string& buf, size_t index);
