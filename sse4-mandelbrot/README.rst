========================================================================
    Mandelbrot fractal generator --- SSE2 & SSE4.1 implementation
========================================================================

SSE procedure calculates 4 pixels in parallel. SSE4.1 procedure uses
``PTEST`` instruction to break loop when lengths of all 4 complex numbers
are greater then some threshold.  SSE2 version uses ``PMOVMSKB`` and x86
``TEST``.

Average speedup over FPU procedure is around 4.5 times --- see below


Compilation SSE4.1 version::

	gcc -O3 -Wall -pedantic -mfpmath=387 -std=c99 sse4-mandelbrot.c -o your_favorite_name

Compilation SSE2 version::

	gcc -O3 -Wall -pedantic -mfpmath=387 -std=c99 -DSSE2 sse-mandelbrot.c -o your_favorite_name

Flag ``mfpmath=387`` is very important, because I mixed floating points
calculations with asm statements.


Results
------------------------------------------------------------------------


"FPU" procedure uses FPU instructions
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Compilation::

	gcc -O3 -mfpmath=387 -std=c99 sse4-mandelbrot.c

+----------------------------------+----------------+-------------+-------------+
| CPU                              | FPU [us]       | SSE4.1 [us] | speedup [%] |
+==================================+================+=============+=============+
| Core2 Duo E8200 @ 2.66GHz        | ?              | ?           | 450         |
+----------------------------------+----------------+-------------+-------------+
| Core i7-3612QM CPU @ 2.10GHz     | 530472         | 152459      | 348         |
+----------------------------------+----------------+-------------+-------------+
| Core2 Duo E8200 @ 2.66GHz        | 1716500        | 250706      | 685         |
+----------------------------------+----------------+-------------+-------------+


"FPU" procedure uses scalar SSE instructions
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Compilation::

	gcc -O3 -mfpmath=sse2 -std=c99 sse4-mandelbrot.c


+----------------------------------+----------------+-------------+-------------+
| CPU                              | FPU [us]       | SSE4.1 [us] | speedup [%] |
+==================================+================+=============+=============+
| Core i7-3612QM CPU @ 2.10GHz     | 488984         | 152459      | 320         |
+----------------------------------+----------------+-------------+-------------+
