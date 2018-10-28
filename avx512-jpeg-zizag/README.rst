Sample code for `AVX512 implementation of JPEG zigzag transformation`__.

__ http://0x80.pl/notesen/2018-05-13-avx512-jpeg-zigzag-transform.html

The subdirectory ``8bit-array`` has got code deals with array of
``uint8_t``.  Similarly, the code from subdirectory ``16bit-array`` handle
array of ``uint16_t``.

Following instruction sets were tested:

* AVX512F,
* AVX512BW,
* AVX512VBMI, 
* and SSE.
