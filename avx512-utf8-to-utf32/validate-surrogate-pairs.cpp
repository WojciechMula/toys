#include <cstdint>
#include <cstdio>
#include <cstring>

#include "avx512-surrogate-pairs.h"

class Test {
    uint32_t input[16];
    char16_t output[32];
    char16_t expected_output[32];
    size_t expected_size;

public:
    bool run() {
        bool ret = true;

        ret = test("AVX512", avx512_utf32_to_utf16) and ret;

        if (ret)
            puts("All OK");

        return ret;
    }

private:
    template <typename FUN>
    bool test(const char* name, FUN convert) {
        printf("%-15s ", name);
        fflush(stdout);

        for (uint64_t i=0; i < 65536; i++) {
            // given
            prepare_input(i);

            const __m512i in = _mm512_loadu_si512((__m512i*)input);

            // when
            const auto size = convert(in, output);

            // then
            if (size != expected_size) {
                puts("");
                printf("expected = %ld\n", expected_size);
                printf("got =      %ld\n", size);
                printf("case #%ld: wrong size\n", i);
                return false;
            }

            if (memcmp(output, expected_output, 2 * size) != 0) {
                puts("");
                dump("expected", expected_output, size);
                dump("got     ", output, size);
                printf("case #%ld: wrong output\n", i);
                return false;
            }
        }

        puts("OK");
        return true;
    }

    void prepare_input(uint16_t pattern) {
        expected_size = 0;
        for (int i=0; i < 16; i++) {
            if (pattern & (uint16_t(1) << i)) {
                input[i] = 0x1'0000 + i;
                expected_output[expected_size++] = 0xd800;
                expected_output[expected_size++] = 0xdc00 + i;
            } else {
                input[i] = i;
                expected_output[expected_size++] = i;
            }

            output[i] = 0xffff;
        }
    }

    void dump(const char* name, char16_t* data, int size) {
        printf("%s = [%04x", name, data[0]);
        for (int i=1;  i < size; i++) {
            printf(" %04x", data[i]);
        }

        printf("]\n");
    }
};

int main() {
    Test test;
    return test.run() ? EXIT_SUCCESS : EXIT_FAILURE;
}
