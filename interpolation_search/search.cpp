#include <cstdint>
#include <vector>
#include <assert.h>


typedef int                   KeyType;
typedef std::vector<KeyType>  ArrayType;

template <typename Callback>
bool search(const ArrayType& array, KeyType key, Callback middle) {
    
    std::size_t a = 0;
    std::size_t b = array.size() - 1;

    while (a <= b) {
        const auto c = middle(a, b, array, key);
        if (c == std::size_t(-1)) {
            return false;
        }

        if (array[c] == key) {
            return true;
        } else if (key < array[c]) {
            b = c - 1;
        } else {
            a = c + 1;
        }
    }

    return false;
}


int bin_middle(std::size_t a, std::size_t b, const ArrayType& /*array*/, int /*key*/) {
    return (a + b)/2;
}


int interpolation_middle(std::size_t a, std::size_t b, const ArrayType& array, int key) {
    if (array[a] == array[b]) {
        return a;
    }
    
    double t = double(key - array[a])/(array[b] - array[a]);

    if (t < 0 || t > 1) {
        return std::size_t(-1);
    }

    assert((t >= 0.0) && (t <= 1.0));

    return int(t * (b - a)) + a;
}

