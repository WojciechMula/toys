================================================================================
        Comparison of two different string join approaches (C++)
================================================================================

Procedure joins many strings from a collection, inserting separator between::

    string_join("#", {"cat", "jumps", "over"}) => "cat#jumps#over"

There are two variants:

* **naive** --- appends strings to initially empty string;
* **precalc** --- firstly calculates total size of output, then reserve memory,
  and finally appends strings.

**Precalc** approach avoid resizing result string and thus calling memory
allocation. It's a bit faster when input arrays are small, otherwise cost
of copying strings dominates.

--------------------------------------------------------------------------------

Usage::

    $ make && ./test size-of-collection
