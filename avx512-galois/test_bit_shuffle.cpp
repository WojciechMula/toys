#include <cstdio>
#include <cstdint>
#include <cassert>

#include "interleave.cpp"
#include "reverse.cpp"
#include "replicate.cpp"

__m512i replicate_third_bit_epi8(__m512i in) {
    return replicate_bit_epi8(in, 3);
}

class Test {
public:
    bool operator()() {
        return test(interleave_epi8, 0, 4, 1, 5, 2, 6, 3, 7);
        return test(reverse_epi8, 7, 6, 5, 4, 3, 2, 1, 0);
        return test(replicate_third_bit_epi8, 3, 3, 3, 3, 3, 3, 3, 3);
    }

private:
    template <typename FUNCTION>
    bool test(FUNCTION fun, int b0, int b1, int b2, int b3, int b4, int b5, int b6, int b7) {
        uint8_t transformed[64];

        for (int val=0; val < 256; val++) {
            const __m512i in  = _mm512_set1_epi8(val);
            const __m512i out = fun(in);

            _mm512_storeu_si512((__m512i*)transformed, out);
#define bit(pos) (((val) >> (pos)) & 0x01)
            const int expected = (bit(b0) << 0) |
                                 (bit(b1) << 1) |
                                 (bit(b2) << 2) |
                                 (bit(b3) << 3) |
                                 (bit(b4) << 4) |
                                 (bit(b5) << 5) |
                                 (bit(b6) << 6) |
                                 (bit(b7) << 7);
#undef bit
            if (transformed[0] != expected) {
                printf("Error for 0x%02x: result = 0x%02x, expected = 0x%02x\n", val, transformed[0], expected);
                return false;
            }
        }

        return true;
    }
};

int main() {
    Test test;

    if (test()) {
        puts("All OK");
        return EXIT_SUCCESS;
    } else
        return EXIT_FAILURE;
}
