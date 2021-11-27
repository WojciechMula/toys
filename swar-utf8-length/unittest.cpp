#include <cstdio>
#include <cstdlib>

#include "all.h"

class Test {
    char buffer[256];

public:
    bool run() {
        return test("SWAR", swar_count_code_points);
    }

private:
    template <typename FUN>
    bool test(const char* name, FUN custom_count_code_points) {
        printf("%10s... ", name);
        fflush(stdout);

        srand(0);
        initialize_buffer();
        const size_t n = sizeof(buffer);
        const int tries = 100;
        for (int i=0; i < tries; i++) {
            for (size_t size=0; size < n; size++) {
                const auto expected = count_code_points(buffer, size);
                const auto result = custom_count_code_points(buffer, size);
                if (expected != result) {
                    printf("failed for size %ld: expected=%lu, result=%lu\n", size, expected, result);
                    return false;
                }
            }
        }

        puts("OK");

        return true;
    }

    void initialize_buffer() {
        for (size_t i=0; i < sizeof(buffer); i++)
            buffer[i] = rand();
    }
};

int main() {
    
    Test test;
    return test.run() ? EXIT_SUCCESS : EXIT_FAILURE;
}

