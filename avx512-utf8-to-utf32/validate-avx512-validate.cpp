#include <cstdint>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>

#include "avx512-utf8-validate.h"


class Test {
    static constexpr int length = 5;
    struct Testcase {
        std::string bytes; // always `length` bytes
        bool valid;
    };

    std::vector<Testcase> testcases;
    std::string ascii;

public:
    Test() : ascii{"????????????????????????????????"} {
        prepare_testcases();
    }

    bool run() {
        bool ret = true;

        ret = test() and ret;

        if (ret)
            puts("All OK");

        return ret;
    }

private:
    bool test() {
        std::string str;
        for (int position=0; position < 16; position++) {
            str = ascii;
            for (size_t i=0; i < testcases.size(); i++) {
                // given
                const auto& tc = testcases[i];
                for (size_t j=0; j < length; j++)
                    str[position + j] = tc.bytes[j];

                // when
                uint16_t leading_bytes{0};
                uint16_t valid_chars{0};

                avx512_utf8_structure_validate_16_bytes(&str[0], leading_bytes, valid_chars);

                // then
                const uint16_t position_bit = (1 << position);
                bool pass = false;
                if (tc.valid) {
                    pass = (bool(leading_bytes & valid_chars & position_bit) == true);
                } else {
                    pass = (bool(leading_bytes & valid_chars & position_bit) == false);
                }

                if (not pass) {
                    dump(str, leading_bytes, valid_chars, position_bit);
                    printf("case #%ld: failed at vector word %d (valid=%s)\n", i, position, tc.valid ? "true" : "false");
                    printf("leading_bytes = %04x\n", leading_bytes);
                    printf("valid_chars   = %04x\n", valid_chars);
                    printf("position_bit  = %04x\n", position_bit);
                    return false;
                }
            }
        }

        return true;
    }

    void prepare_testcases() {
        constexpr int characters = 5;
        static const char bytes[characters]{'A', '\xc0', '\xe0', '\xf0', '\x80'};
        int counters[length];
        for (int i=0; i < length; i++)
            counters[i] = 0;

        std::string image;
        image.resize(length);
        while (true) {
            for (int i=0; i < length; i++) {
                image[i] = bytes[counters[i]];
            }

            Testcase tc;
            tc.bytes = image;
            tc.valid = is_valid_utf8_char(image);
            testcases.push_back(std::move(tc));

            int carry = 1;
            for (int i=0; i < length && carry == 1; i++) {
                counters[i] += carry;
                carry = int(counters[i] == characters);
                if (carry)
                    counters[i] = 0;
            }

            if (carry)
                break;
        }
    }

    enum class ByteType {
        ASCII,
        Leading_2_bytes,
        Leading_3_bytes,
        Leading_4_bytes,
        Continuation,
    };

    ByteType type(char b) const {
        const uint8_t byte = b;

        if ((byte & 0xc0) == 0x80)
            return ByteType::Continuation;

        if ((byte & 0xe0) == 0xc0)
            return ByteType::Leading_2_bytes;

        if ((byte & 0xf0) == 0xe0)
            return ByteType::Leading_3_bytes;

        if ((byte & 0xf8) == 0xf0)
            return ByteType::Leading_4_bytes;

        return ByteType::ASCII;
    }

    bool is_continuation(char b) const {
        return type(b) == ByteType::Continuation;
    }

    bool is_leading(char b) const {
        return not is_continuation(b);
    }

    bool is_valid_utf8_char(const std::string& bytes) const {
        assert(bytes.size() >= 5);

        switch (type(bytes[0])) {
            case ByteType::ASCII:
                return is_leading(bytes[1]);

            case ByteType::Leading_2_bytes:
                return is_continuation(bytes[1]) and
                       is_leading(bytes[2]);

            case ByteType::Leading_3_bytes:
                return is_continuation(bytes[1]) and
                       is_continuation(bytes[2]) and
                       is_leading(bytes[3]);

            case ByteType::Leading_4_bytes:
                return is_continuation(bytes[1]) and
                       is_continuation(bytes[2]) and
                       is_continuation(bytes[3]) and
                       is_leading(bytes[4]);

            default:
                return false;
        }

        return false;
    }

    void dump(const std::string v, uint16_t leading_bytes, uint16_t valid_chars, uint16_t position_bit) {
        dumphex(v);
        underline(position_bit, '^', ' ');
        underline(leading_bytes, 'L', 'c');
        underline(valid_chars, 'V', ' ');
    }

    void dumphex(const std::string v) {
        for (size_t i=0; i < v.size(); i++) {
            const uint8_t byte = v[i];
            if (i > 0) putchar(' ');
            printf("%02x", byte);
        }

        putchar('\n');

    }

    void underline(uint16_t mask, char t, char f) {
        for (int i=0; i < 16; i++) {
            if (mask & (1 << i)) {
                putchar(t);
            } else {
                putchar(f);
            }
            putchar(' ');
            putchar(' ');
        }

        putchar('\n');
    }
};

int main() {
    Test test;
    return test.run() ? EXIT_SUCCESS : EXIT_FAILURE;
}
