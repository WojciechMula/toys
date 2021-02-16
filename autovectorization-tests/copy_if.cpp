#include <algorithm>
#include <vector>
#include <cstdint>
#include <iterator>

void copy_if_epi8(const std::vector<int8_t>& v, std::vector<int8_t>& out) {
    std::copy_if(v.begin(), v.end(), std::back_inserter(out),
                 [](int8_t x){return x > 0;});
}

void copy_if_epi32(const std::vector<int32_t>& v, std::vector<int32_t>& out) {
    std::copy_if(v.begin(), v.end(), std::back_inserter(out),
                 [](int32_t x){return x > 0;});
}

