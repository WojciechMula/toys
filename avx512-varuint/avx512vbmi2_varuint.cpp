#include "avx512vbmi2_varuint.h"

#include <immintrin.h>
#include "byte_buffer.h"


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

    uint8_t encode_nibble(uint32_t v0, uint32_t v1) {
        const uint8_t code0 = bytes_count(v0) - 1;
        const uint8_t code1 = bytes_count(v1) - 1;

        return code0 | (code1 << 2);
    }
}

void Packed16VarUintBuilder::add(uint32_t v) {
    incoming[count] = v;
    count += 1;

    if (count == 16) {
        flush();
        count = 0;
    }
}

std::string Packed16VarUintBuilder::capture() {
    if (count > 0) {
        for (int i=count; i < 16; i++) {
            incoming[i] = 0;
        }

        flush();
        count = 0;
    }

    return buffer;
}

void Packed16VarUintBuilder::flush() {
    uint32_t lo_nibbles = 0;
    uint32_t hi_nibbles = 0;

    lo_nibbles |= encode_nibble(incoming[0], incoming[1]) << (0*8);
    lo_nibbles |= encode_nibble(incoming[2], incoming[3]) << (1*8);
    lo_nibbles |= encode_nibble(incoming[4], incoming[5]) << (2*8);
    lo_nibbles |= encode_nibble(incoming[6], incoming[7]) << (3*8);

    hi_nibbles |= encode_nibble(incoming[8] , incoming[9])  << (0*8 + 4);
    hi_nibbles |= encode_nibble(incoming[10], incoming[11]) << (1*8 + 4);
    hi_nibbles |= encode_nibble(incoming[12], incoming[13]) << (2*8 + 4);
    hi_nibbles |= encode_nibble(incoming[14], incoming[15]) << (3*8 + 4);

    const uint32_t codewords = lo_nibbles | hi_nibbles;

    append_4bytes(buffer, codewords);

    for (int i=0; i < 16; i++) {
        const uint32_t v = incoming[i];
        switch (bytes_count(v)) {
            case 1:
                append_byte(buffer, v);
                break;
            case 2:
                append_2bytes(buffer, v);
                break;
            case 3:
                append_3bytes(buffer, v);
                break;
            case 4:
                append_4bytes(buffer, v);
                break;
        }
    }
}

void unsafe_unpack16(const std::string& buf, size_t count, uint32_t* output) {
    size_t j = 0;
    size_t i = 0;

    while (i < count) {
        const uint32_t codewords = unsafe_read_4bytes(buf, j);
        j += 4;

        const uint64_t lo_nibbles = codewords & 0x0f0f0f0f;
        const uint64_t hi_nibbles = codewords & 0xf0f0f0f0;

        uint64_t nibbles = lo_nibbles | (hi_nibbles << 28);

        auto decode = [&buf, &j](const uint32_t code) {
            uint32_t v{0};
            switch (code) {
                case 0:
                    v = unsafe_read_byte(buf, j);
                    j += 1;
                    break;
                case 1:
                    v = unsafe_read_2bytes(buf, j);
                    j += 2;
                    break;
                case 2:
                    v = unsafe_read_3bytes(buf, j);
                    j += 3;
                    break;
                case 3:
                    v = unsafe_read_4bytes(buf, j);
                    j += 4;
                    break;
            }

            return v;
        };

        for (int k=0; k < 8; k++) {
            uint8_t code0 = (nibbles & 0x03);
            uint8_t code1 = ((nibbles >> 2) & 0x03);
            nibbles >>= 8;

            output[i++] = decode(code0);
            output[i++] = decode(code1);
        }
    }
}

#ifdef __AVX512VBMI2__
void avx512vbmi2_unsafe_unpack16(const std::string& buf, size_t count, uint32_t* output) {
    size_t j = 0;
    size_t i = 0;

    const __m128i masks = _mm_setr_epi8(
        /* 00_00 */ 0x11,
        /* 00_01 */ 0x13,
        /* 00_10 */ 0x17,
        /* 00_11 */ 0x1f,
        /* 01_00 */ 0x31,
        /* 01_01 */ 0x33,
        /* 01_10 */ 0x37,
        /* 01_11 */ 0x3f,
        /* 10_00 */ 0x71,
        /* 10_01 */ 0x73,
        /* 10_10 */ 0x77,
        /* 10_11 */ 0x7f,
        /* 11_00 */ char(0xf1),
        /* 11_01 */ char(0xf3),
        /* 11_10 */ char(0xf7),
        /* 11_11 */ char(0xff)
    );

    while (i < count) {
        const uint32_t codewords = unsafe_read_4bytes(buf, j);

        const uint64_t lo_nibbles = codewords & 0x0f0f0f0f;
        const uint64_t hi_nibbles = codewords & 0xf0f0f0f0;

        const uint64_t nibbles = lo_nibbles | (hi_nibbles << 28);

        const __m128i t0       = _mm_cvtsi64x_si128(nibbles);
        const __m128i v_mask   = _mm_shuffle_epi8(masks, t0);
        const __mmask64 mask   = _mm_cvtsi128_si64x(v_mask);

        const __m512i input    = _mm512_loadu_si512((const __m512*)(&buf[j + 4]));
        const __m512i expanded = _mm512_maskz_expand_epi8(mask, input);
        j += 4 + __builtin_popcountll(mask);

        _mm512_storeu_si512((__m512i*)(&output[i]), expanded);
        i += 16;
    }
}
#endif
