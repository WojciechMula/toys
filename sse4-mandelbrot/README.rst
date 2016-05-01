========================================================================
  Mandelbrot fractal generator --- SSE2, SSE4.1 & AVX2 implementations
========================================================================

SSE procedure calculates 4 pixels in parallel. SSE4.1 procedure uses
``PTEST`` instruction to break loop when lengths of all 4 complex numbers
are greater then some threshold.  SSE2 version uses ``PMOVMSKB`` and x86
``TEST``. AVX2 procedure is a translation of the SSE4.1 version.

Average speedup over FPU procedure is around 4.5 times --- see below

Compilation
------------------------------------------------------------------------

Simply type ``make``. Following programs will be compiled:

* ``fractal32sse2``    --- 32-bit SSE2 procedure + scalar version using default GCC
  settings (probably scalar SSE instructions)
* ``fractal32sse4``    --- 32-bit SSE4.1 procedure + scalar version as above
* ``fractal64sse4``    --- 64-bit SSE4.1 procedure + scalar version as above
* ``fractal64avx2``    --- 64-bit AVX2 procedure + SSE4.1 + scalar version
* ``fractal32sse2fpu`` --- 32-bit SSE2 procedure + scalar version using FPU
* ``fractal32sse4fpu`` --- 32-bit SSE2 procedure + scalar version using FPU
* ``fractal64sse4fpu`` --- 64-bit SSE4.1 procedure + scalar version using FPU


Results for 32-bit versions
------------------------------------------------------------------------

"FPU" procedure uses FPU instructions
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

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

+----------------------------------+----------------+-------------+-------------+
| CPU                              | FPU [us]       | SSE4.1 [us] | speedup [%] |
+==================================+================+=============+=============+
| Core i7-3612QM CPU @ 2.10GHz     | 488984         | 152459      | 320         |
+----------------------------------+----------------+-------------+-------------+


Results for 64-bit versions
------------------------------------------------------------------------


"FPU" procedure uses FPU instructions
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

+----------------------------------+---------------+---------------+---------------+
| CPU                              | FPU [us]      | SSE4.1 [us]   | AVX2 [us]     |
+==================================+===============+===============+===============+
| Core i5 M540 CPU @ 2.35GHz       | 904228        | 143635 (6.3x) |               |
+----------------------------------+---------------+---------------+---------------+
| Skylake i7-6700 CPU @ 3.40GHz    | 685141        | 119640 (5.7x) | 61883 (1.9x)  |
+----------------------------------+---------------+---------------+---------------+

"FPU" procedure uses scalar SSE instructions
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

+----------------------------------+---------------+---------------+---------------+
| CPU                              | FPU [us]      | SSE4.1 [us]   | AVX2 [us]     |
+==================================+===============+===============+===============+
| Core i5 M540 CPU @ 2.35GHz       | 542305        | 142498 (3.8x) |               |
+----------------------------------+---------------+---------------+---------------+
| Skylake i7-6700 CPU @ 3.40GHz    | 424202        | 114512 (3.7x) | 61876 (1.8x)  |
+----------------------------------+---------------+---------------+---------------+

