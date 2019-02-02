#include <algorithm>
#include <vector>
#include <cstdint>

bool all_of_epi8(const std::vector<int8_t>& v) {
    return std::all_of(v.begin(), v.end(), [](int8_t x){return x == 42;});
}

bool all_of_epi32(const std::vector<int32_t>& v) {
    return std::all_of(v.begin(), v.end(), [](int32_t x){return x == 42;});
}
