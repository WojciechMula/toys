#include <cstdio>
#include <cstdlib>

#include "benchmark.h"
#include "all.h"

class Benchmark {
    char buffer[1024];

public:
    Benchmark() {
        srand(0);
        for (size_t i=0; i < sizeof(buffer); i++)
            buffer[i] = rand();
    }

public:
    void run() {
        test("scalar", count_code_points);
        test("swar",   swar_count_code_points);
    }

private:
    template <typename FUN>
    void test(const char* name, FUN utf8_code_points) {

        const size_t repeat = 1000000;
        const size_t size = 1;

        BEST_TIME(/**/, utf8_code_points(buffer, sizeof(buffer)), name, repeat, size);
    }

};

int main() {

    Benchmark bench;
    bench.run();

    return 0;
}
