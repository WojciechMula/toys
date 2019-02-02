#include <algorithm>
#include <vector>
#include <cstdint>

void replace_if_epi8(std::vector<int8_t>& v) {
    std::replace_if(v.begin(), v.end(), [](int8_t x){return x == 13 || x == -12; }, 42);
}

void replace_if_epi32(std::vector<int32_t>& v) {
    std::replace_if(v.begin(), v.end(), [](int8_t x){return x == 13 || x == -12; }, 42);
}

