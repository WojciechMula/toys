#include <algorithm>
#include <vector>
#include <cstdint>

bool find_epi8(const std::vector<int8_t>& v) {
    return std::find(v.begin(), v.end(), 42) != v.end();
}

bool find_epi32(const std::vector<int32_t>& v) {
    return std::find(v.begin(), v.end(), 42) != v.end();
}
