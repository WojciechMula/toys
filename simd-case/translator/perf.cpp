#include <cstdio>

#include "benchmark.h"

int switch_procedure(int);

const int start = 99;
const int end   = 2000;
const int range = end - start + 1;

void perf() {
    for (int i=start; i < end; i++)
        switch_procedure(i);
}

int main() {
    BEST_TIME(/**/, perf(), "switch_procedure", 1000, range);
}
