================================================================================
                                SIMD animation
================================================================================

A script used to create SIMD animation.

How to use:

1. Create two directories ``input`` and ``output``.
2. Download your favourite gif :) into ``input`` directory.
3. Extract all frames::

   $ cd input
   $ convert your.gif frame%02d.pnm

4. Run the script::

   $ ./animate.py

5. The output gif is saved as ``output/out.gif``
