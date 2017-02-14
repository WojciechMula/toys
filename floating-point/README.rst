================================================================================
                    Floating-point numbers
================================================================================

Programs for article `Floating point tricks`__:

* ``float2int.c`` --- conversion float to integers
* ``round2.c`` --- rounding double precision numbers

__ http://0x80.pl/articles/fptricks.html 

Other programs:

* ``round.c`` --- rounding numbers
* ``range01.c`` --- checks whether number lies in range [0, 1] (integer
  operations are used)


--------------------------------------------------------------------------------

Type ``make`` to build ``float2int`` and ``round2``; type ``make test``
to run performance tests.

Below are results from my Core i5 M540.

``float2int``::

    function FPU, iterations = 10000, size = 65536                  0:01.43
    function simple (C), iterations = 10000, size = 65536           0:01.26
    function simple (x86), iterations = 10000, size = 65536         0:00.85
    
``round2``::

    stdlib, iterations = 10000, size = 65536                        0:15.12
    FPU FRNDINT, iterations = 10000, size = 65536                   0:18.43
    FPU FISTP/FILD, iterations = 10000, size = 65536                0:01.01
    simple method (C impl.), iterations = 10000, size = 65536       0:01.01

