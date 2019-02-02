#include <algorithm>
#include <vector>
#include <cstdint>

void unique_epi8(std::vector<int8_t>& v) {
    std::unique(v.begin(), v.end());
}

void unique_epi32(std::vector<int32_t>& v) {
    std::unique(v.begin(), v.end());
}
