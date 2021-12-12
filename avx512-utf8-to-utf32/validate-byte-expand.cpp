// This tool fully validates the core AVX512 algorithm

#include <cstdint>
#include <cstdio>
#include <cstring>

#include "avx512-expand.h"

class Test {
    uint8_t input[64];
    uint8_t expected[64]; 

public:
    Test() {
        // numbers from 1 to 64
        for (int i=1; i < 64; i++) {
            input[i - 1] = i  -1 ;
         }

        for (int i=0, j=0; i < 16; i++, j+=4) {
            expected[j + 0] = input[i + 0];
            expected[j + 1] = input[i + 1];
            expected[j + 2] = input[i + 2];
            expected[j + 3] = input[i + 3];
        }
    }

    bool run() {
        bool ret = true;

        ret = test("AVX512 (ver1)", avx512_expand__version1) and ret;
        ret = test("AVX512 (ver2)", avx512_expand__version2) and ret;
        
        if (ret)
            puts("All OK");

        return ret;
    }

private:
    template <typename FUN>
    bool test(const char* name, FUN expandfun) {
        uint8_t output[64];
        _mm512_storeu_si512((__m512i*)output, expandfun((const char*)input));

        printf("%-15s ", name);
        fflush(stdout);

        if (memcmp(expected, output, sizeof(output)) != 0) {
            printf("failed\n");
            dump("expected ", expected, sizeof(expected));
            dump("output   ", output, sizeof(output));
            return false;
        }

        puts("OK");

        return true;
    }

    void dump(const char* name, uint8_t* data, int size) {
        printf("%s = [%d", name, data[0]);
        for (int i=1;  i < size; i++) {
            printf(" %d", data[i]);
        }

        printf("]\n");
    }
};

int main() {
    Test test;
    return test.run() ? EXIT_SUCCESS : EXIT_FAILURE;
}
