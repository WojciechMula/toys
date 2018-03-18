#include <chrono>
#include <cstdio>
#include <cassert>
#include <cstring>

#include "procedures.cpp"


template <typename T>
unsigned elapsed_time(T t0, T t1) {
    using namespace std::chrono;
    return duration_cast<microseconds>(t1 - t0).count();
}

void benchmark(const std::string& info, convfun fun, int count) {
    const char* input = "0000000123456789";
    assert(strlen(input) == 16);

    printf("%-10s ", info.c_str());
    fflush(stdout);

    using Clock = std::chrono::high_resolution_clock;

    int tmp = count;
    const auto t0 = Clock::now();
    while (tmp-- > 0) {
        fun(input);
    }
    const auto t1 = Clock::now();

    printf("%8u us\n", elapsed_time(t0, t1));
}

int main() {

    for (auto& item: get_procedures()) {
        benchmark(item.name, item.fun, 10000000);
    }
}
