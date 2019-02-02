#include <algorithm>
#include <vector>
#include <cstdint>

size_t count_if_epi8(const std::vector<int8_t>& v) {
    return std::count_if(v.begin(), v.end(), [](int32_t x){return x == 42 || x == -1;});
}

size_t count_if_epi32(const std::vector<int32_t>& v) {
    return std::count_if(v.begin(), v.end(), [](int32_t x){return x == 42 || x == -1;});
}
