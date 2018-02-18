#pragma once

#include <vector>
#include "MultipleAndInterface.h"

class SequentialAndZeroTracking: public MultipleAndInterface {

protected:
    std::vector<bitvector*> input;
    std::vector<char> zero;
    const size_t block_size = 64;

public:
    SequentialAndZeroTracking(const std::vector<bitvector*>& input_)
        : input(input_) {
     
        assert(input.size() >= 2);

        const size_t n = (input[0]->n + block_size - 1) / block_size;
        zero.resize(n);
    }

    virtual std::unique_ptr<bitvector> calculate() override {

        bitvector* bv = new bitvector(*input[0]);

#if 0
#   define TRACE(msg, ...) printf(msg, __VA_ARGS__)
#else
#   define TRACE(msg, ...)
#endif

        size_t zero_blocks = 0;
        for (size_t i=1; i < input.size(); i++) {
            TRACE("bitmap %lu of %lu\n", i, input.size() - 1);
            for (size_t j=0; j < zero.size(); j++) {
                if (zero[j]) {
                    continue; // skip zero block
                }

                const size_t start = j * block_size;
                const size_t end   = std::min(start + block_size, bv->n);

                uint64_t nonzero = 0;
                for (size_t p=start; p < end; p++) {
                    bv->data[p] &= input[i]->data[p];
                    nonzero |= bv->data[p];
                }

                if (nonzero == 0) {
                    // the block is zero, skip in the future
                    TRACE("\tblock %lu will be skip\n", j);
                    zero[j] = 1;
                    zero_blocks += 1;
                }
            }

            if (zero_blocks == zero.size()) {
                TRACE("early exit after processing bitmap %lu\n", i);
                break; // all blocks are zero
            }
        }

        return std::unique_ptr<bitvector>(bv);
    }
};
