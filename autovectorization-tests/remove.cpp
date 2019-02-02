#include <algorithm>
#include <vector>
#include <cstdint>
#include <cstdlib>

void remove_epi8(std::vector<int8_t>& v) {
    std::remove(v.begin(), v.end(), 42);
}

void remove_epi32(std::vector<int32_t>& v) {
    std::remove(v.begin(), v.end(), 42);
}

