================================================================================
            Speeding up image bluring with MMX & SSE
================================================================================

This is program for my Polish article `Rozmycie obrazów`__ (Blurring images);
try `Google translate`__ if you wish, it gives quite good translation.

__ http://0x80.pl/articles/blur.html
__ https://translate.google.pl/translate?hl=en&sl=pl&tl=en&u=http%3A%2F%2F0x80.pl%2Farticles%2Fblur.html


Short introduction
--------------------------------------------------

Blurring in this case means calculating following kernel::

    +---+---+---+
    | 1 | 1 | 1 |
    +---+---+---+
    | 1 | 1 | 1 |
    +---+---+---+
    | 1 | 1 | 1 |
    +---+---+---+

where bias is 0 and divisor is 9.

Following observation have made possible significant speedup:

* each pixel could be fetched **excatly once**;
* some calculation can be shared across calculations for adjacent blocks.


Sample program
--------------------------------------------------
 
The sample program contains several implementations:

* ``x86`` --- a scalar reference implementation;
* ``MMX`` --- an MMX variant of the scalar algorithm;
* ``MMX2`` --- an MMX variant with minimized memory fetches;
* ``SSE2`` --- an SSE2 variant of the MMX implementation.

Results from Core i5
--------------------------------------------------

CPU: Core i5 M 540 @ 2.53GHz

Note: a 32-bit code

+------+----------+----------+----------------------------------------------+
| proc | time [s] | speedup  |                                              |
+======+==========+==========+==============================================+
| x86  | 0:08.27  | 1.00     | ``█████``                                    |
+------+----------+----------+----------------------------------------------+
| mmx  | 0:01.82  | 4.52     | ``██████████████████████``                   |
+------+----------+----------+----------------------------------------------+
| mmx2 | 0:02.35  | 3.52     | ``█████████████████``                        |
+------+----------+----------+----------------------------------------------+
| sse2 | 0:01.04  | 7.95     | ``████████████████████████████████████████`` |
+------+----------+----------+----------------------------------------------+
