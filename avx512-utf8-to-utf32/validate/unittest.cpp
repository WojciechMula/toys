#include <vector>
#include <string>
#include <cstdint>
#include <cstdio>
#include <cstdlib>

#include "utf8-sequences.h"
#include "reference.h"


class Test {
    static constexpr size_t size = 64+8;
    std::string ascii;
    std::string buffer;

public:
    Test(): ascii(size, '_') {}

    bool run() {
        bool ret = true;

        ret = test("reference", scalar_validate_utf8_simple);

        if (ret) {
            puts("All OK");
        }

        return ret;
    }

private:
    template <typename FUNC>
    bool test(const char* name, FUNC validate_utf8) {
        printf("%s ", name);
        fflush(stdout);

        for (size_t pos=0; pos < 60; pos++) {
            buffer = ascii;

            for (size_t j=0; j < utf8_sequences_size; j++) {
                // given
                const auto& tc = utf8_sequences[j];
                for (int k=0; k < 5; k++)
                    buffer[pos + k] = tc.bytes[k];

                // when
                const bool valid = validate_utf8(buffer.data(), buffer.size());

                // then
                if (valid != tc.valid) {
                    printf("expected = %s\n", tc.valid ? "true" : "false");
                    printf("result   = %s\n", valid ? "true" : "false");
                    printf("testcase [%lu]: sequence %02x %02x %02x %02x %02x\n",
                            j, tc.bytes[0], tc.bytes[1], tc.bytes[2], tc.bytes[3], tc.bytes[4]);
                    printf("position: %ld\n", pos);
                    return false;
                }
            }
        }

        puts("OK");
        return true;
    }
};

int main() {
    Test test{};

    return test.run() ? EXIT_SUCCESS : EXIT_FAILURE;
}
