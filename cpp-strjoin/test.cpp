#include <cstdlib>

#include "benchmark.h"
#include "join_naive.h"
#include "join_precalc.h"


class Test {

    const int min_length = 1;
    const int max_length = 64;
    const int sep_length = 2;
    size_t count;

    std::vector<std::string> input;
    std::string output;
    std::string sep;

public:
    Test(size_t count_) : count(count_) {}

    void run() {
        prepare();
        printf("element count = %lu\n", count);

        const size_t repeat = 1000;

        auto f1 = [this]() {
            output = join_naive(sep, input);
        };
        BEST_TIME(/**/, f1(), "naive", repeat, count);

        auto f2 = [this]() {
            output = join_precalc(sep, input);
        };
        BEST_TIME(/**/, f2(), "precalc", repeat, count);
    }

private:
    void prepare() {
        sep.assign(sep_length, '#');

        input.reserve(count);
        for (size_t i=0; i < count; i++)
            input.push_back(random_string());
    }

    std::string random_string() {
        const size_t k = rand() % (max_length - min_length + 1) + min_length;

        return std::string(k, '*');
    }
};


int main(int argc, char* argv[]) {

    if (argc < 2) {
        printf("usage: %s input-size\n", argv[0]);
        return 1;
    }

    Test test(atoi(argv[1]));

    test.run();

    return 0;
}
