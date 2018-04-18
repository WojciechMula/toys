#pragma once

#include <chrono>
#include <cstdio>

using Clock = std::chrono::high_resolution_clock;

template <typename UNIT = std::chrono::microseconds>
Clock::time_point::rep elapsed(const Clock::time_point& t1, const Clock::time_point& t2) {
    return std::chrono::duration_cast<UNIT>(t2 - t1).count();
}

template <typename FUN>
Clock::time_point::rep measure_time(FUN fun) {

    const auto t1 = Clock::now();
    fun();
    const auto t2 = Clock::now();

    return elapsed(t1, t2);
}

template <typename FUN>
Clock::time_point::rep measure_time(const char* info, FUN fun) {

    printf("%s", info);
    fflush(stdout);
    const auto dt = measure_time(fun);
    printf("%lu us\n", dt);

    return dt;
}

template <typename FUN>
Clock::time_point::rep measure_total_time(FUN fun, int repeat_count) {

    const auto t1 = Clock::now();
    int k = repeat_count;
    while (k--) {
        volatile auto tmp = fun();
    }
    const auto t2 = Clock::now();

    return elapsed(t1, t2);
}

template <typename FUN>
Clock::time_point::rep measure_total_time(const char* info, FUN fun, int repeat_count) {

    printf("%s", info);
    fflush(stdout);
    const auto dt = measure_total_time(fun, repeat_count);
    printf("%lu us\n", dt);

    return dt;
}
