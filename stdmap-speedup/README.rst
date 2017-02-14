================================================================================
            STL: map with string as key — access speedup
================================================================================

`Speedup accesing map with strings as keys`__. Instead of single std::map
there is table of maps (addressed in O(1) time) storing keys that share
same properies:

* equal length
* equal first char (one level trie)
* both

On my system the best speedup occured for third method.

__ http://0x80.pl/notesen.html#stl-map-with-string-as-key-access-speedup-3-04-2010



Type ``make`` to build a demo program. Sample results from my machine::

    $ ./demo < /usr/share/dict/words 
    loading words...
    2687 ms words=3639638
    inserting into maps grouped by size & first char
    1704 ms
    inserting into maps grouped by size
    2212 ms
    inserting into maps grouped by first char
    2283 ms
    inserting into std::map
    2625 ms

    size1=3639637 size2=3639637 size3=3639637 size4=3639637
    reading from maps grouped by size & first char
    1080 ms
    reading from maps grouped by size
    1344 ms
    reading from maps grouped by first char
    1293 ms
    reading from std::map
    1579 ms

