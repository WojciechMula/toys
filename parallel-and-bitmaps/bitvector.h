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

    bool set_unsafe(size_t index) {
        const size_t n = index / 64;
        const size_t k = index % 64;

        const uint64_t tmp = data[n];
        data[n] |= uint64_t(1) << k;

        return tmp != data[n];
    }

    void fill(uint64_t word) {
        for (size_t i=0; i < n; i++)
            data[i] = word;
    }

    void fill_random() {
        assert(RAND_MAX > 65535);
        for (size_t i=0; i < n; i++) {
            const uint64_t w0 = rand() % 65536;
            const uint64_t w1 = rand() % 65536;
            const uint64_t w2 = rand() % 65536;
            const uint64_t w3 = rand() % 65536;

            data[i] = (w3 << (3*16)) |
                      (w2 << (1*16)) |
                      (w1 << (1*16)) |
                      (w0 << (0*16));
        }
    }

    void fill_random(double fillfactor) {
        assert(fillfactor >= 0.0);
        assert(fillfactor <= 1.0);

        if (fillfactor == 0.0) {
            fill(0);
            return;
        }

        if (fillfactor == 1.0) {
            fill(-1);
            return;
        }

        const size_t n = size();
        const size_t expected = n * fillfactor;
        size_t k = expected;
        fill(0);
        srand(0);
        while (k > 0) {
            k -= size_t(set_unsafe(rand() % n));
        }

        assert(cardinality() == expected);
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

    void __attribute__ ((noinline)) bitwise_and(const bitvector& v1, const bitvector& v2) {
        for (size_t i=0; i < n; i++) {
            data[i] = v1.data[i] & v2.data[i];
        }
    }

    void __attribute__ ((noinline)) bitwise_and(const bitvector& v) {
        for (size_t i=0; i < n; i++) {
            data[i] &= v.data[i];
        }
    }
};

