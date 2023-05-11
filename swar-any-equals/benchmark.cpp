#include <cstdio>
#include <cstdint>
#include <cstdlib>

#include "benchmark.h"
#include "reference.h"
#include "better.h"
#include "subtract.h"

void __attribute__ ((noinline)) reference() {
    find_authority_delimiter_special_reference(0x0102030405060708);
}

void __attribute__ ((noinline)) better() {
    find_authority_delimiter_special_better(0x0102030405060708);
}

void __attribute__ ((noinline)) subtract() {
    find_authority_delimiter_special_subtract(0x0102030405060708);
}

int main() {
    const size_t repeat = 1000000;
    BEST_TIME(/**/, reference(), "reference", repeat, 1);
    BEST_TIME(/**/, better(),    "better",    repeat, 1);
    BEST_TIME(/**/, subtract(),  "subtract",  repeat, 1);
}
