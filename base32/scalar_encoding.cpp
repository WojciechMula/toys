template <Base32Alphabet alhabet>
size_t base32_encoding(const uint8_t* data, size_t size, char* output) {
    if (size == 0) {
        return 0;
    }

    const char* base32 = (alhabet == Base32Alphabet::Default)
        ? base32_alphabet
        : base32_hex_alphabet;

    char* buf = output;
    size_t i=0;
    for (/**/; i + 5 < size; i += 5) {
        // 40 bits = 5 bytes of data
        uint64_t packed = (uint64_t(data[i + 4]) << 0*8)
                        | (uint64_t(data[i + 3]) << 1*8)
                        | (uint64_t(data[i + 2]) << 2*8)
                        | (uint64_t(data[i + 1]) << 3*8)
                        | (uint64_t(data[i + 0]) << 4*8);

        for (int field=0; field < 8; field++) {
            *buf++ = base32[(packed >> (40 - 5)) & 0x1f];
            packed <<= 5;
        }
    }

    if (output + size != buf) {
        uint64_t packed = 0;
        int pos = 0;
        for (/**/; i < size; i++) {
            packed |= uint64_t(data[i]) << pos;
            pos += 8;
        }

        packed = __builtin_bswap64(packed);

        while (pos > 0) {
            *buf++ = base32[(packed >> (64 - 5)) & 0x1f];
            packed <<= 5;
            pos -= 5;
        }
    }

    const size_t written = buf - output;
    size_t pad = 8 - written % 8;
    if (pad < 8) {
        while (pad--) {
            *buf++ = '=';
        }
    }

    return buf - output;
}
