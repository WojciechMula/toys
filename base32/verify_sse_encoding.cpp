#include <cstdio>
#include <cstdint>
#include <cassert>
#include <string>
#include <immintrin.h>

void dump_u8(uint8_t x) {
    for (int i=7; i >= 0; i--) {
        const uint8_t bit = 1 << i;
        putchar((x & bit) ? '1' : '.');
    }
}

void dump_u32(uint32_t x) {
    putchar('|');
    dump_u8((x >> 3*8) & 0xff);
    putchar('|');
    dump_u8((x >> 2*8) & 0xff);
    putchar('|');
    dump_u8((x >> 1*8) & 0xff);
    putchar('|');
    dump_u8((x >> 0*8) & 0xff);
    putchar('|');
}

void dump(__m128i x) {
    const uint64_t v = _mm_extract_epi64(x, 0);

    dump_u32((v >> 32) & 0xffffffff);
    dump_u32(v & 0xffffffff);
    putchar('\n');
}

#include "sse_encoding.cpp"

void verify_base32_encoding_sse_expand() {
    constexpr uint64_t values[4] = {
        0x00,
        0x03,
        0x1c,
        0x1f,
    };

    uint8_t buf[32];
    for (uint32_t word=0; word <= 0x1'0000; word++) {
        const uint32_t a_idx = (word >> 0*2) & 0x3;
        const uint32_t b_idx = (word >> 1*2) & 0x3;
        const uint32_t c_idx = (word >> 2*2) & 0x3;
        const uint32_t d_idx = (word >> 3*2) & 0x3;
        const uint32_t e_idx = (word >> 4*2) & 0x3;
        const uint32_t f_idx = (word >> 5*2) & 0x3;
        const uint32_t g_idx = (word >> 6*2) & 0x3;
        const uint32_t h_idx = (word >> 7*2) & 0x3;

        const uint64_t a = values[a_idx] << (64 - 1*5);
        const uint64_t b = values[b_idx] << (64 - 2*5);
        const uint64_t c = values[c_idx] << (64 - 3*5);
        const uint64_t d = values[d_idx] << (64 - 4*5);
        const uint64_t e = values[e_idx] << (64 - 5*5);
        const uint64_t f = values[f_idx] << (64 - 6*5);
        const uint64_t g = values[g_idx] << (64 - 7*5);
        const uint64_t h = values[h_idx] << (64 - 8*5);

        const uint64_t input = __builtin_bswap64(a | b | c | d | e | f | g | h);

        const auto in = _mm_set1_epi64x(input);
        const auto out = base32_encoding_sse_expand(in);
        _mm_storeu_si128(reinterpret_cast<__m128i*>(buf), out);

#define ASSERT_EQUAL(want_id, got_id) do {      \
        const uint8_t want = values[want_id];   \
        const uint8_t got  = buf[got_id];       \
        if (want != got) {                      \
            puts("");                           \
            printf("input  = "); dump(in);      \
            printf("result = "); dump(out);     \
            printf("index  = %d\n", want_id);   \
            printf("want   = 0x%02x\n", want);  \
            printf("got    = 0x%02x\n", got);   \
            exit(1);                            \
        }                                       \
    } while(0)

        ASSERT_EQUAL(a_idx, 0);
        ASSERT_EQUAL(b_idx, 1);
        ASSERT_EQUAL(c_idx, 2);
        ASSERT_EQUAL(d_idx, 3);
        ASSERT_EQUAL(e_idx, 4);
        ASSERT_EQUAL(f_idx, 5);
        ASSERT_EQUAL(g_idx, 6);
        ASSERT_EQUAL(h_idx, 7);

#undef ASSERT_EQUAL
    }
}

void verify_base32_encoding_sse_translate_default() {
    uint8_t buf[16];
    for (int i=0; i < 32; i++) {
        const auto in  = _mm_set1_epi8(i);
        const auto out = base32_encoding_sse_translate<Base32Alphabet::Default>(in);
        _mm_storeu_si128(reinterpret_cast<__m128i*>(buf), out);

        const auto want = base32_alphabet[i];
        for (int j=0; j < 16; j++) {
            const auto got = buf[j];
            if (got != want) {
                printf("val  = %d\n", i);
                printf("want = '%c' [0x%02x]\n", want, want);
                printf("got  = '%c' [0x%02x]\n", got, got);
                exit(1);
            }
        }
    }
}

void verify_base32_encoding_sse_translate_hex() {
    uint8_t tmp[16];
    for (int i=0; i < 32; i++) {
        const auto in  = _mm_set1_epi8(i);
        const auto out = base32_encoding_sse_translate<Base32Alphabet::Hex>(in);
        _mm_storeu_si128(reinterpret_cast<__m128i*>(tmp), out);

        const auto want = base32_hex_alphabet[i];
        for (int j=0; j < 16; j++) {
            const auto got = tmp[j];
            if (got != want) {
                printf("val  = %d\n", i);
                printf("want = '%c' [0x%02x]\n", want, want);
                printf("got  = '%c' [0x%02x]\n", got, got);
                exit(1);
            }
        }
    }
}

void smoke_test() {
    const char* input = "foobarfoobarfoobar";

    const auto in  = _mm_loadu_si128(reinterpret_cast<const __m128i*>(input));
    const auto t0  = base32_encoding_sse_expand(in);
    const auto out = base32_encoding_sse_translate<Base32Alphabet::Default>(t0);

    std::string got;
    got.resize(16);
    _mm_storeu_si128(reinterpret_cast<__m128i*>(got.data()), out);

    const std::string want = "MZXW6YTBOJTG633C";

    if (want != got) {
        printf("want = %s\n", want.c_str());
        printf("got  = %s\n", got.c_str());
        exit(1);
    }
}

int main() {
#define test(name) do {             \
        printf("%s... ", #name);    \
        fflush(stdout);             \
        name();                     \
        puts("OK");                 \
    } while (0)

    test(verify_base32_encoding_sse_translate_default);
    test(verify_base32_encoding_sse_translate_hex);
    test(verify_base32_encoding_sse_expand);
    test(smoke_test);

    return 0;
}
