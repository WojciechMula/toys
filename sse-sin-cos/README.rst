================================================================================
         Calculate sin approximation using SSE instructions
================================================================================

An SSE code calculates two sines (double precision) with `Taylor series`__.

__ https://en.wikipedia.org/wiki/Taylor_series

There are two programs, type ``make`` to build them:

* ``test_accuracy`` -- displays differences between values returned by
  libc ``sin`` and the SSE procedure;
* ``test_speed`` -- compares speed of libc ``sin``, the SSE procedure
  and a few Taylor series expansions written in C.

Results from Westemre i5 M540::

    libc sin                                : 0.221 s
    Taylor series (3 terms)                 : 0.033 s (6.61)
    Taylor series (4 terms)                 : 0.039 s (5.61)
    Taylor series (5 terms)                 : 0.050 s (4.40)
    2 x Taylor series (5 terms, SSE)        : 0.123 s (3.59)

