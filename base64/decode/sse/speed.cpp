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
#if defined(HAVE_AVX512_INSTRUCTIONS)
#   include "decoders.avx512.cpp"
#endif

#include "function_registry.cpp"
#include "application.cpp"

class Application final: public ApplicationBase {

    bool print_csv;

public:
    Application(const CommandLine& c, const FunctionRegistry& r)
        : ApplicationBase(c, r) {

        print_csv = cmd.has_flag("csv");
        quiet     = print_csv;
    }

    int run() {
        double reference = 0.0;

#define RUN(name, function) \
        if (cmd.empty() || cmd.has(name)) { \
            const double ret = measure(name, function, reference); \
            if (reference == 0.0) { \
                reference = ret; \
            } \
        }


#define RUN_TEMPLATE1(name, decode_fn, lookup_fn) \
        if (cmd.empty() || cmd.has(name)) { \
            auto function = [](const uint8_t* input, size_t size, uint8_t* output) { \
                return decode_fn(lookup_fn, input, size, output); \
            }; \
            const double ret = measure(name, function, reference); \
            if (reference == 0.0) { \
                reference = ret; \
            } \
        }

#define RUN_TEMPLATE2(name, decode_fn, lookup_fn, pack_fn) \
        if (cmd.empty() || cmd.has(name)) { \
            auto function = [](const uint8_t* input, size_t size, uint8_t* output) { \
                return decode_fn(lookup_fn, pack_fn, input, size, output); \
            }; \
            const double ret = measure(name, function, reference); \
            if (reference == 0.0) { \
                reference = ret; \
            } \
        }

#define RUN_SSE_TEMPLATE1 RUN_TEMPLATE1
#define RUN_AVX2_TEMPLATE1 RUN_TEMPLATE1
#define RUN_SSE_TEMPLATE2 RUN_TEMPLATE2
#define RUN_AVX2_TEMPLATE2 RUN_TEMPLATE2

        #include "run_all.cpp"

        return 0;
    }

private:
    template<typename T>
    double measure(const char* name, T callback, double reference) {

        initialize();

        if (print_csv) {
            const auto& fn = names.get(name);
            printf("%s, %s, %s", fn.display_name.c_str(), fn.lookup_method.c_str(), fn.pack_method.c_str());
        } else {
            printf("%*s ... ", -names.get_width(), names[name]);
        }

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

        if (print_csv) {
            printf(", %0.5f\n", time);
        } else {
            if (reference > 0.0) {
                printf("%0.5f (speed up: %0.2f)", time, reference/time);
            } else {
                printf("%0.5f", time);
            }
            putchar('\n');
        }


        return time;
    }
};


int main(int argc, char* argv[]) {

    FunctionRegistry registry;
    CommandLine cmd(argc, argv);
    Application app(cmd, registry);

    return app.run();
}

