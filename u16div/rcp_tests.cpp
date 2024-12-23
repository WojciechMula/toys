#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <immintrin.h>
#include <limits>
#include <map>
#include <vector>
#include <thread>

__m128 nr_step(const __m128 x0, const __m128 a) {
    // f(x) = 1/x - a
    // f'(x) = -1/x^2
    //
    // x_{n+1} = x_n - f(x_n)/f'(x_n) = x_n = x_n + x_n^2 (1/x_n - a) = x_n + x_n - x_n^2*a = 2x_n - x_n^2*a

    const __m128 t0 = _mm_add_ps(x0, x0); // 2x_n
    const __m128 t1 = _mm_mul_ps(x0, x0); // x_n^2
    const __m128 t2 = _mm_mul_ps(t1, a);  // x_n^2 * a
    const __m128 t3 = _mm_sub_ps(t0, t2); // 2x_n - x_n^2 * a

    return t3;
}

__m128 nr_inv(const __m128 a) {
    const __m128 x0 = _mm_rcp_ps(a);

    const __m128 x1 = nr_step(x0, a);

    return x1;
}

uint32_t sse_div_u16_rcp(uint32_t a, uint32_t b) {
    const __m128i a_u16 = _mm_cvtsi32_si128(a);
    const __m128i a_u32 = _mm_cvtepu16_epi32(a_u16);
    const __m128  a_f32 = _mm_cvtepi32_ps(a_u32);

    const __m128i b_u16 = _mm_cvtsi32_si128(b);
    const __m128i b_u32 = _mm_cvtepu16_epi32(b_u16);
    const __m128  b_f32 = _mm_cvtepi32_ps(b_u32);

    const __m128  b_inv_f32 = nr_inv(b_f32);
    const __m128  c_f32 = _mm_mul_ps(_mm_mul_ps(a_f32, _mm_set1_ps(1.000001)), b_inv_f32);

    const __m128i c_i32 = _mm_cvttps_epi32(c_f32);

    const uint32_t buf  = _mm_cvtsi128_si32(c_i32);

    return buf;
}

struct Stats {
    std::map<int, uint64_t> hist;
};


void check(uint32_t bmin, uint32_t bmax, Stats* stats) {
    for (uint32_t b=bmin; b <= bmax; b++) {
        for (uint32_t a=0; a < 65536; a++) {
            const uint32_t ref = a / b;

            const uint32_t got = sse_div_u16_rcp(a, b);
            const int diff = (int)ref - (int)got;
            stats->hist[diff] += 1;
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


int main() {
    const unsigned int num_cpus = thread_count();
    std::vector<Stats> stats;
    std::vector<std::thread> threads;
    threads.reserve(num_cpus);

    for (unsigned int i=0; i < num_cpus; i++) {
        stats.push_back(Stats{});
    }
    
    const uint32_t max = 65535;
    const uint32_t b_inc = max / num_cpus;

    uint32_t bmin = 1;
    for (unsigned int i=0; i < num_cpus; i++) {
        uint32_t bmax = bmin + b_inc;
        if (i + 1 == num_cpus) {
            bmax = max;
        }

        printf("thread #%d: [%d,%d]\n", i, bmin, bmax);

        threads.push_back(std::thread(check, bmin, bmax, &stats[i]));

        bmin = bmax + 1;
    }

    Stats total;
    for (unsigned int i=0; i < num_cpus; i++) {
        threads[i].join();
        for (const auto& n: stats[i].hist) {
            total.hist[n.first] += n.second;
        }
    }

    puts("difference => cases count");
    for (const auto& n: total.hist) {
        printf("%4d => %lu\n", n.first, n.second);
    }

    if (total.hist.size() == 1) {
        puts("");
        puts("All passed!");
    }

    return 0;
}
