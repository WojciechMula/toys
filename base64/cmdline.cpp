#include <cstring>

class CommandLine final {
    int argc;
    char** argv;

public:
    CommandLine(int argc, char* argv[])
        : argc(argc)
        , argv(argv) {}

    bool has(const char* name) const {
        for (int i=1; i < argc; i++) {
            if (strcmp(name, argv[i]) == 0) {
                return true;
            }
        }

        return false;
    }

    bool empty() const {
        return argc == 1;
    }
};
