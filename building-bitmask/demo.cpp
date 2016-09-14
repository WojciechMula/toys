#include <cstdlib>
#include <cstdint>
#include <cstdio>

#include "algorithms.cpp"

class Test {

    uint32_t bitvector;
    uint32_t input[32];
    bool result;

public:
    template <typename FUNCTION>
    bool run_all(FUNCTION fun) {

        result = true;

        test_empty(fun);
        if (!result) {
            puts("empty");
            return false;
        }
    
        test_full(fun);
        if (!result) {
            puts("full");
            return false;
        }
    
        test_one_exists(fun);
        if (!result) {
            puts("exists");
            return false;
        }
    
        test_first_n_equal(fun);
        if (!result) {
            puts("first n");
            return false;
        }
    
        test_last_n_equal(fun);
        if (!result) {
            puts("last n");
            return false;
        }
    
        test_random(fun);
        if (!result) {
            puts("random");
            return false;
        }

        return true;
    }
    
private:
    template <typename FUNCTION>
    bool check(FUNCTION fun, uint32_t value) {
        
        set_input(value);
        bitvector = 0;
        
        fun(input, 32, 0xaa, reinterpret_cast<uint8_t*>(&bitvector));

        if (value != bitvector) {
            printf("failed: result = 0x%08x, expected = 0x%08x\n", bitvector, value);
        }

        return value == bitvector;
    }

    template <typename FUNCTION>
    bool test_empty(FUNCTION fun) {
        
        return check(fun, 0);
    }

    template <typename FUNCTION>
    void test_full(FUNCTION fun) {
        
        result = result && check(fun, 0xffffffff);
    }

    template <typename FUNCTION>
    void test_one_exists(FUNCTION fun) {
        
        for (unsigned i=0; i < 32; i++) {
            result = result && check(fun, uint32_t(1) << i);
        }
    }

    template <typename FUNCTION>
    void test_first_n_equal(FUNCTION fun) {
        
        for (unsigned i=0; i < 32; i++) {
            result = result && check(fun, uint32_t(-1) >> i);
        }
    }

    template <typename FUNCTION>
    void test_last_n_equal(FUNCTION fun) {
        
        for (unsigned i=0; i < 32; i++) {
            result = result && check(fun, uint32_t(-1) << i);
        }
    }

    template <typename FUNCTION>
    void test_random(FUNCTION fun) {
        
        for (unsigned i=0; i < 32; i++) {
            result = result && check(fun, rand());
        }
    }

private:
    void set_input(uint32_t in, uint32_t key = 0xaa, uint32_t other = 0x1234) {

        for (unsigned i=0; i < 32; i++) {
            const uint32_t bit = uint32_t(1) << i;
            input[i] = (in & bit) ? key : other;
        }
    }

};


int main() {

    Test test;

    printf("bitmask_naive... "); fflush(stdout);
    if (test.run_all(bitmask_naive)) {
        puts("OK");
    } else {
        puts("FAILED");
    }

    printf("bitmask_better_1... "); fflush(stdout);
    if (test.run_all(bitmask_better_1)) {
        puts("OK");
    } else {
        puts("FAILED");
    }

    printf("bitmask_better_2... "); fflush(stdout);
    if (test.run_all(bitmask_better_2)) {
        puts("OK");
    } else {
        puts("FAILED");
    }

    printf("bitmask_SSE... "); fflush(stdout);
    if (test.run_all(bitmask_SSE)) {
        puts("OK");
    } else {
        puts("FAILED");
    }
}
