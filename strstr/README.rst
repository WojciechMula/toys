================================================================================
                SIMD-friendly Rabin-Karp modification
================================================================================

SWAR algorithm, **faster 2-3 times** than C++ ``std::string::find``.

Read the full description: http://0x80.pl/articles/simd-friendly-karp-rabin.html


Usage
------------------------------

Run ``make analyze64`` to compare ``std::string::find``, ``strlen`` and
a sample implementation.

Run ``make verification`` to check if the sample implementation returns
valid results.
