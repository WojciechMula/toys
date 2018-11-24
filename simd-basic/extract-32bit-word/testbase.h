#include <cstdint>
#include <cassert>
#include <string>

#include "ansi.cpp"


template <class T, int size>
class TestBase {

protected:
    uint8_t  input[size];
    int      index;
    uint32_t output;

protected:
    template <typename FUNCTION>
    void test(const char* name, FUNCTION fun) {
        printf("%-10s: ", name); fflush(stdout);

        for (index = 0; index <= size - 4; index++) {

            prepare();

            static_cast<T*>(this)->execute(fun);

            if (!validate()) {
                printf("%sfailed%s", ansi::str::RED, ansi::str::RESET);
                printf(" index = %d output = 0x%08x ", index, output);
                dump(input);
                putchar('\n');
                return;
            }
        }

        printf("%sOK%s\n", ansi::str::GREEN, ansi::str::RESET);
    }

    void prepare() {
        for (size_t i = 0; i < size; i++) {
            input[i] = 0;
        }

        input[index + 0] = 0x11;
        input[index + 1] = 0x22;
        input[index + 2] = 0x33;
        input[index + 3] = 0x44;
    }

    bool validate() const {
        return output == 0x44332211;
    }

    void dump(uint8_t* arr) {
        putchar('[');
        for (size_t i = 0; i < size; i++) {
            printf(" %u", arr[i]);
        }

        printf(" ]\n");
    }
};

