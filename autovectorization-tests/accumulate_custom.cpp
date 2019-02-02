#include <numeric>
#include <vector>
#include <cstdint>

size_t accumulate_custom_epi8(const std::vector<int8_t>& v) {
    return std::accumulate(v.begin(), v.end(), 0, [](int8_t a, int8_t b){return a - b;});
}

size_t accumulate_custom_epi32(const std::vector<int32_t>& v) {
    return std::accumulate(v.begin(), v.end(), 0, [](int32_t a, int32_t b){return a - b;});
}
