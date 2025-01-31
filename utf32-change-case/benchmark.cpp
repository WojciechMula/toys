#include <filesystem>
#include <vector>
#include <fstream>
#include <cstdio>
#include <cassert>

#include "impl.cpp"
#include "testcase.cpp"
#include "argparse.cpp"
#include "application_base.cpp"
#include "benchmark.h"


class Application: public ApplicationBase {
    size_t repeat;

public:
    Application(std::vector<std::string> procedure, std::vector<std::string> testcase, size_t repeat)
        : ApplicationBase{procedure, testcase}
        , repeat{repeat} {}

    void run() {
        for (const auto& tc: testcases) {
            if (not can_run_testcase(tc)) {
                continue;
            }

            printf("testcase %s\n", tc.utf32.name().c_str());
            bench(avx2_utf32_uppercase_plain, tc.utf32);
            bench(avx2_utf32_uppercase_compressed, tc.utf32);
            bench(avx2_utf32_uppercase_compressed_unrolled4, tc.utf32);
            bench(avx2_utf32_uppercase_compressed_v3, tc.utf32);
            bench(avx2_utf32_uppercase_compressed_v4, tc.utf32);
            bench(avx2_utf32_uppercase_compressed_v5, tc.utf32);
            bench(avx2_utf32_lowercase_compressed_v3, tc.utf32);
            bench(utf32_uppercase_plain, tc.utf32);
            bench(utf32_uppercase_compressed_v1, tc.utf32);
            bench(utf32_uppercase_compressed_v2, tc.utf32);
            bench(utf32_uppercase_compressed_v3, tc.utf32);
            bench(utf32_lowercase_plain, tc.utf32);
            bench(utf32_lowercase_compressed_v1, tc.utf32);
            bench(utf32_lowercase_compressed_v2, tc.utf32);
            bench(utf32_lowercase_compressed_v3, tc.utf32);
            bench(cpp_utf32_uppercase, tc.utf32);
            bench(cpp_utf32_lowercase, tc.utf32);
        #ifdef HAVE_AVX512
            bench(avx512_utf32_uppercase_compressed_v6, tc.utf32);
        #endif
        }
    }

private:
    template <typename CONV_CASE>
    void bench(CONV_CASE conv, const File& input) {
        const auto& name = fn_names.at(conv);
        if (not can_run_procedure(name)) {
            return;
        }

        std::vector<uint32_t> output;
        output.resize(input.size() * 3);

        BEST_TIME(/**/, conv(input.u32(), input.size(), output.data()), name.c_str(), repeat, input.size());
    }
};


int main(int argc, char* argv[]) {
    Arguments args(argc, argv);
    if (args.consume_flag("-h") or args.consume_flag("--help")) {
        printf("usage %s [--procedure name] [--testcase name] [--repeat count]\n", argv[0]);
        return EXIT_SUCCESS;
    }

    const auto procedure = args.consume_all_arguments("--procedure");
    const auto testcase = args.consume_all_arguments("--testcase");
    const auto repeat = args.consume_usize("--repeat").value_or(100);

    Application app{procedure, testcase, repeat};

    app.run();

    return EXIT_SUCCESS;
}
