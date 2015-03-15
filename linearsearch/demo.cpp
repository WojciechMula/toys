#include <cstdio>
#include <cassert>

#include <string>
#include <sys/time.h>

#include "simple_list.hpp"
#include "simd_list.hpp"
#include "arglist.hpp"
#include "measure.hpp"


template <typename T>
void generate(int n, T& collection) {
    for (int i=0; i < n; i++) {
        collection.add(i, i);
    }
}


template <typename T>
int find_all(int n, T& collection) {
    
    int count = 0;

    for (int i=0; i < n; i++) {
        const auto result = collection.find(i);

        if (result != -1) {
            count += 1;
        }
    }

    return count;
}


template <typename Collection>
int run(Object& m, const std::size_t count, const std::size_t tries) {
    m.add("construction");
    m.add("search");

    std::printf("%s\n", m.name.c_str());

    auto result = 0;

    Collection list;
    {
        std::printf("* construction... ");
        std::fflush(stdout);
        auto c = scoped_timer<Timer>(m["construction"]);
        generate(count, list);

        std::printf("%.3fs\n", c.in_seconds());
    }

    std::printf("* search... [");
    std::fflush(stdout);
    for (std::size_t i=0; i < tries; i++) {
        auto c = scoped_timer<Timer>(m["search"]);

        result += find_all(count, list);

        std::putchar('.');
        std::fflush(stdout);
    }
    std::printf("] min=%.3f, max=%.3f, avg=%.3fs\n", m["search"].min(), m["search"].max(), m["search"].avg());

    return result;
}


void usage() {
    std::puts("usage: program [options]");
    std::puts("");
    std::puts("Options");
    std::puts("    --simple   measure time of simple linked list");
    std::puts("    --array4   measure time of linked arrays of size 4");
    std::puts("    --array8   measure time of linked arrays of size 8");
    std::puts("    --simd4    like --array4 but searched by SIMD code");
    std::puts("    --simd8    like --array8 but searched by SIMD code");
    std::puts("    --all      measure time of all structures");
    std::puts("    --help/-h  show this help");
}


int main(int argc, char* argv[]) {

    arglist args(argc, argv);
    Measure measure;

    const auto count = 20000;
    const auto tries = 5;

    volatile int total = 0;

    if ((args.size() < 1) || args("--help") || args("-h")) {
        usage();
        return 0;
    }

    if (args("--all") || args("--simple")) {
        typedef simple_list<int> list_type;
        total += run<list_type>(measure.add("list"), count, tries);
    }

    if (args("--all") || args("--array4")) {
        typedef block_list<int, 4> list_type;
        total += run<list_type>(measure.add("array list (4)"), count, tries);
    }

    if (args("--all") || args("--array8")) {
        typedef block_list<int, 8> list_type;
        total += run<list_type>(measure.add("array list (8)"), count, tries);
    }

    if (args("--all") || args("--simd4")) {
        typedef simd_list<int> list_type;
        total += run<list_type>(measure.add("SIMD array list (4)"), count, tries);
    }

    if (args("--all") || args("--simd8")) {
        typedef simd2_list<int> list_type;
        total += run<list_type>(measure.add("SIMD array list (8)"), count, tries);
    }

    if (measure.has("list")) {
        const auto ref = measure["list"]["search"].min();

        for (auto& m: measure) {
            const auto curr = (*m)["search"].min();

            printf("%-30s: %10.3fs, speedup %5.2f\n", m->name.c_str(), curr, ref/curr);
        }
    }
}
