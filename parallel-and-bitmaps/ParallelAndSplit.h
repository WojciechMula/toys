#pragma once

#include <vector>
#include <list>
#include <unordered_set>

#include <thread>

#include "MultipleAndInterface.h"
#include "SequentialAndSubrange.h"
#include "SequentialAnd.h"


class ParallelAndSplit: public MultipleAndInterface {

    std::vector<bitvector*> input;
    std::vector<bitvector*> results;

    std::vector<std::thread> threads;
    size_t thread_count;

public:
    ParallelAndSplit(const std::vector<bitvector*>& input_, size_t thread_count_)
        : input(input_)
        , thread_count(thread_count_) {

        assert(input.size() >= 2);
    }

    virtual std::unique_ptr<bitvector> calculate() override {

        threads.reserve(thread_count);
        size_t start = 0;
        size_t end;
        const size_t avg = input.size() / thread_count;

        results.resize(thread_count);
        for (size_t i=0; i < thread_count; i++) {
            
            if (i == thread_count - 1) {
                end = input.size();
            } else {
                end = start + avg;
            }

            threads.push_back(std::thread(&ParallelAndSplit::and_pair, this, i, start, end));
            start = end;
        }

        for (auto& thread: threads) {
            thread.join();
        }

        SequentialAnd seq(results);

        return seq.calculate();
    }

private:

    void and_pair(size_t index, size_t start, size_t end) {

        SequentialAndSubrange seq(input, start, end);
        results[index] = seq.calculate().release();
    }

};

