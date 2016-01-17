#include <cstdlib>
#include <cstdio>
#include <cstdint>
#include <memory>

#include "config.h"
#include "../../gettime.cpp"
#include "../../cmdline.cpp"
#include "../../fnv32.cpp"

#include "decode.common.cpp"
#include "decode.scalar.cpp"
#include "decode.sse.cpp"

#include "application.cpp"

class Application final {

protected:
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

        base64::scalar::initialize();

        input.reset (new uint8_t[get_input_size()]);
        output.reset(new uint8_t[get_output_size()]);

        printf("input size: %lu\n", get_input_size());

        fill_input();

        initialized = true;
    }

    int run() {
        double reference = 0.0;

        if (cmd.empty() || cmd.has("scalar1")) {
            reference = measure("scalar1", base64::scalar::decode_lookup1, 0.0);
        }

        if (cmd.empty() || cmd.has("scalar2")) {
            measure("scalar2", base64::scalar::decode_lookup2, reference);
        }

        if (cmd.empty() || cmd.has("sse")) {
            measure("SSE", base64::sse::decode, reference);
        }

        return 0;
    }

    template<typename T>
    double measure(const char* name, T callback, double reference) {

        initialize();

        printf("%20s... ", name);
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
            printf("%0.3f (speed up: %0.2f)", time, reference/time);
        } else {
            printf("%0.3f", time);
        }

        printf(" hash: %08x\n", FNV32::get(reinterpret_cast<const char*>(output.get()), get_output_size()));

        return time;
    }

protected:
    size_t get_input_size() const {
        return count;
    }

    size_t get_output_size() const {
        return (3*count)/4;
    }

    void fill_input() {
        for (unsigned i=0; i < get_input_size(); i++) {
            const uint8_t idx = i * 71;
            input.get()[i] = base64::lookup[idx % 64];
        }
    }

    void clear_output() {
        memset(output.get(), 0, get_output_size());
    }
};


int main(int argc, char* argv[]) {

    CommandLine cmd(argc, argv);
    Application app(cmd);

    return app.run();
}

