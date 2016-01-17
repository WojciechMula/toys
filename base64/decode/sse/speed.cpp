#include <cstdlib>
#include <cstdio>
#include <cstdint>
#include <memory>

#include "config.h"
#include "../../gettime.cpp"
#include "../../cmdline.cpp"

#include "decode.common.cpp"
#include "decode.scalar.cpp"
#include "decode.sse.cpp"

#include "application.cpp"

class Application final: public ApplicationBase {

public:
    Application(const CommandLine& c)
        : ApplicationBase(c) {}

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

private:
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

        putchar('\n');

        return time;
    }
};


int main(int argc, char* argv[]) {

    CommandLine cmd(argc, argv);
    Application app(cmd);

    return app.run();
}

