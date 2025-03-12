#include <cstdio>
#include <cstdint>
#include <immintrin.h>
#include "common.h"

__m128i base32_encoding_sse_expand(__m128i in) {
    // 1. expand 2x5 bytes into 2x8 lanes
    //
    // in = [00000000|00000000|00000000|ggghhhhh||efffffgg|ddddeeee|bbcccccd|aaaaabbb] x 2
    //                                     4         3        2        1        0
    //
    // t0 = [efffffgg|ggghhhhh|ddddeeee|efffffgg||bbcccccd|ddddeeee|aaaaabbb|bbcccccd]
    //          3        4        2         3        1        2        0        1

    const auto t0 = _mm_shuffle_epi8(in, _mm_setr_epi8(
        1, 0, 2, 1, 3, 2, 4, 3,
        1 + 5, 0 + 5, 2 + 5, 1 + 5, 3 + 5, 2 + 5, 4 + 5, 3 + 5
    ));

    // t1 = [......gg|ggg.....|....eeee|e.......||..ccccc.|........|aaaaa...|........]
    const auto t1 = _mm_and_si128(t0, _mm_setr_epi16(
        int16_t(uint16_t(0x1f) << 11),
        int16_t(uint16_t(0x1f) << 9),
        int16_t(uint16_t(0x1f) << 7),
        int16_t(uint16_t(0x1f) << 5),
        int16_t(uint16_t(0x1f) << 11),
        int16_t(uint16_t(0x1f) << 9),
        int16_t(uint16_t(0x1f) << 7),
        int16_t(uint16_t(0x1f) << 5)
    ));

    // t2 = [........|...ggggg|........|...eeeee||........|...ccccc|........|...aaaaa]
    const auto t2 = _mm_mulhi_epu16(t1, _mm_setr_epi16(
        int16_t(1 << 5),
        int16_t(1 << (5 + 2)),
        int16_t(1 << (5 + 4)),
        int16_t(1 << (5 + 6)),
        int16_t(1 << 5),
        int16_t(1 << (5 + 2)),
        int16_t(1 << (5 + 4)),
        int16_t(1 << (5 + 6))
    ));

    // t3 = [........|...hhhhh|........|.fffff..||.......d|dddd....|.....bbb|bb......]
    const auto t3 = _mm_and_si128(t0, _mm_setr_epi16(
        int16_t(uint16_t(0x1f) << 6),
        int16_t(uint16_t(0x1f) << 4),
        int16_t(uint16_t(0x1f) << 2),
        int16_t(uint16_t(0x1f) << 0),
        int16_t(uint16_t(0x1f) << 6),
        int16_t(uint16_t(0x1f) << 4),
        int16_t(uint16_t(0x1f) << 2),
        int16_t(uint16_t(0x1f) << 0)
    ));

    // t4 = [...hhhhh|........|...fffff|........||...ddddd|........|...bbbbb|........]
    const auto t4 = _mm_mullo_epi16(t3, _mm_setr_epi16(
        int16_t(1 << 2),
        int16_t(1 << 4),
        int16_t(1 << 6),
        int16_t(1 << 8),
        int16_t(1 << 2),
        int16_t(1 << 4),
        int16_t(1 << 6),
        int16_t(1 << 8)
    ));

    return _mm_or_si128(t4, t2);
}

template <Base32Alphabet>
__m128i base32_encoding_sse_translate(__m128i in);

template <>
__m128i base32_encoding_sse_translate<Base32Alphabet::Default>(__m128i in) {
    /*
        ABCDEFGHIJKLMNOPQRSTUVWXYZ234567
         0..26 => 'A'..'Z' => 65..95
        27..31 => '2'..'7' => 50..55
    */

    const auto letters = _mm_cmplt_epi8(in, _mm_set1_epi8(26));

    const auto shift   = _mm_blendv_epi8(
        _mm_set1_epi8('2' - 26),
        _mm_set1_epi8('A'),
        letters
    );

    // in[i] = in[i] < 27 ? in[i] + 'A' : in[i] - 27 + '2'
    return _mm_add_epi8(in, shift);
}

template <>
__m128i base32_encoding_sse_translate<Base32Alphabet::Hex>(__m128i in) {
    /*
        0123456789ABCDEFGHIJKLMNOPQRSTUV
         0.. 9 => '0'..'9' => 48..57
        10..31 => 'A'..'V' => 65..86
    */

    const auto digits = _mm_cmplt_epi8(in, _mm_set1_epi8(10));

    const auto shift   = _mm_blendv_epi8(
        _mm_set1_epi8('A' - 10),
        _mm_set1_epi8('0'),
        digits
    );

    // in[i] = in[i] < 27 ? in[i] + 'A' : in[i] - 27 + '2'
    return _mm_add_epi8(in, shift);
}
