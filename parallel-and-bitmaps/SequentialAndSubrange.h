#pragma once

#include <vector>
#include "MultipleAndInterface.h"

class SequentialAndSubrange: public MultipleAndInterface {

protected:
    std::vector<bitvector*> input;
    const size_t start;
    const size_t end;

public:
    SequentialAndSubrange(const std::vector<bitvector*>& input_, size_t start_, size_t end_)
        : input(input_)
        , start(start_)
        , end(end_) {
        
        assert(start <= end);
    }

    virtual std::unique_ptr<bitvector> calculate() override {

        const size_t k = end - start;
        assert(k >= 2);

        bitvector* bv = new bitvector(input[start]->n);

        bv->bitwise_and(*input[start], *input[start + 1]);
        for (size_t i=start + 2; i < end; i++) {
            bv->bitwise_and(*input[i]);
        }

        return std::unique_ptr<bitvector>(bv);
    }
};
