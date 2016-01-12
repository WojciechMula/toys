Base64 encoding with SIMD instructions
--------------------------------------------------------------------------------

An SSE implementation is more then **2 times faster** on Core i7,
and about **70% faster** on Core i5.

This directory contains following programs:

* ``verify`` --- verifies branchless procedures calculating the lookup table,
  both scalar and SSE versions;
* ``check`` --- checks if base64 encoders using different lookup procedures
  and splitting bytes methods works correctly;
* ``speed`` --- allows to measure speed of all or selected base64 encoder;
  it encodes 192 MiB of artificial data 10 times, and then print the smallest
  measurement.

The full description: http://0x80.pl/notesen/2016-01-12-sse-base64-encoding.html
