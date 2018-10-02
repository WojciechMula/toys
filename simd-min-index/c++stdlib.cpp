#include <algorithm> // for std::min_element
#include <iterator>  // for std::distance
#include <cassert>

template <typename T>
size_t min_index(const T& v) {
    
    assert(!v.empty());

    return std::distance(v.begin(), std::min_element(v.begin(), v.end()));
}

#include <vector>

int main() {

    std::vector<int> v;
    size_t i = min_index(v);
}
