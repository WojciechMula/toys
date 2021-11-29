#include <cstdio>
#include <cstdlib>
#include <memory>
#include <initializer_list>

#include "benchmark.h"
#include "avx512-utf8-to-utf32.h"
#include "utf8.h"

class Benchmark {
    const size_t count;
    size_t input_size;
    std::unique_ptr<uint32_t[]> characters;
    std::unique_ptr<uint8_t[]> input;
    std::unique_ptr<uint32_t[]> output;

public:
    Benchmark(size_t count)
        : count{count}
        , characters{std::make_unique<uint32_t[]>(count)}
        , input{std::make_unique<uint8_t[]>(count * 4)}
        , output{std::make_unique<uint32_t[]>(count + 32)} {}

public:
    void run() {
        prepare_input();

        test("AVX512F (ver1)", avx512_utf8_to_utf32__version1);
        test("AVX512F (ver2)", avx512_utf8_to_utf32__version2);
    }

private:
    template <typename FUN>
    void test(const char* name, FUN utf8_to_utf32) {

        const size_t repeat = 10000;
        const size_t size = input_size;

        BEST_TIME(/**/, utf8_to_utf32((const char*)input.get(), input_size, output.get()), name, repeat, size);
    }

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

};

int main() {

    for (size_t size: {512, 1024, 4096}) {
        Benchmark bench{size};
        bench.run();
    }

    return 0;
}
