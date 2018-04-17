#include "linux-perf-events.h"
#include <cstdio>

int main() {

    LinuxEvents<PERF_TYPE_HARDWARE> misses(PERF_COUNT_HW_BRANCH_MISSES);
    LinuxEvents<PERF_TYPE_HARDWARE> branches(PERF_COUNT_HW_BRANCH_INSTRUCTIONS);

    misses.start();
    branches.start();

    for (int i=0; i < 100; i++) {
        printf("sample instruction %d\n", i);
    }

    const auto b = branches.end();
    const auto m = misses.end();

    puts("");
    printf("branches: %lu, misses: %lu (miss ratio: %0.2f%%)\n", b, m, (100.0 * m)/b);

}
