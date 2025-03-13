#include "sse-dump.h"

__m128i base32_decoding_sse_pack(__m128i in) {
    // 1. pack 5-bit values stored in separate bytes into continuous array of bits
    //
    // in   = [...hhhhh|...ggggg|...fffff|...eeeee||...ddddd|...ccccc|...bbbbb|...aaaaa] x 2
    // want = [........|........|........|ggghhhhh||efffffgg|ddddeeee|bbcccccd|aaaaabbb] x 2

    // t0   = [......gg|ggghhhhh|......ee|eeefffff||......cc|cccddddd|......aa|aaabbbbb] x 2
    const auto t0 = _mm_maddubs_epi16(in, _mm_set1_epi16(0x0120));

    // t1   = [........|....eeee|efffffgg|ggghhhhh||........|aaaaabbb|bbcccccd|dddd....] x 2
    const auto t1 = _mm_madd_epi16(t0, _mm_setr_epi16(
        1 << 14, 1 << 4,
        1 << 10, 1,
        1 << 14, 1 << 4,
        1 << 10, 1
    ));

    // t2   = [........|........|........|........||........|........|........|....eeee] x 2
    const auto t2 = _mm_and_si128(
        _mm_srli_epi64(in, 32 + 1),
        _mm_set1_epi64x(0xf)
    );

    // t3   = [........|....eeee|efffffgg|ggghhhhh||........|aaaaabbb|bbcccccd|ddddeeee] x 2
    const auto t3 = _mm_or_si128(t2, t1);

    // t3   = [........|....eeee|efffffgg|ggghhhhh||........|aaaaabbb|bbcccccd|ddddeeee]
    //                              5        4                  2        1        0
    // t4   = [........|........|........|ggghhhhh||efffffgg|ddddeeee|bbcccccd|aaaaabbb]
    //           0 + 8    1 + 8    2 + 8     4          5       0        1        2

    const auto t4 = _mm_shuffle_epi8(t3, _mm_setr_epi8(
        2, 1, 0, 5, 4,
        2 + 8, 1 + 8, 0 + 8, 5 + 8, 4 + 8,
        -1, -1, -1, -1, -1, -1
    ));
    
    return t4;
}   

struct base32_decoding_translate_t {
    __m128i translated;
    uint16_t errors;
};

template <Base32Alphabet>
base32_decoding_translate_t base32_decoding_sse_translate(__m128i in);

template <>
base32_decoding_translate_t base32_decoding_sse_translate<Base32Alphabet::Default>(__m128i in) {
    /*
        ABCDEFGHIJKLMNOPQRSTUVWXYZ234567
         0..26 => 'A'..'Z' => 65..95
        27..31 => '2'..'7' => 50..55
    */
    const auto l0 = _mm_sub_epi8(in, _mm_set1_epi8(int8_t(128 + 'A')));
    const auto letters = _mm_cmplt_epi8(l0, _mm_set1_epi8(-128 + ('Z' - 'A' + 1)));
    const auto l1 = _mm_sub_epi8(in, _mm_set1_epi8('A'));
    const auto l2 = _mm_and_si128(l1, letters);

    const auto d0 = _mm_sub_epi8(in, _mm_set1_epi8(int8_t(128 + '2')));
    const auto digits = _mm_cmplt_epi8(d0, _mm_set1_epi8(-128 + ('7' - '2' + 1)));
    const auto d1 = _mm_sub_epi8(in, _mm_set1_epi8('2' - 26));
    const auto d2 = _mm_and_si128(d1, digits);

    const auto res = _mm_or_si128(d2, l2);

    const auto e0 = _mm_or_si128(letters, digits);
    const auto e1 = _mm_cmpeq_epi8(e0, _mm_setzero_si128());
    const auto e2 = _mm_or_si128(e1, in);

    const uint16_t errors = _mm_movemask_epi8(e2);

    return {res, errors};
}

template <>
base32_decoding_translate_t base32_decoding_sse_translate<Base32Alphabet::Hex>(__m128i in) {
    /*
        0123456789ABCDEFGHIJKLMNOPQRSTUV
         0.. 9 => '0'..'9' => 48..57
        10..31 => 'A'..'V' => 65..86
    */
    const auto d0 = _mm_sub_epi8(in, _mm_set1_epi8(int8_t(128 + '0')));
    const auto digits = _mm_cmplt_epi8(d0, _mm_set1_epi8(-128 + ('9' - '0' + 1)));
    const auto d1 = _mm_sub_epi8(in, _mm_set1_epi8('0'));
    const auto d2 = _mm_and_si128(d1, digits);

    const auto l0 = _mm_sub_epi8(in, _mm_set1_epi8(int8_t(128 + 'A')));
    const auto letters = _mm_cmplt_epi8(l0, _mm_set1_epi8(-128 + ('V' - 'A' + 1)));
    const auto l1 = _mm_sub_epi8(in, _mm_set1_epi8('A' - 10));
    const auto l2 = _mm_and_si128(l1, letters);

    const auto res = _mm_or_si128(d2, l2);

    const auto e0 = _mm_or_si128(letters, digits);
    const auto e1 = _mm_cmpeq_epi8(e0, _mm_setzero_si128());
    const auto e2 = _mm_or_si128(e1, in);

    const uint16_t errors = _mm_movemask_epi8(e2);

    return {res, errors};
}
