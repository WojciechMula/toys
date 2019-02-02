#include <algorithm>
#include <vector>
#include <cstdint>
#include <cstdlib>

void transform_abs_epi8(std::vector<int8_t>& v) {
    std::transform(v.begin(), v.end(), v.begin(), [](int8_t x){return abs(x);});
}

void transform_abs_epi32(std::vector<int32_t>& v) {
    std::transform(v.begin(), v.end(), v.begin(), [](int32_t x){return abs(x);});
}

