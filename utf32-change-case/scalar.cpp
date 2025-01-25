#include <cstdint>
#include <cstddef>
#include <cassert>

#include "plain.cpp.inl"
#include "compressed.cpp.inl"

#define likely(x)   __builtin_expect(!!(x), 1) 
#define unlikely(x) __builtin_expect(!!(x), 0) 

size_t utf32_uppercase_plain(const uint32_t* input, size_t n, uint32_t* output) {
    size_t j=0;
    for (size_t i=0; i < n; i++) {
        const uint32_t src = input[i];
        if (likely(src <= 0x1'ffff)) {
            const uint32_t dst = UTF32_UPPERCASE_PLAIN[src];
            if (unlikely(int32_t(dst) < 0)) {
                const size_t ofs = dst & 0x1ff;
                switch (dst >> 30) {
                    case 2:
                        output[j++] = UTF32_UPPERCASE_PLAIN_LONG_REPL[ofs + 0];
                        output[j++] = UTF32_UPPERCASE_PLAIN_LONG_REPL[ofs + 1];
                        break;
                    case 3:
                        output[j++] = UTF32_UPPERCASE_PLAIN_LONG_REPL[ofs + 0];
                        output[j++] = UTF32_UPPERCASE_PLAIN_LONG_REPL[ofs + 1];
                        output[j++] = UTF32_UPPERCASE_PLAIN_LONG_REPL[ofs + 2];
                        break;
                    default:
                        assert(false);
                }
            } else {
                output[j++] = dst;
            }
        } else {
            output[j++] = src;
        }
    }

    return j;
}

size_t utf32_lowercase_plain(const uint32_t* input, size_t n, uint32_t* output) {
    size_t j=0;
    for (size_t i=0; i < n; i++) {
        const uint32_t src = input[i];
        if (src <= 0x1'ffff) {
            const uint32_t dst = UTF32_LOWERCASE_PLAIN[src];
            if (int32_t(dst) < 0) {
                // there's exactly one replacement pair for lowercase
                // 'İ' => 'i̇' (2)
                output[j++] = 0x0069;
                output[j++] = 0x0307;
            } else {
                output[j++] = dst;
            }
        } else {
            output[j++] = src;
        }
    }

    return j;
}

size_t utf32_uppercase_compressed(const uint32_t* input, size_t n, uint32_t* output) {
    size_t j=0;
    for (size_t i=0; i < n; i++) {
        const uint32_t src = input[i];
        const uint32_t key = src >> 7; // use higher 10 bits
        if (key < UTF32_UPPERCASE_MAX_HI_BITS) {
            const uint16_t index = UTF32_UPPERCASE_OFFSET[key];
            if (int16_t(index) >= 0) {
                const uint32_t dst = UTF32_UPPERCASE_DATA[index + (src & 0x7f)];
                if (int32_t(dst) < 0) {
                    const size_t ofs = dst & 0x1ff;
                    switch (dst >> 30) {
                        case 2:
                            output[j++] = UTF32_UPPERCASE_PLAIN_LONG_REPL[ofs + 0];
                            output[j++] = UTF32_UPPERCASE_PLAIN_LONG_REPL[ofs + 1];
                            break;
                        case 3:
                            output[j++] = UTF32_UPPERCASE_PLAIN_LONG_REPL[ofs + 0];
                            output[j++] = UTF32_UPPERCASE_PLAIN_LONG_REPL[ofs + 1];
                            output[j++] = UTF32_UPPERCASE_PLAIN_LONG_REPL[ofs + 2];
                            break;
                        default:
                            assert(false);
                        }
                } else {
                    output[j++] = dst;
                }
            } else {
                output[j++] = src;
            }
        } else {
            output[j++] = src;
        }
    }

    return j;
}

size_t utf32_lowercase_compressed(const uint32_t* input, size_t n, uint32_t* output) {
    size_t j=0;
    for (size_t i=0; i < n; i++) {
        const uint32_t src = input[i];
        const uint32_t key = src >> 7; // use higher 10 bits
        if (key < UTF32_LOWERCASE_MAX_HI_BITS) {
            const uint16_t index = UTF32_LOWERCASE_OFFSET[key];
            if (int16_t(index) >= 0) {
                const uint32_t dst = UTF32_LOWERCASE_DATA[index + (src & 0x7f)];
                if (int32_t(dst) < 0) {
                    // there's exactly one replacement pair for lowercase
                    // 'İ' => 'i̇' (2)
                    output[j++] = 0x0069;
                    output[j++] = 0x0307;
                } else {
                    output[j++] = dst;
                }
            } else {
                output[j++] = src;
            }
        } else {
            output[j++] = src;
        }
    }

    return j;
}
