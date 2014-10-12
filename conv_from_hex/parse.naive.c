/*
    Convert 4 hex digits [0-9a-fA-F] to number
*/
uint32_t parse_naive(char* str) {

    assert(strlen(str) >= 4);

    const uint32_t input  = *reinterpret_cast<uint32_t*>(str);

    // 1. to ASCII
    const uint32_t letter = input & packed32(0x40);
    const uint32_t shift  = letter >> 3 | letter >> 6; // 9 if char ~ [a-fA-F], 0 otherwise

    const uint32_t adjusted   = input + shift;

    // 2. merge nibbles
    const uint32_t t1 = (adjusted >> 4) | adjusted;

    return (t1 & 0xff) | (((t1 >> 16) & 0xff) << 8);
}
