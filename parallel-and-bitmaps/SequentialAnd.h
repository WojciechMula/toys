#pragma once

#include "MultipleAndInterface.h"

class SequentialAnd: public MultipleAndInterface {

    std::vector<bitvector*> input;

public:
    SequentialAnd(const std::vector<bitvector*>& input_) : input(input_) {}

    virtual std::unique_ptr<bitvector> calculate() override {

        const size_t k = input.size();
        assert(k >= 2);

        bitvector* bv = new bitvector(input[0]->n);

        bv->bitwise_and(*input[0], *input[1]);
        for (size_t i=2; i < k; i++) {
            bv->bitwise_and(*input[i]);
        }

        return std::unique_ptr<bitvector>(bv);
    }
};
