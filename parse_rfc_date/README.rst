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


Know problems
--------------------------------------------------------------------------------

* My translation of Leandro's code might not be perfect.

* In SSE code I use ``_mm_extract_epi16`` (``pextract``) instruction to
  store all numeric fields (month day, hour, minute, second). This could be
  solved with **single store**, maybe masked one, if the layout of fields
  in ``std::tm`` structure was considered.


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



