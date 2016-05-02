================================================================================
    SSSE3: PMADDUBSW and image crossfading
================================================================================

Sample program from article `SSSE3: PMADDUBSW and image crossfading`__.

__ http://0x80.pl/articles/sse4-crossfading.html

The program contains a reference C implementation and two SSE procedures:
one using old SSE instructions, and another using the new SSE4.1 instruction
``PMADDUBSW``.  

Run ``make`` to compare perfromance on your machine.

Run ``make demo`` to build a X11 application. Perhaps you'll have to run
``git submodule init``.

Application reads two .pnm files of the same size. Mouse position
determines alpha value, keys 1, 2 and 3 select bledning procedure. Usage::

    ./demo view file1.pnm file2.pnm
