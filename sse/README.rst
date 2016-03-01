==================================================
          Various SSE procedures
==================================================

**Warning**: the code is rather old (2002-2007).

Keywords: SSE3, SSE4, basic math

1. Samples from Polish article `Streaming SIMD Extensions — przykłady zastosowań`__ [2007-09-15]

__ http://0x80.pl/articles/sse.html

* ``sse-dotprod.c`` -- dot product
* ``sse-dotprod4.c`` -- 4 dot products
* ``sse-crossprod.c`` -- cross product
* ``sse-transpose.c`` -- 4x4 matrix transposition
* ``sse-matvec-mult.c`` -- multiplication of matrix 4x4 by a vector
* ``sse-vecmat-mult.c`` -- multiplication of vector by matrix 4x4
* ``sse-matmult.c`` -- 4x4 matrices multiplication
* ``sse-aux.c`` -- auxiliary function

2. Example from Polish article `SSE3: HADDPS i iloczyn skalarny`__ [2007-09-14]

__ http://0x80.pl/articles/sse3-haddpsdotprod.html

* ``sse3-dotprod.S`` -- calculate 4 x dot product using SSE3 instruction ``HADDPS``

3. Example from Polish article `SSE4: DPPS — iloczyn skalarny`__ [13.09.2007]

__ http://0x80.pl/articles/sse4-dppsdotprod.html

* ``sse4-matvec-mult.S`` -- mutiplication of matrix 4x4 and vector 4x1 using ``DPPS`` from SSE4.1

4. Samples from Polish article `SSE4: instrukcje działające na łańcuchach`__ [2007-09-xx]

__ http://0x80.pl/articles/sse4-string-instr.html

* ``sse4-string-instr.S`` -- some functions that use SSE4 string instructions

5. Other

* ``sse4-insertionsort.c`` [2008-08-31] -- unusual application of ``PHMINPOSUW`` instruction as the key part of insertion sort for 8 element tables
* ``sse-matvecmult.c`` [2008-06-28] -- multiplication of matrix 4x4 by vector 4x1 --- FPU, SSE3 and SSE4 procedures.
