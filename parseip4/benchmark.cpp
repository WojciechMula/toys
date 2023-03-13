#include "benchmark.h"

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "common.h"
#include "naive.cpp"
#include "glibc_ref.cpp"
#include "sse.cpp"

class Application {
private:
    std::vector<std::string> addresses;

public:
    Application() {
        for (uint64_t tmp = 0; tmp <= 0xffffffff; tmp += 881) {
            uint32_t ipv4 = tmp;
            addresses.push_back(ipv4str(ipv4));
        }

        printf("size: %lu\n", addresses.size());
    }

    void run() {
        benchmark("naive",      naive_parse_ipv4);
        benchmark("glibc",      glibc_parse_ipv4);
        benchmark("naive (no validation)", naive_parse_ipv4_no_validation);
        benchmark("SSE",        sse_parse_ipv4);
        benchmark("SSE (v2)",   sse_parse_ipv4_v2);
        benchmark("SSE (v3)",   sse_parse_ipv4_v3);
        benchmark("SSE (v4)",   sse_parse_ipv4_v4);
        benchmark("SSE (v5)",   sse_parse_ipv4_v5);
        benchmark("SSE (v6)",   sse_parse_ipv4_v6);
        benchmark("SSE (v7)",   sse_parse_ipv4_v7);
    }

private:
    template <typename FUNCTION>
    void benchmark(const char* name, FUNCTION function) {
        
        auto fn = [this, function]() {
            for (const auto& ipv4: addresses) {
                (void)function(ipv4);
            }
        };

        const size_t size = addresses.size();

        BEST_TIME(/**/, fn(), name, 10, size);
    }

    static std::string ipv4str(uint32_t x) {
        char tmp[16];
        sprintf(tmp, "%d.%d.%d.%d", (x >> 24), (x >> 16) & 0xff, (x >> 8) & 0xff, x & 0xff);

        return tmp;
    }
};

int main() {
    Application app{};
    app.run();

    return EXIT_SUCCESS;
}
