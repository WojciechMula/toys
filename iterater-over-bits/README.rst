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
to "better" timing is the speed-up factors: in most cases the naive version
is 1.5 times faster.


Core i5 M 540  @ 2.53GHz
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

::

    empty
        size=4096, cardinality=0
            naive:  2155ms [0]
            better: 2693ms [0] (0.80)
        size=16384, cardinality=0
            naive:  6247ms [0]
            better: 2709ms [0] (2.31)
        size=65536, cardinality=0
            naive:  10797ms [0]
            better: 19132ms [0] (0.56)
        size=262144, cardinality=0
            naive:  40842ms [0]
            better: 40654ms [0] (1.00)
        size=524288, cardinality=0
            naive:  81372ms [0]
            better: 81236ms [0] (1.00)
    1/4
        size=4096, cardinality=1024
            naive:  1160ms [2072064000]
            better: 1803ms [2072064000] (0.64)
        size=16384, cardinality=4096
            naive:  4751ms [33454080000]
            better: 7100ms [33454080000] (0.67)
        size=65536, cardinality=16384
            naive:  18799ms [536469504000]
            better: 28713ms [536469504000] (0.65)
        size=262144, cardinality=65536
            naive:  75872ms [8588328960000]
            better: 114304ms [8588328960000] (0.66)
        size=524288, cardinality=131072
            naive:  150294ms [34356527104000]
            better: 234628ms [34356527104000] (0.64)
    1/2
        size=4096, cardinality=2048
            naive:  2170ms [4160512000]
            better: 3652ms [4160512000] (0.59)
        size=16384, cardinality=8192
            naive:  8630ms [66973696000]
            better: 14182ms [66973696000] (0.61)
        size=65536, cardinality=32768
            naive:  34653ms [1073201152000]
            better: 56667ms [1073201152000] (0.61)
        size=262144, cardinality=131072
            naive:  140858ms [17177706496000]
            better: 236560ms [17177706496000] (0.60)
        size=524288, cardinality=262144
            naive:  277566ms [68715151360000]
            better: 456657ms [68715151360000] (0.61)
    3/4
        size=4096, cardinality=3072
            naive:  3171ms [6265344000]
            better: 5382ms [6265344000] (0.59)
        size=16384, cardinality=12288
            naive:  12907ms [100558848000]
            better: 21038ms [100558848000] (0.61)
        size=65536, cardinality=49152
            naive:  53118ms [1610194944000]
            better: 85209ms [1610194944000] (0.62)
        size=262144, cardinality=196608
            naive:  212492ms [25768132608000]
            better: 350787ms [25768132608000] (0.61)
        size=524288, cardinality=393216
            naive:  406933ms [103075872768000]
            better: 685104ms [103075872768000] (0.59)
    full
        size=4096, cardinality=4096
            naive:  4178ms [8386560000]
            better: 7097ms [8386560000] (0.59)
        size=16384, cardinality=16384
            naive:  16781ms [134209536000]
            better: 28206ms [134209536000] (0.59)
        size=65536, cardinality=65536
            naive:  67200ms [2147450880000]
            better: 113032ms [2147450880000] (0.59)
        size=262144, cardinality=262144
            naive:  278662ms [34359607296000]
            better: 452156ms [34359607296000] (0.62)
        size=524288, cardinality=524288
            naive:  538709ms [137438691328000]
            better: 905084ms [137438691328000] (0.60)
    rand
        size=4096, cardinality=896
            naive:  10827ms [17116800000]
            better: 17498ms [17116800000] (0.62)
        size=16384, cardinality=3136
            naive:  38499ms [236139200000]
            better: 62275ms [236139200000] (0.62)
        size=65536, cardinality=14208
            naive:  174848ms [4853402240000]
            better: 283114ms [4853402240000] (0.62)
        size=262144, cardinality=51904
            naive:  638066ms [66453592640000]
            better: 1032216ms [66453592640000] (0.62)
        size=524288, cardinality=103424
            naive:  1281804ms [268603120640000]
            better: 2059662ms [268603120640000] (0.62)


