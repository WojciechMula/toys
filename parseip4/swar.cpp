#include "swar.h"

#include <cstring>

result swar_ipv4_aux(const uint8_t* s, size_t size, size_t cap);

result swar_parse_ipv4(const std::string& s) {
    return swar_ipv4_aux(
        reinterpret_cast<const uint8_t*>(s.data()),
        s.size(),
        s.capacity());
}

void shift_long(uint64_t& lo, uint64_t& hi, unsigned amount) {
    const uint64_t t0 = lo >> amount;
    const uint64_t t1 = hi << (64 - amount);

    lo = t0 | t1;
    hi = hi >> amount;
}

// convert a 2-digit BCD number
uint32_t cvt2xBCD(uint32_t w) {
    // input : [00|00|b1|b0], where b0 and b1 are bytes in range 0..9
    // output: 10*b0 + b1
#if 0
    const uint8_t b0 = w & 0xff;
    const uint8_t b1 = (w >> 8) & 0xff;
    return b0 * 10 + b1;
#else
    const uint32_t t0 = w * (1 + (10 << 8));
    const uint32_t t1 = t0 >> 8;
    const uint32_t t2 = t1 & 0xff;
    return t2;
#endif
}

// convert a 3-digit BCD number
uint32_t cvt3xBCD(uint32_t w) {
    // input : [00|b2|b1|b0], where b{0,1,2} in range 0..9
    // output: 100*b0 + 10*b1 + b2
#if 0
    const uint32_t b0 = w & 0xff;
    const uint32_t b1 = (w >> 8) & 0xff;
    const uint32_t b2 = (w >> 16) & 0xff;
    return 100*b0 + 10*b1 + b2;
#else
    // calculate a = 100*b0 + b2
    const uint32_t a0 = w & 0x0f000f;
    const uint32_t a1 = a0 * ((1 + (100 << 16)) << 8);  // a spans bits [24:24+10]
    const uint32_t a2 = (a1 >> 24) & 0x3ff;

    // calculate 10*b1
    const uint32_t c0 = w >> (8 - 3);
    const uint32_t c1 = w >> (8 - 1);
    const uint32_t c2 = (c0 + c1) & 0xff;

    return a2 + c2;
#endif
}

