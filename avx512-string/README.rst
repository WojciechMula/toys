================================================================================
                       AVX512 string operations
================================================================================


Overview
--------------------------------------------------

This directory contains implementations of string function that use AVX512F
instructions. Note that AVX512F doesn't support byte-leve operations, so
some SWAR tricks were used. Following functions are available:

* ``strlen``,
* ``strchr``,
* ``strfind`` -- which doesn't match any standard, it's modified Karp-Rabin
  scheme, where equality of first four characters causes exact comparison.


Building
--------------------------------------------------

Type ``make`` to build following programs:

* ``test`` --- does basic tests and validation;
* ``speed_strlen``, ``speed_strchr`` --- compare performance of vector 
  procecures against stdlib and custom scalar procedures.

`Intel Software Development Emulator`__ can be used to run the programs.

__ https://software.intel.com/en-us/articles/intel-software-development-emulator


See also
--------------------------------------------------

Other repositories related to string processing:

* https://github.com/WojciechMula/sse4-strstr
* https://github.com/WojciechMula/sse2string
* https://github.com/WojciechMula/toys/tree/master/strstr


Preliminary performance results
--------------------------------------------------

I'm aware that these tests aren't very good, they do not cover wider
range of strings lengths and so forth.

Compiler: GCC 5.4.3, CPU: Knights Landing 7210.

strlen (10kB strings)::

    std::strlen     0.0829 s
    AVX512F         0.0167 s (4.96 faster)

strchr (10kB strings)::

    std::strchr     0.1000 s
    AVX512F         0.0225 s (4.44 faster)
    
