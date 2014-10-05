uint32_t lookup_nibble0_1[256]; // 1kiB
uint32_t lookup_nibble2[16];    // & 64B


void prepare_two_lookups() {
    for (uint32_t i=0; i < 256; i++) {
        lookup_nibble0_1[i] = expand_12bits_naive(i);
    }

    for (uint32_t i=0; i < 16; i++) {
        lookup_nibble2[i] = expand_12bits_naive(i << 8);
    }
}


uint32_t to_oct_two_lookups(uint16_t x) {

    const uint32_t expanded = lookup_nibble0_1[x & 0xff] | lookup_nibble2[(x >> 8) & 0xf];

    return expanded + packed32('0');
}