Skylake
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

::

    empty
        size=4096, cardinality=0
            naive:  457ms [0]
            better: 448ms [0] (1.02)
        size=16384, cardinality=0
            naive:  1580ms [0]
            better: 1580ms [0] (1.00)
        size=65536, cardinality=0
            naive:  6118ms [0]
            better: 6145ms [0] (1.00)
        size=262144, cardinality=0
            naive:  24337ms [0]
            better: 24269ms [0] (1.00)
        size=524288, cardinality=0
            naive:  50465ms [0]
            better: 48426ms [0] (1.04)
    1/4
        size=4096, cardinality=1024
            naive:  607ms [2072064000]
            better: 1123ms [2072064000] (0.54)
        size=16384, cardinality=4096
            naive:  2417ms [33454080000]
            better: 4487ms [33454080000] (0.54)
        size=65536, cardinality=16384
            naive:  9666ms [536469504000]
            better: 17930ms [536469504000] (0.54)
        size=262144, cardinality=65536
            naive:  38660ms [8588328960000]
            better: 71659ms [8588328960000] (0.54)
        size=524288, cardinality=131072
            naive:  77313ms [34356527104000]
            better: 143123ms [34356527104000] (0.54)
    1/2
        size=4096, cardinality=2048
            naive:  1583ms [4160512000]
            better: 2733ms [4160512000] (0.58)
        size=16384, cardinality=8192
            naive:  6296ms [66973696000]
            better: 10920ms [66973696000] (0.58)
        size=65536, cardinality=32768
            naive:  25151ms [1073201152000]
            better: 43666ms [1073201152000] (0.58)
        size=262144, cardinality=131072
            naive:  100630ms [17177706496000]
            better: 174726ms [17177706496000] (0.58)
        size=524288, cardinality=262144
            naive:  201159ms [68715151360000]
            better: 349272ms [68715151360000] (0.58)
    3/4
        size=4096, cardinality=3072
            naive:  2191ms [6265344000]
            better: 3978ms [6265344000] (0.55)
        size=16384, cardinality=12288
            naive:  8728ms [100558848000]
            better: 15896ms [100558848000] (0.55)
        size=65536, cardinality=49152
            naive:  34882ms [1610194944000]
            better: 63576ms [1610194944000] (0.55)
        size=262144, cardinality=196608
            naive:  139533ms [25768132608000]
            better: 254530ms [25768132608000] (0.55)
        size=524288, cardinality=393216
            naive:  279012ms [103075872768000]
            better: 508614ms [103075872768000] (0.55)
    full
        size=4096, cardinality=4096
            naive:  2771ms [8386560000]
            better: 5145ms [8386560000] (0.54)
        size=16384, cardinality=16384
            naive:  11042ms [134209536000]
            better: 20564ms [134209536000] (0.54)
        size=65536, cardinality=65536
            naive:  44174ms [2147450880000]
            better: 82213ms [2147450880000] (0.54)
        size=262144, cardinality=262144
            naive:  176527ms [34359607296000]
            better: 328885ms [34359607296000] (0.54)
        size=524288, cardinality=524288
            naive:  353177ms [137438691328000]
            better: 657774ms [137438691328000] (0.54)
    rand
        size=4096, cardinality=896
            naive:  6412ms [17116800000]
            better: 11987ms [17116800000] (0.53)
        size=16384, cardinality=3136
            naive:  22594ms [236139200000]
            better: 41804ms [236139200000] (0.54)
        size=65536, cardinality=14208
            naive:  112015ms [4853402240000]
            better: 193945ms [4853402240000] (0.58)
        size=262144, cardinality=51904
            naive:  422391ms [66453592640000]
            better: 719652ms [66453592640000] (0.59)
        size=524288, cardinality=103424
            naive:  846520ms [268603120640000]
            better: 1440212ms [268603120640000] (0.59)
