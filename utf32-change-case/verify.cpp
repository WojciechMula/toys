#include <filesystem>
#include <vector>
#include <format>
#include <fstream>
#include <cstdio>
#include <cassert>

#include "impl.cpp"
#include "testcase.cpp"
#include "argparse.cpp"
#include "application_base.cpp"


class Application: public ApplicationBase {
    int passed;
    int failed;

public:
    Application(std::vector<std::string> procedure, std::vector<std::string> testcase)
        : ApplicationBase{procedure, testcase}
        , passed{0}
        , failed{0} {}

    bool run() {
        for (const auto& tc: testcases) {
            if (not can_run_testcase(tc)) {
                continue;
            }

            verify(avx2_utf32_uppercase_plain, tc.utf32, tc.uppercase);
            verify(avx2_utf32_uppercase_compressed, tc.utf32, tc.uppercase);
            verify(avx2_utf32_uppercase_compressed_unrolled4, tc.utf32, tc.uppercase);
            verify(utf32_uppercase_plain, tc.utf32, tc.uppercase);
            verify(utf32_uppercase_compressed, tc.utf32, tc.uppercase);
            verify(utf32_uppercase_compressed_v2, tc.utf32, tc.uppercase);
            verify(utf32_lowercase_plain, tc.utf32, tc.lowercase);
            verify(utf32_lowercase_compressed, tc.utf32, tc.lowercase);
            verify(utf32_lowercase_compressed_v2, tc.utf32, tc.lowercase);
            verify(cpp_utf32_uppercase, tc.utf32, tc.uppercase);
            verify(cpp_utf32_lowercase, tc.utf32, tc.lowercase);
        }

        if (failed + passed == 0) {
            puts("no tests were run");
            return true;
        }

        if (failed == 0) {
            puts("All Ok");
            return true;
        } else {
            return false;
        }
    }

private:
    template <typename CONV_CASE>
    void verify(CONV_CASE conv, const File& input, const File& reference) {
        const auto& name = fn_names.at(conv);
        if (not can_run_procedure(name)) {
            return;
        }

        printf("%s (%s)... ", name.c_str(), input.name().c_str());
        fflush(stdout);

        std::vector<uint32_t> output;
        output.resize(input.size() * 3);

        const size_t expected_size = reference.size();
        const auto output_size = conv(input.u32(), input.size(), output.data());
        if (output_size != expected_size) {
            puts("");
            printf("expected size = %lu\n", expected_size);
            printf("output size   = %lu\n", output_size);

            failed += 1;
            return;
        }

        if (not compare_u32_arrays(reference.u32(), output.data(), output_size)) {
            failed += 1;
            return;
        }

        passed += 1;
        puts("OK");
    }

    bool compare_u32_arrays(const uint32_t* want, const uint32_t* got, size_t n) {
        int errors = 0;
        constexpr int max_errors = 10;
        for (size_t i=0; i < n; i++) {
            if (want[i] == got[i]) {
                continue;
            }

            printf("index %lu:\n", i);
            printf("\twant = 0x%04x\n", want[i]);
            printf("\tgot  = 0x%04x\n", got[i]);

            errors += 1;
            if (errors >= max_errors) {
                puts("reached max errors");
                break;
            }
        }

        return (errors == 0);
    }
};

int main(int argc, char* argv[]) {
    Arguments args(argc, argv);
    if (args.consume_flag("-h") or args.consume_flag("--help")) {
        printf("usage %s [--procedure name] [--testcase name]\n", argv[0]);
        return EXIT_SUCCESS;
    }

    auto procedure = args.consume_all_arguments("--procedure");
    auto testcase = args.consume_all_arguments("--testcase");

    Application app{procedure, testcase};

    return app.run() ? EXIT_SUCCESS : EXIT_FAILURE;
}
