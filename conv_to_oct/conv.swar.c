/*
    input: dddcccbbbaaa
           ===2---1===0 <- nibbles

    output: 00000aaa00000bbb00000ccc00000ddd
            -------3-------2-------1-------0 <- bytes
*/

uint32_t expand_12bits_naive(uint32_t x) {
    const uint32_t a = (x & 0x007) << 24;
    const uint32_t b = (x & 0x038) << (16 - 3);
    const uint32_t c = (x & 0x1c0) << (8 - 6);
    const uint32_t d = (x & 0xe00) >> 9;

    return a | b | c | d;
}


// this trick use multiplication to perfom 2 shifts and one bit-or at once
uint32_t expand_12bits_mul(uint32_t x) {

    uint32_t ac = x & 0x1c7; // ac = 000ccc000aaa
    uint32_t bd = x & 0xe38; // bd = ddd000bbb000

    uint32_t expanded_ac = (ac * ((1 << 0) + (1 << 10))) & 0x00070007;
    uint32_t expanded_bd = (bd * ((1 << 5) + (1 << 15))) & 0x07000700;

    return expanded_ac | expanded_bd;
}


uint32_t to_oct_naive(uint32_t x) {
    return expand_12bits_naive(x) + packed32('0');
}


uint32_t to_oct_mul(uint32_t x) {
    return bswap(expand_12bits_mul(x) + packed32('0'));
}
