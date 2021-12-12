#pragma once

#ifdef __cplusplus
#   include <cstdio>
#   include <cctype>
#else
#   include <stdio.h>
#   include <ctype.h>
#endif

void dump_epi8(__m512i v) {
    int8_t tmp[64];

    _mm512_storeu_si512((__m512i*)tmp, v);
    for (int i=0; i < 64; i++)
        printf(" %d", tmp[i]);
    printf("\n");
}

void dump_epu8(__m512i v) {
    uint8_t tmp[64];

    _mm512_storeu_si512((__m512i*)tmp, v);
    printf("[ %3u ", tmp[0]);
    for (int i=1; i < 64; i++)
        printf("| %3u", tmp[i]);

    printf(" ]\n");
}

void dump_epu8_hex(__m512i v) {
    uint8_t tmp[64];

    _mm512_storeu_si512((__m512i*)tmp, v);
    printf("[%02x", tmp[0]);
    for (int i=1; i < 64; i++)
        printf(" %02x", tmp[i]);

    printf("]\n");
}

void dump_epu8_ascii(__m512i v) {
    uint8_t tmp[64];

    _mm512_storeu_si512((__m512i*)tmp, v);
    printf("[ %2c ", isprint(tmp[0]) ? tmp[0] : '.');
    for (int i=1; i < 64; i++)
        printf("| %2c ", isprint(tmp[i]) ? tmp[i] : '.');

    printf("]\n");
}

void dump_epu16(__m512i v) {
    uint16_t tmp[32];

    _mm512_storeu_si512((__m512i*)tmp, v);
    printf("[ %5d", tmp[0]);
    for (int i=1; i < 32; i++)
        printf(" | %5d", tmp[i]);

    printf(" ]\n");
}

void dump_epu32(__m512i v) {
    uint32_t tmp[16];

    _mm512_storeu_si512((__m512i*)tmp, v);
    printf("[ %5u", tmp[0]);
    for (int i=1; i < 16; i++)
        printf(" | %5u", tmp[i]);

    printf(" ]\n");
}

void dump_epu16_hex(__m512i v) {
    uint16_t tmp[32];

    _mm512_storeu_si512((__m512i*)tmp, v);
    printf("[ %04x", tmp[0]);
    for (int i=1; i < 32; i++)
        printf(" | %04x", tmp[i]);

    printf(" ]\n");
}

void dump_epu32_hex(__m512i v) {
    uint32_t tmp[16];

    _mm512_storeu_si512((__m512i*)tmp, v);
    printf("[ %08x", tmp[0]);
    for (int i=1; i < 16; i++)
        printf(" | %08x", tmp[i]);

    printf(" ]\n");
}

void dump_mask16(__mmask16 mask, const char* t, const char* f) {
    uint16_t m = mask;
    for (int i=0; i < 16; i++) {
        const uint16_t bit = ((1 << i) & m);
        printf("%s", bit ? t : f);
    }

    printf(" (%02x)\n", m);
}

void dump_mask16(__mmask16 mask) {
    dump_mask16(mask, "1", "0");
}


void dump_mask32(__mmask32 mask, const char* t, const char* f) {
    uint16_t m = mask;
    for (int i=0; i < 32; i++) {
        const uint16_t bit = ((1 << i) & m);
        printf("%s", bit ? t : f);
    }

    printf(" (%02x)\n", m);
}

void dump_mask32(__mmask32 mask) {
    dump_mask32(mask, "1", "0");
}

void print_uint32_revbin(uint32_t x, const char* t, const char* f) {
    for (int i=0; i < 32; i++) {
        const uint16_t bit = ((1 << i) & x);
        printf("%s", bit ? t : f);
    }
    putchar('\n');
}

void print_uint32_revbin(uint32_t x) {
    print_uint32_revbin(x, "1", "0");
}
