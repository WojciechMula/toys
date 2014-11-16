#ifndef ARGLIST_HPP_INCLUDED__
#define ARGLIST_HPP_INCLUDED__

#include <cstring>

class arglist {
    int argc;
    char** argv;

public:
    arglist(int argc, char* argv[])
        : argc(argc)
        , argv(argv) {}

    bool operator()(const char* name) const {
        for (int i=1; i < argc; i++) {
            if (strcmp(name, argv[i]) == 0) {
                return true;
            }
        }

        return false;
    }
};

#endif
