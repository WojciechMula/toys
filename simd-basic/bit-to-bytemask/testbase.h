#include <cstdint>
#include <string>

#include "ansi.cpp"


template <class T, int size>
class TestBase {

protected:
    uint8_t input_vec[size];
    uint8_t input_mask[size];
    uint8_t output[size];
    uint8_t expected_output[size];

protected:
    template <typename FUNCTION>
    void test(const char* name, FUNCTION fun) {
        printf("%-10s: ", name); fflush(stdout);

        for (int x = 0; x < 256; x++) {
            prepare_inputs(x);
            static_cast<T*>(this)->execute(fun);

            if (!validate()) {
                printf("%sfailed%s ", ansi::str::RED, ansi::str::RESET);
                dump(input_vec);
                dump(input_mask);
                dump(output);
                dump(expected_output);
                return;
            }
        }
        printf("%sOK%s\n", ansi::str::GREEN, ansi::str::RESET);
    }

    void prepare_inputs(uint8_t byte) {
        for (size_t i=0; i < size; i++) {
            const uint8_t mask = 1 << (i % 8);

            input_vec[i]  = byte;
            input_mask[i] = mask;
            expected_output[i] = ((byte & mask) == mask) ? 0xff : 0x00;
        }
    }

    bool validate() {
        for (size_t i = 0; i < size; i++) {
            if (output[i] != expected_output[i]) {
                return false;
            }
        }

        return true;
    }

    void dump(uint8_t* arr) {
        putchar('[');
        for (size_t i = 0; i < size; i++) {
            printf(" %02x", arr[i]);
        }

        printf(" ]\n");
    }
};

