#include "vector_utils.h"
#include <set>

#include <cstdlib>
#include <cassert>


template <typename SOURCE>
vec create(size_t size, SOURCE source) {

    std::set<int32_t> tmp;
    for (size_t i=0; i < size; i++) {
        tmp.insert(source());
    }

    while (tmp.size() < size) {
        tmp.insert(source());
    }

    vec result(tmp.begin(), tmp.end());
    assert(result.size() == size);

    return result;
}

vec create_sorted(size_t size) {
    return create(size, []{return rand();});
}

vec sample_sorted(const vec& input, size_t size) {

    return create(size, [&input]{
        const size_t index = rand() % input.size();
        return input[index];
    });
}

