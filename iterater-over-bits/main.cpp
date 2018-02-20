#include <chrono>
#include <vector>

#include <cstdio>

#include "bitvector.h"

#ifdef __GNUC__
#   define NOINLINE __attribute__((noline))
#else
#   define NOINLINE
#endif

size_t callback_function(size_t index) {
    return index;
}


void testcase(const bitvector& bv, int iterations, size_t (*cb_fun)(size_t)) {
    using clock = std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::microseconds;

    uint64_t ta;
    uint64_t tb;

    uint64_t n;
    auto callback = [&n, cb_fun](size_t i) {
#if 0
        n += cb_fun(i);
#else
        n += i;
#endif
    };

    {
        int tmp = iterations;
        volatile uint64_t k = 0;

        const auto t1 = clock::now();
        while (tmp--) {
            n = 0;
            bv.iterate_naive(callback);
            k += n;
        }
        const auto t2 = clock::now();

        ta = duration_cast<microseconds>(t2 - t1).count();
        printf("\t\tnaive:  %10ld us [%ld]\n", ta, k);
    }

    {
        int tmp = iterations;
        volatile uint64_t k = 0;

        const auto t1 = clock::now();
        while (tmp--) {
            n = 0;
            bv.iterate_better(callback);
            k += n;
        }
        const auto t2 = clock::now();

        tb = duration_cast<microseconds>(t2 - t1).count();
        printf("\t\tbetter: %10ld us [%ld]", tb, k);
        printf(" (%0.2f)\n", ta/double(tb));
    }


    {
        int tmp = iterations;
        volatile uint64_t k = 0;

        const auto t1 = clock::now();
        while (tmp--) {
            n = 0;
            bv.iterate_block3(callback);
            k += n;
        }
        const auto t2 = clock::now();

        tb = duration_cast<microseconds>(t2 - t1).count();
        printf("\t\tblock3: %10ld us [%ld]", tb, k);
        printf(" (%0.2f)\n", ta/double(tb));
    }

    {
        int tmp = iterations;
        volatile uint64_t k = 0;

        const auto t1 = clock::now();
        while (tmp--) {
            n = 0;
            bv.iterate_block4(callback);
            k += n;
        }
        const auto t2 = clock::now();

        tb = duration_cast<microseconds>(t2 - t1).count();
        printf("\t\tblock4: %10ld us [%ld]", tb, k);
        printf(" (%0.2f)\n", ta/double(tb));
    }
}


template <typename INITIALIZER>
void test(const char* info, const std::vector<size_t>& sizes, int iterations, INITIALIZER initalizer) {

    bool print = true;
    for (size_t i: sizes) {
        bitvector bv(i);   
        initalizer(bv);
        if (print) {
            printf("%s\n", info);
            print = false;
        }
        printf("\tsize=%lu, cardinality=%lu\n", bv.size(), bv.cardinality());

        testcase(bv, iterations, callback_function);
    }
}


int main() {
 
    const std::vector<size_t> sizes = {64, 256, 1024, 4096, 8192};

    test("empty", sizes, 10000, [](bitvector& bv) {bv.fill(0);});
    test("1/4",   sizes,  1000, [](bitvector& bv) {bv.fill(0x000000000000ffff);});
    test("1/2",   sizes,  1000, [](bitvector& bv) {bv.fill(0x00000000ffffffff);});
    test("3/4",   sizes,  1000, [](bitvector& bv) {bv.fill(0x0000ffffffffffff);});
    test("full",  sizes,  1000, [](bitvector& bv) {bv.fill(0xffffffffffffffff);});
    test("rand",  sizes,  1000, [](bitvector& bv) {bv.fill_random(80);});
    test("rand2", sizes,  1000, [](bitvector& bv) {bv.fill_random(5);});
    return 0;
}

