#include <algorithm>
#include <vector>
#include <cstdint>

bool find_if_epi8(const std::vector<int8_t>& v) {
    return std::find_if(v.begin(), v.end(), [](int32_t x){return x == 42 || x == -1;}) != v.end();
}

bool find_if_epi32(const std::vector<int32_t>& v) {
    return std::find_if(v.begin(), v.end(), [](int32_t x){return x == 42 || x == -1;}) != v.end();
}
