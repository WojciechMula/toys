#include <cstdint>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>

#include "avx512-utf8-validate.h"


class Test {
public:
    bool run() {
        const bool ret = test();

        if (ret)
            puts("All OK");

        return ret;
    }

private:
    bool test() {
        // In case of 4-byte chars we're taking into account
        // also the 4th bit of leading byte. For valid UTF-8
        // it's zero, so we don't alter the result. But if
        // it's one, it would increase the number above
        // `max_unicode_value` and we can detect it.
        constexpr uint32_t max_decoded_value = (1 << (3*7 + 4)) - 1;

        const int frequency = 100000;
        int k = frequency;
        for (uint8_t char_class=8; char_class < 16; char_class++) {
            if ((char_class & 0xc) == 0x8)
                continue; // skip continuation bytes

            const __m512i v_char_class = _mm512_set1_epi32(char_class);
            for (uint32_t val=0; val <= max_decoded_value; val++) {
                // given
                const bool expected = is_valid(char_class, val);

                // when
                const __mmask16 mask = avx512_utf8_validate_ranges(v_char_class, _mm512_set1_epi32(val));
                const bool result = bool(mask & 0x1);

                // then
                if (expected != result) {
                    printf("failed for class %x and value %d (%x)\n", char_class, val, val);
                    printf("expected = %s\n", expected ? "true" : "false");
                    printf("result   = %s\n", result ? "true" : "false");
                    return false;
                }

                k -= 1;
                if (k == 0) {
                    k = frequency;
                    const double current = double(char_class) * max_decoded_value + val;
                    const double total = 16.0 * max_decoded_value;
                    printf("%6.3f%%\r", ((current * 100)/total));
                    fflush(stdout);
                }
            }
        }

        puts("");

        return true;
    }

    bool is_valid(uint8_t char_class, uint32_t value) const {
        constexpr uint32_t max_unicode_value = 1114112;
        constexpr uint32_t surrogate_min = 0xd800;
        constexpr uint32_t surrogate_max = 0xdfff;
        if (value >= surrogate_min and value <= surrogate_max)
            return false;

        if (value > max_unicode_value)
            return false;

        switch (char_class) {
            // ASCII
            case 0b0000:
            case 0b0001:
            case 0b0010:
            case 0b0011:
            case 0b0100:
            case 0b0101:
            case 0b0110:
            case 0b0111:
                return (value <= 0x7f);

            // 2-byte char
            case 0b1100:
            case 0b1101:
                return ((value >= 0x80) and (value <= 0x07ff));

            // 3-byte char
            case 0b1110:
                return ((value >= 0x0800) and (value <= 0xffff));

            // 4-byte char
            case 0b1111:
                return ((value >= 0x100000) and (value <= 0x10ffff));

            default:
                abort();
        }
    }
};

int main() {
    Test test;
    return test.run() ? EXIT_SUCCESS : EXIT_FAILURE;
}
