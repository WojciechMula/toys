================================================================================
    SSSE3: PMADDUBSW and image crossfading
================================================================================

Sample program from article `SSSE3: PMADDUBSW and image crossfading`__.

__ http://0x80.pl/articles/sse4-crossfading.html

The program contains a reference C implementation and two SSE procedures:
one using old SSE instructions, and another using the new SSE4.1 instruction
``PMADDUBSW``.  

Run ``make`` to compare perfromance on your machine (note: the program is 32-bit).
