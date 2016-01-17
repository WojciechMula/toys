#include <cstdlib>
#include <cstdio>
#include <cstdint>
#include <memory>

#include "encode.cpp"
#include "../../gettime.cpp"
#include "../../cmdline.cpp"

class Application final {

    const CommandLine& cmd;
    const unsigned size;
    const unsigned iterations;

    std::unique_ptr<uint8_t> input;
    std::unique_ptr<uint8_t> output;
public:
    Application(const CommandLine& c)
        : cmd(c)
        , size(32*1024*1024)
        , iterations(10) {}

    void initialize() {
        
        input.reset (new uint8_t[size*3]);
        output.reset(new uint8_t[size*4]);

        printf("input size: %d\n", size*3);

        for (unsigned i=0; i < size*3; i++) {
            input.get()[i] = i * 71;
        }
    }

    int run() {
        double time = 0.0;

        if (cmd.empty() || cmd.has("1")) {
            time = measure("version 1", encode_triplets_1, 0.0);
        }

        if (cmd.empty() || cmd.has("2")) {
            measure("version 2", encode_triplets_2, time);
        }

        if (cmd.empty() || cmd.has("3")) {
            measure("version 3", encode_triplets_3, time);
        }

        if (cmd.empty() || cmd.has("4")) {
            measure("version 4", encode_triplets_4, time);
        }

        if (cmd.empty() || cmd.has("5")) {
            measure("version 5", encode_triplets_5, time);
        }

        if (cmd.empty() || cmd.has("6")) {
            measure("version 6", encode_triplets_6, time);
        }

        if (cmd.empty() || cmd.has("7")) {
            measure("version 7", encode_triplets_7, time);
        }

#if defined(HAVE_BMI2_INSTRUCTION)
        if (cmd.empty() || cmd.has("8")) {
            measure("version 8", encode_triplets_8, time);
        }

        if (cmd.empty() || cmd.has("9")) {
            measure("version 9", encode_triplets_9, time);
        }

        if (cmd.empty() || cmd.has("10")) {
            measure("version 10", encode_triplets_10, time);
        }
#endif

        return 0;
    }

private:
    template<typename T>
    double measure(const char* name, T callback, double reference_time) {

        printf("%s... ", name);
        fflush(stdout);

        unsigned n = iterations;
        double time = -1;
        while (n-- > 0) {

            const auto t1 = get_time();
            callback(input.get(), size, output.get());
            const auto t2 = get_time();

            const double t = (t2 - t1)/1000000.0;
            if (time < 0) {
                time = t;
            } else {
                time = std::min(time, t);
            }
        }

        if (reference_time > 0.0) {
            printf("%0.3f (speed up: %5.2f)\n", time, reference_time/time);
        } else {
            printf("%0.3f\n", time);
        }
        return time;
    }
};


int main(int argc, char* argv[]) {

    CommandLine cmd(argc, argv);
    Application app(cmd);

    app.initialize();
    return app.run();
}

