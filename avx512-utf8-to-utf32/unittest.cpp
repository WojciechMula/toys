#include <cstdint>
#include <cstdlib>
#include <cstdio>
#include <memory>

#include "avx512-utf8-to-utf32.h"
#include "utf8.h"

class Test {
    const size_t count;
    size_t input_size;
    std::unique_ptr<uint32_t[]> characters;
    std::unique_ptr<uint8_t[]> input;
    std::unique_ptr<uint32_t[]> output;

public:
    Test(size_t count)
        : count{count}
        , characters{std::make_unique<uint32_t[]>(count)}
        , input{std::make_unique<uint8_t[]>(count * 4)}
        , output{std::make_unique<uint32_t[]>(count + 32)} {}

    bool run() {
        prepare_input();
        avx512_utf8_to_utf32((const char*)input.get(), input_size, output.get());
        const bool ret = compare();
        if (ret)
            puts("All OK");

        return ret;
    }

private:
    void prepare_input() {
        srand(42);
        uint8_t* inp = input.get();
        for (size_t i=0; i < count; i++) {
            characters[i] = random_char();
            const int n = utf8_bytes(characters[i], inp);
            inp += n;
        }

        input_size = inp - input.get();
    }

    uint32_t random_char() {
        uint32_t v = rand();
        switch (rand() % 4) {
            case 0:
                return v & 0x7f;
            case 1:
                return v & 0x7ff;
            case 2:
                return v & 0xffff;
            case 3:
                return v & 0xfffff;
        }

        return 0;
    }

    bool compare() const {
        // Note: we are not validating the tail (16 last chars), as the
        //       current implementation doesn't deal with data that
        //       not fit in an AVX512 reg.
        for (size_t i=0; i < count - 16; i++) {
            if (characters[i] != output[i]) {
                printf("failed at #%lu: expected=%x, result=%x\n", i, characters[i], output[i]);
                return false;
            }
        }

        return true;
    }
};


int main() {

    Test test{1024};

    return test.run() ? EXIT_SUCCESS : EXIT_FAILURE;
}
