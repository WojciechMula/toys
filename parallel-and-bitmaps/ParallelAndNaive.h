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
    std::unordered_set<bitvector*> free;

    std::list<bitvector*> queue;
    std::mutex queue_lock;
    size_t awaiting = 0;

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
        bitvector* result = queue.front();
        for (bitvector* bv: allocated_by_us) {
            if (bv != result)
                delete bv;
        }

        return std::unique_ptr<bitvector>(result);
    }

private:

    void and_pair() {

        bitvector* v1;
        bitvector* v2;
        bitvector* result;

        enum class Operation {
            v1_inplace,
            v2_inplace,
            new_vector
        };


        while (1) {
            timepoint(t0);
            // 1. get two items
            Operation op;
            {
                std::lock_guard<std::mutex> lock(queue_lock);
                if (queue.size() < 2) {
                    if (awaiting == 0) {
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

                if (is_our_bitvector(v1)) {
                    op = Operation::v1_inplace;
                    result = v1;
                } else if (is_our_bitvector(v2)) {
                    op = Operation::v2_inplace;
                    result = v2;
                } else {
                    op = Operation::new_vector;
                    result = allocate(*v1);
                }

                awaiting += 1;
            }

            // 2. perform and
            timepoint(t1);
            switch (op) {
                case Operation::v1_inplace:
                    v1->bitwise_and(*v2);
                    break;

                case Operation::v2_inplace:
                    v2->bitwise_and(*v1);
                    break;

                case Operation::new_vector:
                    result->bitwise_and(*v1, *v2);
                    break;
            }
            timepoint(t2);

            // 3. store result
            {
                std::lock_guard<std::mutex> lock(queue_lock);
                if (op != Operation::v1_inplace) {
                    try_free(v1);
                }

                if (op != Operation::v2_inplace) {
                    try_free(v2);
                }

                queue.push_back(result);
                awaiting -= 1;
            }
            timepoint(t3);

#ifdef TIME
            printf("thread %d\n", std::this_thread::get_id());
            print_time("wait", t0, t1);
            print_time("and", t1, t2);
            print_time("save", t2, t3);
#endif
        }
    }

    bitvector* allocate(const bitvector& bv) {

        bitvector* result;

        if (free.empty()) {
            result = new bitvector(bv.n);
            allocated_by_us.insert(result);
        } else {
            auto any = free.begin();
            result = *any;
            free.erase(any);
        }

        return result;
    }

    void try_free(bitvector* bv) {
        if (bv == nullptr) {
            return;
        }

        auto it = allocated_by_us.find(bv);
        if (it != allocated_by_us.end()) {
            free.insert(bv);
        }

    }

    bool is_our_bitvector(bitvector* bv) const {
        return allocated_by_us.count(bv);
    }
};
