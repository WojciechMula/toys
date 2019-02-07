#include <algorithm>
#include <vector>
#include <cstdint>

bool adjacent_find_epi8(const std::vector<int8_t>& v) {
    return std::adjacent_find(v.begin(), v.end()) != v.end();
}

bool adjacent_find_epi32(const std::vector<int32_t>& v) {
    return std::adjacent_find(v.begin(), v.end()) != v.end();
}

