uint32_t to_oct_pdep(uint32_t x) {
    const uint32_t result = pdep(x, 0x07070707);

    return bswap(result + packed32('0'));
}

