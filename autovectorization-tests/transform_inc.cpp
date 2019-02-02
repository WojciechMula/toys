#include <algorithm>
#include <vector>
#include <cstdint>

void transform_inc_epi8(std::vector<int8_t>& v) {
    std::transform(v.begin(), v.end(), v.begin(), [](int8_t x){return x + 42;});
}

void transform_inc_epi32(std::vector<int32_t>& v) {
    std::transform(v.begin(), v.end(), v.begin(), [](int32_t x){return x + 42;});
}

