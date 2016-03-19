#include <cstdlib>
#include <cstdio>
#include <cstdint>
#include <memory>

#include "config.h"
#include "../../cmdline.cpp"
#include "../../fnv32.cpp"
#include "../../bmi2.cpp"

#include "decode.common.cpp"
#include "decode.scalar.cpp"
#include "decoders.sse.cpp"
#if defined(HAVE_AVX2_INSTRUCTIONS)
#   include "decoders.avx2.cpp"
#endif

#include "function_registry.cpp"
#include "application.cpp"

class Application final: public ApplicationBase {

    bool all_ok;

public:
    Application(const CommandLine& c, const FunctionRegistry& r)
        : ApplicationBase(c, r)
        , all_ok(true) {}

    int run() {
        uint32_t valid_hash = 0;

#define RUN(name, function) \
        if (cmd.empty() || cmd.has(name)) { \
            valid_hash = check(name, function, valid_hash); \
        }

#define RUN_TEMPLATE1(name, decode_fn, lookup_fn) \
        if (cmd.empty() || cmd.has(name)) { \
            auto function = [](const uint8_t* input, size_t size, uint8_t* output) { \
                return decode_fn(lookup_fn, input, size, output); \
            }; \
            valid_hash = check(name, function, valid_hash); \
        }

#define RUN_TEMPLATE2(name, decode_fn, lookup_fn, pack_fn) \
        if (cmd.empty() || cmd.has(name)) { \
            auto function = [](const uint8_t* input, size_t size, uint8_t* output) { \
                return decode_fn(lookup_fn, pack_fn, input, size, output); \
            }; \
            valid_hash = check(name, function, valid_hash); \
        }

#define RUN_SSE_TEMPLATE1 RUN_TEMPLATE1
#define RUN_AVX2_TEMPLATE1 RUN_TEMPLATE1
#define RUN_SSE_TEMPLATE2 RUN_TEMPLATE2
#define RUN_AVX2_TEMPLATE2 RUN_TEMPLATE2

        #include "run_all.cpp"

        if (cmd.empty()) {

            puts(all_ok ? "all OK" : "!!!ERRORS!!!");
        }

        return 0;
    }

private:
    template<typename T>
    uint32_t check(const char* name, T callback, uint32_t valid_hash) {

        initialize();

        printf("%*s ... ", -names.get_width(), names[name]);
        fflush(stdout);

        clear_output();
        callback(input.get(), get_input_size(), output.get());

        const uint32_t hash = FNV32::get(reinterpret_cast<const char*>(output.get()), get_output_size());
        printf("hash: %08x", hash);
        if (valid_hash != 0) {
            const bool ok = (hash == valid_hash);
            printf(" %s", ok ? "OK" : "!!!ERROR!!!");
            all_ok = all_ok && ok;
        }

        putchar('\n');

        return hash;
    }
};


int main(int argc, char* argv[]) {

    FunctionRegistry names;
    CommandLine cmd(argc, argv);
    Application app(cmd, names);

    return app.run();
}


