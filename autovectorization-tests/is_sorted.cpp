#include <algorithm>
#include <vector>
#include <cstdint>

bool is_sorted_epi8(const std::vector<int8_t>& v) {
    return std::is_sorted(v.begin(), v.end());
}

bool is_sorted_epi32(const std::vector<int32_t>& v) {
    return std::is_sorted(v.begin(), v.end());
}
