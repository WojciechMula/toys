#include <filesystem>
#include <vector>
#include <format>
#include <fstream>
#include <cstdio>
#include <cassert>

#include "impl.cpp"
#include "testcase.cpp"
#include "argparse.cpp"
#include "benchmark.h"


class Application {
    std::optional<std::string> procedure;
    std::optional<std::string> testcase;
    size_t repeat;

    function_names_t fn_names;
    std::vector<Testcase> testcases;

public:
    Application(std::optional<std::string> procedure, std::optional<std::string> testcase, size_t repeat)
        : procedure{procedure}
        , testcase{testcase}
        , repeat{repeat}
        , fn_names(function_names())
        , testcases{load_testcases("datasets")} {}

    void run() {
        for (const auto& tc: testcases) {
            if (testcase and tc.utf32.name().find(testcase.value()) == std::string::npos) {
                continue;
            }

            printf("testcase %s\n", tc.utf32.name().c_str());
            bench(avx2_utf32_uppercase_plain, tc.utf32);
            bench(avx2_utf32_uppercase_compressed, tc.utf32);
            bench(utf32_uppercase_plain, tc.utf32);
            bench(utf32_uppercase_compressed, tc.utf32);
            bench(utf32_lowercase_plain, tc.utf32);
            bench(utf32_lowercase_compressed, tc.utf32);
        }
    }

private:
    template <typename CONV_CASE>
    void bench(CONV_CASE conv, const File& input) {
        const auto& name = fn_names.at(conv);
        if (procedure and name.find(procedure.value()) == std::string::npos) {
            return;
        }

        std::vector<uint32_t> output;
        output.resize(input.size() * 3);

        constexpr size_t repeat = 100;
        BEST_TIME(/**/, conv(input.u32(), input.size(), output.data()), name.c_str(), repeat, input.size());
    }
};


int main(int argc, char* argv[]) {
    Arguments args(argc, argv);
    if (args.consume_flag("-h") or args.consume_flag("--help")) {
        printf("usage %s [--procedure name] [--testcase name] [--repeat count]\n", argv[0]);
        return EXIT_SUCCESS;
    }

    auto procedure = args.consume_argument("--procedure");
    auto testcase = args.consume_argument("--testcase");
    auto repeat = args.consume_usize("--repeat").value_or(100);

    Application app{procedure, testcase, repeat};

    app.run();

    return EXIT_SUCCESS;
}
