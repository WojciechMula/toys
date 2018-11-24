#include <cstdint>
#include <string>

#include "ansi.cpp"


template <class T, int size>
class TestBase {

protected:
    const uint8_t byte = 0xab;
    uint8_t output[size];

protected:
    template <typename FUNCTION>
    void test(const char* name, FUNCTION fun) {
        printf("%-10s: ", name); fflush(stdout);

        static_cast<T*>(this)->execute(fun);

        if (validate()) {
            printf("%sOK%s\n", ansi::str::GREEN, ansi::str::RESET);
        } else {
            printf("%sfailed%s ", ansi::str::RED, ansi::str::RESET);
            dump(output);
        }
    }

    bool validate() {
        for (size_t i = 0; i < size; i++) {
            if (output[i] != byte) {
                return false;
            }
        }

        return true;
    }

    void dump(uint8_t* arr) {
        putchar('[');
        for (size_t i = 0; i < size; i++) {
            printf(" %u", arr[i]);
        }

        printf(" ]\n");
    }
};

