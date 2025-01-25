#include <filesystem>
#include <vector>
#include <format>
#include <fstream>
#include <cstdio>
#include <cassert>

#include "load_file.cpp"
#include "scalar.cpp"

class File {
    std::filesystem::path path;
    std::string data;
    std::string filename;

public:
    File(const std::filesystem::path& path) : path(path) {
        filename = path.stem();
        data = load_file(path);
        if (data.size() % 4 != 0) {
            throw std::runtime_error(std::format("'{}' size is not multiple of 4, likely it's not UTF-32 bit encoded", path.string()));
        }
    }

    const uint32_t* u32() const {
        return (const uint32_t*)data.data();
    }

    size_t size() const {
        return data.size() / 4;
    }

    const std::string& name() const {
        return filename;
    }
};

struct Testcase {
    File utf32;
    File uppercase;
    File lowercase;

    Testcase(const std::filesystem::path& utf32, const std::filesystem::path& uppercase, const std::filesystem::path& lowercase)
        : utf32{utf32}
        , uppercase{uppercase}
        , lowercase{lowercase} {}
};

#define assert_eq(left, right) do {             \
    if ((left) != (right)) {                    \
        printf("%s != %s\n", #left, #right);    \
        abort();                                \
    }                                           \
} while (0);

std::filesystem::path append_extension(const std::filesystem::path& path, std::string extension) {
    return path.string() + extension;
}

std::vector<Testcase> load_testcases(const std::filesystem::path& rootdir) {
    std::vector<Testcase> result;

    for (const auto& entry: std::filesystem::directory_iterator{rootdir}) {
        const auto& path = entry.path();
        if (path.extension() == ".utf32") {
            const auto uppercase = append_extension(path, ".uppercase");
            const auto lowercase = append_extension(path, ".lowercase");
            if (not std::filesystem::exists(uppercase)) {
                const auto err = std::format("path '{}' not found, run `make` in '{}'", uppercase.string(), rootdir.string());
                throw std::runtime_error(err);
            }

            if (not std::filesystem::exists(lowercase)) {
                const auto err = std::format("path '{}' not found, run `make` in '{}'", lowercase.string(), rootdir.string());
                throw std::runtime_error(err);
            }

            result.emplace_back(Testcase{path, uppercase, lowercase});
        }
    }

    return result;
}

bool compare_u32_arrays(const uint32_t* want, const uint32_t* got, size_t n) {
    int errors = 0;
    constexpr int max_errors = 10;
    for (size_t i=0; i < n; i++) {
        if (want[i] == got[i]) {
            continue;
        }

        printf("index %lu:\n", i);
        printf("\twant = 0x%04x\n", want[i]);
        printf("\tgot  = 0x%04x\n", got[i]);

        errors += 1;
        if (errors >= max_errors) {
            puts("reached max errors");
            break;
        }
    }

    return (errors == 0);
}

template <typename CONV_CASE>
bool verify(const char* name, CONV_CASE conv, const File& input, const File& reference) {
    printf("%s (%s)... ", name, input.name().c_str());
    fflush(stdout);

    std::vector<uint32_t> output;
    output.resize(input.size() * 3);

    const size_t expected_size = reference.size();
    const auto output_size = conv(input.u32(), input.size(), output.data());
    if (output_size != expected_size) {
        puts("");
        printf("expected size = %lu\n", expected_size);
        printf("output size   = %lu\n", output_size);

        return false;
    }

    if (not compare_u32_arrays(reference.u32(), output.data(), output_size)) {
        return false;
    }

    puts("OK");

    return true;
}


int main() {
    const auto testcases = load_testcases("datasets");

    bool all_ok = true;
    for (const auto& tc: testcases) {
        all_ok = verify("uppercase scalar plain", utf32_uppercase_plain, tc.utf32, tc.uppercase) and all_ok;
        all_ok = verify("uppercase scalar compressed", utf32_uppercase_compressed, tc.utf32, tc.uppercase) and all_ok;
        all_ok = verify("lowercase scalar plain", utf32_lowercase_plain, tc.utf32, tc.lowercase) and all_ok;
        all_ok = verify("lowercase scalar compressed", utf32_lowercase_compressed, tc.utf32, tc.lowercase) and all_ok;
    }

    if (all_ok) {
        puts("All OK");
    }
}
