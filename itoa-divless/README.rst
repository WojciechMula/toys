================================================================================
    Conversion uint32 into decimal without division nor multiplication
================================================================================

This is follow up to Daniel Lemire's `Converting integers to fix-digit representations quickly`__.

__ https://lemire.me/blog/2021/11/18/converting-integers-to-fix-digit-representations-quickly/

The method described here **does not** use multiplication nor division
instructions.  It relies only on addition and byte-level comparison.
It's weird and slow, though.

The main idea is to work directly on the BCD representation. First,
we precaulate BCD images (16-byte arrays) for individual bytes of
a 32-bit number. The following values are considered:

- ``0x00``, ``0x01``, ..., ``0xff``;
- ``0x0000``, ``0x0100``, ..., ``0xff00``;
- ``0x000000``, ``0x010000``, ..., ``0xff0000``;
- ``0x00000000``, ``0x01000000``, ..., ``0xff000000``;

Then when converting a number we fetch the BCD images and add them
together.

The next step of algorithm is fixing up the sum, as some bytes
might be greater then 9. After this step all bytes are in range
0 .. 9.

The last step is simple conversion into ASCII by adding ``ord('0') = 0x30``.


Example
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Let ``x = 20211121 = 13465b1``. We split the value into separate
bytes ``0xb1``, ``0x65``, ``0x34`` and ``0x01``.

Then, for each byte, we fetch the appropriate BCD image:

- ``0xb1`` => ``[ 0| 0| 0| 0| 0| 0| 0| 0| 0| 0| 0| 0| 0| 1| 7| 7]`` (177)
- ``0x65`` => ``[ 0| 0| 0| 0| 0| 0| 0| 0| 0| 0| 0| 2| 5| 8| 5| 6]`` (101 * 256 = 25'856)
- ``0x34`` => ``[ 0| 0| 0| 0| 0| 0| 0| 0| 0| 3| 4| 0| 7| 8| 7| 2]`` (52 * 65536 = 3'407'872)
- ``0x01`` => ``[ 0| 0| 0| 0| 0| 0| 0| 0| 1| 6| 7| 7| 7| 2| 1| 6]`` (1 * 16777216 = 16'777'216)

This step requires six 64-loads. For byte #0 and byte #1 the higher 8 bytes of
BCD image are always zero. For byte #2 and #3 all 16 bytes of images are
required.

Once we have all the BCD images, we simply add them together. We have four
inputs, where none of bytes exceed 9, thus it's safe to perform 64-bit additions.

For our sample data we have::

    [ 0| 0| 0| 0| 0| 0| 0| 0| 0| 0| 0| 0| 0| 1| 7| 7]
    [ 0| 0| 0| 0| 0| 0| 0| 0| 0| 0| 0| 2| 5| 8| 5| 6] +
    [ 0| 0| 0| 0| 0| 0| 0| 0| 0| 3| 4| 0| 7| 8| 7| 2] +
    [ 0| 0| 0| 0| 0| 0| 0| 0| 1| 6| 7| 7| 7| 2| 1| 6] +
    --------------------------------------------------
    [ 0| 0| 0| 0| 0| 0| 0| 0| 1| 9|11| 9|19|19|20|21]

There are some bytes greater than 9, we need to fix them up::
    
    t0 = [ 0| 0| 0| 0| 0| 0| 0| 0| 1| 9|11| 9|19|19|20|21]
    t1 = [ 0| 0| 0| 0| 0| 0| 0| 0| 1| 9|11| 9|19|19|22| 1] -- carry 2 from #0 to #1
    t3 = [ 0| 0| 0| 0| 0| 0| 0| 0| 1| 9|11| 9|19|21| 2| 1] -- carry 2 from #1 to #2
    t4 = [ 0| 0| 0| 0| 0| 0| 0| 0| 1| 9|11| 9|21| 1| 2| 1] -- carry 2 from #2 to #3
    t5 = [ 0| 0| 0| 0| 0| 0| 0| 0| 1| 9|11|11| 1| 1| 2| 1] -- carry 2 from #3 to #4
    t6 = [ 0| 0| 0| 0| 0| 0| 0| 0| 1| 9|12| 1| 1| 1| 2| 1] -- carry 1 from #4 to #5
    t7 = [ 0| 0| 0| 0| 0| 0| 0| 0| 1|10| 2| 1| 1| 1| 2| 1] -- carry 1 from #5 to #6
    t8 = [ 0| 0| 0| 0| 0| 0| 0| 0| 2| 0| 2| 1| 1| 1| 2| 1] -- carry 1 from #6 to #7

The carry value between bytes never exceeds 3. Since we have four inputs, than
maximum value of byte at 0th position is 4*9 = 36. Any subsequent carry value
cannot be greater than 3, as 4*9 + 3 is 39.

This means that the carry value can be obtained with a series of comparisons.
