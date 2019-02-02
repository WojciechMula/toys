#include <algorithm>
#include <vector>
#include <cstdint>
#include <cstdlib>

void remove_if_epi8(std::vector<int8_t>& v) {
    std::remove_if(v.begin(), v.end(), [](int8_t c){return c != 42;});
}

void remove_if_epi32(std::vector<int32_t>& v) {
    std::remove_if(v.begin(), v.end(), [](int8_t c){return c != 42;});
}

