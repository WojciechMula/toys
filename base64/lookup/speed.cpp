#include <cstdlib>
#include <cstdio>
#include <cstdint>
#include <memory>

#include "config.h"
#include "../gettime.cpp"
#include "../cmdline.cpp"
#include "fnv32.cpp"

#include "encode.scalar.cpp"
#include "lookup.sse.cpp"
#include "encode.sse.cpp"


class Application final {

    const CommandLine& cmd;
    const unsigned count;
    const unsigned iterations;
    bool initialized;

    std::unique_ptr<uint8_t> input;
    std::unique_ptr<uint8_t> output;
public:
    Application(const CommandLine& c)
        : cmd(c)
        , count(64*1024*1024)
        , iterations(10)
        , initialized(false) {}

    void initialize() {

        if (initialized) {
            return;
        }
        
        input.reset (new uint8_t[get_input_size()]);
        output.reset(new uint8_t[get_output_size()]);

        printf("input size: %lu\n", get_input_size());

        fill_input();

        initialized = true;
    }

    int run() {
        if (cmd.empty() || cmd.has("scalar32")) {
            measure("scalar32", base64::scalar::encode32);
        }

        if (cmd.empty() || cmd.has("scalar64")) {
            measure("scalar64", base64::scalar::encode64);
        }

        auto sse_naive = [](uint8_t* input, size_t bytes, uint8_t* output) {
            base64::sse::encode(base64::sse::lookup_naive, input, bytes, output);
        };

        auto sse_optimized1 = [](uint8_t* input, size_t bytes, uint8_t* output) {
            base64::sse::encode(base64::sse::lookup_version1, input, bytes, output);
        };

        auto sse_optimized2 = [](uint8_t* input, size_t bytes, uint8_t* output) {
            base64::sse::encode(base64::sse::lookup_version2, input, bytes, output);
        };

        if (cmd.empty() || cmd.has("sse")) {
            measure("SSE (naive)", sse_naive);
        }

        if (cmd.empty() || cmd.has("sse1")) {
            measure("SSE (optimized v1)", sse_optimized1);
        }

        if (cmd.empty() || cmd.has("sse2")) {
            measure("SSE (optimized v2)", sse_optimized2);
        }

#if defined(HAVE_PEXT_INSTRUCTION)
        auto sse_bmi2_naive = [](uint8_t* input, size_t bytes, uint8_t* output) {
            base64::sse::encode_bmi2(base64::sse::lookup_naive, input, bytes, output);
        };

        auto sse_bmi2_optimized = [](uint8_t* input, size_t bytes, uint8_t* output) {
            base64::sse::encode_bmi2(base64::sse::lookup_version1, input, bytes, output);
        };

        if (cmd.empty() || cmd.has("bmi1")) {
            measure("SSE & BMI2 (naive)", sse_bmi2_naive);
        }

        if (cmd.empty() || cmd.has("bmi2")) {
            measure("SSE & BMI2 (optimized)", sse_bmi2_optimized);
        }
#endif

        if (cmd.has("check")) {
            uint32_t valid;
            valid = check("scalar32", base64::scalar::encode32, 0);
            check("scalar64", base64::scalar::encode64, valid);
            check("SSE (naive)", sse_naive, valid);
            check("SSE (optimized v1)", sse_optimized1, valid);
            check("SSE (optimized v2)", sse_optimized2, valid);
#if defined(HAVE_PEXT_INSTRUCTION)
            check("SSE & BMI2 (naive)", sse_bmi2_naive, valid);
            check("SSE & BMI2 (optimized)", sse_bmi2_optimized, valid);
#endif
        }

        return 0;
    }

private:
    size_t get_input_size() const {
        return 3*count;
    }

    size_t get_output_size() const {
        return 4*count;
    }

    void fill_input() {
        for (unsigned i=0; i < get_input_size(); i++) {
            input.get()[i] = i * 71;
        }
    }

    void clear_output() {
        memset(output.get(), 0, get_output_size());
    }

    template<typename T>
    double measure(const char* name, T callback) {

        initialize();

        printf("%s... ", name);
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

        printf("%0.3f\n", time);
        return time;
    }

    template<typename T>
    uint32_t check(const char* name, T callback, uint32_t valid) {

        initialize();

        printf("%20s... ", name);
        fflush(stdout);

        clear_output();
        callback(input.get(), get_input_size(), output.get());

        const uint32_t result = FNV32::get(reinterpret_cast<const char*>(output.get()), get_output_size() - 16);

        if (valid != 0) {
            printf("%08x %s\n", result, (valid != result) ? "!!!ERROR!!!" : "OK");
        } else {
            printf("%08x\n", result);
        }
        return result;
    }
};


int main(int argc, char* argv[]) {

    CommandLine cmd(argc, argv);
    Application app(cmd);

    return app.run();
}

