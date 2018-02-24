================================================================================
             Iterate over bits of a large bit stream
================================================================================

:author: Wojciech Muła

.. contents::


Introduction
-----------------------------------------------------------

See also the `Daniel Lemire's article`__.

__ https://lemire.me/blog/2018/02/21/iterating-over-set-bits-quickly/

A "bitvecor" is an array of words; in the current implementation a word is
``uint64_t``, however it might be any SIMD type.

Iteration over a bitvector means that for each 1 bit an action is performed;
in particular, the action has to know **the index** of the bit in the
bitvector.

Comparison of four methods:

1. naive method --- test each bit of word, run a procedure if the bit is set;
2. better method --- find the lowest bit set, determine its index and clear it;
3. block-3 -- split a word into 3-bit subwords, for each subword unroll callback calls;
4. block-4 -- as above, but subword size is 4 bits.

In all methods the number of callback call is the same and is equal to the number
of bits set in a word.  The methods differ in the number of iterations over
a single word:

1. naive method -- the position of most significant bit set;
2. better method -- the number of bits set;
3. block-3 -- 3 * index of last non-zero block;
4. block-4 -- 4 * index of last non-zero block.

Discussion
-----------------------------------------------------------

The better method is indeed faster in an average case. However, for specific
bit patterns other methods perform better.

These patterns contain regular, long runs of 1, thanks to that a branch
predictor is able to help. For instance, if all words in a bitvector are
``0x00000000ffffffff`` (fill factor is 0.5), then the naive method is two
times faster than the better method.  For bitvector having fill factor 0.5,
but with randomly set bits, the naive method is 4-5 times slower than better
one.


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

Tests check different vectors sizes (given in bits) and various fill
factors.  The action which is performed for each bit is storing the index in
an auxiliary table.


Core i5 M540 @ 2.53GHz
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

include core-i5-m540.txt


Skylake Core i7-6700 CPU @ 3.40GHz
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

include skylake-i7-6700.txt

