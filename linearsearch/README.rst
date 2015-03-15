========================================================================
                    Linked list comparision
========================================================================

This program compares searching time in linked lists, to build the
program simply type ``make``, then ``./demo --all``.

A list stores key (``uint32_t``) and associated value (``int`` in
the tests).  Basically two data structures are examined:

- **Simple linked list**, i.e. each item contains key, value and
  a pointer to the next element.
- **Linked arrays**, i.e. each item contains two **fixed-size arrays**
  of keys and values, and pointer to the next element and counter of
  elements in the array. For arrays of size 4 and 8 there are two
  specializations using SSE instructions.

Linked arrays seems to be better, because (1) requires less dereferences,
(2) keys are grouped together, increasing memory locality.


Results
------------------------------------------------------------------------

Changing a data structure gives some speedup, but using SSE instructions
makes searching really fast.


Pentium M @ 1.5GHz
~~~~~~~~~~~~~~~~~~

::

    list                          :      0.780s, speedup  1.00
    array list (4)                :      0.703s, speedup  1.11
    array list (8)                :      0.515s, speedup  1.51
    SIMD array list (4)           :      0.365s, speedup  2.14
    SIMD array list (8)           :      0.258s, speedup  3.03


Core i5 @ 2.5GHz
~~~~~~~~~~~~~~~~

::

    list                          :      0.504s, speedup  1.00
    array list (4)                :      0.197s, speedup  2.56
    array list (8)                :      0.231s, speedup  2.18
    SIMD array list (4)           :      0.198s, speedup  2.55
    SIMD array list (8)           :      0.105s, speedup  4.80

