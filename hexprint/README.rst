================================================================================
                  SSSE3: printing hex values   
================================================================================

Sample program for article `SSSE3: printing hex values`__.

__ http://0x80.pl/articles/sse-hexprint.html

Program ``hexprint.c`` implements following procedures:

* ``std`` --- standard 16-byte lookup (2 lookups per byte);
* ``std2`` --- 256-byte lookup (1 lookup per byte);
* ``std3`` --- 2 x 256-byte lookups (2 lookups per 2 bytes);
* ``ssse3`` --- method described in the article (using instruction ``pshufb``).

Type ``make`` to compare speed of different implementations.

--------------------------------------------------------------------------------

Program ``branchless_hex.c`` implement various methods to convert nibbles
into ASCII hex. It's not described in the above article, but in `Conversion
numbers to hexadecimal representation`__, which covers also other methods
and CPU instructions.

__ http://0x80.pl/articles/convert-to-hex.html
