#include <random>
#include <vector>
#include <thread>
#include <limits>
#include <cstdio>
#include <cassert>

#include "impl.cpp"
#include "unittest.cpp.inl"

void check_pdep(signature_t func, size_t iters, State* state) {
    for (size_t i=0; i < iters; i++) {
        state->fill_buffers();
        scalar_pdep_u32(state->data.data(), state->mask.data(), state->ref.data(), buffer_size);
        func(state->data.data(), state->mask.data(), state->res.data(), buffer_size);

        if (not state->check()) {
            return;
        }
    }
}

unsigned int thread_count() {
    const unsigned int n = std::thread::hardware_concurrency();
    if (n == 0) {
        return 1;
    }

    return n;
}

class Application {
    std::vector<std::string> args;
    function_names_t names;

public:
    Application(std::vector<std::string> args) : args{args}, names{function_names()} {}

    void run() {
        std::random_device random_device;

        #ifdef HAVE_AVX2
            test(avx2_pdep_u32, cases_count, random_device);
            test(avx2_pdep_u32_ee, cases_count, random_device);
        #endif

        #ifdef HAVE_AVX512
            test(avx512_pdep_u32, cases_count, random_device);
            test(avx512_pdep_u32_ee, cases_count, random_device);
            test(avx512_pdep_u32_ver2, cases_count, random_device);
            test(avx512_pdep_u32_ver2_ee, cases_count, random_device);
        #endif
    }

private:
    void test(signature_t func, size_t cases_count, std::random_device& rd) {
        const auto& name = names.at(func);
        if (not can_run(name)) {
            return;
        }
        printf("checking %s... ", name.c_str());
        fflush(stdout);

        const unsigned tc = thread_count();

        const size_t iter_count = cases_count / buffer_size;
        assert(iter_count > 0);

        std::vector<std::thread> threads;
        threads.reserve(tc);
        std::vector<State> states;
        states.reserve(tc);

        for (unsigned i=0; i < tc; i++) {
            states.push_back(State{rd});
        }

        for (unsigned i=0; i < tc; i++) {
            threads.push_back(std::thread(check_pdep, func, iter_count, &states[i]));
        }

        putchar('[');
        fflush(stdout);
        for (unsigned i=0; i < tc; i++) {
            threads[i].join();
            putchar('.');
            fflush(stdout);
        }
        puts("]");

        for (unsigned i=0; i < tc; i++) {
            for (const auto& err: states[i].failures) {
                printf("pdep(%08x, %08x) = %08x, got %08x\n",
                    err.data, err.mask, err.got, err.want);
            }
        }
    }

    bool can_run(const std::string& name) const {
        for (const auto& arg: args) {
            if (name.find(arg) == std::string::npos) {
                return false;
            }
        }

        return true;
    }
};

int main(int argc, char* argv[]) {
    std::vector<std::string> args;
    for (int i=1; i < argc; i++) {
        args.push_back(argv[i]);
    }

    auto app = Application{args};
    app.run();
}
