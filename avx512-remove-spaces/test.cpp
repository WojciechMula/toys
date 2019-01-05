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


void save(const std::string& path, const char* data, size_t size) {

    std::ofstream file(path, std::ios::out | std::ios::trunc);
    file.write(data, size);
}


template <typename FUNCTION>
void measure(const char* name, FUNCTION fun, const char* input, char* output, size_t size) {

    using namespace std::chrono;

    printf("%-11s: ", name); fflush(stdout);

    const int runs = 10;
    uint64_t best_time = -1;

    for (int i=0; i < runs; i++) {
        putchar('.'); fflush(stdout);
        const auto ts = high_resolution_clock::now();
        fun(input, output, size);
        const auto te = high_resolution_clock::now();

        const uint64_t d = duration_cast<microseconds>(te - ts).count();
        best_time = std::min(best_time, d);
    }

    printf(" %10lu us\n", best_time);
}


int main(int argc, char* argv[1]) {

    if (argc < 2) {
        puts("argument expected");
        return EXIT_FAILURE;
    }

    std::string text = load(argv[1]);
    if (text.size() < 64) {
        puts("please provide a file larger than 64 bytes");
        return EXIT_FAILURE;
    }

    size_t size = 64 * ((text.size() + 63) / 64);
    char* output = new char[size];

    char* scalar_ret = remove_spaces__scalar(text.data(), output, size);
    save("scalar.out", output, scalar_ret - output);
    puts("scalar.out was created");

    char* avx512_ret = remove_spaces__avx512vbmi(text.data(), output, size);
    save("avx512.out", output, avx512_ret - output);
    puts("avx512.out was created");

    return EXIT_SUCCESS;
}

