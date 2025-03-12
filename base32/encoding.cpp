#include <vector>
#include <string>
#include <cstdio>
#include <cstdint>

#include "common.h"
#include "scalar_encoding.cpp"

int main() {
    const std::vector<std::pair<std::string, std::string>> inputs = {
        {"", ""},
        {"f", "MY======"},
        {"fo","MZXQ===="},
        {"foo","MZXW6==="},
        {"foob","MZXW6YQ="},
        {"fooba","MZXW6YTB"},
        {"foobar","MZXW6YTBOI======"},
        {"foobarfoobarfoob", ""},
    };

    bool ok = true;
    for (const auto& v: inputs) {
        const auto& input = v.first;
        const auto& want = v.second;

        std::string output;
        output.resize(256);
        const auto n = base32_encoding<Base32Alphabet::Default>(
            reinterpret_cast<const uint8_t*>(input.data()), input.size(), output.data());

        output.resize(n);

        if (output != want) {
            printf("error: BASE32('%s')\n", input.c_str());
            printf("\twant: '%s'\n", want.c_str());
            printf("\tgot:  '%s'\n", output.c_str());
            ok = false;
        }
    }

    if (ok) {
        puts("All OK");
        return EXIT_SUCCESS;
    } else {
        return EXIT_FAILURE;
    }
}
