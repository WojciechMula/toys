#pragma once

#include <cstdio>
#include <cctype>

void dump_epi8(__m512i v) {
    int8_t tmp[64];

    _mm512_storeu_si512((__m512i*)tmp, v);
    printf("[ %4d ", tmp[0]);
    for (int i=1; i < 64; i++)
        printf("| %4d", tmp[i]);

    printf(" ]\n");
}

void dump_epu8_hex(__m512i v) {
    uint8_t tmp[64];

    _mm512_storeu_si512((__m512i*)tmp, v);
    printf("[ %02x", tmp[0]);
    for (int i=1; i < 64; i++)
        printf(" | %02x", tmp[i]);

    printf(" ]\n");
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

void dump_epu16_hex(__m512i v) {
    uint16_t tmp[32];

    _mm512_storeu_si512((__m512i*)tmp, v);
    printf("[ %04x", tmp[0]);
    for (int i=1; i < 32; i++)
        printf(" | %04x", tmp[i]);

    printf(" ]\n");
}
