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
* ``strrchr``,
* ``strcmp``.


Building
--------------------------------------------------

Type ``make`` to build following programs:

* ``test`` --- does basic tests and validation;
* ``speed_str{len,chr,rchr,cmp}`` --- compare performance of vector 
  procecures against stdlib and custom scalar procedures.

`Intel Software Development Emulator`__ can be used to run the programs.

__ https://software.intel.com/en-us/articles/intel-software-development-emulator


See also
--------------------------------------------------

Other repositories related to string processing:

* https://github.com/WojciechMula/sse4-strstr (SSE4.1, AVX2 and AVX512F)
* https://github.com/WojciechMula/sse2string (SSE2)
* https://github.com/WojciechMula/toys/tree/master/strstr (SWAR)


Preliminary performance results
--------------------------------------------------

I'm aware that these tests aren't very good, they do not cover wider
range of strings lengths and so forth.

* Compiler: GCC 5.4.3
* CPU: Knights Landing 7210
* 10kB strings were processed

+----------+-------------------+----------+
|          |       time [s]    |          |
| function +---------+---------+ speed-up |
|          |   std   | AVX512F |          |
+==========+=========+=========+==========+
| strlen   | 0.0829  | 0.0167  |     4.96 |
+----------+---------+---------+----------+
| strchr   | 0.1000  | 0.0225  |     4.44 |
+----------+---------+---------+----------+
| strrchr  | 0.7211  | 0.0450  |    16.03 |
+----------+---------+---------+----------+
| strcmp   | 0.1171  | 0.0297  |     3.94 |
+----------+---------+---------+----------+
