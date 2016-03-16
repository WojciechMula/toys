Base64 encoding with SIMD instructions
--------------------------------------------------------------------------------

An SSE implementation is more then **2 times faster** on Core i7 (Haswell),
and about **70% faster** on Core i5. An AVX2 implementation is **3.5 times**
faster on Core i7 (Skylake).

The full description: http://0x80.pl/notesen/2016-01-12-sse-base64-encoding.html


Contents
--------------------------------------------------

This directory contains following programs:

* ``verify`` --- verifies branchless procedures calculating the lookup table,
  both scalar and SSE versions;
* ``check`` --- checks if base64 encoders using different lookup procedures
  and splitting bytes methods works correctly;
* ``speed`` --- allows to measure speed of all or selected base64 encoder;
  it encodes 192 MiB of artificial data 10 times, and then print the smallest
  measurement.
* ``verify_avx2``, ``check_avx2`` and ``speed_avx2`` do the same as above
  programs, but include AVX2 versions of the algorithms.


Compilation
--------------------------------------------------

Please edit ``config.h`` if you have BMI2 instruction set.

Run ``make`` to compile all the programs containing scalar, SSE and
possibly BMI2 versions.

Run ``make avx2`` to compile all the programs containing all versions,
including AVX2.
