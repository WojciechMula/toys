================================================================================
                    SIMDized sum of all bytes in the array
================================================================================

Sample programs for aricle__.

__ http://0x80.pl/notesen/2018-10-24-sse-sumbytes.html


Usage
--------------------------------------------------------------------------------

Run unittests for SSE target::

    $ make unittest && ./unittest

For AVX2 target::

    $ make unittest_avx2 && ./unittest_avx2

Run benchmarks for SSE target::

    $ make benchmark && ./benchmark

For AVX2 target::

    $ make benchmark_avx2 && ./benchmark_avx2
