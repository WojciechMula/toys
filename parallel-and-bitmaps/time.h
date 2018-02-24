#pragma once

#include <chrono>
#include <cstdio>

#ifdef TIME
    using Clock = std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::microseconds;
    #define timepoint(name) const auto name = Clock::now()
    #define print_time(info, t0, t1) printf("%s: %lu us\n", (info), duration_cast<microseconds>((t1) - (t0)).count())
#else
    #define timepoint(name)
    #define print_time(info, t1, t0)
#endif

