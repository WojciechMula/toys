#include <cstring>
#include <string>
#include <unordered_set>

class CommandLine final {
    int argc;
    char** argv;

    std::unordered_set<std::string> arguments;
    std::unordered_set<std::string> flags;

public:
    CommandLine(int argc, char* argv[])
        : argc(argc)
        , argv(argv) {

        for (int i=1; i < argc; i++) {
            const std::string arg(argv[i]);

            if (arg.size() >= 2 && arg[0] == '-' && arg[1] == '-') {
                flags.insert(std::move(arg));
            } else {
                arguments.insert(std::move(arg));
            }
        }
    }

    bool has(const std::string& name) const {
        return arguments.count(name);
    }

    bool has_flag(const std::string& name) const {
        return flags.count(name) || flags.count("--" + name);
    }

    bool empty() const {
        return arguments.empty();
    }
};
