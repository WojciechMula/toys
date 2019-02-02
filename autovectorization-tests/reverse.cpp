#include <algorithm>
#include <vector>
#include <cstdint>

void reverse_epi8(std::vector<int8_t>& v) {
    std::reverse(v.begin(), v.end());
}

void reverse_epi32(std::vector<int32_t>& v) {
    std::reverse(v.begin(), v.end());
}
