#pragma once

#include "SequentialAndSubrange.h"

class SequentialAnd: public SequentialAndSubrange {

public:
    SequentialAnd(const std::vector<bitvector*>& input_)
        : SequentialAndSubrange(input_, 0, input_.size()) {}
};
