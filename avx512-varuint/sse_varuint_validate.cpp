#include <vector>
#include <cstdio>
#include <cstdlib>

#include "sse_varuint.h"


class Test {
    std::vector<uint32_t> input;
    std::vector<uint32_t> output;

public:
    bool run() {
        bool ret = true;

        ret = test("reference", unsafe_unpack) and ret;
        ret = test("SSE",       sse_unsafe_unpack) and ret;

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
        static const std::vector<std::vector<uint32_t>> testcases = {
            {0xff, 2, 3, 4},
            {0xffff, 2, 3, 4},
            {0xffffff, 2, 3, 4},
            {0xffffffff, 2, 3, 4},
            {1, 0xff, 3, 4},
            {1, 0xffff, 3, 4},
            {1, 0xffffff, 3, 4},
            {1, 0xffffffff, 3, 4},
            {1, 2, 0xff, 4},
            {1, 2, 0xffff, 4},
            {1, 2, 0xffffff, 4},
            {1, 2, 0xffffffff, 4},
            {1, 2, 3, 0xff},
            {1, 2, 3, 0xffff},
            {1, 2, 3, 0xffffff},
            {1, 2, 3, 0xffffffff},
            {0xff, 0xffff, 0xffffff, 0xffffffff},
            {100},
            {100, 200},
            {100, 200, 300},
            {100, 200, 300, 400},
            {100, 200, 300, 400, 500},
            {100, 200, 300, 400, 500, 600},
            {100, 200, 300, 400, 500, 600, 700},
            {100, 200, 300, 400, 500, 600, 700, 800},
        };

        for (const auto& tc: testcases) {
            input = tc;
            if (not check(decode_function)) {
                return false;
            }
        }

        return true;
    }

    template <typename FUN>
    bool check(FUN decode_function) {
        // given
        PackedVarUintBuilder builder;
        for (const uint32_t v: input) {
            builder.add(v);
        }

        const auto buf = builder.capture();

        const size_t size        = input.size();
        const size_t output_size = 4*((size + 3)/4);

        output.clear();
        output.resize(output_size);
        output.reserve(output_size + 16); // padding for SIMD procedures

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
