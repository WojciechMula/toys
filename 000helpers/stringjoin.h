#pragma once

#include <string>

std::string stringjoin(const std::string& sep) {
  return "";
}

template <typename T>
std::string stringjoin(const std::string& sep, const T& v) {
  return v;
}

template <typename T, typename... TA>
std::string stringjoin(const std::string& sep, const T& v, TA... args) {
  return v + sep + stringjoin(sep, args...);
}

