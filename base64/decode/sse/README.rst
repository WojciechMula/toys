Base64 encoding with SIMD instructions
--------------------------------------------------------------------------------

An SSE implementation is **2 times faster** than basic scalar version on Core i5.

This directory contains following programs:

* ``verify`` --- verifies all decoding procedures, both scalar and SSE;
* ``check`` --- checks if base64 decoders work correctly.
* ``speed`` --- allows to measure speed of all or selected base64 decoder;
  it decodes 64 MiB of artificial data 10 times, and then print the smallest
  measurement.

The full description: http://0x80.pl/notesen/2016-01-17-sse-base64-decoding.html
