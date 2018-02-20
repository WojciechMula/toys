#pragma once

#include <cstddef>
#include <cstdint>
#include <cassert>
#include <cstdlib>


class bitvector {

    const size_t n;
    uint64_t* array;

public:
    bitvector(size_t n_) : n(n_) {
        assert(n > 0);
        array = new uint64_t[n];
    }

    ~bitvector() {
        delete[] array;
    }

    void fill(uint64_t word) {
        for (size_t i=0; i < n; i++)
            array[i] = word;
    }

    void fill_random(int threshold) {
        assert(threshold >= 0);
        assert(threshold <= 100);

        srand(0);
        for (size_t i=0; i < n; i++) {
            if ((rand() % 100) > threshold) {
                array[i] = -1;
            } else {
                array[i] = 0;
            }
        }
    }

    size_t size() const {
        return n * 64;
    }

    size_t cardinality() const {
        size_t k = 0;
        for (size_t i=0; i < n; i++) {
            k += __builtin_popcountll(array[i]);
        }

        return k;
    }

public:
    template <typename CALLBACK>
    void iterate_naive(CALLBACK callback) const {
        for (size_t i=0; i < n; i++) {
            uint64_t tmp = array[i];

            size_t k = i * 64;
            while (tmp) {
                if (tmp & 0x1) {
                    callback(k);
                }

                tmp >>= 1;
                k += 1;
            }
        }
    }

    template <typename CALLBACK>
    void iterate_better(CALLBACK callback) const {
        for (size_t i=0; i < n; i++) {
            uint64_t tmp = array[i];

            size_t k = i * 64;
            while (tmp) {
                const uint64_t t = tmp & (~tmp + 1);
                const uint64_t r = __builtin_ctzll(t);
                callback(k + r);
                tmp ^= t;
            }
        }
    }

    template <typename CALLBACK>
    void iterate_block3(CALLBACK callback) const {
        for (size_t i=0; i < n; i++) {
            uint64_t tmp = array[i];

            size_t k = i * 64;
            while (tmp) {
                switch (tmp & 0x7) {
                    case 0:
                        break;

                    case 1:
                        callback(k);
                        break;

                    case 2:
                        callback(k + 1);
                        break;

                    case 3:
                        callback(k);
                        callback(k + 1);
                        break;

                    case 4:
                        callback(k + 2);
                        break;

                    case 5:
                        callback(k);
                        callback(k + 2);
                        break;

                    case 6:
                        callback(k + 1);
                        callback(k + 2);
                        break;

                    case 7:
                        callback(k);
                        callback(k + 1);
                        callback(k + 2);
                        break;
                }

                tmp >>= 3;
                k += 3;
            }
        }
    }

    template <typename CALLBACK>
    void iterate_block4(CALLBACK callback) const {
        for (size_t i=0; i < n; i++) {
            uint64_t tmp = array[i];

            size_t k = i * 64;
            while (tmp) {
                switch (tmp & 0xf) {
                    case 0:
                        break;

                    case 1:
                        callback(k);
                        break;

                    case 2:
                        callback(k + 1);
                        break;

                    case 3:
                        callback(k);
                        callback(k + 1);
                        break;

                    case 4:
                        callback(k + 2);
                        break;

                    case 5:
                        callback(k);
                        callback(k + 2);
                        break;

                    case 6:
                        callback(k + 1);
                        callback(k + 2);
                        break;

                    case 7:
                        callback(k);
                        callback(k + 1);
                        callback(k + 2);
                        break;

                    case 8:
                        callback(k + 3);
                        break;

                    case 9:
                        callback(k);
                        callback(k + 3);
                        break;

                    case 10:
                        callback(k + 1);
                        callback(k + 3);
                        break;

                    case 11:
                        callback(k);
                        callback(k + 1);
                        callback(k + 3);
                        break;

                    case 12:
                        callback(k + 2);
                        callback(k + 3);
                        break;

                    case 13:
                        callback(k);
                        callback(k + 2);
                        callback(k + 3);
                        break;

                    case 14:
                        callback(k + 1);
                        callback(k + 2);
                        callback(k + 3);
                        break;

                    case 15:
                        callback(k);
                        callback(k + 1);
                        callback(k + 2);
                        callback(k + 3);
                        break;
                }

                tmp >>= 4;
                k += 4;
            }
        }
    }
};

