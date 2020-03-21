#include <cstdint>
#include <cassert>

uint64_t binom_scalar(uint64_t n, uint64_t k) {
    assert(n > 1);
    assert(k > 1);
    assert(k < n);

    const uint64_t p = std::min(k, n - k);
    
    uint64_t num = 1;
    uint64_t denom = 1;
    for (uint64_t i=0; i < p; i++) {
        num   *= n - p + (i + 1);
        denom *= (i + 1);
    }

    return num / denom;
}
