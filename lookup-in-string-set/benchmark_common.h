#include <vector>
#include <string>
#include <string_view>
#include <fstream>

std::string load_file(const std::string& path) {
    std::ifstream file;
    file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    file.open(path);

    std::string data;
    data.assign(std::istreambuf_iterator<char>(file),
                std::istreambuf_iterator<char>());

    return data;
}

std::vector<std::string> split_lines(const std::string& str) {
    std::vector<std::string> res;

    std::string_view s{str};
    while (true) {
        const auto pos = s.find('\n');
        if (pos < std::string_view::npos) {
            res.push_back(std::string{s.substr(0, pos)});
        } else {
            res.push_back(std::string{s});
            break;
        }

        s = s.substr(pos+1);
    }

    return res;
}

std::vector<std::string> read_lines(const std::string& path) {
    const auto contents = load_file(path);
    
    return split_lines(contents);
}
