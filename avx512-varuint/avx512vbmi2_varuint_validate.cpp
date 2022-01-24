#include <vector>
#include <cstdio>
#include <cstdlib>


#include "avx512vbmi2_varuint.h"


class Test {
    std::vector<uint32_t> input;
    std::vector<uint32_t> output;

public:
    bool run() {
        bool ret = true;

        ret = test("reference",     unsafe_unpack16) and ret;
#ifdef __AVX512VBMI2__
        ret = test("AVX512VBMI2",   avx512vbmi2_unsafe_unpack16) and ret;
#endif

        if (ret) {
            puts("All OK");
        }

        return ret;
    }

private:
    template <typename FUN>
    bool test(const char* name, FUN decode_function) {
        printf("%-16s", name);
        fflush(stdout);

        const bool ret = simple(decode_function) and random(decode_function);
        if (ret) {
            puts("OK");
        }

        return ret;
    }

    template <typename FUN>
    bool random(FUN decode_function) {
        // given
        constexpr size_t count = 1024 * 10;

        srand(42);
        input.clear();
        for (size_t i=0; i < count; i++) {
            const uint32_t v = rand();
            switch (rand() % 4) {
                case 0:
                    input.push_back(v & 0xff);
                    break;
                case 1:
                    input.push_back(v & 0xffff);
                    break;
                case 2:
                    input.push_back(v & 0xffffff);
                    break;
                case 3:
                    input.push_back(v);
                    break;
            }
        }

        return check(decode_function);
    }

    template <typename FUN>
    bool simple(FUN decode_function) {
        static const std::vector<uint32_t> words{0x11, 0x2223, 0x333231, 0x44434241};

        for (int size=1; size < 32; size++) {
            for (int pos=0; pos < size; pos++) {
                input.clear();
                input.resize(size);
                for (int i=0; i < 4; i++) {
                    input[pos] = words[i];
                    if (not check(decode_function)) {
                        return false;
                    }
                }

            }
        }

        return true;
    }

    template <typename FUN>
    bool check(FUN decode_function) {
        // given
        Packed16VarUintBuilder builder;
        for (const uint32_t v: input) {
            builder.add(v);
        }

        const auto buf = builder.capture();

        const size_t size        = input.size();
        const size_t output_size = 16*((size + 15)/16);

        output.clear();
        output.resize(output_size);
        output.reserve(output_size + 64); // padding for SIMD procedures

        // when
        decode_function(buf, output_size, &output[0]);

        // then
        for (size_t i=0; i < size; i++) {
            if (input[i] != output[i]) {
                printf("expected = %d\n", input[i]);
                printf("got      = %d\n", output[i]);
                printf("error at index %ld\n", i);
                for (size_t j=0; j < size; j++) {
                    printf("%ld: %d - %d\n", j, input[j], output[j]);
                }
                return false;
            }
        }

        for (size_t i=size; i < output_size; i++) {
            if (output[i] != 0) {
                printf("expected = %d\n", 0);
                printf("got      = %d\n", output[i]);
                printf("error at index %ld\n", i);
                return false;
            }
        }

        return true;
    }
};

int main() {
    Test test;
    return test.run() ? EXIT_SUCCESS : EXIT_FAILURE;
}
