#include "reference.h"

#include <cstdint>
#include <cassert>

namespace {
    bool is_continuation(uint8_t b) {
        return (b & 0xc0) == 0x80;
    }
}

// Algorithm 1 from "Validating UTF-8 In Less Than One Instruction Per Byte"
// by Daniel Lemire and John Keiser --- https://arxiv.org/abs/2010.03090
Error scalar_validate_utf8_char(const char* bytes, int& length) {
    const uint8_t byte = *bytes;
    if ((byte & 0x80) == 0) {
        // ASCII
        length = 1;
        return Error::no_error;
    }

    // 2-byte chars
    if ((byte & 0xe0) == 0xc0) {
        if (byte < 0xc2)
            return Error::wrong_first_byte;

        if (not is_continuation(bytes[1]))
            return Error::not_continuation_1;

        length = 2;
        return Error::no_error;
    }

    // 3-byte chars
    if ((byte & 0xf0) == 0xe0) {
        if (not is_continuation(bytes[1]))
            return Error::not_continuation_1;
        if (not is_continuation(bytes[2]))
            return Error::not_continuation_2;

        const uint8_t c1 = bytes[1] & 0x3f;
        switch (byte & 0xf) {
            case 0x0:
                if (c1 <= 0x1f) // disallowed range 0b00_0000 .. 0b01_1111
                    return Error::overlong;
                break;

            case 0xd:
                if (c1 >= 0x20)  // disallowed range 0b10_0000 .. 0b11_1111
                    return Error::surrogate;
                break;

            default:
                break;
        }

        length = 3;
        return Error::no_error;
    }

    // 4-byte chars
    if ((byte & 0xf0) == 0xf0) {
        if (not is_continuation(bytes[1]))
            return Error::not_continuation_1;
        if (not is_continuation(bytes[2]))
            return Error::not_continuation_2;
        if (not is_continuation(bytes[3]))
            return Error::not_continuation_3;

        const uint8_t c1 = bytes[1] & 0x3f;
        switch (byte & 0x0f) {
            case 0x0:
                if (c1 <= 0x0f) // disallowed range 0b00_0000 ... 0b00_1111
                    return Error::overlong;
                break;

            case 0x1:
            case 0x2:
            case 0x3:
                break;

            case 0x4:
                if (c1 > 0x0f) // disallowed range 0b01_0000 ... 0b11_1111
                    return Error::too_large;
                break;

            case 0x5:
            case 0x6:
            case 0x7:
                // Bytes 0x1111_1xxx are not allowed at all, but we tested only
                // a single nibble, not the five top bits. Thus these extra
                // cases.
            case 0x8: case 0x9: case 0xa:
            case 0xb: case 0xc: case 0xd:
            case 0xe: case 0xf:
                return Error::wrong_first_byte;
        }

        length = 4;
        return Error::no_error;
    }

    if ((byte & 0xc0) == 0x80) {
        return Error::unexpected_continuation;
    }

    assert(false && "must not reach this point");
    return Error::assertion;
}

Error scalar_validate_utf8(const char* ptr, size_t size) {
    const char* end = ptr + size;

    int length = 0;
    while (ptr < end) {
        const auto err = scalar_validate_utf8_char(ptr, length);
        if (err != Error::no_error)
            return err;

        ptr += length;
    }

    return Error::no_error;
}

bool scalar_validate_utf8_simple(const char* bytes, size_t size) {
    return scalar_validate_utf8(bytes, size) == Error::no_error;
}
