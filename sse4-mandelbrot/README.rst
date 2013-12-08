========================================================================
    Mandelbrot fractal generator --- SSE2 & SSE4.1 implementation
========================================================================

SSE procedure calculates 4 pixels in parallel. SSE4.1 procedure uses
``PTEST`` instruction to break loop when lengths of all 4 complex numbers
are greater then some threshold.  SSE2 version uses ``PMOVMSKB`` and x86
``TEST``.

Average speedup over FPU procedure is around 4.5 times.  Measured on
Core2 Duo E8200 @ 2.66GHz.


Compilation SSE4.1 version::

	gcc -O3 -Wall -pedantic -std=c99 sse4-mandelbrot.c -o your_favorite_name

Compilation SSE2 version::

	gcc -O3 -Wall -pedantic -std=c99 -DSSE2 sse-mandelbrot.c -o your_favorite_name
