#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <chrono>
#include <cstdio>

#include "all.cpp"

std::string load(const std::string& path) {
    
    std::ifstream file(path);
    std::stringstream buffer;
    buffer << file.rdbuf();

    return buffer.str();
}


template <typename FUNCTION>
void measure(const char* name, FUNCTION fun, const char* input, char* output, size_t size) {

    using namespace std::chrono;

    printf("%-11s: ", name); fflush(stdout);

    const auto ts = high_resolution_clock::now();
    fun(input, output, size);
    const auto te = high_resolution_clock::now();

    printf("%lu ms\n", duration_cast<milliseconds>(te - ts).count());
}


int main(int argc, char* argv[1]) {

    if (argc < 2) {
        puts("argument expected");
        return EXIT_FAILURE;
    }

    std::string text = load(argv[1]);
    size_t size = 64 * ((text.size() + 63) / 64);
    char* output = new char[text.size()];

    measure("scalar",     remove_spaces__scalar,     text.data(), output, size);
    measure("AVX512VBMI", remove_spaces__avx512vbmi, text.data(), output, size);
}
