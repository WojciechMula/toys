================================================================================
                            SIMD-ized parsing of RFC date
================================================================================

This is a proof-of-concept of SIMD-assisted RFC date parser which is used,
for instance, in HTML headers. Sample date in this format::

    "Fri, 17 Apr 2015 16:14:11 GMT"


Scalar version
--------------------------------------------------------------------------------

The baseline scalar implementation is derived from great implementation by
**Leandro A. F. Pereira** (@lpereira), who introduced following important
optimizations:

* Translation from both weekday and month names into numbers 0..6/0..11 is
  done with a switch statement. This is a very clever solution. GCC translates
  such a switch into binary search algorithm.

* All numeric conversions and range checking are done with custom, tailored
  functions. Input validation is done similarly.

This approach is obviously faster than the standard ``strptime`` function.
See ``scalar.cpp`` for more details.

SSE version
--------------------------------------------------------------------------------

SIMD implementation, available in file ``sse.cpp``, does many things in
parallel, i.e.:

* Validation of input: check if constant fields contain valid characters
  (like spaces, commas, 'GMT' string at the end).

* Translation from weekday and months names are vectorized; each require
  a few instructions and just one branch.

* Most numeric conversion, digits validation, and numbers range checking
  is done in single step. Only the year requires more scalar code.


SSE with minimal perfect hashing
--------------------------------------------------------------------------------

A much clever approach was developed by `Kendall Willets`__; we discussed
this by email, he kindly agreed to share his code.

__ https://twitter.com/kendallwillets

One of the most difficult part in parsing is conversion from four-character
abbreviations of month and weekday into numbers. Kendall observed that this
transformation might be done by **multiplication by a magic constant** and then
extraction of a few bits from the result word.

Moreover, hash values are not calculated for whole 32-bit values, but 16-bit
subwords. Thanks to that multiplication can be done alongside other
multiplications needed to convert from ASCII to numeric values.

Although the conversion itself can be done **extremely fast** -- approximately
4 cycles per input string! (SSE variant works at 27 cycles) -- the input
validation kills the performance.


Known problems
--------------------------------------------------------------------------------

* My translation of Leandro's code might not be perfect.


How to compile
--------------------------------------------------------------------------------

Type ``make test`` to compiler and run detailed unittests of scalar and SSE
procedures.

Type ``make benchmark`` to build simple benchmark utility.


Performance comparison on Core i5
--------------------------------------------------------------------------------

``make benchmark && ./benchmark`` gives on my old laptop::

    rdtsc_overhead set to 92
    scalar                          :    77.805 cycle/op (best)   98.557 cycle/op (avg)
    SSE                             :    33.979 cycle/op (best)   34.977 cycle/op (avg)



