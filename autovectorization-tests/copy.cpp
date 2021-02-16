#include <algorithm>
#include <vector>
#include <cstdint>
#include <iterator>

void copy_epi8(const std::vector<int8_t>& v, std::vector<int8_t>& out) {
    std::copy(v.begin(), v.end(), std::back_inserter(out));
}

void copy_epi32(const std::vector<int32_t>& v, std::vector<int32_t>& out) {
    std::copy(v.begin(), v.end(), std::back_inserter(out));
}

