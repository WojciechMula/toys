Base64 encoding with SIMD instructions
================================================================================

An SSE implementation is **1.4 times faster** than improved scalar version on
Core i5 (Westmere). AVX2 version is more than **2 times faster** on Core i7 (Sylake).

The full description: http://0x80.pl/notesen/2016-01-17-sse-base64-decoding.html


Contents
--------------------------------------------------

This directory contains following programs:

* ``verify`` --- verifies all decoding procedures: scalar (naive and improve),
  BMI2, SSE and AVX2;
* ``check`` --- checks if base64 decoders work correctly.
* ``speed`` --- allows to measure speed of all or selected base64 decoder;
  it decodes 64 MiB of artificial data 10 times, and then print the smallest
  measurement.
* ``verify_avx2``, ``check_avx2`` and ``speed_avx2`` do the same as above
  programs, but include AVX2 versions of the algorithms.


Compilation
--------------------------------------------------

Please edit ``config.h`` if you have BMI2 instruction set.

Run ``make see`` (or simply ``make``) to run all the programs containing
scalar, SSE and possibly BMI2 versions.

Run ``make avx2`` to run all the programs containing all versions,
including AVX2.
