#include <chrono>

#include "SequentialAnd.h"
#include "SequentialAndZeroTracking.h"
#include "ParallelAndNaive.h"
#include "ParallelAndSplit.h"

using Clock = std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::microseconds;

void test(const char* info, MultipleAndInterface& ma, const std::vector<bitvector*> input) {

    assert(input.size() >= 2);

    printf("%-30s (%lu bitmaps): ", info, input.size());
    fflush(stdout);

    const auto t1 = Clock::now();
    auto res = ma.calculate();
    const auto t2 = Clock::now();

    const auto t_us = duration_cast<microseconds>(t2 - t1).count();
    printf("%10luus [cardinality=%lu]\n", t_us, res->cardinality());
}

int main() {
    
    const size_t bitmap_size = 1000000;
    const size_t count = 100;

    std::vector<bitvector*> input;
    srand(0);
    for (size_t i=0; i < count; i++) {
        bitvector* bv = new bitvector(bitmap_size);
        bv->fill_random(50);

        input.push_back(bv);
    }

    SequentialAnd seq(input);
    test("SequentialAnd", seq, input);

    SequentialAndZeroTracking seq2(input);
    test("SequentialAndZeroTracking", seq2, input);

    ParallelAndNaive par1(input, 4);
    test("ParallelAndNaive", par1, input);

    ParallelAndSplit par2(input, 4);
    test("ParallelAndSplit", par2, input);
}
