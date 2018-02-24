#pragma once

#include "bitvector.h"
#include "time.h"
#include <memory>

class MultipleAndInterface {
public:
    virtual std::unique_ptr<bitvector> calculate() = 0;
};
