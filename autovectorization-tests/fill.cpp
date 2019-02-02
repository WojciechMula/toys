#include <algorithm>
#include <vector>
#include <cstdint>
#include <cstdlib>

void fill_epi8(std::vector<int8_t>& v) {
    std::fill(v.begin(), v.end(), 42);
}

void fill_epi32(std::vector<int32_t>& v) {
    std::fill(v.begin(), v.end(), 42);
}
