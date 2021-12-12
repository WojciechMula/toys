#include <cstdint>
#include <cstdlib>
#include <cstdio>
#include <memory>
#include <string>
#include <iostream>
#include <fstream>

#include "avx512-utf8-to-utf32.h"


class Test {
    std::string utf8_input;
    std::string utf32_reference;
    std::unique_ptr<uint32_t[]> output;

public:
    Test(const std::string& utf8_path, const std::string& utf32_path) {
        utf8_input = load_file(utf8_path);
        utf32_reference = load_file(utf32_path);
        output = std::make_unique<uint32_t[]>(utf32_reference.size() / 4);
    }

    bool run() {
        bool ret = true;

        ret = test("AVX512", avx512_validating_utf8_to_utf32) and ret;

        if (ret)
            puts("All OK");

        return ret;
    }

private:
    template <typename FUN>
    bool test(const char* name, FUN validating_utf8_to_utf32) {
        printf("%-15s", name);
        fflush(stdout);

        bool ret = true;

        const auto processed = validating_utf8_to_utf32(utf8_input.data(),
                                                        utf8_input.size(),
                                                        output.get());
        if (processed != utf8_input.size()) {
            puts("wrong return value");
            printf("expected = %lu\n", utf8_input.size());
            printf("got      = %lu\n", processed);
            ret = false;
        }

        return compare(reinterpret_cast<const uint32_t*>(utf32_reference.data()),
                       output.get(),
                       utf32_reference.size()) and ret;
    }

    bool compare(const uint32_t* reference, const uint32_t* result, size_t size) const {
        for (size_t i=0; i < size; i++) {
            if (reference[i] != result[i]) {
                printf("wrong character #%lu\n", i);
                printf("expected = %8x\n", reference[i]);
                printf("got      = %8x\n", result[i]);
                return false;
            }
        }

        return true;
    }

    std::string load_file(const std::string& path) {
        std::ifstream file;
        file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        file.open(path);

        std::string data;
        data.assign(std::istreambuf_iterator<char>(file),
                    std::istreambuf_iterator<char>());

        return data;
    }
};


int main() {

    Test test{"dataset/combined.utf8", "dataset/combined.utf32"};

    return test.run() ? EXIT_SUCCESS : EXIT_FAILURE;
}
