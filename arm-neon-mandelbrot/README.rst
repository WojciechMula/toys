=================================================================================
      Mandelbrot fractal generator --- ARM Neon implementation
=================================================================================


Compilation
------------------------------------------------------------------------

Simply type ``make``, program ``fractal`` will be created.

``./fractal fpu`` runs a FPU procedure
``./fractal neon`` runs an ARM Neon  procedure


Peformance results
------------------------------------------------------------------------

CPU: ARMv7 Processor rev 4 (v7l) [Raspberry Pi 3]

Compiler: GCC 4.9.2

+----------------+-----------+----------+
| procedure      | time [us] | speed up |
+================+===========+==========+
| FPU            | 2.669.333 |   1.0    |
+----------------+-----------+----------+
| ARM Neon       |   799.234 |   3.3    | 
+----------------+-----------+----------+
| ARM Neon (FMA) |   922.903 |   2.9    | 
+----------------+-----------+----------+
