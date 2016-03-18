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

        RUN("improved", base64::scalar::decode_lookup2);
        RUN("scalar", base64::scalar::decode_lookup1);

#if defined(HAVE_BMI2_INSTRUCTIONS)
        RUN("scalar_bmi2", base64::scalar::decode_lookup1_bmi2);
#endif
        RUN("sse/base", base64::sse::decode_with_lookup_base);
        RUN("sse/blend", base64::sse::decode_with_lookup_byte_blend);
        RUN("sse/incremental", base64::sse::decode_with_lookup_incremental);

#if defined(HAVE_BMI2_INSTRUCTIONS)
        RUN("sse_bmi2/base", base64::sse::bmi2::decode_with_lookup_base);
        RUN("sse_bmi2/blend", base64::sse::bmi2::decode_with_lookup_byte_blend);
        RUN("sse_bmi2/incremental", base64::sse::bmi2::decode_with_lookup_incremental);
#endif

#if defined(HAVE_AVX2_INSTRUCTIONS)
        RUN("avx2/base", base64::avx2::decode_with_lookup_base);
        RUN("avx2/blend", base64::avx2::decode_with_lookup_byte_blend);

    #if defined(HAVE_BMI2_INSTRUCTIONS)
        RUN("avx2_bmi2/base", base64::avx2::bmi2::decode_with_lookup_base);
        RUN("avx2_bmi2/blend", base64::avx2::bmi2::decode_with_lookup_byte_blend);
    #endif // HAVE_BMI2_INSTRUCTIONS
#endif // HAVE_AVX2_INSTRUCTIONS

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


