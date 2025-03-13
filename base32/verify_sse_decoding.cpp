#include <cstdio>
#include <cstdint>
#include <cassert>
#include <string>
#include <immintrin.h>
#include "common.h"

#include "sse_decoding.cpp"

template <Base32Alphabet alphabet>
void base32_decoding_translate_aux(const char* base32) {
    uint8_t all[256];
    for (size_t i=0; i < sizeof(all); i++) {
        all[i] = 0xff;
    }

    for (int i=0; i < 32; i++) {
        const uint8_t idx = base32[i];
        all[idx] = i;
    }

    for (int i=0; i < 256; i++) {
        const auto in  = _mm_set1_epi8(i);
        const auto res = base32_decoding_sse_translate<alphabet>(in);

        if (all[i] == 0xff) {
            const uint16_t want_mask = 0xffff;
            if (res.errors != want_mask) {
                printf("code = 0x%02x ('%c')\n", i, i);
                printf("want = 0x%04x\n", want_mask);
                printf("got  = 0x%04x\n", res.errors);
                exit(1);
            }
        } else {
            const uint16_t want_mask = 0x0000;
            if (res.errors != want_mask) {
                printf("code = 0x%02x ('%c')\n", i, i);
                printf("want = 0x%04x\n", want_mask);
                printf("got  = 0x%04x\n", res.errors);
                exit(1);
            }

            const uint8_t want = all[i];
            const uint8_t got = _mm_extract_epi8(res.translated, 0);
            if (got != want) {
                printf("code = 0x%02x ('%c')\n", i, i);
                printf("want = 0x%04x\n", want);
                printf("got  = 0x%04x\n", got);
                exit(1);
            }
        }
    }
}

void base32_decoding_translate_default() {
    base32_decoding_translate_aux<Base32Alphabet::Default>(base32_alphabet);
}

void base32_decoding_translate_hex() {
    base32_decoding_translate_aux<Base32Alphabet::Hex>(base32_hex_alphabet);
}

void smoke_test() {
    const char* input = "MZXW6YTBOJTG633C";

    const auto in  = _mm_loadu_si128(reinterpret_cast<const __m128i*>(input));
    const auto t0  = base32_decoding_sse_translate<Base32Alphabet::Default>(in);
    const auto out = base32_decoding_sse_pack(t0.translated);

    std::string got;
    got.resize(16);
    _mm_storeu_si128(reinterpret_cast<__m128i*>(got.data()), out);
    got.resize(10);

    const std::string want = "foobarfoob";

    if (want != got) {
        puts("");
        printf("want = '%s'\n", want.c_str());
        printf("got  = '%s'\n", got.c_str());
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

    test(base32_decoding_translate_default);
    test(base32_decoding_translate_hex);
    test(smoke_test);

    return 0;
}
