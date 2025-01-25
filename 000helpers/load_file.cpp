template <typename T>
std::string load_file(const T& path) {
    std::ifstream file;
    file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    file.open(path);

    std::string data;
    data.assign(std::istreambuf_iterator<char>(file),
                std::istreambuf_iterator<char>());

    return data;
}
