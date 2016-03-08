================================================================================
     Penalties of errors in SSE floating point calculations
================================================================================

Sample program for article `Penalties of errors in SSE floating point calculations`__.

__ http://0x80.pl/articles/sse-penalties-of-errors.html

After typing ``make`` following program will be created:

* ``test_flush_to_zero`` --- the flag **flush to zero** disables underflow/denormal errors;
* ``test_denormals_speed`` --- compare speed of calculations where denormals appears
  when flags **denormals are zero** or **flush to zero** are set.

