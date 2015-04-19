/*
	Convert to binary representation - verification util

	Author  : Wojciech Muła
	Date    : 2014-09-11
	License : BSD
*/


#include <cstdio>
#include <cstdint>
#include <cstring>
#include <assert.h>


#include "config.h"
#include "conv_to_bin.cpp"


void verify() {
	for (int i=0; i < 256; i++) {
        const uint64_t naive = convert_to_bin::naive(i);
        const uint64_t swar  = convert_to_bin::swar(i);
        const uint64_t swar2 = convert_to_bin::swar2(i);
        const uint64_t simd  = convert_to_bin::simd(i);
        const uint64_t pdep  = convert_to_bin::pdep(i);

        if (naive != swar) {
            std::printf("failed SWAR for %d: %016llx != %016llx\n", i, naive, swar);
            return;
        }

        if (naive != swar2) {
            std::printf("failed SWAR2 for %d: %016llx != %016llx\n", i, naive, swar2);
            return;
        }

        if (naive != simd) {
            std::printf("failed SIMD for %d: %016llx != %016llx\n", i, naive, simd);
            return;
        }

        if (naive != pdep) {
            std::printf("failed PDEP for %d: %016llx != %016llx\n", i, naive, pdep);
            return;
        }
	}

    std::puts("all ok");
}


// ------------------------------------------------------------------------


int main() {

    convert_to_bin::prepare_lookup();
    verify();
}

