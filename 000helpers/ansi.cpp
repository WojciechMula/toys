#include <string>

namespace ansi {
    
    const int RED   = 31;
    const int GREEN = 32;
    const int WHITE = 37;

    std::string seq(const std::string& str, int color) {

        return "\033[" + std::to_string(color) + "m" + str + "\033[0m";
    }

    namespace str {

        const char* RED   = "\033[31m";
        const char* GREEN = "\033[32m";
        const char* WHITE = "\033[37m";
        const char* RESET = "\033[0m";

    }

} // namespace ansi

