================================================================================
                 Frequent substring compression
================================================================================

In the `Re-pair compression`__ we look for the most frequent pair and replaced
it with a new symbol. The process continues until we have a single symbol ---
the starting symbol for a formal grammar that describes the input string.

__ https://en.wikipedia.org/wiki/Re-Pair

This modification looks for the most frequent substring and replaces it with
a new symbol. Note that the implementation is slow and requires a whole lot of
memory.

Usage::

    $ python3 compress.py file file.compressed
    $ python3 decompress.py file.compressed file.decomp

    # make sure nothing was lost
    $ cmp file file.decomp

.. list-table:: Sample results
    :header-rows: 1

    - * file
      * size
      * compressed
      * compression / size

    - * ``amd64enc.s`` from Go source
      * 595,915
      * 296,674
      * 49.8%

    - * ``xml`` from Silesia Corpus
      * 5,345,280
      * 2,977,779
      * 55.8%

    - * ``reymont`` form Silesia Corpus
      * 6,627,202
      * 4,535,586
      * 68.4%
