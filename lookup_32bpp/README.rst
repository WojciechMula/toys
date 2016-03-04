================================================================================
        SSE: modify 32bpp images with lookup tables
================================================================================

Sample program from article `SSE: modify 32bpp images with lookup tables`__

__ http://0x80.pl/articles/sse-lookup32bpp.html

The simple program includes following procedures:

* naive --- strightforward C implementation;
* x86	--- hand-coded assembler version of naive;
* SSE2	--- SSE2 instructions used;
* SSE4	--- SSE4.1 instructions used.

Run ``make`` to compare perfromance on your machine (note: the program is 32-bit).
