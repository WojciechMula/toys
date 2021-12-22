#include <cstdint>

extern void func_true(int);
extern void func_false(int);

bool test_and_clear_bit(uint64_t& val, int bitpos) {
    const uint64_t bitmask = uint64_t(1) << bitpos;
    const uint64_t old = val; 

    val &= ~bitmask;

    return val < old;
}

void loop_v1(uint64_t mask) {
    for (int i=63; i >= 0 && mask != 0; i--) {
        if (test_and_clear_bit(mask, i))
            func_true(i);
        else
            func_false(i);
    }
}

void loop_v2(uint64_t mask) {
    for (int i=63; i >= 0 && mask != 0; i--) {
        if ((int64_t)mask < 0) // test the MSB
            func_true(i);
        else
            func_false(i);

        mask <<= 1;
    }
}

void loop_v3(uint64_t mask) {
    using function = void (*)(int);
    function func[2] = {func_false, func_true};

    for (int i=63; i >= 0 && mask != 0; i--) {
        const int idx = ((int64_t)mask < 0); // 0 or 1
        func[idx](i);
        mask <<= 1;
    }
}
