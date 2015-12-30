#include <cstddef>
#include <cstdint>
#include <cctype>

namespace scalar {

    void to_lower_inplace(char* s, size_t n) {

        for (size_t j=0; j < n; j++) {

            if (s[j] >= 'A' && s[j] <= 'Z') {

                s[j] ^= (1 << 5);
            } else if (static_cast<unsigned char>(s[j]) >= '\x7f') {

                s[j] = tolower(s[j]);
            }
        }
    }

} // namespace scalar


namespace swar {

    #define packed_byte(b) ((uint64_t(b) & 0xff) * 0x0101010101010101u)

    bool is_ascii(uint64_t chars) {

        return (chars & packed_byte(0x80)) == 0;
    }

    uint64_t to_lower_ascii_mask(uint64_t chars) {

        // assert(is_ascii(chars))
        // Note: MSBs are used here as boolean flags

        const uint64_t A = chars + packed_byte(128 - 'A');        // MSB[i] is set if chars[i] is greater or equal than 'A'
        const uint64_t Z = chars + packed_byte(128 - 'Z' - 1);    // MSB[i] is set if chars[i] is greater than 'Z'

        // Now relation 'A' <= chars[i] <= 'Z' is repesented as A & ~Z.
        // However, it's not possible that MSB_A[i] is true and MSB_B[i] is false.
        // Thanks to that expression could be simplified to A ^ Z

        return (A ^ Z) & packed_byte(0x80);
    }

    uint64_t to_lower_ascii(uint64_t chars) {

        const uint64_t mask = to_lower_ascii_mask(chars) >> 2; // change case (toggle 5th bit)
        const uint64_t result =  chars ^ mask;

        return result;
    }


    void to_lower_inplace(char* str, size_t n) {

        char* s = str;

        {
            const size_t k = n / 8;
            for (size_t i=0; i < k; i++, s+=8) {

                uint64_t* chunk = reinterpret_cast<uint64_t*>(s);

                if (is_ascii(*chunk)) {

                    *chunk = to_lower_ascii(*chunk);
                } else {

                    scalar::to_lower_inplace(s, 8);
                }
            }
        }

        {
            const size_t k = n % 8;

            if (k) {
                scalar::to_lower_inplace(s, k);
            }
        }
    }

} // namespace swar

