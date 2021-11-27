================================================================================
    SWAR algorithm to count characters in a UTF-8 string
================================================================================

Author: Wojciech Muła

Last update: 2021-11-27


.. contents::


Introduction
--------------------------------------------------------------------------------

A short `UTF-8 <https://datatracker.ietf.org/doc/html/rfc3629>`_ recap.
UTF-8 characters can span 1, 2, 3 or 4 bytes.

Single-byte characters are ASCII characters; their most significant bit is
always 0.

Multi-byte characters consist the leading byte followed by 1, 2 or 3
continuation bytes. Continuation bytes have two most significant bits set to
10. In case of leading bytes, the two most significant bits are always 1.

The following table shows bit layouts.

::

    ASCII               0xxx.xxxx
    2 bytes             110x.xxxx 10xx.xxxx
    3 bytes             1110.xxxx 10xx.xxxx 10xx.xxxx
    4 bytes             1111.0xxx 10xx.xxxx 10xx.xxxx 10xx.xxxx


Providing the input string is a valid UTF-8 sequence, counting number of
characters can be done by counting **continuation bytes** and then subtracting
this number from the total string length in bytes.


Scalar algorithm
--------------------------------------------------------------------------------

To detect a continuation byte it's sufficient to cast the byte to an **signed**
byte and compare with "a magic number". This approach can be easily vectorized
(if a SIMD unit handles signed bytes).

The following scalar code comes from `simdutf`__ library::


    size_t count_code_points(const char* buf, size_t len) {
        const int8_t * p = reinterpret_cast<const int8_t *>(buf);
        size_t counter{0};
        for(size_t i = 0; i < len; i++) {
            // -65 is 0b10111111, anything larger in two-complement's should start a new code point.
            if(p[i] > -65) { counter++; }
        }
        return counter;
    }

__ https://github.com/simdutf/simdutf


SWAR algorithm
--------------------------------------------------------------------------------

Expressing comparison in SWAR is usually difficult. Thus to detect continuation
bytes we use their bit pattern: bit #7 is 1 and #6 is 0. We evaluate expression
``not bit6 and bit7`` and then count (with a population count instruction) how
many bytes have this property true.

1. input::

    t0 = [00xx.xxxx|01xx.xxxx|10xx.xxxx|11xx.xxxx]
                              ^^^^^^^^^
                              continuation byte

2. negate input (``not bit6``)::

    t1 = ~t0
    t1 = [11xx.xxxx|10xx.xxxx|01xx.xxxx|00xx.xxxx]

3. isolate the negated 6th bit::

    t2 = t1 & 0x40404040
    t2 = [0100.0000|0000.0000|0100.0000|0000.0000]

4. shift bit 6th left by 1 (to move it to the 7th position)::

    t3 = t2 + t2
    t3 = [1000.0000|0000.0000|1000.0000|0000.0000]

5. perform ``not bit6 and bit7``::

    t4 = t0 & t3
    t4 = [00xx.xxxx|01xx.xxxx|10xx.xxxx|11xx.xxxx] &
         [1000.0000|0000.0000|1000.0000|0000.0000]
       = [0000.0000|0000.0000|1000.0000|0000.0000]
                              ^^^^^^^^^
                              the only non-zero byte

6. Count continuation bytes with ``popcount(t4)``.


The actual `implementation <swar.cpp>`_::

    size_t swar_count_code_points(const char* buf, size_t len) {
        const uint64_t* qword = reinterpret_cast<const uint64_t*>(buf);
        const uint64_t* end = qword + len / 8;

        size_t count = 0;
        for (/**/; qword != end; qword++) {
            const uint64_t t0 = *qword;
            const uint64_t t1 = ~t0;
            const uint64_t t2 = t1 & 0x04040404040404040llu;
            const uint64_t t3 = t2 + t2;
            const uint64_t t4 = t0 & t3;

            count += __builtin_popcountll(t4);
        }

        count = 8 * (len / 8) - count;

        return count + ((len % 8) ? count_code_points((const char*)end, len % 8) : 0);
    }


Performance comparison
--------------------------------------------------------------------------------

We used two programs benchmark programs that were compiled with ``-O3`` and
``-march=native``.  The program ``benchmark-force-scalar`` is additionally
compiled with ``-fno-tree-vectorize`` that prevents GCC from
autovectorization.


Pentium M
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

CPU: Intel(R) Core(TM) i5 CPU M 540  @ 2.53GHz

GCC: gcc version 10.2.1 20210108 (Debian 10.2.1-5)

::

    $ ./benchmark
    rdtsc_overhead set to 33
    scalar                          :  1271.000 cycle/op (best) 1285.555 cycle/op (avg)
    swar                            :   444.000 cycle/op (best)  461.197 cycle/op (avg)

    $ ./benchmark-force-scalar
    rdtsc_overhead set to 33
    scalar                          :  2554.000 cycle/op (best) 2576.128 cycle/op (avg)
    swar                            :   447.000 cycle/op (best)  461.625 cycle/op (avg)


Speedup over the scalar version is 2.8 / 5.7.


Skylake
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

CPU: Intel(R) Core(TM) i7-6700 CPU @ 3.40GHz

GCC: gcc version 8.4.0 (Ubuntu 8.4.0-1ubuntu1~16.04.1)

::

    $ ./benchmark
    rdtsc_overhead set to 24
    scalar                          :   640.000 cycle/op (best)  650.519 cycle/op (avg)
    swar                            :   372.000 cycle/op (best)  401.109 cycle/op (avg)

    $ ./benchmark-force-scalar
    rdtsc_overhead set to 24
    scalar                          :  2840.000 cycle/op (best) 2853.797 cycle/op (avg)
    swar                            :   284.000 cycle/op (best)  318.811 cycle/op (avg)

Speedup over the scalar version is 1.7 / 10.8.
