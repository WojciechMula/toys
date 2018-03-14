#include "time_utils.h"

#include <cstdio>


auto elapsed(const Clock::time_point& t1, const Clock::time_point& t2) {
    return std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
}

template <typename FUN>
void measure_time(const char* info, FUN fun) {
    
    printf("%s", info);
    fflush(stdout);
    const auto t1 = Clock::now();
    fun();
    const auto t2 = Clock::now();

    printf("%lu us\n", elapsed(t1, t2));
}

