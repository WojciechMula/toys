#include <cstdio>
#include <string>
#include <cmath>


#include "search.cpp"
#include "common.cpp"


template <typename Value, typename... Args>
void test(const std::size_t n, Value value, const std::string& name, Args... args) {

    printf("\n%s\n", name.c_str());
    const auto array = prepare(n, value, args...);

    count(array, bin_middle, "binary search");
    count(array, interpolation_middle, "interpolation search");
}


int main(int argc, char* argv[]) {
    if (argc <= 1) {
        return 1;
    }

    const auto n = atoi(argv[1]);

    using namespace distribution;

    test(n, power, "pow 0.1", 0.1);
    test(n, power, "pow 0.2", 0.2);
    test(n, power, "pow 0.3", 0.3);
    test(n, power, "pow 0.4", 0.4);
    test(n, power, "pow 0.5", 0.5);
    test(n, power, "pow 0.6", 0.6);
    test(n, power, "pow 0.7", 0.7);
    test(n, power, "pow 0.8", 0.8);
    test(n, power, "pow 0.9", 0.9);

    test(n, power, "pow 1", 1);
    test(n, power, "pow 2", 2);
    test(n, power, "pow 3", 3);
    test(n, power, "pow 4", 4);
    test(n, power, "pow 5", 5);
    test(n, power, "pow 6", 6);
    test(n, power, "pow 7", 7);
    test(n, power, "pow 8", 8);
    test(n, power, "pow 9", 9);

    test(n, power, "pow 10", 10);
    test(n, power, "pow 20", 20);
    test(n, power, "pow 30", 30);
    test(n, power, "pow 40", 40);
    test(n, power, "pow 50", 50);
    test(n, power, "pow 60", 60);
    test(n, power, "pow 70", 70);
    test(n, power, "pow 80", 80);
    test(n, power, "pow 90", 90);
    test(n, power, "pow 100", 100);
}
