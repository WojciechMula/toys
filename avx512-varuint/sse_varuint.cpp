#include "sse_varuint.h"

#include <immintrin.h>


namespace {
    unsigned bytes_count(uint32_t v) {
        if ((v & 0xffffff00) == 0)
            return 1;
        if ((v & 0xffff0000) == 0)
            return 2;
        if ((v & 0xff000000) == 0)
            return 3;
        return 4;
    }
}

void PackedVarUintBuilder::add(uint32_t v) {
    incoming[count] = v;
    count += 1;

    if (count == 4) {
        flush();
        count = 0;
    }
}

std::string PackedVarUintBuilder::capture() {
    if (count > 0) {
        for (int i=count; i < 4; i++) {
            incoming[i] = 0;
        }

        flush();
        count = 0;
    }

    return buffer;
}

void PackedVarUintBuilder::flush() {
    const uint8_t code0 = (bytes_count(incoming[0]) - 1);
    const uint8_t code1 = (bytes_count(incoming[1]) - 1);
    const uint8_t code2 = (bytes_count(incoming[2]) - 1);
    const uint8_t code3 = (bytes_count(incoming[3]) - 1);

    const uint8_t code = code0 | (code1 << 2) | (code2 << 4) | (code3 << 6);

    buffer.push_back(code);

    for (int i=0; i < 4; i++) {
        const uint32_t v = incoming[i];
        switch (bytes_count(v)) {
            case 1:
                buffer.push_back((v >> 0*8) & 0xff);
                break;
            case 2:
                buffer.push_back((v >> 0*8) & 0xff);
                buffer.push_back((v >> 1*8) & 0xff);
                break;
            case 3:
                buffer.push_back((v >> 0*8) & 0xff);
                buffer.push_back((v >> 1*8) & 0xff);
                buffer.push_back((v >> 2*8) & 0xff);
                break;
            case 4:
                buffer.push_back((v >> 0*8) & 0xff);
                buffer.push_back((v >> 1*8) & 0xff);
                buffer.push_back((v >> 2*8) & 0xff);
                buffer.push_back((v >> 3*8) & 0xff);
                break;
        }
    }
}

void unsafe_unpack(const std::string& buf, size_t count, uint32_t* output) {
    size_t j = 0;
    size_t i = 0;

    while (i < count) {
        const uint8_t code = buf[j];
        j += 1;
        const uint8_t code0 = (code >> 0*2) & 0x3;
        const uint8_t code1 = (code >> 1*2) & 0x3;
        const uint8_t code2 = (code >> 2*2) & 0x3;
        const uint8_t code3 = (code >> 3*2) & 0x3;

        auto decode = [&buf, &j](const uint32_t code) {
            uint32_t v{0};
            switch (code) {
                case 0:
                    v = uint32_t(uint8_t(buf[j + 0]));
                    j += 1;
                    break;
                case 1:
                    v = (uint32_t(uint8_t(buf[j + 0])) << (0*8))
                      | (uint32_t(uint8_t(buf[j + 1])) << (1*8));
                    j += 2;
                    break;
                case 2:
                    v = (uint32_t(uint8_t(buf[j + 0])) << (0*8))
                      | (uint32_t(uint8_t(buf[j + 1])) << (1*8))
                      | (uint32_t(uint8_t(buf[j + 2])) << (2*8));
                    j += 3;
                    break;
                case 3:
                    v = (uint32_t(uint8_t(buf[j + 0])) << (0*8))
                      | (uint32_t(uint8_t(buf[j + 1])) << (1*8))
                      | (uint32_t(uint8_t(buf[j + 2])) << (2*8))
                      | (uint32_t(uint8_t(buf[j + 3])) << (3*8));
                    j += 4;
                    break;
            }

            return v;
        };

        output[i++] = decode(code0);
        output[i++] = decode(code1);
        output[i++] = decode(code2);
        output[i++] = decode(code3);
    }
}

#include "sse_varuint.incl.cpp"

void sse_unsafe_unpack(const std::string& buf, size_t count, uint32_t* output) {
    size_t j = 0;
    size_t i = 0;

    while (i < count) {
        const uint8_t code = buf[j];

        const __m128i input    = _mm_loadu_si128((const __m128i*)(&buf[j + 1]));
        const __m128i shuffle  = _mm_loadu_si128((const __m128i*)(&shuffle_patterns[code][0]));
        const __m128i expanded = _mm_shuffle_epi8(input, shuffle);
        j += 1 + input_lengths[code];

        _mm_storeu_si128((__m128i*)(&output[i]), expanded);
        i += 4;
    }
}
