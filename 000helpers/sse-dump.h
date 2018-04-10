#pragma once

#include <immintrin.h>

#include <cstdio>
#include <cstdint>
#include <cctype>

void dump_epi8(__m128i v) {
    int8_t tmp[16];

    _mm_storeu_si128((__m128i*)tmp, v);
    printf("[ %4d ", tmp[0]);
    for (int i=1; i < 16; i++)
        printf("| %4d ", tmp[i]);

    printf(" ]\n");
}

void dump_epi16(__m128i v) {
    int16_t tmp[8];

    _mm_storeu_si128((__m128i*)tmp, v);
    printf("[ %6d ", tmp[0]);
    for (int i=1; i < 8; i++)
        printf("| %6d ", tmp[i]);

    printf(" ]\n");
}

void dump_epi32(__m128i v) {
    int32_t tmp[4];

    _mm_storeu_si128((__m128i*)tmp, v);
    printf("[ %6d ", tmp[0]);
    for (int i=1; i < 4; i++)
        printf("| %12d ", tmp[i]);

    printf(" ]\n");
}

void dump_epu8_hex(__m128i v) {
    uint8_t tmp[16];

    _mm_storeu_si128((__m128i*)tmp, v);
    printf("[ %02x", tmp[0]);
    for (int i=1; i < 16; i++)
        printf(" | %02x", tmp[i]);

    printf(" ]\n");
}

void dump_epu32_hex(__m128i v) {
    uint32_t tmp[4];

    _mm_storeu_si128((__m128i*)tmp, v);
    printf("[ %02x", tmp[0]);
    for (int i=1; i < 4; i++)
        printf(" | %08x", tmp[i]);

    printf(" ]\n");
}

void dump_epu8_ascii(__m128i v) {
    uint8_t tmp[16];

    _mm_storeu_si128((__m128i*)tmp, v);
    printf("[ %2c ", isprint(tmp[0]) ? tmp[0] : '.');
    for (int i=1; i < 16; i++)
        printf("| %2c ", isprint(tmp[i]) ? tmp[i] : '.');

    printf("]\n");
}
