#include <numeric>
#include <vector>
#include <cstdint>

size_t accumulate_epi8(const std::vector<int8_t>& v) {
    return std::accumulate(v.begin(), v.end(), 0);
}

size_t accumulate_epi32(const std::vector<int32_t>& v) {
    return std::accumulate(v.begin(), v.end(), 0);
}
