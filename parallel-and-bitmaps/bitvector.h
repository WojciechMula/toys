#pragma once

#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <cassert>

class bitvector {

public:
    const size_t n;
    uint64_t* data;

public:
    bitvector(size_t n_) : n(n_) {
        assert(n > 0);
        data = new uint64_t[n];
    }

    bitvector(const bitvector& bv) : bitvector(bv.n) {

        memcpy(data, bv.data, n * sizeof(uint64_t));
    }

    ~bitvector() {
        delete[] data;
    }

    void fill(uint64_t word) {
        for (size_t i=0; i < n; i++)
            data[i] = word;
    }

    void fill_random(int threshold) {
        assert(threshold >= 0);
        assert(threshold <= 100);
        
        for (size_t i=0; i < n; i++) {
            if ((rand() % 100) > threshold) {
                data[i] = -1;
            } else {
                data[i] = 0;
            }
        }
    }

    size_t size() const {
        return n * 64;
    }

    size_t cardinality() const {
        size_t k = 0;
        for (size_t i=0; i < n; i++) {
            k += __builtin_popcountll(data[i]);
        }

        return k;
    }

    void bitwise_and(const bitvector& v1, const bitvector& v2) {
        for (size_t i=0; i < n; i++) {
            data[i] = v1.data[i] & v2.data[i];
        }
    }

    void bitwise_and(const bitvector& v) {
        for (size_t i=0; i < n; i++) {
            data[i] &= v.data[i];
        }
    }
};

