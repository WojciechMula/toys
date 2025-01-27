#include <vector>
#include <string>
#include <optional>
#include <algorithm>
#include <stdexcept>
#include <cassert>


class Arguments {
public:
    std::vector<std::string> args;

public:
    Arguments(int argc, char* argv[]) {
        args.reserve(argc);

        std::string before;
        std::string after;
        for (int i=1; i < argc; i++) {
            std::string arg(argv[i]);
            if (partition(arg, '=', before, after)) {
                args.push_back(before);
                args.push_back(after);
            } else {
                args.push_back(arg);
            }
        }
    }

    bool consume_flag(const std::string& flag) {
        assert(is_command(flag));
        const auto it = std::find(args.begin(), args.end(), flag);

        if (it == args.end()) {
            return false;
        }

        args.erase(it);
        return true;
    }

    std::optional<std::string> consume_argument(const std::string& flag) {
        assert(is_command(flag));
        auto it = std::find(args.begin(), args.end(), flag);

        if (it == args.end()) {
            return std::nullopt;
        }

        it = args.erase(it);

        if (it == args.end()) {
            throw std::runtime_error("missing argument for '" + flag + "'");
        }

        auto v = *it;

        args.erase(it);

        return v;
    }

    std::vector<std::string> consume_all_arguments(const std::string& flag) {
        std::vector<std::string> result;   
        while (true) {
            const auto s = consume_argument(flag);
            if (not s) {
                break;
            }

            result.push_back(s.value());
        }

        return result;
    }

    std::optional<size_t> consume_usize(const std::string& flag) {
        const auto s = consume_argument(flag);
        if (not s) {
            return std::nullopt;
        }

        const long long ret = std::stoll(s.value());
        if (ret < 0) {
            throw std::runtime_error("flag '" + flag + "': negative number");
        }

        return ret;
    }
    
    std::optional<size_t> consume_usize(const std::string& flag, size_t min) {
        const auto val = consume_usize(flag);
        if (val) {
            if (val.value() < min) {
                throw std::runtime_error("flag '" + flag + "': cannot be smaller than " + std::to_string(min));
            }
        }

        return val;
    }

    std::vector<std::string> consume_remaining() {
        for (const auto& arg: args) {
            if (is_command(arg)) {
                throw std::runtime_error("unknown argument '" + arg + "'");
            }
        }

        return args;
    }

private:
    bool is_command(const std::string& s) {
        return is_short_command(s) || is_long_command(s);
    }

    bool is_long_command(const std::string& s) {
        return (s.size() >= 3 && s[0] == '-' && s[1] == '-');
    }

    bool is_short_command(const std::string& s) {
        return (s.size() >= 2 && s[0] == '-');
    }

    bool partition(const std::string& s, char c, std::string& before, std::string& after) {
        const auto pos = s.find(c);
        if (pos == std::string::npos) {
            return false;
        }

        before = s.substr(0, pos);
        after  = s.substr(pos + 1);
        return true;
    }
};
