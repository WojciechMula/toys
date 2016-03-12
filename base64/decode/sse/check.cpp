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

#include "application.cpp"

class Application final: public ApplicationBase {

    bool all_ok;

public:
    Application(const CommandLine& c)
        : ApplicationBase(c)
        , all_ok(true) {}

    int run() {
        uint32_t valid_hash = 0;

        if (cmd.empty() || cmd.has("scalar")) {
            valid_hash = check("scalar", base64::scalar::decode_lookup1, valid_hash);
        }

        if (cmd.empty() || cmd.has("improved")) {
            check("improved scalar", base64::scalar::decode_lookup2, valid_hash);
        }

#if defined(HAVE_BMI2_INSTRUCTIONS)
        if (cmd.empty() || cmd.has("scalar_bmi2")) {
            check("scalar & BMI2", base64::scalar::decode_lookup1_bmi2, valid_hash);
        }
#endif

        if (cmd.empty() || cmd.has("sse") || cmd.has("sse/base")) {
            check("SSE (lookup: base)       ", base64::sse::decode_with_lookup_base, valid_hash);
        }

        if (cmd.empty() || cmd.has("sse") || cmd.has("sse/blend")) {
            check("SSE (lookup: byte blend) ", base64::sse::decode_with_lookup_byte_blend, valid_hash);
        }

        if (cmd.empty() || cmd.has("sse") || cmd.has("sse/incremental")) {
            check("SSE (lookup: incremental)", base64::sse::decode_with_lookup_incremental, valid_hash);
        }

#if defined(HAVE_BMI2_INSTRUCTIONS)
        if (cmd.empty() || cmd.has("sse_bmi2") || cmd.has("sse_bmi2/base")) {
            check("SSE & BMI2 (lookup: base)      ", base64::sse::bmi2::decode_with_lookup_base, valid_hash);
        }

        if (cmd.empty() || cmd.has("sse_bmi2") || cmd.has("sse_bmi2/blend")) {
            check("SSE & BMI2 (lookup: byte blend) ", base64::sse::bmi2::decode_with_lookup_byte_blend, valid_hash);
        }

        if (cmd.empty() || cmd.has("sse_bmi2") || cmd.has("sse_bmi2/incremental")) {
            check("SSE & BMI2 (lookup: incremental)", base64::sse::bmi2::decode_with_lookup_incremental, valid_hash);
        }
#endif

#if defined(HAVE_AVX2_INSTRUCTIONS)
        if (cmd.empty() || cmd.has("avx2") || cmd.has("avx2/base")) {
            check("AVX2 (lookup: base)      ", base64::avx2::decode_with_lookup_base, valid_hash);
        }

        if (cmd.empty() || cmd.has("avx2") || cmd.has("avx2/blend")) {
            check("AVX2 (lookup: byte blend)", base64::avx2::decode_with_lookup_byte_blend, valid_hash);
        }

    #if defined(HAVE_AVX2_INSTRUCTIONS) && defined(HAVE_BMI2_INSTRUCTIONS)
        if (cmd.empty() || cmd.has("avx2_bmi2") || cmd.has("avx2_bmi2/base")) {
            check("AVX2 & BMI2 (lookup: base)      ", base64::avx2::bmi2::decode_with_lookup_base, valid_hash);
        }

        if (cmd.empty() || cmd.has("avx2_bmi2") || cmd.has("avx2_bmi2/blend")) {
            check("AVX2 & BMI2 (lookup: byte blend)", base64::avx2::bmi2::decode_with_lookup_byte_blend, valid_hash);
        }
    #endif // defined(HAVE_BMI2_INSTRUCTIONS)

#endif // defined(HAVE_AVX2_INSTRUCTIONS)

        if (cmd.empty()) {
            
            puts(all_ok ? "all OK" : "!!!ERRORS!!!");
        }

        return 0;
    }

private:
    template<typename T>
    uint32_t check(const char* name, T callback, uint32_t valid_hash) {

        initialize();

        printf("%40s... ", name);
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

    CommandLine cmd(argc, argv);
    Application app(cmd);

    return app.run();
}


