#include <random>
#include <vector>
#include <thread>
#include <limits>
#include <cstdio>
#include <cassert>

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