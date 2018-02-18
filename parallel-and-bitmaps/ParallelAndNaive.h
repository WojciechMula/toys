#pragma once

#include <vector>
#include <list>
#include <unordered_set>

#include <thread>
#include <mutex>
#include <atomic>

#include "MultipleAndInterface.h"


class ParallelAndNaive: public MultipleAndInterface {

    std::vector<bitvector*> input;
    std::unordered_set<bitvector*> allocated_by_us;

    std::list<bitvector*> queue;
    std::mutex queue_lock;   

    std::vector<std::thread> threads;
    size_t thread_count;

public:
    ParallelAndNaive(const std::vector<bitvector*>& input_, size_t thread_count_)
        : input(input_)
        , thread_count(thread_count_) {

        assert(input.size() >= 2);

        for (auto* bv: input) {
            queue.push_back(bv);
        }
    }

    virtual std::unique_ptr<bitvector> calculate() override {
        
        threads.reserve(thread_count);
        for (size_t i=0; i < thread_count; i++) {
            threads.push_back(std::thread(&ParallelAndNaive::and_pair, this));
        }

        for (auto& thread: threads) {
            thread.join();
        }

        assert(queue.size() == 1);
        assert(allocated_by_us.size() == 1);

        return std::unique_ptr<bitvector>(queue.front());
    }

private:

    struct Statistics {
        size_t processed_pairs = 0;
        
        void print() {}
    };

    void and_pair() {

        Statistics stats;

        bitvector* v1;
        bitvector* v2;
        bitvector* result;

        while (1) {
            // 1. get two items
            {
                std::lock_guard<std::mutex> lock(queue_lock);
                if (queue.size() < 2) {
                    if (allocated_by_us.size() == 1) { // no more items to process
                        break;
                    } else {
                        continue;
                    }
                }

                assert(queue.size() >= 2);
                
                v1 = queue.front();
                queue.pop_front();
                v2 = queue.front();
                queue.pop_front();

                result = allocate(*v1);
            }

            // 2. perform and
#if 0
            using Clock = std::chrono::high_resolution_clock;
            using std::chrono::duration_cast;
            using std::chrono::microseconds;
            const auto t1 = Clock::now();
            result->bitwise_and(*v1, *v2);
            const auto t2 = Clock::now();
            const auto t_us = duration_cast<microseconds>(t2 - t1).count();
            printf("%d, %luus\n", std::this_thread::get_id(), t_us);
#else
            result->bitwise_and(*v1, *v2);
#endif
            // 3. store result
            {
                std::lock_guard<std::mutex> lock(queue_lock);
                try_free(v1);   
                try_free(v2);   

                queue.push_back(result);
            }
        }

        stats.print();
    }

    bitvector* allocate(const bitvector& bv) {
        
        bitvector* result = new bitvector(bv.n);
        allocated_by_us.insert(result);

        return result;
    }

    void try_free(bitvector* bv) {
        if (bv == nullptr) {
            return;
        }

        auto it = allocated_by_us.find(bv);
        if (it != allocated_by_us.end()) {
            allocated_by_us.erase(it);
            delete bv;
        }

    }
};
