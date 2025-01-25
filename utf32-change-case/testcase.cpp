#include "load_file.cpp"

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
