// This tool fully validates the core AVX512 algorithm

#include <cstdint>
#include <cstdio>

#include "avx512-transcode-utf8.h"
#include "utf8.h"

class Test {
public:
    bool run() {
        bool ret = true;

        ret = test("AVX512 (ver1)", avx512_utf8_to_utf32__aux__version1) and ret;
        ret = test("AVX512 (ver2)", avx512_utf8_to_utf32__aux__version2) and ret;
        ret = test("AVX512 (ver3)", static_cast<__m512i (*)(__m512i)>(avx512_utf8_to_utf32__aux__version3)) and ret;
        ret = test("AVX512 (ver4)", avx512_utf8_to_utf32__aux__version4) and ret;
        ret = test("AVX512 (ver5)", static_cast<__m512i (*)(__m512i)>(avx512_utf8_to_utf32__aux__version5)) and ret;
        if (ret)
            puts("All OK");

        return ret;
    }

private:
    template <typename FUN>
    bool test(const char* name, FUN avx512_utf8_to_utf32__aux) {
        printf("%s ... ", name);
        fflush(stdout);

        uint32_t buf[16];
        for (uint32_t character=0; character <= 0x10ffff; character++) {
            const uint32_t word = utf8_bytes(character);
            const __m512i input = _mm512_set1_epi32(word);

            const __m512i output = avx512_utf8_to_utf32__aux(input);
            _mm512_storeu_si512((__m512i*)buf, output);

            if (buf[0] != character) {
                printf("failed for %u: result=%u (%08x)\n", character, buf[0], buf[0]);
                return false;
            }
        }

        puts("OK");
        return true;
    }
};

int main() {
    Test test;
    return test.run() ? EXIT_SUCCESS : EXIT_FAILURE;
}
