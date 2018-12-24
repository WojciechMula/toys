Broadcasting given bit into whole byte.

For instance, we have eight bytes::

    0101_0111 0111_0101 0011_1100 1100_0001 1000_0101 0111_1111 1110_1001 0010_0100
     ^           ^       ^               ^         ^        ^   ^          ^

And want to populat marked bits to the bytes::

    1111_1111 1111_1111 0000_0000 0000_0000 0000_0000 1111_1111 1111_1111 0000_0000
