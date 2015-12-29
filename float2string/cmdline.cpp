class CommandLine final {

    int argc;
    char** argv;
public:
    CommandLine(int argc, char* argv[])
        : argc(argc)
        , argv(argv) {}

public:
    bool has(const char* opt) const {
        for (int i=1; i < argc; i++) {
            if (strcmp(opt, argv[i]) == 0) {
                return true;
            }
        }

        return false;
    }


    bool empty() const {
        return (argc == 1);
    }
};

