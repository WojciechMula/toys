// This tool fully validates the core AVX512 algorithm

#include <cstdint>
#include <cstdio>

#include "avx512-utf8-to-utf32.h"
#include "utf8.h"

int main() {
    uint32_t buf[16];
    for (uint32_t character=0; character <= 0x10ffff; character++) {
        const uint32_t word = utf8_bytes(character);
        const __m512i input = _mm512_set1_epi32(word);

        const __m512i output = avx512_utf8_to_utf32__aux(input);
        _mm512_storeu_si512((__m512i*)buf, output);

        if (buf[0] != character) {
            printf("failed for %u: result=%u\n", character, buf[0]);
            return 1;
        }
    }

    puts("All OK");
    return 0;
}
