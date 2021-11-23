================================================================================
    Conversion uint32 into decimal without division nor multiplication
================================================================================

Author: Wojciech Muła

Last update: 2021-11-23


Introduction
--------------------------------------------------------------------------------

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

Sample scalar implementation (source `itoa_divless.cpp <itoa_divless.cpp>`_)::
    
    void itoa_divless(uint32_t x, char* buffer) {
        union {
            uint64_t qword[2];
            uint8_t bytes[16];
        };

        qword[0] = qword[1] = 0;

        // 1. obtain BCD representation of all bytes
        {
            const uint8_t byte0 = x & 0xff;
            qword[1] += *(uint64_t*)&lookup0[byte0][0];
        }
        {
            const uint8_t byte1 = (x >> 8) & 0xff;
            qword[1] += *(uint64_t*)&lookup1[byte1][0];
        }
        {
            const uint8_t byte2 = (x >> 16) & 0xff;
            qword[0] += *(uint64_t*)&lookup2[byte2][0];
            qword[1] += *(uint64_t*)&lookup2[byte2][8];
        }
        {
            const uint8_t byte3 = (x >> 24) & 0xff;
            qword[0] += *(uint64_t*)&lookup3[byte3][0];
            qword[1] += *(uint64_t*)&lookup3[byte3][8];
        }
        
        // 2. fixup BCD & store result
        uint8_t carry = 0;
        for (int i=15; i >= 0; i--) {
            const uint8_t byte = bytes[i] + carry;
            if (byte >= 30) {
                buffer[i] = byte - 30 + '0';
                carry = 3;
            } else if (byte >= 20) {
                buffer[i] = byte - 20 + '0';
                carry = 2;
            } else if (byte >= 10) {
                buffer[i] = byte - 10 + '0';
                carry = 1;
            } else {
                buffer[i] = byte + '0';
                carry = 0;
            }
        }
    }


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


BCD addition
--------------------------------------------------------------------------------

Adding two BCD numbers, where each decimal digit occupies either a byte or
nibble, can be done with single addition. However, fixing up the digits grater
than 9 is non-trivial.

The fix up step is needed, as a regular addition does not propagate the carry
values between adjacent decimal digits. It would be perfect if we somehow
forced such propagation across the whole input word.

Good news is that's possible, although at cost of modifying input values and
result.  These modifications are easily SIMD-izable.

Lets assume just two decimal digits **a** and **b** stored on a byte. We need
to have ``a + b + carry`` = ``0x1??`` if the left-hand size sum is greater than
9 (``0x0??`` otherwise). We can achieve this by **shifting** one of the
operands to the upper bound of byte range, so that exceeding 9 will result in
carrying to the next byte.

The following expression holds this property (see ``proof_carry`` in `proof_single_digit.py`__)::

    (255 - 9 + a) + b + carry

__ proof_single_digit.py


At this point we have the result in form ``0x1??`` if the sum is greater than
9.  We now want to obtain from the byte marked with ``??`` the desired digit, i.e.:
``digit = (a + b + carry) mod 10``.

We need to consider two cases:

1. If there was overflow, then the byte equals digit::

    digit = ((255 - 9 + a) + b + carry) & 0xff

2. If there was no overflow, than the sum stored in the byte remain intact and
   we need to subtract the shift value::

        digit = ((255 - 9 + a) + b + carry) & 0xff - (255 - 9)

These two facts are hold for all possible values of **a**, **b** and **carry**
(see ``proof_digit`` in `proof_single_digit.py`__).

__ proof_single_digit.py


The whole calculations for a single pair of digits looks like this::

    input: a = 0..9, b = 0..9, carry = 0..1

    const shift = 255 - 9

    1. a'  := shift + a
    2. sum := a' + b + carry

    3. carry' := sum >> 8
    4. digit  := sum & 0xff
    5. if digit > shift:
    6.    digit -= shift

The initial shifting (line 1) can be even done in SWAR. Getting back to BCD
representation (lines 5 and 6) is easy to do with SIMD (in SWAR is feasible,
too).


See `verify_bcd_add.cpp <verify_bcd_add.cpp>`_ for sample SWAR & SSE implementations.
