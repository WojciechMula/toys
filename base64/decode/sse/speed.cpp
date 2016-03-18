#include <cstdlib>
#include <cstdio>
#include <cstdint>
#include <memory>

#include "config.h"
#include "../../gettime.cpp"
#include "../../cmdline.cpp"
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

public:
    Application(const CommandLine& c, const FunctionRegistry& r)
        : ApplicationBase(c, r) {}

    int run() {
        double reference = 0.0;

#define RUN(name, function) \
        if (cmd.empty() || cmd.has(name)) { \
            const double ret = measure(name, function, reference); \
            if (reference == 0.0) { \
                reference = ret; \
            } \
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

        return 0;
    }

private:
    template<typename T>
    double measure(const char* name, T callback, double reference) {

        initialize();

        printf("%*s ... ", -names.get_width(), names[name]);
        fflush(stdout);

        unsigned n = iterations;
        double time = -1;
        while (n-- > 0) {

            const auto t1 = get_time();
            callback(input.get(), get_input_size(), output.get());
            const auto t2 = get_time();

            const double t = (t2 - t1)/1000000.0;
            if (time < 0) {
                time = t;
            } else {
                time = std::min(time, t);
            }
        }

        if (reference > 0.0) {
            printf("%0.5f (speed up: %0.2f)", time, reference/time);
        } else {
            printf("%0.5f", time);
        }

        putchar('\n');

        return time;
    }
};


int main(int argc, char* argv[]) {

    FunctionRegistry registry;
    CommandLine cmd(argc, argv);
    Application app(cmd, registry);

    return app.run();
}

