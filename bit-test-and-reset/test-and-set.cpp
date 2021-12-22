#include <cstdint>

bool test_and_clear_bit(uint64_t& val, int bitpos) {
    const uint64_t bitmask = uint64_t(1) << bitpos;

    const bool ret = (val & bitmask);

    val &= ~bitmask;

    return ret;
}

bool test_and_clear_bit_v2(uint64_t& val, int bitpos) {
    const uint64_t bitmask = uint64_t(1) << bitpos;
    const uint64_t old = val; 

    val &= ~bitmask;

    return val < old;
}
