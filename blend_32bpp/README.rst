================================================================================
                SSSE3/SSE4: alpha blending — operator over
================================================================================

Sample program from article `SSSE3/SSE4: alpha blending — operator over`__.

__ http://0x80.pl/articles/sse4-alphaover.html

The program contains four procedurs:

* reference C implementation;
* SSS3-based implementation;
* SSE4.1 implementation (SSS3 with minor improvments);
* SSE4.1 unrolled 4 times.

Run ``make`` to compare perfromance on your machine (note: the program is 32-bit).
