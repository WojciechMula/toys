#include <algorithm>
#include <vector>
#include <cstdint>

void replace_epi8(std::vector<int8_t>& v) {
    std::replace(v.begin(), v.end(), 13, 42);
}

void replace_epi32(std::vector<int32_t>& v) {
    std::replace(v.begin(), v.end(), 13, 42);
}

