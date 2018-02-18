#pragma once

#include "bitvector.h"
#include <memory>

class MultipleAndInterface {
public:
    virtual std::unique_ptr<bitvector> calculate() = 0;
};
