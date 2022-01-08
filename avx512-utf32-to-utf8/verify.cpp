#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <immintrin.h>

#include "avx512bw-utf32-to-utf8.h"
#include "avx512vbmi2-utf32-to-utf8.h"


size_t reference(const uint32_t* utf32, const uint32_t* length, size_t n, char* output) {
    char* start = output;

    for (size_t i=0; i < n; i++) {
        switch (length[i]) {
            case 1:
                *output++ = utf32[i] & 0xff;
                break;

            case 2:
                *output++ = (utf32[i] >> 0*8) & 0xff;
                *output++ = (utf32[i] >> 1*8) & 0xff;
                break;

            case 3:
                *output++ = (utf32[i] >> 0*8) & 0xff;
                *output++ = (utf32[i] >> 1*8) & 0xff;
                *output++ = (utf32[i] >> 2*8) & 0xff;
                break;

            case 4:
                *output++ = (utf32[i] >> 0*8) & 0xff;
                *output++ = (utf32[i] >> 1*8) & 0xff;
                *output++ = (utf32[i] >> 2*8) & 0xff;
                *output++ = (utf32[i] >> 3*8) & 0xff;
                break;

            default:
                abort();
        }
    }

    return output - start;
}


class Test {
    static constexpr int n = 16;
    uint32_t utf32[n];
    uint32_t length[n];
    char expected_output[n*4 + 16];
    char output[n*4 + 16];

public:
    bool run() {
        bool ret = true;

        ret = test("AVX512BW",    avx512bw_compress_utf8) and ret;
        ret = test("AVX512VBMI2", avx512vbmi2_compress_utf8) and ret;

        if (ret)
            puts("All OK");

        return ret;
    }

private:
    template <typename FUN>
    bool test(const char* name, FUN utf32_to_utf8) {
        printf("%-15s ", name);
        fflush(stdout);

        initialize();

        int k = 0;
        for (unsigned i=0; i < 256; i++) {
            const uint32_t len0 = ((i >> (2*0)) & 0x3) + 1;
            const uint32_t len1 = ((i >> (2*1)) & 0x3) + 1;
            const uint32_t len2 = ((i >> (2*2)) & 0x3) + 1;
            const uint32_t len3 = ((i >> (2*3)) & 0x3) + 1;

            for (int j=0; j < 4; j++) {
                length[4*j + 0] = len0;
                length[4*j + 1] = len1;
                length[4*j + 2] = len2;
                length[4*j + 3] = len3;
            }

            const size_t expected_count = reference(utf32, length, n, expected_output);

            const __m512i v_utf32 = _mm512_loadu_si512((const __m512i*)utf32);
            const __m512i v_length = _mm512_loadu_si512((const __m512i*)length);

            const size_t count = utf32_to_utf8(v_utf32, v_length, output);

            if (expected_count != count) {
                puts("");
                printf("expected = %ld\n", expected_count);
                printf("count    = %ld\n", count);
                printf("case #%d: wrong count\n", k);
                return false;
            }

            if (memcmp(expected_output, output, count) != 0) {
                puts("");
                dump("expected ", expected_output, count);
                dump("output   ", output, count);
                dump("lengths  ");
                printf("case #%d: wrong output; count = %ld\n", k, count);
                return false;
            }

            k += 1;
        }

        puts("OK");
        return true;
    }

    void initialize() {
        for (int i=0; i < n; i++) {
            const uint32_t k = i;
            // 0xi0i0i0i0
            utf32[i] = (k << (3*8 + 4))
                     | (k << (2*8 + 4))
                     | (k << (1*8 + 4))
                     | (k << (0*8 + 4));

            // 0xi4i3i2i1
            utf32[i] += 0x04030201;

            length[i] = 1;
        }
    }

    void dump(const char* name, const char* data, int size) {
        printf("%s = [%02x", name, uint8_t(data[0]));
        for (int i=1;  i < size; i++) {
            printf(" %02x", uint8_t(data[i]));
        }

        printf("]\n");
    }

    void dump(const char* name) {
        printf("%s = [%d", name, length[0]);
        for (int i=1;  i < n; i++) {
            printf(" %d", length[i]);
        }

        printf("]\n");
    }
};

int main() {
    Test test;
    return test.run() ? EXIT_SUCCESS : EXIT_FAILURE;
}
