#include <cstdio>
#include <map>
#include <string>
#include <vector>
#include <thread>

#include "impl.cpp"

#define SIZE 65536

unsigned int thread_count() {
    const unsigned int n = std::thread::hardware_concurrency();
    if (n == 0) {
        return 1;
    }

    return n;
}

struct Error {
    size_t   index;
    uint32_t dividend;
    uint32_t divisor;
    uint16_t got;
    uint16_t want;
};

struct State {
    std::vector<Error> errors;

    bool is_ok() const {
        return errors.empty();
    }
};

void check_range(uint32_t bmin, uint32_t bmax, signature_t func, State* state) {
    uint16_t dividend_arr[SIZE + 64];
    uint16_t divisor_arr[SIZE + 64];
    uint16_t reference[SIZE + 64];
    uint16_t got[SIZE + 64];

    // 1. all values of dividend
    for (size_t i = 0; i < 65536; i++) {
        dividend_arr[i] = i;
    }

    // 2. iterate over divisor range
    int errors = 0;
    for (uint32_t divisor=bmin; divisor <= bmax; divisor++) {
        for (size_t i=0; i < 65536; i++) {
            divisor_arr[i] = divisor;
        }

        memset(got, 0, SIZE);
        scalar_div_u16(dividend_arr, divisor_arr, reference, SIZE);
        func(dividend_arr, divisor_arr, got, SIZE);

        for (size_t i=0; i < SIZE; i++) {
            if (got[i] != reference[i]) {
                auto err = Error{};
                err.index    = i;
                err.dividend = dividend_arr[i];
                err.divisor  = divisor_arr[i];
                err.got      = got[i];
                err.want     = reference[i];
                state->errors.push_back(err);

                errors += 1;
                if (errors == 10) {
                    return;
                }
            }
        }
    }
}

class Application {
    std::vector<std::string> args;
    bool all_ok;
    bool any_run;
    function_names_t names;

public:
    Application(std::vector<std::string> args)
        : args{args}
        , all_ok(false)
        , any_run(false)
        , names(function_names())
    {}

    void run() {
        all_ok = true;

        #ifdef HAVE_AVX2
            check(avx2_div_u16_cvtt);
            check(avx2_div_u16_cvtt_ver2);
            check(avx2_div_u16_rcp);
        #endif

        #ifdef HAVE_AVX512
            check(avx512_div_u16_cvtt);
            check(avx512_div_u16_cvtt_x4);
        #endif

        if (any_run) {
            if (all_ok) {
                puts("All OK");
            }
        } else {
            puts("none of tests matched arguments");
        }
    }

private:
    template<typename T>
    void check(T func) {
        const auto name = names[func];
        for (const auto& arg: args) {
            if (name.find(arg) == std::string::npos) {
                return;
            }
        }

        any_run = true;
        printf("checking %s... ", name.c_str());
        fflush(stdout);

        const unsigned int num_cpus = thread_count();
        std::vector<State> state;
        std::vector<std::thread> threads;
        threads.reserve(num_cpus);

        for (unsigned int i=0; i < num_cpus; i++) {
            state.push_back(State{});
        }

        const uint32_t max = 65535;
        const uint32_t b_inc = max / num_cpus;

        uint32_t bmin = 1;
        for (unsigned int i=0; i < num_cpus; i++) {
            uint32_t bmax = bmin + b_inc;
            if (i + 1 == num_cpus) {
                bmax = max;
            }

            threads.push_back(std::thread(check_range, bmin, bmax, func, &state[i]));

            bmin = bmax + 1;
        }

        bool first = true;
        bool ok = true;
        for (unsigned int i=0; i < num_cpus; i++) {
            threads[i].join();
            if (state[i].is_ok()) {
                continue;
            }

            ok = false;

            if (first) {
                putchar('\n');
                first = false;
            }
            for (const auto& err: state[i].errors) {
                printf("item #%lu (%d/%d)\n", err.index, err.dividend, err.divisor);
                printf(" got: %d\n", err.got);
                printf("want: %d\n", err.want);
            }
        }

        if (ok) {
            puts("OK");
        } else {
            all_ok = false;
        }
    }
};

int main(int argc, char* argv[]) {
    std::vector<std::string> args;
    for (int i=1; i < argc; i++) {
        args.push_back(argv[i]);
    }

    Application app{args};

    app.run();
}
