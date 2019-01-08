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
    size_t size = 64 * ((text.size() + 63) / 64);
    char* output = new char[text.size()];

#define RUN(__name__, __procedure__) \
    measure(__name__, __procedure__, text.data(), output, size);

    RUN("scalar",                       remove_spaces__scalar);
    RUN("AVX512VBMI",                   remove_spaces__avx512vbmi);
    RUN("AVX512VBMI (Travis)",          remove_spaces__avx512vbmi__travis);
    RUN("AVX512VBMI (Zach)",            remove_spaces__avx512vbmi__zach);
    RUN("despacer_bitmap (aqrit)",      despacer_bitmap);
    RUN("despace_block_mux (aqrit)",    despace_block_mux);
    RUN("despace_ssse3_cumsum (aqrit)", despace_ssse3_cumsum);
    RUN("despace_avx2_vpermd (aqrit)",  despace_avx2_vpermd);
}
