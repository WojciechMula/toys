#include <random>
#include <vector>
#include <thread>
#include <limits>
#include <cstdio>
#include <cassert>

#include "argparse.cpp"

constexpr size_t max_errors = 3;
constexpr size_t buffer_size = 32*1024;
constexpr size_t cases_count = 10 * 1024 * buffer_size;

struct Error {
    uint32_t mask;
    uint32_t data;
    uint32_t got;
    uint32_t want;
};

struct State {
    std::mt19937 random_engine;
    std::uniform_int_distribution<uint32_t> random_u32;

    std::vector<Error> failures;
    std::vector<uint32_t> data;
    std::vector<uint32_t> mask;
    std::vector<uint32_t> ref;
    std::vector<uint32_t> res;

    State(std::random_device& rd)
        : random_engine{rd()}
        , random_u32{0, std::numeric_limits<uint32_t>::max()}
        , data(buffer_size)
        , mask(buffer_size)
        , ref(buffer_size)
        , res(buffer_size)
    {}

    void fill_buffers() {
        for (size_t i=0; i < buffer_size; i++) {
            data[i] = random_u32(random_engine);
            mask[i] = random_u32(random_engine);
        }
    }

    bool check() {
        for (size_t i=0; i < buffer_size; i++) {
            if (ref[i] == res[i]) {
                continue;
            }

            Error err;
            err.mask = mask[i];
            err.data = data[i];
            err.got  = res[i];
            err.want = ref[i];

            if (failures.size() == max_errors) {
                return false;
            }

            failures.push_back(err);
        }

        return true;
    }
};

struct Options {
    std::vector<std::string> fragments;
    std::optional<size_t> max_threads;
};

class ApplicationBase {
protected:
    Options opts;
    function_names_t names;

public:
    ApplicationBase(Options opts) : opts{opts}, names{function_names()} {}

protected:
    unsigned int thread_count() {
        if (opts.max_threads) {
            return opts.max_threads.value();
        }

        const unsigned int n = std::thread::hardware_concurrency();
        if (n == 0) {
            return 1;
        }

        return n;
    }

    bool can_run(const std::string& name) const {
        for (const auto& arg: opts.fragments) {
            if (name.find(arg) == std::string::npos) {
                return false;
            }
        }

        return true;
    }
};

Options parse_args(int argc, char* argv[]) {
    Arguments args{argc, argv};

    Options ret;
    ret.max_threads = args.consume_usize("--max-threads", 1);
    ret.fragments = args.consume_remaining();

    return ret;
}
