#include <cstdint>
#include <cstdlib>
#include <cstdio>
#include <memory>
#include <string>
#include <iostream>
#include <fstream>

#include "avx512-utf8-to-utf32.h"
#include "bom.h"


class Test {
    std::string utf8_input_str;
    std::string utf32_reference_str;
    std::unique_ptr<uint32_t[]> output;
    const char* utf8_input;
    size_t utf8_input_size;
    const uint32_t *utf32_reference;
    size_t utf32_reference_size;

public:
    Test(const std::string& utf8_path, const std::string& utf32_path) {
        utf8_input_str = load_file(utf8_path);
        utf32_reference_str = load_file(utf32_path);

        {
            const auto bom  = detect(utf8_input_str);
            const auto size = bom_size(bom);
            if (bom != BOM::None)
                printf("'%s' BOM is %s\n", utf8_path.c_str(), to_string(bom));

            utf8_input = utf8_input_str.data() + size;
            utf8_input_size = utf8_input_str.size() - size;
        }

        {
            const auto bom  = detect(utf32_reference_str);
            const auto size = bom_size(bom);
            if (bom != BOM::None)
                printf("'%s' BOM is %s\n", utf32_path.c_str(), to_string(bom));

            utf32_reference = reinterpret_cast<const uint32_t*>(utf32_reference_str.data() + size);
            utf32_reference_size = (utf32_reference_str.size() - size)/4;
        }

        output = std::make_unique<uint32_t[]>(utf32_reference_size);
    }

    bool run() {
        bool ret = true;

        //ret = test("AVX512",   avx512_validating_utf8_to_utf32) and ret;
        ret = test("AVX512BW", avx512bw_validating_utf8_to_utf32) and ret;

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

        const auto written = validating_utf8_to_utf32(utf8_input, utf8_input_size, output.get());
        if (written != utf32_reference_size) {
            puts("wrong return value");
            printf("expected = %lu\n", utf32_reference_size);
            printf("got      = %lu\n", written);
            ret = false;
        }

        ret = compare(utf32_reference, output.get(), utf32_reference_size) and ret;
        if (ret)
            puts("OK");

        return ret;
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
