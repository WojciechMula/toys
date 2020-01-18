#include <cstdio>
#include <cstdint>
#include <cassert>

#include "transpose.cpp"

class Test {
    uint8_t input[64];
    uint8_t transposed[64];

public:
    bool operator()() {
        // Note: we fill & validate values only in the 0th lane
        for (int row=0; row < 8; row++) {
            for (int val=0; val < 256; val++) {
                #define bit(N) ((val >> N) & 0x01)
                input[0] = bit(7) << row;
                input[1] = bit(6) << row;
                input[2] = bit(5) << row;
                input[3] = bit(4) << row;
                input[4] = bit(3) << row;
                input[5] = bit(2) << row;
                input[6] = bit(1) << row;
                input[7] = bit(0) << row;
                #undef bit

                __m512i in  = _mm512_loadu_si512((__m512i*)input);
                __m512i out = transpose_8x8_epi64(in);
                _mm512_storeu_si512((__m512i*)transposed, out);

                if (!check(row, val)) {
                    printf("Failed for row = %d, value = 0x%02x\n", row, val);
                    dump();
                    return false;
                }
            }
        }

        return true;
    }

private:
    bool check(int row, int value) const {
        for (int i=0; i < 8; i++) {
            const int expected = (i == row) ? value : 0x00;
            if (transposed[i] != expected)
                return false;
        }

        return true;
    }

    void dump() const {
        dump(input, "input");
        dump(transposed, "transposed");
    }

    void dump(const uint8_t* array, const char* name) const {
        for (int i=0; i < 8; i++) {
            printf("%s[%d] = 0x%02x\n", name, i, array[i]);
        }
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
