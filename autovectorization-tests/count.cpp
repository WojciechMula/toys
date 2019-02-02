#include <algorithm>
#include <vector>
#include <cstdint>

size_t count_epi8(const std::vector<int8_t>& v) {
    return std::count(v.begin(), v.end(), 42);
}

size_t count_epi32(const std::vector<int32_t>& v) {
    return std::count(v.begin(), v.end(), 42);
}
