================================================================================
             Iterate over bits of a large bit stream
================================================================================

.. contents::


Introduction
-----------------------------------------------------------

Comparison of four methods:

1. naive method --- test each bit of word, run a procedure if the bit is set;
2. better method --- find the lowest bit set, determine its index and clear it;
3. block-3 -- split a word into 3-bit subwords, for each subword unroll callback calls;
4. block-4 -- as above, but subword size is 4 bits.

In all methods the number of callback call is the same and is equal the number
of bits set in a word.  The methods differ in the number of iterations over
a single word:

1. naive method -- the position of most significant bit set;
2. better method -- the number of bits set;
3. block-3 -- 3 * index of last non-zero block;
4. block-4 -- 4 * index of last non-zero block.


Implementations
-----------------------------------------------------------

Naive method::

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

Better method::

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

Block-3 method::

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

                // inline callback calls for rest values 2..7
            }

            tmp >>= 3;
            k += 3;
        }
    }

Block-4 method::

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

                // inline callback calls for rest values 2..15
            }

            tmp >>= 4;
            k += 4;
        }
    }

Tests & results
--------------------------------------------------------------------------------

Tests check different vectors sizes (given in bits) and various fill factors.

Below are unprocessed outputs from ``make``. The number in parentheses next
to "better" timing is the speed-up factor.


Core i5 M540 @ 2.53GHz
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

include core-i5-m540.txt

Skylake Core i7-6700 CPU @ 3.40GHz
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

include skylake-i7-6700.txt

