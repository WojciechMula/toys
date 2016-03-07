#include <cstdio>
#include <cstring>

#include "config.h"
#include "../../bmi2.cpp"

#include "decode.common.cpp"
#include "decode.scalar.cpp"
#include "decode.sse.cpp"

class Test {

    uint8_t input[16];
    uint8_t output[16];
    unsigned bytes;
    unsigned out_size;
    unsigned current;

    uint8_t decode_table[256]; // ASCII -> raw value or 0xff if a value is not valid

public:
    Test(unsigned in_size, unsigned out_size)
        : bytes(in_size)
        , out_size(out_size) {
    
        for (unsigned i=0; i < 256; i++) {
            decode_table[i] = 0xff;
        }

        for (unsigned i=0; i < 64; i++) {
            uint8_t idx = base64::lookup[i];
            decode_table[idx] = i;
        }
    }

public:
    template <typename FN>
    bool run(FN fn) {

        for (current=0; current < bytes; current++) {
            
            clear_input();

            for (unsigned k=0; k < 256; k++) {
                input[current] = k;

                if (decode_table[k] != 0xff) {

                    try {
                        fn(input, bytes, output);
                    } catch (base64::invalid_input& e) {
                        printf("unexpected error: invalid input byte %c (%02x)\n", e.byte, e.byte);
                        return false;
                    }

                    const bool ok = validate_output(decode_table[k]);
                    if (!ok) {
                        return false;
                    }
                } else {
                    try {
                        fn(input, bytes, output);

                        printf("function should return error for invalid input %02x\n", k);
                        dump_input();
                        return false;
                    } catch (base64::invalid_input& e) {
                        
                        if (e.offset != current) {
                            printf("exception field 'offset' is %lu, should be %u\n", e.offset, current);
                            return false;
                        }

                        if (e.byte != k) {
                            printf("exception field 'byte' is %u, should be %u\n", e.byte, k);
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }

private:
    void clear_input() {
        for (unsigned i=0; i < bytes; i++) {
            input[i] = base64::lookup[0];
        }
    }

    bool validate_output(unsigned expected_current) {

        for (unsigned i=0; i < bytes; i++) {

            const uint8_t val = get_6bit_word(i);
            if (i == current) {
                if (val != expected_current) {
                    printf("6-bit field #%d has value %d, expected %d\n", i, val, expected_current);
                    dump_output();
                    return false;
                }
            } else {
                if (val != 0) {
                    printf("6-bit field #%d has value %d, expected to be cleared\n", i, val);
                    dump_output();
                    return false;
                }
            }
        }

        return true;
    }

    void dump_output() {

        for (int i=out_size - 1; i >= 0; i--) {
            printf("%02x", output[i]);
        }

        putchar('\n');
    }

    void dump_input() {

        for (int i=bytes - 1; i >= 0; i--) {
            printf("%02x", input[i]);
        }

        putchar('\n');
    }

    uint8_t get_6bit_word(unsigned i) {

        const unsigned pos   = i * 6;
        const unsigned idx   = pos / 8;
        const unsigned shift = pos % 8;

        if (shift == 0) {
            return output[idx] & 0x3f;
        } else {
            const uint8_t b0 = output[idx];
            const uint8_t b1 = output[idx + 1];

            return ((b0 >> shift) | (b1 << (8 - shift))) & 0x3f;
        }
    }
};


int test() {

    printf("lookup...");
    fflush(stdout);
    {   Test test(4, 3);

        if (test.run(base64::scalar::decode_lookup1)) {
            puts("OK");
        } else {
            return 1;
        }
    }

    printf("four lookups...");
    fflush(stdout);
    {   Test test(4, 3);

        if (test.run(base64::scalar::decode_lookup2)) {
            puts("OK");
        } else {
            return 1;
        }
     }

#if defined(HAVE_BMI2_INSTRUCTIONS)
    printf("lookup (BMI2)...");
    fflush(stdout);
    {   Test test(4, 3);

        if (test.run(base64::scalar::decode_lookup1_bmi2)) {
            puts("OK");
        } else {
            return 1;
        }
     }
#endif

    printf("SSE...");
    fflush(stdout);
    {   Test test(16, 12);

        if (test.run(base64::sse::decode)) {
            puts("OK");
        } else {
            return 1;
        }
     }

    return 0;
}


int main() {

    base64::scalar::prepare_lookup();
    base64::scalar::prepare_lookup32();

    try {
        return test();
    } catch (base64::invalid_input& e) {
        
        printf("invalid input byte %c (%02x)\n", e.byte, e.byte);
        return 2;
    }
}
