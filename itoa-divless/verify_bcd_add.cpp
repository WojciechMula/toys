#include <cstdlib>
#include <cstring>
#include <cstdint>
#include <cstdio>

void add_swar(uint64_t a, uint64_t b, char* result) {
    const uint64_t  a1 = 0xf6f6f6f6f6f6f6f6lu + a; // 0xf6 = 255 - 9
    const uint64_t sum = a1 + b;    // bytes are either less than 10 or greater or equals 128

    const uint64_t msb  = sum & 0x8080808080808080lu;
    const uint64_t t0   = msb >> 7;
    const uint64_t mask = (msb - t0) | msb; // bytes are either 0x00 or 0xff

    const uint64_t corr = mask & 0xf6f6f6f6f6f6f6f6lu; // 0 or 255 - 9 
    const uint64_t sum1 = sum - corr;   // byte or (byte - shift)

    const uint64_t ascii = __builtin_bswap64(sum1 + 0x3030303030303030lu);

    memcpy(result, &ascii, 8);
}

#ifdef __SSE2__
#include <immintrin.h>
void add_sse(uint64_t a, uint64_t b, char* result) {
    const uint64_t  a1 = 0xf6f6f6f6f6f6f6f6lu + a; // 0xf6 = 255 - 9
    const uint64_t  s1 = a1 + b;
    const uint64_t sum = __builtin_bswap64(s1);

    const __m128i vsum   = _mm_set_epi64x(sum, sum);

    const __m128i mask = _mm_cmplt_epi8(vsum, _mm_setzero_si128());
    const __m128i corr = _mm_and_si128(mask, _mm_set1_epi8(255 - 9));

    const __m128i sum1  = _mm_sub_epi8(vsum, corr);
    const __m128i ascii = _mm_add_epi8(sum1, _mm_set1_epi8('0'));

    _mm_storel_epi64((__m128i*)result, ascii);
}
#endif


void verify() {
    union {
        uint64_t a;
        char a_img[9]; // BCD representation
    };

    union {
        uint64_t b;
        char b_img[9]; // BCD representation
    };

    char expected[9];
    char result_swar[9];
    char result_sse[9];
    memset(expected, 0, sizeof(expected));
    memset(result_swar, 0, sizeof(result_swar));
    memset(result_sse, 0, sizeof(result_sse));

    // we check all possible combinations of 4-digit decimal numbers
    const uint64_t max = 10000;
    const int interval = 1000;
    int k = interval;
    for (uint64_t i=1; i < max; i++) {
        sprintf(a_img, "%08ld", i);
        a -= 0x3030303030303030lu; // get back from ASCII to BCD
        a  = __builtin_bswap64(a);
        for (uint64_t j=0; j < max; j++) {
            sprintf(b_img, "%08ld", j);
            b -= 0x3030303030303030lu; // get back from ASCII to BCD
            b  = __builtin_bswap64(b);

            sprintf(expected, "%08ld", (i + j));

            add_swar(a, b, result_swar);
            if (memcmp(result_swar, expected, 8) != 0) {
                printf("SWAR failed for a=%ld and b=%ld\n", i, j);
                printf("expected = '%s'\n", expected);
                printf("result   = '%s'\n", result_swar);
                exit(1);
            }

#ifdef __SSE2__
            add_sse(a, b, result_sse);
            if (memcmp(result_sse, expected, 8) != 0) {
                printf("SSE failed for a=%ld and b=%ld\n", i, j);
                printf("expected = '%s'\n", expected);
                printf("result   = '%s'\n", result_sse);
                exit(1);
            }
#endif

            k -= 1;
            if (k == 0) {
                const double prog = double(i * max + j) * 100 / double(max * max);
                printf("%6.2f%%\r", prog);
                fflush(stdout);
                k = interval;
            }
        }
    }
}

int main() {
    verify();

    puts("");
    puts("All OK");
}