result swar_ipv4_aux(const uint8_t* s, size_t size, size_t /*cap*/) {
    result r;
    r.err = 0;

    if (size < 7) {
        r.err = errTooShort;
        return r;
    }

    if (size > 15) {
        r.err = errTooLong;
        return r;
    }

    uint64_t lo = 0;
    uint64_t hi = 0;

    if (size == 7) {
        memcpy(&lo, s, size);
        lo = lo | 0x3000000000000000llu;
        hi = 0x3030303030303030llu;
    } else if (size == 8) {
        memcpy(&lo, s, 8);
        hi = 0x3030303030303030llu;
    } else {
        memcpy(&lo, s, 8);
        memcpy(&hi, s + 8, size - 8);
        hi |= 0x3030303030303030llu << ((size - 8)*8);
    }

    // 0. prevalidate input: reject every byte with higher nibble different than 2 or 3
    //    Now, we're sure inputs are 6-bit characters in form b001x_yyyy, that helps.
    {
        const uint64_t l0 = ((lo | 0x1010101010101010llu) & 0xf0f0f0f0f0f0f0f0llu);
        const uint64_t h0 = ((hi | 0x1010101010101010llu) & 0xf0f0f0f0f0f0f0f0llu);

        if (l0 != 0x3030303030303030llu) {
            r.err = errWrongCharacter;
            return r;
        }
        if (h0 != 0x3030303030303030llu) {
            r.err = errWrongCharacter;
            return r;
        }
    }

    // 2. produce mask for expected digits: 0b0011xxxx => 0b00001111
    uint64_t digitmask_lo;
    uint64_t digitmask_hi;
    {
        const uint64_t l0 = (lo & 0x1010101010101010llu);
        const uint64_t l1 = l0 >> 4;
        const uint64_t l2 = l0 - l1;
        digitmask_lo = l2;

        const uint64_t h0 = (hi & 0x1010101010101010llu);
        const uint64_t h1 = h0 >> 4;
        const uint64_t h2 = h0 - h1;
        digitmask_hi = h2;
    }

    // 3. negation of these maps locates bytes with higher nibble eq 2
    const uint64_t dotmask_lo = (digitmask_lo ^ 0x0f0f0f0f0f0f0f0fllu);
    const uint64_t dotmask_hi = (digitmask_hi ^ 0x0f0f0f0f0f0f0f0fllu);

    // 4. check if we have exactly three dots
    //    in fact we count bytes having the high nibble eq 2, later
    //    on we wil validate if it's really 0x2e ('.')
    {
        const int dots = __builtin_popcountll(dotmask_lo) + __builtin_popcountll(dotmask_hi);
        if (dots != 3*4) {
            if (dots < 3*4) {
                r.err = errTooFewFields;
            } else {
                r.err = errTooManyFields;
            }
            return r;
        }
    }

    // 5. check if the expected location of dots really have dots
    {
        const uint64_t l0 = lo ^ 0x2e2e2e2e2e2e2e2ellu;
        const uint64_t l1 = l0 & dotmask_lo;

        const uint64_t h0 = hi ^ 0x2e2e2e2e2e2e2e2ellu;
        const uint64_t h1 = h0 & dotmask_hi;

        const uint64_t t0 = l1 | h1;
        if (t0 != 0) {
            r.err = errWrongCharacter;
            return r;
        }
    }

    // 6. check if digits are really digits
    {
        const uint64_t l = lo + 0x0606060606060606llu;
        const uint64_t h = hi + 0x0606060606060606llu;

        const uint64_t t0 = (l | h);
        const uint64_t t1 = t0 & 0x4040404040404040llu;

        if (t1 != 0) {
            r.err = errWrongCharacter;
            return r;
        }
    }

    // 7. merge lower nibbles of digits with dot marks
    {
        const uint64_t l0 = (dotmask_lo + dotmask_lo) & 0x1010101010101010llu;
        const uint64_t l1 = lo & digitmask_lo;
        lo = l0 | l1;

        const uint64_t h0 = (dotmask_hi + dotmask_hi) & 0x1010101010101010llu;
        const uint64_t h1 = hi & digitmask_hi;
        hi = h0 | h1;
    }

    // 6. process three fields
    size_t n = size;
    for (int i=0; i < 3; i++) {
        const int pos = __builtin_ctzll(lo & 0x1010101010101010llu);
        switch (pos) {
            case 8*2 - 4: { // 1-digit field
                r.ipv4 <<= 8;
                r.ipv4 |= (lo & 0x0f);
                shift_long(lo, hi, 2*8);
                n -= 2;
                break;
            }

            case 8*3 - 4: { // 2-digits field
                r.ipv4 <<= 8;

                uint32_t x = uint32_t(lo & 0x0f0f);
                if ((x & 0xff) == 0) {
                    r.err = errLeadingZeros;
                    return r;
                }
                r.ipv4 |= uint32_t(cvt2xBCD(x));
                shift_long(lo, hi, 3*8);
                n -= 3;
                break;
            }

            case 8*4 - 4: { // 3-digits field
                r.ipv4 <<= 8;
                uint32_t x = uint32_t(lo & 0x0f0f0f);
                if ((x & 0xff) == 0) {
                    r.err = errLeadingZeros;
                    return r;
                }
                r.ipv4 |= uint32_t(cvt3xBCD(x));
                shift_long(lo, hi, 4*8);
                n -= 4;
                break;

            }

            default:
                r.err = errInvalidInput;
                return r;
        }
    }

    // process 4th field
    if (true) {
        switch (n) {
            case 1: { // 1-digit field
                r.ipv4 <<= 8;
                r.ipv4 |= lo;
                break;
            }

            case 2: { // 2-digits field
                r.ipv4 <<= 8;

                uint32_t x = uint32_t(lo & 0x0f0f);
                if ((x & 0xff) == 0) {
                    r.err = errLeadingZeros;
                    return r;
                }
                r.ipv4 |= uint32_t(cvt2xBCD(x));
                break;
            }

            case 3: { // 3-digits field
                r.ipv4 <<= 8;
                uint32_t x = uint32_t(lo & 0x0f0f0f);
                if ((x & 0xff) == 0) {
                    r.err = errLeadingZeros;
                    return r;
                }
                r.ipv4 |= uint32_t(cvt3xBCD(x));
                break;

            }

            default:
                r.err = errInvalidInput;
                return r;
        }
    }

    r.ipv4 = __builtin_bswap32(r.ipv4);
    return r;
}
