#include <cstdio>
#include <optional>
#include <string_view>
#include <initializer_list>

template <typename T>
constexpr std::optional<T> parse(std::string_view x, T value, std::string_view value_name) {
    if (x == value_name)
        return value;
    else
        return {};
}

template <typename T, typename... Args>
constexpr std::optional<T> parse(std::string_view x, T value, std::string_view value_name, Args&&... args) {
    if (auto ret = parse(x, value, value_name); ret)
        return ret;
    else
        return parse(x, args...);
}

enum class Color {
    red,
    green,
    blue
};

int main(int argc, char* argv[])
{
    if (argc < 2) {
        puts("Usage: demo string");
        return 1;
    }
    const auto val = parse(argv[1], Color::red, "red", Color::blue, "blue", Color::green, "green");
    if (val)
        printf("%s -> %d\n", argv[1], val.value());
    else
        printf("%s -> no match\n", argv[1]);
}
