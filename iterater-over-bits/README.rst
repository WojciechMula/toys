================================================================================
             Iterate over bits of a large bit stream
================================================================================

Comparison of two methods:

1. naive method --- test each bit of word, run a procedure if the bit is set;
2. better method --- find the lowest bit set, determine its index and clear it;

In the naive method the number of iterations is fixed, number of calls is
proportional to the number of set bits. In the better method both number of
iterations and calls are proportional to the number of set bits.

Method 1::

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

Method 2::

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


Tests & results
--------------------------------------------------------------------------------

Tests check different vectors sizes (given in bits) and various fill factors.

Below are unprocessed outputs from ``make``. The number in parentheses next
to "better" timing is the speed-up factor: in most cases the naive version
is 1.5 times faster.


Core i5 M 540  @ 2.53GHz
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. include:: core-i5.txt
    :literal:

Skylake
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. include:: skylake.txt
    :literal:
